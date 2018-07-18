//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
	song_count = 0;
    song_list_bottom_index = 0;
    current_song_index = 0;
    is_playing = false;
    mode = sequencial;

	Label1->Caption = "No music playing now";
    updateTimeDisplay(0, Label2);
    updateTimeDisplay(0, Label4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Timer1->Enabled = false;

        if(OpenDialog1->Execute())
        {
                Timer1->Enabled = true;

                for(int i = 0; i < OpenDialog1->Files->Count; i++)
                {
                	std::vector<AnsiString>::iterator iter;
                    iter = std::find(song_name_list.begin(), song_name_list.end(), OpenDialog1->Files->Strings[i]);
                    if(iter == song_name_list.end())
                    {
                        song_name_list.push_back(OpenDialog1->Files->Strings[i]);
                        ListBox1->Items->Add(getSongName(OpenDialog1->Files->Strings[i]));
                        song_count++;
                    }
                	
                }

                for(int i = song_list_bottom_index; i < (song_count) + song_list_bottom_index; i++)
                {


                }
                song_list_bottom_index = song_name_list.size();

                ListBox1->ItemIndex = current_song_index;
                loadMusicAndPlay(song_name_list[current_song_index]);
                updateTimeDisplay(MediaPlayer1->Position, Label2);
                updateTimeDisplay(MediaPlayer1->Length, Label4);
        }
}
//---------------------------------------------------------------------------


AnsiString __fastcall TForm1::getSongName(AnsiString fileloc)
{
        int start = fileloc.LastDelimiter("\\");
        int end = fileloc.LastDelimiter(".");
        AnsiString song_name = fileloc.SubString(start+1, end-start-1);
        return song_name;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
     if (MediaPlayer1->Position != MediaPlayer1->Length)
     {
        ScrollBar1->Position = MediaPlayer1->Position;
     }
     else if(MediaPlayer1->Position >= MediaPlayer1->Length){
            dealWithBoard();
     }


     updateTimeDisplay(MediaPlayer1->Position, Label2);
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------


void __fastcall TForm1::ScrollBar1Scroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
      
      if (MediaPlayer1->FileName != "")
      {
         	MediaPlayer1->Pause();
            is_playing = false;
            Button2->Caption = "Play";

         	MediaPlayer1->Position = ScrollBar1->Position;
         	MediaPlayer1->Play();
            is_playing = true;
            Button2->Caption = "Pause";
      }
      else if (ScrollBar1->Position >= MediaPlayer1->Length)
      {
      		dealWithBoard();
      }
      else
      {
          	ScrollBar1->Enabled = false;
      }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ScrollBar1Enter(TObject *Sender)
{
     ScrollBar1->Position = 0;
     if (MediaPlayer1->FileName == "")
        ScrollBar1->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::loadMusicAndPlay(AnsiString fileloc)
{
	if (fileloc != "")
    {
         MediaPlayer1->FileName = fileloc;
         MediaPlayer1->Open();
         
         Label1->Caption = "Now playing: " + getSongName(MediaPlayer1->FileName);
    	 MediaPlayer1->Play();
         is_playing = true;

         ScrollBar1->Min = 0;
         ScrollBar1->Max = MediaPlayer1->Length;
         ScrollBar1->Position = 0;

    }
	
}

void __fastcall TForm1::ListBox1DblClick(TObject *Sender)
{
	current_song_index = ListBox1->ItemIndex;
    MediaPlayer1->Stop();
    is_playing = false;

    loadMusicAndPlay(song_name_list[current_song_index]);
    updateTimeDisplay(MediaPlayer1->Position, Label2);
    updateTimeDisplay(MediaPlayer1->Length, Label4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::updateTimeDisplay(int time, TLabel* label)
{
       int second = time / 1000;
       int minute = second / 60;
       int hour = minute / 60;

       label->Caption = AnsiString(hour) + ":" + AnsiString(minute % 60) + ":" + AnsiString(second % 60);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if(is_playing == true)
    {
    	MediaPlayer1->Pause();
        is_playing = false;
        Button2->Caption = "Play";
    }
    else
    {
    	if(MediaPlayer1->FileName != "")
        {
    		MediaPlayer1->Play();
        	is_playing = true;
            Button2->Caption = "Pause";
        }
    }
}
//---------------------------------------------------------------------------


//Prev song button click event call back function
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if(song_name_list.size())
    {
    	current_song_index--;
        if(current_song_index < 0)
        {
        	current_song_index = song_count-1;
            ListBox1->ItemIndex = current_song_index;
        }
        loadMusicAndPlay(song_name_list[current_song_index]);
        updateTimeDisplay(MediaPlayer1->Length, Label4);
        updateTimeDisplay(MediaPlayer1->Position, Label2);
    }
}
//---------------------------------------------------------------------------


//Next song button click event call back function
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    if(song_name_list.size())
    {
    	current_song_index++;
        if(current_song_index >= song_count)
        {
        	current_song_index = 0;
            ListBox1->ItemIndex = current_song_index;
        }
        loadMusicAndPlay(song_name_list[current_song_index]);
        updateTimeDisplay(MediaPlayer1->Length, Label4);
        updateTimeDisplay(MediaPlayer1->Position, Label2);
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
	mode = sequencial;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	mode = single;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	mode = random;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::dealWithBoard()
{
	if(mode == sequencial)
    {
       //	MediaPlayer1->Stop();
    	current_song_index++;
        ListBox1->ItemIndex = current_song_index;

    	if (current_song_index >= song_count)
    		current_song_index = 0;
        Label3->Caption = "0";
        loadMusicAndPlay(song_name_list[current_song_index]);
    	updateTimeDisplay(MediaPlayer1->Position, Label2);
    	updateTimeDisplay(MediaPlayer1->Length, Label4);
    }
    else if(mode == single)
    {
    	MediaPlayer1->Rewind();
        MediaPlayer1->Play();
    }
    else if(mode == random)
    {
    	srand(time(NULL));
    	int next_song_index = std::rand()%(song_name_list.size());
    	current_song_index = next_song_index;
        ListBox1->ItemIndex = current_song_index;
        
        loadMusicAndPlay(song_name_list[current_song_index]);
    	updateTimeDisplay(MediaPlayer1->Position, Label2);
    	updateTimeDisplay(MediaPlayer1->Length, Label4);
    }


}




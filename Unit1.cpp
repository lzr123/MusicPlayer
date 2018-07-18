//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//int song_count = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
	song_count = 0;
    song_list_bottom_index = 0;
    current_song_index = 0;

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
                song_count = song_count + OpenDialog1->Files->Count;

                for(int i = 0; i < OpenDialog1->Files->Count; i++)
                {
                	song_name_list.push_back(OpenDialog1->Files->Strings[i]);
                }

                for(int i = song_list_bottom_index; i < (OpenDialog1->Files->Count) + song_list_bottom_index; i++)
                {
                	ListBox1->Items->Add(AnsiString(i+1) + "  " + getSongName(song_name_list[i]));
                   
                }
                song_list_bottom_index = song_name_list.size();


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
     if (MediaPlayer1->Position != MediaPlayer1->EndPos)
     {
        ScrollBar1->Position = MediaPlayer1->Position;
     }

     if (MediaPlayer1->Position >= MediaPlayer1->Length)
     {
     	MediaPlayer1->Stop();
        current_song_index++;

        if (current_song_index >= song_count)
     		current_song_index = 0;

        loadMusicAndPlay(song_name_list[current_song_index]);
        updateTimeDisplay(MediaPlayer1->Position, Label2);
     	updateTimeDisplay(MediaPlayer1->Length, Label4);
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
         	MediaPlayer1->Position = ScrollBar1->Position;
         	MediaPlayer1->Play();
      }
      else if (ScrollBar1->Position >= MediaPlayer1->Length)
      {
            current_song_index++;
            if (current_song_index >= song_count)
            	current_song_index = 0;
            loadMusicAndPlay(song_name_list[current_song_index]);
            updateTimeDisplay(MediaPlayer1->Position, Label2);
            updateTimeDisplay(MediaPlayer1->Length, Label4);
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

         ScrollBar1->Min = 0;
         ScrollBar1->Max = MediaPlayer1->Length;
         ScrollBar1->Position = 0;

    }
	
}

void __fastcall TForm1::ListBox1DblClick(TObject *Sender)
{
	current_song_index = ListBox1->ItemIndex;
    MediaPlayer1->Stop();
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


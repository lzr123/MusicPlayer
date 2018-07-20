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

    apploc = Application->ExeName;
	int end = apploc.LastDelimiter("\\");
    apploc = apploc.SubString(0, end);
	song_count = 0;
    song_list_bottom_index = 0;
    current_song_index = 0;
    is_playing = false;
    erase_activate = false;
    mode = sequencial;

    mouse_key_down = false;
    mouse_x = 0;
    mouse_y = 0;

    scrollbar_min_value = 0;
    scrollbar_max_value = Image2->Width;
	scrollbar_min_pos = Image2->Left;
	scrollbar_max_pos = Image2->Left + Image2->Width;
    scrollbar_length = scrollbar_max_pos - scrollbar_min_pos;
    scrollbar_enabled = false;

    volu_trackbar_min_value = 0;
    volu_trackbar_max_value = 10;
    volu_trackbar_min_pos = Image3->Top - Image4->Height / 2;
    volu_trackbar_max_pos = Image3->Top + Image3->Height - Image4->Height / 2;
    volu_trackbar_length = volu_trackbar_max_pos - volu_trackbar_min_pos;

    Image1->Left = Image2->Left;
	Image1->Parent->DoubleBuffered = true;

	Label1->Caption = "No music playing now";
    SpeedButton4->Glyph->LoadFromFile(apploc + "icons\\delete_icon.bmp");
    SpeedButton6->Glyph->LoadFromFile(apploc + "icons\\seq_play_act_icon.bmp");
    updateTimeDisplay(0, Label2);
    updateTimeDisplay(0, Label4);

    getSystemVolume();
    Label6->Caption = AnsiString(current_volume);

    lyric_displayer_array = new TLabel* [7];
    lyric_displayer_array[0] = Label3;
    lyric_displayer_array[1] = Label7;
    lyric_displayer_array[2] = Label8;
    lyric_displayer_array[3] = Label9;
    lyric_displayer_array[4] = Label10;
    lyric_displayer_array[5] = Label11;
    lyric_displayer_array[6] = Label12;
}
//---------------------------------------------------------------------------
/*
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
*/
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
        //ScrollBar1->Position = MediaPlayer1->Position;
        changeCrusorPos(MediaPlayer1->Position);
        
     }
     else if(MediaPlayer1->Position >= MediaPlayer1->Length){
            dealWithBoard();
     }


     updateTimeDisplay(MediaPlayer1->Position, Label2);
}
//---------------------------------------------------------------------------


/*
void __fastcall TForm1::ScrollBar1Scroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
      
      if (MediaPlayer1->FileName != "")
      {
         	MediaPlayer1->Pause();
            is_playing = false;
            //Button2->Caption = "Play";
            SpeedButton1->Glyph->LoadFromFile("D:\\KM\\icons\\play_icon.bmp");

         	//MediaPlayer1->Position = ScrollBar1->Position;
         	MediaPlayer1->Play();
            is_playing = true;
            //Button2->Caption = "Pause";
            SpeedButton1->Glyph->LoadFromFile("D:\\KM\\icons\\play_icon.bmp");
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
*/
//---------------------------------------------------------------------------

/*
void __fastcall TForm1::ScrollBar1Enter(TObject *Sender)
{
     ScrollBar1->Position = 0;
     if (MediaPlayer1->FileName == "")
        ScrollBar1->Enabled = false;
}
*/
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

         //ScrollBar1->Min = 0;
         //ScrollBar1->Max = MediaPlayer1->Length;
         //ScrollBar1->Position = 0;

         scrollbar_min_value = 0;
         scrollbar_max_value = MediaPlayer1->Length;
         Image1->Left = Image2->Left;

         //Button2->Caption = "Pause";

         SpeedButton1->Glyph->LoadFromFile(apploc + "\\icons\\pause_icon.bmp");
    }
	
}

//move custom scrollbar's crusor positon
void __fastcall TForm1::changeCrusorPos(int pos)
{
	Image1->Left = Image2->Left + pos * (scrollbar_length/static_cast<double>(scrollbar_max_value));
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

/*
void __fastcall TForm1::Button2Click(TObject *Sender) //play button
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

*/
//---------------------------------------------------------------------------


//Prev song button click event call back function

/*
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
*/
//---------------------------------------------------------------------------


//Next song button click event call back function
/*
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    if(song_name_list.size())
    {
    	current_song_index++;
        if(current_song_index >= song_count)
        {
        	current_song_index = 0;

        }
        ListBox1->ItemIndex = current_song_index;
        loadMusicAndPlay(song_name_list[current_song_index]);
        updateTimeDisplay(MediaPlayer1->Length, Label4);
        updateTimeDisplay(MediaPlayer1->Position, Label2);
    }
}
*/
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

void __fastcall TForm1::Button7Click(TObject *Sender)  //random mode button
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



void __fastcall TForm1::Button8Click(TObject *Sender)
{
	erase_activate = !erase_activate;
    if(erase_activate)
    	Label5->Caption = "Click item to delate";
    else
    	Label5->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
	if(erase_activate)
    {
    	int pos = ListBox1->ItemIndex;
        song_name_list.erase(song_name_list.begin() + pos);
        ListBox1->DeleteSelected();
        song_count = song_name_list.size();

        if(song_name_list.size() != 0)
        {
        	if(current_song_index >= song_name_list.size())
            {
            	current_song_index = song_name_list.size()-1;
                loadMusicAndPlay(song_name_list[current_song_index]);
                updateTimeDisplay(MediaPlayer1->Position, Label2);
                updateTimeDisplay(MediaPlayer1->Length, Label4);
            }
            else
            {
            	loadMusicAndPlay(song_name_list[current_song_index]);
                updateTimeDisplay(MediaPlayer1->Position, Label2);
                updateTimeDisplay(MediaPlayer1->Length, Label4);
            }
        }
        else
        {
        	current_song_index = 0;
            MediaPlayer1->Stop();
            MediaPlayer1->FileName = "";
            updateTimeDisplay(0, Label2);
            updateTimeDisplay(0, Label4);
            Label1->Caption = "No music playing now";
        }
    }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	if(is_playing == true)
    {
    	MediaPlayer1->Pause();
        is_playing = false;
        SpeedButton1->Glyph->LoadFromFile(apploc + "icons\\play_icon.bmp");
    }
    else
    {
    	if(MediaPlayer1->FileName != "")
        {
    		MediaPlayer1->Play();
        	is_playing = true;
            SpeedButton1->Glyph->LoadFromFile(apploc + "icons\\pause_icon.bmp");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
	if(song_name_list.size())
    {
    	current_song_index--;
        if(current_song_index < 0)
        {
        	current_song_index = song_count-1;

        }
        ListBox1->ItemIndex = current_song_index;
        loadMusicAndPlay(song_name_list[current_song_index]);
        updateTimeDisplay(MediaPlayer1->Length, Label4);
        updateTimeDisplay(MediaPlayer1->Position, Label2);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	if(song_name_list.size())
    {
    	current_song_index++;
        if(current_song_index >= song_count)
        {
        	current_song_index = 0;

        }
        ListBox1->ItemIndex = current_song_index;
        loadMusicAndPlay(song_name_list[current_song_index]);
        updateTimeDisplay(MediaPlayer1->Length, Label4);
        updateTimeDisplay(MediaPlayer1->Position, Label2);
    }	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
    erase_activate = !erase_activate;
    if(erase_activate)
    {
    	Label5->Caption = "Click item to delate";
        SpeedButton4->Glyph->LoadFromFile(apploc + "icons\\delete_act_icon.bmp");
    }
    else
    {
    	Label5->Caption = "";
        SpeedButton4->Glyph->LoadFromFile(apploc + "icons\\delete_icon.bmp");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
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

void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
	mode = sequencial;
    SpeedButton6->Glyph->LoadFromFile(apploc + "icons\\seq_play_act_icon.bmp");
    SpeedButton7->Glyph->LoadFromFile(apploc + "icons\\single_play_icon.bmp");
    SpeedButton8->Glyph->LoadFromFile(apploc + "icons\\random_play_icon.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
 	mode = single;
    SpeedButton6->Glyph->LoadFromFile(apploc + "icons\\seq_play_icon.bmp");
    SpeedButton7->Glyph->LoadFromFile(apploc + "icons\\single_play_act_icon.bmp");
    SpeedButton8->Glyph->LoadFromFile(apploc + "icons\\random_play_icon.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{
	mode = random;
    SpeedButton6->Glyph->LoadFromFile(apploc + "icons\\seq_play_icon.bmp");
    SpeedButton7->Glyph->LoadFromFile(apploc + "icons\\single_play_icon.bmp");
    SpeedButton8->Glyph->LoadFromFile(apploc + "icons\\random_play_act_icon.bmp");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
	int desired_pos = Image1->Left + (X - mouse_x);
	if ((desired_pos >= scrollbar_min_pos) && (desired_pos < scrollbar_max_pos))
	{
		if((mouse_key_down == true) && (MediaPlayer1->FileName != ""))
        {
			Image1->Left = desired_pos;
            MediaPlayer1->Position = ((Image1->Left - Image2->Left) / static_cast<double>(scrollbar_length)) * MediaPlayer1->Length;
            MediaPlayer1->Play();
		}
	}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	mouse_key_down = true;
    mouse_x = X;
    mouse_y = Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
	mouse_key_down = false;
    mouse_x = X;
    mouse_y = Y;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::getSystemVolume()
{
	DWORD volume;
    waveOutGetVolume(0, &volume);
    //TrackBar1->Position = 0XFFFF - LOWORD(volume);
    current_volume = LOWORD(volume) * (volu_trackbar_max_value / 65535.0);
    setVolTrackbarPos(current_volume);
    
}
/*
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	int value = 0xffff - TrackBar1->Position;
    DWORD volume;
    waveOutSetVolume(0, TrackBar1->Position * (0xffff / 10.0));
    current_volume = TrackBar1->Position;
    Label6->Caption = AnsiString(current_volume);
    if(current_volume == 0)
    	SpeedButton9->Glyph->LoadFromFile(apploc + "icons\\mute_icon.bmp");
    else
        SpeedButton9->Glyph->LoadFromFile(apploc + "icons\\volu_icon.bmp");
}
*/
//---------------------------------------------------------------------------



void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{
	if(is_muted == false)
    {
    	is_muted = true;
    	waveOutSetVolume(0, 0x0);
        Label6->Caption = "0";
    	SpeedButton9->Glyph->LoadFromFile(apploc + "icons\\mute_icon.bmp");
        setVolTrackbarPos(0);
    }
    else
    {
    	waveOutSetVolume(0, current_volume * (0xffff / 10.0));
        //TrackBar1->Position = current_volume;
        setVolTrackbarPos(current_volume);
        is_muted = false;
        Label6->Caption = AnsiString(current_volume);
    	SpeedButton9->Glyph->LoadFromFile(apploc + "icons\\volu_icon.bmp");
    }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image4MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	mouse_key_down = true;
    mouse_x = X;
    mouse_y = Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
	mouse_key_down = false;
    mouse_x = X;
    mouse_y = Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
	int desired_pos = Image4->Top - (mouse_y - Y);
	if ((desired_pos >= volu_trackbar_min_pos) && (desired_pos < volu_trackbar_max_pos))
	{
		if(mouse_key_down == true)
        {
			Image4->Top = desired_pos;
            int volume =  (volu_trackbar_max_pos - Image4->Top) * (volu_trackbar_max_value / static_cast<double>(volu_trackbar_length));
            waveOutSetVolume(0, volume * (0xffff / static_cast<double>(volu_trackbar_max_value)));
            current_volume = volume;
            Label6->Caption = AnsiString(volume);
            if(volume == 0)
            	SpeedButton9->Glyph->LoadFromFile(apploc + "\\icons\\mute_icon.bmp");
            else
            	SpeedButton9->Glyph->LoadFromFile(apploc + "\\icons\\volu_icon.bmp");

		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setVolTrackbarPos(int vol)
{
	if((vol >= 0)&&(vol <= volu_trackbar_max_value))
    {
    	int desired_pos = volu_trackbar_max_pos -
        				vol * (volu_trackbar_length / static_cast<double>(volu_trackbar_max_value));
        Image4->Top = desired_pos;
    }
}



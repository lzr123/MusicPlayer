//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Timer1->Enabled = true;
        int song_count = 0;
        if(OpenDialog1->Execute())
        {
                song_count = OpenDialog1->Files->Count;
                
                for(int i = 0; i < OpenDialog1->Files->Count; i++)
                {
                        ListBox1->Items->Add(AnsiString(i) + " " + getSongName(OpenDialog1->Files->Strings[i]));
                }

                for(int i = 0; i < song_count;)
                {
                        MediaPlayer1->FileName = OpenDialog1->Files->Strings[i];
                        Label1->Caption = "Now playing: " + getSongName(MediaPlayer1->FileName);

                        MediaPlayer1->Open();
                        MediaPlayer1->Play();

                        ScrollBar1->Min = 0;
                        ScrollBar1->Max = MediaPlayer1->Length;
                        ScrollBar1->Position = 0;

                        if (MediaPlayer1->Position >= MediaPlayer1->Length)
                        {
                               MediaPlayer1->Stop();
                               i++;
                        }
                }
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
        Label2->Caption = MediaPlayer1->Left;
     }
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



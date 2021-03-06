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
        if(OpenDialog1->Execute())
        {
                MediaPlayer1->FileName = OpenDialog1->FileName;

                Label1->Caption = getSongName(MediaPlayer1->FileName);

                MediaPlayer1->Open();
                MediaPlayer1->Play();

                ProgressBar1->Min = 0;
                ProgressBar1->Max = MediaPlayer1->Length;
                Timer1->Enabled = true;
        }
}
//---------------------------------------------------------------------------


AnsiString __fastcall TForm1::getSongName(AnsiString fileloc)
{
        int start = fileloc.LastDelimiter("\\");
        int end = fileloc.LastDelimiter(".");
        AnsiString song_name = "Now playing: " + fileloc.SubString(start+1, end-start-1);
        return song_name;
}

void __fastcall TForm1::TrackBarInit()
{
     DWORD volume;
     TrackBar1->Position = waveOutGetVolume(0, &volume);
     TrackBar1->Position = 0xffff - LOWORD(volume);
}


void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
     DWORD volume;
     int value = 0xffff - TrackBar1->Position;
     waveOutSetVolume(0, MAKELONG(value, value));
     Label2->Caption = waveOutGetVolume(0, &volume);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
     ProgressBar1->Position = MediaPlayer1->Position;
}
//---------------------------------------------------------------------------


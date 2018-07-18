//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <MPlayer.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMediaPlayer *MediaPlayer1;
        TButton *Button1;
        TOpenDialog *OpenDialog1;
        TLabel *Label1;
        TTimer *Timer1;
        TLabel *Label2;
        TScrollBar *ScrollBar1;
        TListBox *ListBox1;
        TLabel *Label3;




        void __fastcall Button1Click(TObject *Sender);
        AnsiString __fastcall getSongName(AnsiString fileloc);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall ScrollBar1Scroll(TObject *Sender,
          TScrollCode ScrollCode, int &ScrollPos);
        void __fastcall ScrollBar1Enter(TObject *Sender);
        void __fastcall loadMusicAndPlay(AnsiString fileloc);
private:	// User declarations
public:		// User declarations

       int song_count;
       
       std::vector<AnsiString> song_name_list;

        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
static int current_song_index = 0;
#endif

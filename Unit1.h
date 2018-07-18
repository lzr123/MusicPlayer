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
#include <Buttons.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMediaPlayer *MediaPlayer1;
        TOpenDialog *OpenDialog1;
        TLabel *Label1;
        TTimer *Timer1;
        TLabel *Label2;
        TScrollBar *ScrollBar1;
        TListBox *ListBox1;
        TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TTimer *Timer2;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;




        //void __fastcall Button1Click(TObject *Sender);
        AnsiString __fastcall getSongName(AnsiString fileloc);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall ScrollBar1Scroll(TObject *Sender,
          TScrollCode ScrollCode, int &ScrollPos);
        void __fastcall ScrollBar1Enter(TObject *Sender);
        void __fastcall loadMusicAndPlay(AnsiString fileloc);
        void __fastcall updateTimeDisplay(int time, TLabel* label);
		void __fastcall ListBox1DblClick(TObject *Sender);
		//void __fastcall Button2Click(TObject *Sender);
		//void __fastcall Button3Click(TObject *Sender);
		//void __fastcall Button4Click(TObject *Sender);
		void __fastcall Button5Click(TObject *Sender);
		void __fastcall Button6Click(TObject *Sender);
		void __fastcall Button7Click(TObject *Sender);
    	void __fastcall dealWithBoard();
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

       int song_count;
       int song_list_bottom_index;
       int current_song_index;
       bool is_playing;
       int mode;
       bool erase_activate;
       enum mode_type{sequencial=0, single=1, random=2};

       std::vector<AnsiString> song_name_list;

        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

#endif

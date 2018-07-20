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
#include <Graphics.hpp>
#include <vector>
#include <string>
//---------------------------------------------------------------------------


class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMediaPlayer *MediaPlayer1;
        TOpenDialog *OpenDialog1;
        TLabel *Label1;
        TTimer *Timer1;
        TLabel *Label2;
        TLabel *Label3;
		TLabel *Label4;
		TTimer *Timer2;
		TSpeedButton *SpeedButton1;
		TSpeedButton *SpeedButton2;
		TSpeedButton *SpeedButton3;
		TSpeedButton *SpeedButton5;
		TSpeedButton *SpeedButton6;
		TSpeedButton *SpeedButton7;
		TSpeedButton *SpeedButton8;
		TLabel *Label5;
		TSpeedButton *SpeedButton4;
		TListBox *ListBox1;
		TImage *Image1;
		TImage *Image2;
	TLabel *Label6;
	TSpeedButton *SpeedButton9;
	TImage *Image3;
	TImage *Image4;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;




        //void __fastcall Button1Click(TObject *Sender);
        AnsiString __fastcall getSongName(AnsiString fileloc);
        void __fastcall Timer1Timer(TObject *Sender);
        //void __fastcall ScrollBar1Scroll(TObject *Sender,
        //  TScrollCode ScrollCode, int &ScrollPos);
        //void __fastcall ScrollBar1Enter(TObject *Sender);
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
		void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          	int Y);
		void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          	TShiftState Shift, int X, int Y);
		void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          	TShiftState Shift, int X, int Y);

        void __fastcall changeCrusorPos(int pos);
        void __fastcall getSystemVolume();
		//void __fastcall TrackBar1Change(TObject *Sender);
		void __fastcall SpeedButton9Click(TObject *Sender);
		void __fastcall Image4MouseDown(TObject *Sender, TMouseButton Button,
          	TShiftState Shift, int X, int Y);
		void __fastcall Image4MouseUp(TObject *Sender, TMouseButton Button,
          	TShiftState Shift, int X, int Y);
		void __fastcall Image4MouseMove(TObject *Sender, TShiftState Shift, int X,
          	int Y);

      	void __fastcall setVolTrackbarPos(int vol);

        void __fastcall loadLyric(std::string fileloc);

        void __fastcall showLyric();


	//void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

       int song_count;
       int song_list_bottom_index;
       int current_song_index;
       bool is_playing;
       int mode;
       bool erase_activate;
       enum mode_type{sequencial=0, single=1, random=2};

       int mouse_x, mouse_y;
       bool mouse_key_down;

	   int scrollbar_min_pos;
	   int scrollbar_max_pos;
       int scrollbar_max_value;
       int scrollbar_min_value;
       int scrollbar_length;
       bool scrollbar_enabled;

       int volu_trackbar_min_pos;
       int volu_trackbar_max_pos;
       int volu_trackbar_max_value;
       int volu_trackbar_min_value;
       int volu_trackbar_length;

       int lyric_focus;

       int current_volume;
       bool is_muted;

       int lyric_display_count;
       TLabel** lyric_displayer_array;

       AnsiString apploc;



       std::vector<AnsiString> song_name_list;
       std::vector<std::string> lyric_words;

        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

#endif

object Form1: TForm1
  Left = 199
  Top = 134
  Width = 870
  Height = 467
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 280
    Top = 16
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 544
    Top = 232
    Width = 41
    Height = 49
    Caption = 'Label2'
  end
  object MediaPlayer1: TMediaPlayer
    Left = 288
    Top = 200
    Width = 253
    Height = 30
    TabOrder = 0
  end
  object Button1: TButton
    Left = 288
    Top = 232
    Width = 75
    Height = 25
    Caption = 'Select'
    TabOrder = 1
    OnClick = Button1Click
  end
  object ProgressBar1: TProgressBar
    Left = 288
    Top = 184
    Width = 249
    Height = 17
    Min = 0
    Max = 100
    TabOrder = 2
  end
  object TrackBar1: TTrackBar
    Left = 392
    Top = 232
    Width = 150
    Height = 45
    Orientation = trHorizontal
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 3
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar1Change
  end
  object OpenDialog1: TOpenDialog
    Left = 288
    Top = 256
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 528
    Top = 120
  end
end

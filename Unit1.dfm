object Form1: TForm1
  Left = 244
  Top = 245
  Width = 814
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
    Width = 265
    Height = 17
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 544
    Top = 304
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 288
    Top = 40
    Width = 249
    Height = 265
    Caption = 'Label3'
  end
  object MediaPlayer1: TMediaPlayer
    Left = 288
    Top = 328
    Width = 253
    Height = 30
    TabOrder = 0
  end
  object Button1: TButton
    Left = 288
    Top = 360
    Width = 75
    Height = 25
    Caption = 'Select'
    TabOrder = 1
    OnClick = Button1Click
  end
  object ScrollBar1: TScrollBar
    Left = 288
    Top = 304
    Width = 249
    Height = 17
    PageSize = 0
    TabOrder = 2
    OnEnter = ScrollBar1Enter
    OnScroll = ScrollBar1Scroll
  end
  object ListBox1: TListBox
    Left = 8
    Top = 8
    Width = 249
    Height = 401
    ItemHeight = 13
    TabOrder = 3
  end
  object OpenDialog1: TOpenDialog
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofEnableSizing]
    Left = 288
    Top = 384
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 592
    Top = 72
  end
end

object Form1: TForm1
  Left = 206
  Top = 169
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
    Left = 320
    Top = 16
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 584
    Top = 304
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 328
    Top = 40
    Width = 32
    Height = 13
    Caption = 'Label3'
  end
  object Label4: TLabel
    Left = 288
    Top = 304
    Width = 41
    Height = 13
    Caption = 'Label4'
  end
  object MediaPlayer1: TMediaPlayer
    Left = 328
    Top = 328
    Width = 253
    Height = 30
    TabOrder = 0
  end
  object Button1: TButton
    Left = 496
    Top = 360
    Width = 89
    Height = 25
    Caption = 'Select'
    TabOrder = 1
    OnClick = Button1Click
  end
  object ScrollBar1: TScrollBar
    Left = 328
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
    OnDblClick = ListBox1DblClick
  end
  object Button2: TButton
    Left = 328
    Top = 360
    Width = 57
    Height = 25
    Caption = 'Play'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 384
    Top = 360
    Width = 57
    Height = 25
    Caption = 'Prev'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 440
    Top = 360
    Width = 57
    Height = 25
    Caption = 'Next'
    TabOrder = 6
    OnClick = Button4Click
  end
  object OpenDialog1: TOpenDialog
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofEnableSizing]
    Left = 328
    Top = 384
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 632
    Top = 72
  end
end

object Form1: TForm1
  Left = 340
  Top = 54
  Width = 910
  Height = 480
  AlphaBlend = True
  AlphaBlendValue = 220
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 288
    Top = 0
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 552
    Top = 288
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 296
    Top = 24
    Width = 249
    Height = 257
    Caption = 'Label3'
  end
  object Label4: TLabel
    Left = 256
    Top = 288
    Width = 41
    Height = 13
    Caption = 'Label4'
  end
  object MediaPlayer1: TMediaPlayer
    Left = 296
    Top = 312
    Width = 253
    Height = 30
    Visible = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 464
    Top = 312
    Width = 89
    Height = 25
    Caption = 'Select'
    TabOrder = 1
    OnClick = Button1Click
  end
  object ScrollBar1: TScrollBar
    Left = 296
    Top = 288
    Width = 249
    Height = 17
    PageSize = 0
    TabOrder = 2
    OnEnter = ScrollBar1Enter
    OnScroll = ScrollBar1Scroll
  end
  object ListBox1: TListBox
    Left = 0
    Top = 24
    Width = 249
    Height = 377
    ItemHeight = 13
    TabOrder = 3
    OnClick = ListBox1Click
    OnDblClick = ListBox1DblClick
  end
  object Button2: TButton
    Left = 296
    Top = 312
    Width = 57
    Height = 25
    Caption = 'Pause'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 352
    Top = 312
    Width = 57
    Height = 25
    Caption = 'Prev'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 408
    Top = 312
    Width = 57
    Height = 25
    Caption = 'Next'
    TabOrder = 6
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 552
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Seq'
    TabOrder = 7
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 552
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Single'
    TabOrder = 8
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 552
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Random'
    TabOrder = 9
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 176
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Delete'
    TabOrder = 10
    OnClick = Button8Click
  end
  object OpenDialog1: TOpenDialog
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofEnableSizing]
    Left = 304
    Top = 384
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 696
    Top = 32
  end
end

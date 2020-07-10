object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1060#1086#1088#1084#1086#1095#1082#1072
  ClientHeight = 486
  ClientWidth = 847
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnMouseDown = FormMouseDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 592
    Top = 184
    Width = 116
    Height = 25
    Caption = #1057#1082#1086#1088#1086#1089#1090#1100' '#1093'1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 592
    Top = 40
    Width = 24
    Height = 25
    Caption = '---'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 592
    Top = 104
    Width = 24
    Height = 25
    Caption = '---'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 592
    Top = 336
    Width = 60
    Height = 25
    Caption = 'Label4'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label5: TLabel
    Left = 592
    Top = 383
    Width = 60
    Height = 25
    Caption = 'Label4'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Speed: TScrollBar
    Left = 592
    Top = 224
    Width = 217
    Height = 17
    Max = 20
    Min = 1
    PageSize = 0
    Position = 1
    TabOrder = 0
    OnChange = SpeedChange
  end
  object Button1: TButton
    Left = 592
    Top = 432
    Width = 105
    Height = 41
    Caption = #1059#1089#1080#1083#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Visible = False
    OnClick = Button1Click
  end
  object MainMenu1: TMainMenu
    Left = 608
    Top = 264
    object Start1: TMenuItem
      Caption = #1057#1090#1072#1088#1090
      OnClick = Start1Click
    end
    object Stop1: TMenuItem
      Caption = #1057#1090#1086#1087
      OnClick = Stop1Click
    end
    object Restart1: TMenuItem
      Caption = #1055#1077#1088#1077#1079#1072#1087#1091#1089#1090#1080#1090#1100
      OnClick = Restart1Click
    end
    object Settings1: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      OnClick = Settings1Click
    end
    object N1: TMenuItem
      Caption = #1048#1085#1092#1086
      OnClick = N1Click
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 656
    Top = 256
  end
end

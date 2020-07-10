object Form2: TForm2
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1053#1072#1089#1090#1088#1086#1077#1095#1082#1080
  ClientHeight = 265
  ClientWidth = 517
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 200
    Top = 24
    Width = 112
    Height = 25
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 16
    Width = 169
    Height = 169
    Caption = #1056#1072#1079#1084#1077#1088' '#1087#1086#1083#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 1
    Items.Strings = (
      '25'#1093'25'
      '50'#1093'50')
    ParentFont = False
    TabOrder = 0
    OnClick = RadioGroup1Click
  end
  object ScrollBar1: TScrollBar
    Left = 200
    Top = 80
    Width = 297
    Height = 17
    Min = 5
    PageSize = 0
    Position = 5
    TabOrder = 1
    OnChange = ScrollBar1Change
  end
  object BitBtn1: TBitBtn
    Left = 378
    Top = 216
    Width = 131
    Height = 41
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    Kind = bkCancel
    NumGlyphs = 2
    ParentFont = False
    TabOrder = 2
  end
  object BitBtn2: TBitBtn
    Left = 241
    Top = 216
    Width = 131
    Height = 41
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    Kind = bkOK
    NumGlyphs = 2
    ParentFont = False
    TabOrder = 3
  end
  object Auto1: TCheckBox
    Left = 200
    Top = 128
    Width = 112
    Height = 25
    Caption = #1040#1074#1090#1086#1080#1075#1088#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
end

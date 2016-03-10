object MainForm: TMainForm
  Left = 411
  Top = 225
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'MainForm'
  ClientHeight = 483
  ClientWidth = 1005
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 23
  object LPeriod_ms: TLabel
    Left = 20
    Top = 332
    Width = 71
    Height = 20
    Caption = #1055#1077#1088#1080#1086#1076'_'#1084#1089
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
  end
  object MLog: TMemo
    Left = 598
    Top = 327
    Width = 403
    Height = 122
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 460
    Width = 1005
    Height = 23
    Panels = <>
    SimplePanel = True
  end
  object BIDENTIFY: TButton
    Left = 472
    Top = 358
    Width = 120
    Height = 25
    Caption = 'IDENTIFY'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = BIDENTIFYClick
  end
  object BStop1: TButton
    Left = 346
    Top = 358
    Width = 120
    Height = 25
    Caption = 'STOP'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = BStop1Click
  end
  object BStart1: TButton
    Left = 346
    Top = 327
    Width = 120
    Height = 25
    Caption = 'START'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = BStart1Click
  end
  object BGetALL: TButton
    Left = 472
    Top = 327
    Width = 120
    Height = 25
    Caption = 'GetALL'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = BGetALLClick
  end
  object GBMain: TGroupBox
    Left = 8
    Top = 358
    Width = 322
    Height = 98
    Caption = 'COM-'#1087#1086#1088#1090
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    object LPortNum: TLabel
      Left = 82
      Top = 29
      Width = 120
      Height = 20
      Caption = #1042#1099#1073#1086#1088' COM '#1087#1086#1088#1090#1072':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object LBaudrate: TLabel
      Left = 81
      Top = 55
      Width = 126
      Height = 20
      Caption = #1057#1082#1086#1088#1086#1089#1090#1100' '#1087#1077#1088#1077#1076#1072#1095#1080':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentFont = False
    end
    object BStart: TButton
      Left = 15
      Top = 25
      Width = 50
      Height = 25
      Caption = #1055#1091#1089#1082
      DoubleBuffered = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 0
      OnClick = BStartClick
    end
    object BStop: TButton
      Left = 15
      Top = 56
      Width = 50
      Height = 25
      Caption = #1057#1090#1086#1087
      DoubleBuffered = False
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 1
      OnClick = BStopClick
    end
    object CBCOMNum: TComboBox
      Left = 213
      Top = 29
      Width = 100
      Height = 22
      Style = csOwnerDrawFixed
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ItemIndex = 9
      ParentFont = False
      TabOrder = 2
      Text = 'COM10'
      Items.Strings = (
        'COM1'
        'COM2'
        'COM3'
        'COM4'
        'COM5'
        'COM6'
        'COM7'
        'COM8'
        'COM9'
        'COM10'
        'COM11'
        'COM12'
        'COM13'
        'COM14'
        'COM15'
        'COM16'
        'COM17'
        'COM18'
        'COM19'
        'COM20')
    end
    object CBCOMSpeed: TComboBox
      Left = 213
      Top = 60
      Width = 100
      Height = 22
      Style = csOwnerDrawFixed
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial Narrow'
      Font.Style = []
      ItemIndex = 11
      ParentFont = False
      TabOrder = 3
      Text = '57600'
      Items.Strings = (
        '110'
        '300'
        '600'
        '1200'
        '2400'
        '4800'
        '9600'
        '14400'
        '19200'
        '38400'
        '56000'
        '57600'
        '115200')
    end
  end
  object BESTOP: TButton
    Left = 346
    Top = 389
    Width = 120
    Height = 25
    Caption = 'ESTOP'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = BESTOPClick
  end
  object EPeriod_ms: TEdit
    Left = 106
    Top = 327
    Width = 50
    Height = 28
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = []
    NumbersOnly = True
    ParentFont = False
    TabOrder = 8
    Text = '1000'
    OnChange = EPeriod_msChange
  end
  object UDPeriod_ms: TUpDown
    Left = 156
    Top = 327
    Width = 16
    Height = 28
    Associate = EPeriod_ms
    Max = 9999
    Position = 1000
    TabOrder = 9
    Thousands = False
  end
  object BSAVE: TButton
    Left = 472
    Top = 389
    Width = 120
    Height = 25
    Caption = 'SAVE'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = BSAVEClick
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 997
    Height = 313
    ActivePage = Графики
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    object Параметры: TTabSheet
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
      object GBParameters: TGroupBox
        Left = -4
        Top = -21
        Width = 993
        Height = 313
        Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
        Color = clBtnFace
        Ctl3D = True
        DoubleBuffered = False
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = []
        ParentBackground = False
        ParentColor = False
        ParentCtl3D = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 0
        object LSpeedRef_krpm: TLabel
          Left = 219
          Top = 32
          Width = 91
          Height = 20
          Caption = 'SpeedRef_rpm'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LFlag_enableSys: TLabel
          Left = 12
          Top = 32
          Width = 97
          Height = 20
          Caption = 'Flag_enableSys'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LMaxAccel_krpmps: TLabel
          Left = 219
          Top = 66
          Width = 104
          Height = 20
          Caption = 'MaxAccel_rpmps'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LSpeed_krpm: TLabel
          Left = 219
          Top = 100
          Width = 71
          Height = 20
          Caption = 'Speed_rpm'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LFlagMotorIdentified: TLabel
          Left = 12
          Top = 100
          Width = 121
          Height = 20
          Caption = 'Flag_MotorIdentified'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LUserErrorCode: TLabel
          Left = 219
          Top = 134
          Width = 90
          Height = 20
          Caption = 'UserErrorCode'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LKp_Idq: TLabel
          Left = 444
          Top = 236
          Width = 43
          Height = 20
          Caption = 'Kp_Idq'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LKi_Idq: TLabel
          Left = 444
          Top = 270
          Width = 38
          Height = 20
          Caption = 'Ki_Idq'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LCtrlState: TLabel
          Left = 219
          Top = 199
          Width = 49
          Height = 20
          Caption = 'CtrlState'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LEstState: TLabel
          Left = 219
          Top = 236
          Width = 49
          Height = 20
          Caption = 'EstState'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LVelCtlStatus: TLabel
          Left = 219
          Top = 270
          Width = 71
          Height = 20
          Caption = 'VelCtlStatus'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LFlag_Run_Identify: TLabel
          Left = 12
          Top = 66
          Width = 105
          Height = 20
          Caption = 'Flag_Run_Identify'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LRs_Ohm: TLabel
          Left = 444
          Top = 32
          Width = 51
          Height = 20
          Caption = 'Rs_Ohm'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LMagnCurr_A: TLabel
          Left = 444
          Top = 66
          Width = 73
          Height = 20
          Caption = 'MagnCurr_A'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LLsd_H: TLabel
          Left = 444
          Top = 100
          Width = 38
          Height = 20
          Caption = 'Lsd_H'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object L: TLabel
          Left = 444
          Top = 134
          Width = 38
          Height = 20
          Caption = 'Lsq_H'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LFlux_VpHz: TLabel
          Left = 444
          Top = 166
          Width = 65
          Height = 20
          Caption = 'Flux_VpHz'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LTorque_Nm: TLabel
          Left = 444
          Top = 199
          Width = 80
          Height = 20
          Caption = 'Torque_mNm'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LEST_ErrorCode: TLabel
          Left = 219
          Top = 166
          Width = 94
          Height = 20
          Caption = 'EST_ErrorCode'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LFlag_enableFieldWeakening: TLabel
          Left = 12
          Top = 270
          Width = 112
          Height = 20
          Caption = 'Flag_enFieldWeak'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LFlag_enableRsRecalc: TLabel
          Left = 12
          Top = 166
          Width = 105
          Height = 20
          Caption = 'Flag_enRsRecalc'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object Label3: TLabel
          Left = 12
          Top = 199
          Width = 118
          Height = 20
          Caption = 'Flag_enForceAngle'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LFlag_enableOffsetcalc: TLabel
          Left = 12
          Top = 236
          Width = 106
          Height = 20
          Caption = 'Flag_enOffsetcalc'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LFlag_enableUserParams: TLabel
          Left = 12
          Top = 134
          Width = 121
          Height = 20
          Caption = 'Flag_enUserParams'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LDUTY1: TLabel
          Left = 598
          Top = 199
          Width = 69
          Height = 20
          Caption = 'cur_pos_sc'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LPOSITION: TLabel
          Left = 598
          Top = 166
          Width = 48
          Height = 20
          Caption = 'cur_pos'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LRunPositionProfile: TLabel
          Left = 598
          Top = 32
          Width = 109
          Height = 20
          Caption = 'RunPositionProfile'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LPosStepInt_MRev: TLabel
          Left = 598
          Top = 65
          Width = 107
          Height = 20
          Caption = 'PosStepInt_MRev'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LPosStepFrac_MRev: TLabel
          Left = 598
          Top = 91
          Width = 89
          Height = 40
          Caption = 'PosStepFrac_ MRev*100'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
          WordWrap = True
        end
        object LMaxVel_krpm: TLabel
          Left = 598
          Top = 137
          Width = 75
          Height = 20
          Caption = 'MaxVel_rpm'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object Ldest_pos: TLabel
          Left = 597
          Top = 236
          Width = 56
          Height = 20
          Caption = 'dest_pos'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LPosCtlStatus: TLabel
          Left = 798
          Top = 166
          Width = 75
          Height = 20
          Caption = 'PosCtlStatus'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LPosMoveStatus: TLabel
          Left = 798
          Top = 199
          Width = 94
          Height = 20
          Caption = 'PosMoveStatus'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LPosMoveCurveType: TLabel
          Left = 798
          Top = 134
          Width = 123
          Height = 20
          Caption = 'PosMoveCurveType'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LPosMoveDone: TLabel
          Left = 798
          Top = 100
          Width = 90
          Height = 20
          Caption = 'PosMoveDone'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LPosCtlErrorID: TLabel
          Left = 798
          Top = 65
          Width = 80
          Height = 20
          Caption = 'PosCtlErrorID'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LPosMoveErrorID: TLabel
          Left = 798
          Top = 32
          Width = 99
          Height = 20
          Caption = 'PosMoveErrorID'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object LPositionError_MRev: TLabel
          Left = 798
          Top = 236
          Width = 119
          Height = 20
          Caption = 'PositionError_MRev'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
        end
        object UDSpeedRef_krpm: TUpDown
          Left = 398
          Top = 29
          Width = 16
          Height = 28
          Associate = ESpeedRef_krpm
          Min = -9999
          Max = 9999
          Position = 100
          TabOrder = 0
          Thousands = False
        end
        object UDFlag_enableSys: TUpDown
          Left = 191
          Top = 29
          Width = 16
          Height = 28
          Associate = EFlag_enableSys
          Max = 1
          TabOrder = 1
          Thousands = False
        end
        object UDMaxAccel_krpmps: TUpDown
          Left = 398
          Top = 63
          Width = 16
          Height = 28
          Associate = EMaxAccel_krpmps
          Max = 9999
          Position = 100
          TabOrder = 2
          Thousands = False
        end
        object ESpeed_krpm: TEdit
          Left = 348
          Top = 97
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 3
          Text = '0'
        end
        object UDFlag_MotorIdentified: TUpDown
          Left = 191
          Top = 97
          Width = 16
          Height = 28
          Associate = EFlag_MotorIdentified
          Max = 1
          TabOrder = 4
          Thousands = False
        end
        object EUserErrorCode: TEdit
          Left = 348
          Top = 131
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 5
          Text = '0'
        end
        object EKp_Idq: TEdit
          Left = 533
          Top = 233
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 6
          Text = '0'
        end
        object EKi_Idq: TEdit
          Left = 533
          Top = 267
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 7
          Text = '0'
        end
        object ECtrlState: TEdit
          Left = 348
          Top = 200
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 8
          Text = '0'
        end
        object EEstState: TEdit
          Left = 348
          Top = 234
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 9
          Text = '0'
        end
        object EVelCtlStatus: TEdit
          Left = 348
          Top = 268
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 10
          Text = '0'
        end
        object UDFlag_Run_Identify: TUpDown
          Left = 191
          Top = 63
          Width = 16
          Height = 28
          Associate = EFlag_Run_Identify
          Max = 1
          TabOrder = 11
          Thousands = False
        end
        object ERs_Ohm: TEdit
          Left = 533
          Top = 29
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 12
          Text = '0'
        end
        object EMagnCurr_A: TEdit
          Left = 533
          Top = 63
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 13
          Text = '0'
        end
        object ELsd_H: TEdit
          Left = 533
          Top = 97
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 14
          Text = '0'
        end
        object ELsq_H: TEdit
          Left = 533
          Top = 131
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 15
          Text = '0'
        end
        object EFlux_VpHz: TEdit
          Left = 533
          Top = 165
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 16
          Text = '0'
        end
        object ETorque_Nm: TEdit
          Left = 533
          Top = 200
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 17
          Text = '0'
        end
        object EEST_ErrorCode: TEdit
          Left = 348
          Top = 165
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 18
          Text = '0'
        end
        object UDFlag_enableFieldWeakening: TUpDown
          Left = 191
          Top = 268
          Width = 16
          Height = 28
          Associate = EFlag_enableFieldWeakening
          Max = 1
          TabOrder = 19
          Thousands = False
        end
        object UDFlag_enableRsRecalc: TUpDown
          Left = 191
          Top = 165
          Width = 16
          Height = 28
          Associate = EFlag_enableRsRecalc
          Max = 1
          TabOrder = 20
          Thousands = False
        end
        object UDFlag_enableForceAngle: TUpDown
          Left = 191
          Top = 200
          Width = 16
          Height = 28
          Associate = EFlag_enableForceAngle
          Max = 1
          TabOrder = 21
          Thousands = False
        end
        object UDFlag_enableOffsetcalc: TUpDown
          Left = 191
          Top = 234
          Width = 16
          Height = 28
          Associate = EFlag_enableOffsetcalc
          Max = 1
          TabOrder = 22
          Thousands = False
        end
        object UDFlag_enableUserParams: TUpDown
          Left = 191
          Top = 131
          Width = 16
          Height = 28
          Associate = EFlag_enableUserParams
          Max = 1
          TabOrder = 23
          Thousands = False
        end
        object EMaxAccel_krpmps: TEdit
          Left = 348
          Top = 63
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 24
          Text = '100'
          OnChange = EMaxAccel_krpmpsChange
        end
        object ESpeedRef_krpm: TEdit
          Left = 348
          Top = 29
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
          TabOrder = 25
          Text = '100'
          OnChange = ESpeedRef_krpmChange
        end
        object EFlag_enableSys: TEdit
          Left = 141
          Top = 29
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 26
          Text = '0'
          OnChange = EFlag_enableSysChange
        end
        object EFlag_Run_Identify: TEdit
          Left = 141
          Top = 63
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 27
          Text = '0'
          OnChange = EFlag_Run_IdentifyChange
        end
        object EFlag_MotorIdentified: TEdit
          Left = 141
          Top = 97
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 28
          Text = '0'
          OnChange = EFlag_MotorIdentifiedChange
        end
        object EFlag_enableUserParams: TEdit
          Left = 141
          Top = 131
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 29
          Text = '0'
          OnChange = EFlag_enableUserParamsChange
        end
        object EFlag_enableRsRecalc: TEdit
          Left = 141
          Top = 165
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 30
          Text = '0'
          OnChange = EFlag_enableRsRecalcChange
        end
        object EFlag_enableForceAngle: TEdit
          Left = 141
          Top = 200
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 31
          Text = '0'
          OnChange = EFlag_enableForceAngleChange
        end
        object EFlag_enableOffsetcalc: TEdit
          Left = 141
          Top = 234
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 32
          Text = '0'
          OnChange = EFlag_enableOffsetcalcChange
        end
        object EFlag_enableFieldWeakening: TEdit
          Left = 141
          Top = 268
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 33
          Text = '0'
          OnChange = EFlag_enableFieldWeakeningChange
        end
        object EDUTY1: TEdit
          Left = 713
          Top = 200
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 34
          Text = '0'
        end
        object EPOSITION: TEdit
          Left = 713
          Top = 165
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 35
          Text = '0'
        end
        object ERunPositionProfile: TEdit
          Left = 713
          Top = 29
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 36
          Text = '0'
          OnChange = ERunPositionProfileChange
        end
        object UDRunPositionProfile: TUpDown
          Left = 763
          Top = 29
          Width = 16
          Height = 28
          Associate = ERunPositionProfile
          Max = 1
          TabOrder = 37
          Thousands = False
        end
        object UDPosStepInt_MRev: TUpDown
          Left = 763
          Top = 63
          Width = 16
          Height = 28
          Associate = EPosStepInt_MRev
          Max = 9999
          Position = 100
          TabOrder = 38
          Thousands = False
        end
        object EPosStepFrac_MRev: TEdit
          Left = 713
          Top = 97
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
          TabOrder = 39
          Text = '0'
          OnChange = EPosStepFrac_MRevChange
        end
        object UDPosStepFrac_MRev: TUpDown
          Left = 763
          Top = 97
          Width = 16
          Height = 28
          Associate = EPosStepFrac_MRev
          Min = -9999
          Max = 9999
          TabOrder = 40
          Thousands = False
        end
        object UDMaxVel_krpm: TUpDown
          Left = 763
          Top = 130
          Width = 16
          Height = 28
          Associate = EMaxVel_krpm
          Min = -9999
          Max = 9999
          Position = 2000
          TabOrder = 41
          Thousands = False
        end
        object EMaxVel_krpm: TEdit
          Left = 713
          Top = 130
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
          TabOrder = 42
          Text = '2000'
          OnChange = EMaxVel_krpmChange
        end
        object EPosStepInt_MRev: TEdit
          Left = 713
          Top = 63
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
          TabOrder = 43
          Text = '100'
          OnChange = EPosStepInt_MRevChange
        end
        object Edest_pos: TEdit
          Left = 713
          Top = 234
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ParentFont = False
          TabOrder = 44
          Text = '0'
          OnChange = Edest_posChange
        end
        object UDdest_pos: TUpDown
          Left = 763
          Top = 234
          Width = 16
          Height = 28
          Associate = Edest_pos
          Max = 65535
          TabOrder = 45
          Thousands = False
        end
        object EPosCtlStatus: TEdit
          Left = 927
          Top = 165
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 46
          Text = '0'
        end
        object EPosMoveStatus: TEdit
          Left = 927
          Top = 200
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 47
          Text = '0'
        end
        object EPosMoveCurveType: TEdit
          Left = 927
          Top = 131
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 48
          Text = '0'
        end
        object EPosMoveDone: TEdit
          Left = 926
          Top = 97
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 49
          Text = '0'
        end
        object EPosCtlErrorID: TEdit
          Left = 926
          Top = 63
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 50
          Text = '0'
        end
        object EPosMoveErrorID: TEdit
          Left = 926
          Top = 29
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 51
          Text = '0'
        end
        object EPositionError_MRev: TEdit
          Left = 927
          Top = 233
          Width = 50
          Height = 28
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial Narrow'
          Font.Style = []
          NumbersOnly = True
          ParentFont = False
          TabOrder = 52
          Text = '0'
        end
      end
    end
    object Графики: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082#1080
      ImageIndex = 1
      DesignSize = (
        989
        278)
      object i1: TImage
        Left = 518
        Top = 36
        Width = 5
        Height = 28
      end
      object i2: TImage
        Left = 518
        Top = 70
        Width = 5
        Height = 28
      end
      object Label1: TLabel
        Left = 523
        Top = 254
        Width = 71
        Height = 20
        Caption = #1055#1077#1088#1080#1086#1076'_'#1084#1089
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        ParentFont = False
      end
      object i3: TImage
        Left = 518
        Top = 104
        Width = 5
        Height = 28
      end
      object Label2: TLabel
        Left = 656
        Top = 10
        Width = 34
        Height = 20
        Caption = 'Value'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 712
        Top = 10
        Width = 21
        Height = 20
        Caption = 'Min'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 768
        Top = 10
        Width = 25
        Height = 20
        Caption = 'Max'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        ParentFont = False
      end
      object Chart: TChart
        Left = 3
        Top = 3
        Width = 502
        Height = 272
        AllowPanning = pmNone
        Border.Visible = True
        Legend.CheckBoxes = True
        Legend.ColorWidth = 10
        Legend.Symbol.Width = 10
        Legend.TextStyle = ltsPlain
        Legend.Visible = False
        SubTitle.Visible = False
        Title.Text.Strings = (
          'TChart')
        Title.Visible = False
        BottomAxis.MinimumOffset = 1
        BottomAxis.Title.Caption = 'ticks'
        DepthAxis.Automatic = False
        DepthAxis.AutomaticMaximum = False
        DepthAxis.AutomaticMinimum = False
        DepthAxis.Maximum = 0.500000000000000000
        DepthAxis.Minimum = -0.500000000000000000
        DepthTopAxis.Automatic = False
        DepthTopAxis.AutomaticMaximum = False
        DepthTopAxis.AutomaticMinimum = False
        DepthTopAxis.Maximum = 0.500000000000000000
        DepthTopAxis.Minimum = -0.500000000000000000
        LeftAxis.MinimumOffset = 1
        RightAxis.Automatic = False
        RightAxis.AutomaticMaximum = False
        RightAxis.Visible = False
        TopAxis.Automatic = False
        TopAxis.AutomaticMaximum = False
        TopAxis.AutomaticMinimum = False
        TopAxis.Visible = False
        View3D = False
        View3DOptions.Perspective = 0
        View3DWalls = False
        Zoom.Animated = True
        Zoom.AnimatedSteps = 16
        Zoom.Pen.Color = clSilver
        BevelOuter = bvNone
        Color = clWindow
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        Anchors = [akLeft, akTop, akRight, akBottom]
        PrintMargins = (
          15
          28
          15
          28)
        ColorPaletteIndex = 13
      end
      object cb1: TComboBox
        Left = 529
        Top = 36
        Width = 117
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        ItemIndex = 1
        ParentFont = False
        TabOrder = 1
        Text = 'SpeedRef_rpm'
        Items.Strings = (
          'None'
          'SpeedRef_rpm'
          'Speed_rpm'
          'MaxAccel_krpmps')
      end
      object BChartClear: TButton
        Left = 698
        Top = 250
        Width = 120
        Height = 25
        Caption = 'Clear'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = BChartClearClick
      end
      object cbEnableChart: TCheckBox
        Left = 517
        Top = 13
        Width = 97
        Height = 17
        Caption = 'Enable chart'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object cb2: TComboBox
        Left = 529
        Top = 70
        Width = 117
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        ItemIndex = 2
        ParentFont = False
        TabOrder = 4
        Text = 'Speed_rpm'
        Items.Strings = (
          'None'
          'SpeedRef_rpm'
          'Speed_rpm'
          'MaxAccel_krpmps')
      end
      object EPeriod2_ms: TEdit
        Left = 600
        Top = 247
        Width = 50
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 5
        Text = '1000'
        OnChange = EPeriod2_msChange
      end
      object UDPeriod2_ms: TUpDown
        Left = 650
        Top = 247
        Width = 16
        Height = 28
        Associate = EPeriod2_ms
        Min = 10
        Max = 10000
        Position = 1000
        TabOrder = 6
        Thousands = False
      end
      object cb3: TComboBox
        Left = 529
        Top = 104
        Width = 117
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        ItemIndex = 3
        ParentFont = False
        TabOrder = 7
        Text = 'MaxAccel_krpmps'
        Items.Strings = (
          'None'
          'SpeedRef_rpm'
          'Speed_rpm'
          'MaxAccel_krpmps')
      end
      object ed00: TEdit
        Left = 656
        Top = 36
        Width = 50
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 8
        Text = '0'
      end
      object ed01: TEdit
        Left = 712
        Top = 36
        Width = 50
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 9
        Text = '0'
      end
      object ed02: TEdit
        Left = 768
        Top = 36
        Width = 50
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 10
        Text = '0'
      end
      object ed10: TEdit
        Left = 656
        Top = 70
        Width = 50
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 11
        Text = '0'
      end
      object ed11: TEdit
        Left = 712
        Top = 70
        Width = 50
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 12
        Text = '0'
      end
      object ed12: TEdit
        Left = 768
        Top = 70
        Width = 50
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 13
        Text = '0'
      end
      object ed20: TEdit
        Left = 656
        Top = 104
        Width = 50
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 14
        Text = '0'
      end
      object ed21: TEdit
        Left = 712
        Top = 104
        Width = 50
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 15
        Text = '0'
      end
      object ed22: TEdit
        Left = 768
        Top = 104
        Width = 50
        Height = 28
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial Narrow'
        Font.Style = []
        NumbersOnly = True
        ParentFont = False
        TabOrder = 16
        Text = '0'
      end
    end
  end
  object Timer: TTimer
    Interval = 1
    OnTimer = TimerTimer
    Left = 40
    Top = 248
  end
  object Timer2: TTimer
    OnTimer = Timer2Timer
    Left = 80
    Top = 248
  end
end

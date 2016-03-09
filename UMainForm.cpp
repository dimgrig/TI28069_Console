//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMainForm.h"
#include "UConstants.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "Series"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma resource "*.dfm"
TMainForm *MainForm;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	MainForm->Caption = PROGRAM_NAME + " v" + VERSION;
    ExtendedMode = false;
	CS_Timer;
	this->CBCOMNum->ItemIndex = 3;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BStartClick(TObject *Sender)
{
  int speed;
  switch(StrToInt(this->CBCOMSpeed->Text))
  {
      case(0):
      speed = 110;
      break;
      case(1):
      speed = 300;
      break;
      case(2):
      speed = 600;
      break;
      case(3):
      speed = 1200;
      break;
      case(4):
      speed = 2400;
      break;
      case(5):
      speed = 800;
      break;
      case(6):
      speed = 9600;
      break;
      case(7):
      speed = 14400;
      break;
      case(8):
      speed = 19200;
      break;
      case(9):
      speed = 38400;
      break;
      case(10):
      speed = 56000;
      break;
      case(11):
      speed = 57600;
      break;
      case(12):
      speed = 115200;
      break;
      default:
      speed = 57600;
      break;
  }
	bool ret = this->aPeriphery.TurnOn(this->CBCOMNum->ItemIndex + 1,speed);

  if(!ret)
  {
	  Application->MessageBoxW(L"Не удалось запустить консоль",
			L"Ошибка запуска консоли", MB_OK|MB_ICONEXCLAMATION);
	  this->AddToLogMemo("Не удалось запустить консоль");
      return;
  }

  this->AddToLogMemo("Консоль запущена");

  this->BGetALL->Click();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BStopClick(TObject *Sender)
{
  this->aPeriphery.TurnOff();
  this->AddToLogMemo("Консоль остановлена");
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::TimerTimer(TObject *Sender)
{
  if(this->aPeriphery.IsRunning())
  {
	this->aPeriphery.Run();
  }
  this->UpdateComponents();
}

void __fastcall TMainForm::UpdateComponents()
{

//отрисовываем состояние главных компонентов формы в зависимости от
//того, работает консоль или нет

    if(this->aPeriphery.IsRunning() == true)
    {
	  this->BStart->Enabled = false;
	  this->BStop->Enabled = true;
	  this->StatusBar->SimpleText = "Состояние консоли: работает...";
	  this->CBCOMNum->Enabled = false;
	  this->CBCOMSpeed->Enabled = false;
	}
	else
    {
      this->BStart->Enabled = true;
      this->BStop->Enabled = false;
	  this->StatusBar->SimpleText = "Состояние консоли: остановлена";
      this->CBCOMNum->Enabled = true;
	  this->CBCOMSpeed->Enabled = true;
	}

    if(this->aPeriphery.IsRunning() == true)
	{
		;
	}

}

//---------------------------------------------------------------------------

void __fastcall TMainForm::AddToLogMemo(String Text)
{
	this->MLog->Lines->Add(TimeToStr(Now()) + " | " + Text);
}


void __fastcall TMainForm::BExtendClick(TObject *Sender)
{
	ExtendedMode = !ExtendedMode;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::EFlag_enableSysChange(TObject *Sender)
{
  if(EFlag_enableSys->Text == "") EFlag_enableSys->Text = IntToStr(this->UDFlag_enableSys->Min);

  if(StrToInt(EFlag_enableSys->Text) > this->UDFlag_enableSys->Max)
  {
	EFlag_enableSys->Text = IntToStr(this->UDFlag_enableSys->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);


  if (StrToInt(EFlag_enableSys->Text) == 1)
  {
	sendpaket.push_back(0x30);
	sendpaket.push_back(0x31);
  }
  else
  {
	sendpaket.push_back(0x39);
	sendpaket.push_back(0x38);
  }
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение Flag_enableSys изменено на " + EFlag_enableSys->Text);

}

//---------------------------------------------------------------------------

void __fastcall TMainForm::EFlag_Run_IdentifyChange(TObject *Sender)
{
  if(EFlag_Run_Identify == "") EFlag_Run_Identify->Text = IntToStr(this->UDFlag_Run_Identify->Min);

  if(StrToInt(EFlag_Run_Identify->Text) > this->UDFlag_Run_Identify->Max)
  {
	EFlag_Run_Identify->Text = IntToStr(this->UDFlag_Run_Identify->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);


  if (StrToInt(EFlag_Run_Identify->Text) == 1)
  {
	sendpaket.push_back(0x30);
	sendpaket.push_back(0x32);
  }
  else
  {
	sendpaket.push_back(0x39);
	sendpaket.push_back(0x39);
  }
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение Flag_Run_Identify изменено на " + EFlag_Run_Identify->Text);
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::ESpeedRef_krpmChange(TObject *Sender)
{
 if(ESpeedRef_krpm->Text == "") ESpeedRef_krpm->Text = IntToStr(this->UDSpeedRef_krpm->Min);

  if(StrToInt(ESpeedRef_krpm->Text) > this->UDSpeedRef_krpm->Max)
  {
	ESpeedRef_krpm->Text = IntToStr(this->UDSpeedRef_krpm->Max);
  }


  //this->aPeriphery.SetEHMKRashod(StrToInt(EFlagRun->Text));
  //this->AddToLogMemo("Значение FlagRun изменено на " + IntToStr(this->aPeriphery.GetEHMKRashod()));

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x33);

  if (StrToInt(ESpeedRef_krpm->Text)>= 0)
  {
	sendpaket.push_back(0x30);  //this->AddToLogMemo("плюс");

  }
  else
  {
	sendpaket.push_back(0x31);//this->AddToLogMemo("минус");
  }

	//BYTE speed1 = 0x0B;
	//BYTE speed2 = 0x0F;
	//BYTE speed3 = 0x0B;
	//BYTE speed4 = 0x00;

  BYTE speed1 = (abs(StrToInt(ESpeedRef_krpm->Text)))/1000;
  BYTE speed2 = ((abs(StrToInt(ESpeedRef_krpm->Text))) %1000)/100;
  BYTE speed3 = (((abs(StrToInt(ESpeedRef_krpm->Text))) %1000)%100)/10;
  BYTE speed4 = ((((abs(StrToInt(ESpeedRef_krpm->Text))) %1000)%100)%10);

  sendpaket.push_back(speed1+ASCII_OFFSET);
  sendpaket.push_back(speed2+ASCII_OFFSET);
  sendpaket.push_back(speed3+ASCII_OFFSET);
  sendpaket.push_back(speed4+ASCII_OFFSET);

  //	 this->AddToLogMemo(IntToStr(speed1));
  //	 this->AddToLogMemo(IntToStr(speed2));
  //	 this->AddToLogMemo(IntToStr(speed3));
  //	 this->AddToLogMemo(IntToStr(speed4));

  //CRC = sendpaket[0]+sendpaket[1]+sendpaket[2]+sendpaket[3]+sendpaket[4]+
  //sendpaket[5]+sendpaket[6]+sendpaket[7];
  //CRC1 = CRC/10;
  //CRC2 = CRC-(CRC/10)*10;
  //sendpaket.push_back(CRC1+ASCII_OFFSET);
  //sendpaket.push_back(CRC2+ASCII_OFFSET);


  sendpaket.push_back(0x30);

  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);
  //aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение SpeedRef_krpm изменено на " + ESpeedRef_krpm->Text);

}
//---------------------------------------------------------------------------




void __fastcall TMainForm::EMaxAccel_krpmpsChange(TObject *Sender)
{

 if(EMaxAccel_krpmps->Text == "") EMaxAccel_krpmps->Text = IntToStr(this->UDMaxAccel_krpmps->Min);

  if(StrToInt(EMaxAccel_krpmps->Text) > this->UDMaxAccel_krpmps->Max)
  {
	EMaxAccel_krpmps->Text = IntToStr(this->UDMaxAccel_krpmps->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x34);
  sendpaket.push_back(0x30);

  BYTE accel1 = EMaxAccel_krpmps->Text/1000;
  BYTE accel2 = (EMaxAccel_krpmps->Text %1000)/100;
  BYTE accel3 = ((EMaxAccel_krpmps->Text %1000)%100)/10;
  BYTE accel4 = (((EMaxAccel_krpmps->Text %1000)%100)%10);

  sendpaket.push_back(accel1+ASCII_OFFSET);
  sendpaket.push_back(accel2+ASCII_OFFSET);
  sendpaket.push_back(accel3+ASCII_OFFSET);
  sendpaket.push_back(accel4+ASCII_OFFSET);

  sendpaket.push_back(0x30);

  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение MaxAccel_krpmps изменено на " + EMaxAccel_krpmps->Text);
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	this->aPeriphery.aRSMaster.RSClose();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

/*void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x33);
  sendpaket.push_back(0x30);

  BYTE accel1 = StrToInt(Edit1->Text);
  BYTE accel2 = StrToInt(Edit2->Text);
  BYTE accel3 = StrToInt(Edit3->Text);
  BYTE accel4 = StrToInt(Edit4->Text);

  sendpaket.push_back(accel1+ASCII_OFFSET);
  sendpaket.push_back(accel2+ASCII_OFFSET);
  sendpaket.push_back(accel3+ASCII_OFFSET);
  sendpaket.push_back(accel4+ASCII_OFFSET);

  sendpaket.push_back(0x30);

  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

   this->AddToLogMemo(IntToStr(accel1));
	 this->AddToLogMemo(IntToStr(accel2));
	 this->AddToLogMemo(IntToStr(accel3));
	 this->AddToLogMemo(IntToStr(accel4));
} */
//---------------------------------------------------------------------------

void __fastcall TMainForm::EFlag_MotorIdentifiedChange(TObject *Sender)
{
  if(EFlag_MotorIdentified->Text == "") EFlag_MotorIdentified->Text = IntToStr(this->UDFlag_MotorIdentified->Min);

  if(StrToInt(EFlag_MotorIdentified->Text) > this->UDFlag_MotorIdentified->Max)
  {
	EFlag_MotorIdentified->Text = IntToStr(this->UDFlag_MotorIdentified->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x30);

  if (StrToInt(EFlag_MotorIdentified->Text) == 1)
  {
	sendpaket.push_back(0x35);
  }
  else
  {
	sendpaket.push_back(0x36);
  }
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение Flag_MotorIdentified изменено на " + EFlag_MotorIdentified->Text);
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TMainForm::BGetSpeed_krpmClick(TObject *Sender)
{

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x32);
  sendpaket.push_back(0x32);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос Speed_krpm");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BGetErorrCodeClick(TObject *Sender)
{
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x32);
  sendpaket.push_back(0x33);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос UserErrorCode");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BKp_IdqClick(TObject *Sender)
{
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x32);
  sendpaket.push_back(0x34);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос Kp_Idq");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BGetKi_IdqClick(TObject *Sender)
{
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x32);
  sendpaket.push_back(0x35);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос Ki_Idq");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BGetStateClick(TObject *Sender)
{
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x32);
  sendpaket.push_back(0x36);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос GetState");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TMainForm::BGetFlagsClick(TObject *Sender)
{
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x32);
  sendpaket.push_back(0x31);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос GetFlag");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BGetMotorParamsClick(TObject *Sender)
{
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x33);
  sendpaket.push_back(0x31);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);
  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос GetMotorParams");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TMainForm::EFlag_enableUserParamsChange(TObject *Sender)
{
  if(EFlag_enableUserParams->Text == "") EFlag_enableUserParams->Text = IntToStr(this->UDFlag_enableUserParams->Min);

  if(StrToInt(EFlag_enableUserParams->Text) > this->UDFlag_enableUserParams->Max)
  {
	EFlag_enableUserParams->Text = IntToStr(this->UDFlag_enableUserParams->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);


  if (StrToInt(EFlag_enableUserParams->Text) == 1)
  {
	sendpaket.push_back(0x31);
	sendpaket.push_back(0x35);
  }
  else
  {
	sendpaket.push_back(0x31);
	sendpaket.push_back(0x36);
  }
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение Flag_enableUserParams изменено на " + EFlag_enableUserParams->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EFlag_enableRsRecalcChange(TObject *Sender)
{
  if(EFlag_enableRsRecalc->Text == "") EFlag_enableRsRecalc->Text = IntToStr(this->UDFlag_enableRsRecalc->Min);

  if(StrToInt(EFlag_enableRsRecalc->Text) > this->UDFlag_enableRsRecalc->Max)
  {
	EFlag_enableRsRecalc->Text = IntToStr(this->UDFlag_enableRsRecalc->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x30);

  if (StrToInt(EFlag_enableRsRecalc->Text) == 1)
  {
	sendpaket.push_back(0x37);
  }
  else
  {
	sendpaket.push_back(0x38);
  }
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение Flag_enRsRecalc изменено на " + EFlag_enableRsRecalc->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EFlag_enableForceAngleChange(TObject *Sender)
{
  if(EFlag_enableForceAngle->Text == "") EFlag_enableForceAngle->Text = IntToStr(this->UDFlag_enableForceAngle->Min);

  if(StrToInt(EFlag_enableForceAngle->Text) > this->UDFlag_enableForceAngle->Max)
  {
	EFlag_enableForceAngle->Text = IntToStr(this->UDFlag_enableForceAngle->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);


  if (StrToInt(EFlag_enableForceAngle->Text) == 1)
  {
	sendpaket.push_back(0x30);
	sendpaket.push_back(0x39);
  }
  else
  {
	sendpaket.push_back(0x31);
	sendpaket.push_back(0x30);
  }
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение Flag_enableForceAngle изменено на " + EFlag_enableForceAngle->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EFlag_enableOffsetcalcChange(TObject *Sender)
{
  if(EFlag_enableOffsetcalc->Text == "") EFlag_enableOffsetcalc->Text = IntToStr(this->UDFlag_enableOffsetcalc->Min);

  if(StrToInt(EFlag_enableOffsetcalc->Text) > this->UDFlag_enableOffsetcalc->Max)
  {
	EFlag_enableOffsetcalc->Text = IntToStr(this->UDFlag_enableOffsetcalc->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x31);

  if (StrToInt(EFlag_enableOffsetcalc->Text) == 1)
  {
	sendpaket.push_back(0x31);
  }
  else
  {
	sendpaket.push_back(0x32);
  }
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение Flag_enableOffsetcalc изменено на " + EFlag_enableOffsetcalc->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EFlag_enableFieldWeakeningChange(TObject *Sender)
{
  if(EFlag_enableFieldWeakening->Text == "") EFlag_enableFieldWeakening->Text = IntToStr(this->UDFlag_enableFieldWeakening->Min);

  if(StrToInt(EFlag_enableFieldWeakening->Text) > this->UDFlag_enableFieldWeakening->Max)
  {
	EFlag_enableFieldWeakening->Text = IntToStr(this->UDFlag_enableFieldWeakening->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x30);

  if (StrToInt(EFlag_enableFieldWeakening->Text) == 1)
  {
	sendpaket.push_back(0x33);
  }
  else
  {
	sendpaket.push_back(0x34);
  }
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение Flag_enableFieldWeakening изменено на " + EFlag_enableFieldWeakening->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BStart1Click(TObject *Sender)
{
	/*EFlag_enableUserParams->Text = "1";
	EFlag_enableRsRecalc->Text = "1";
	EFlag_enableOffsetcalc->Text = "1";
	EFlag_enableSys->Text = "1";
	EFlag_Run_Identify->Text = "1";*/
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x35);
  sendpaket.push_back(0x31);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос START");
	//ESpeedRef_krpm->Text = "100";
	//EMaxAccel_krpmps->Text = "100";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BStop1Click(TObject *Sender)
{
	//EFlag_Run_Identify->Text = "0";
	//EFlag_enableSys->Text = "0";

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x35);
  sendpaket.push_back(0x32);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос STOP");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BIDENTIFYClick(TObject *Sender)
{
	/*EFlag_MotorIdentified->Text = "0";
	EFlag_enableUserParams->Text = "0";
	EFlag_enableSys->Text = "1";
	EFlag_Run_Identify->Text = "1";*/
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x35);
  sendpaket.push_back(0x33);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос IDENTIFY");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TMainForm::BGetALLClick(TObject *Sender)
{
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x35);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос GetALL");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ERunPositionProfileChange(TObject *Sender)
{
  if(ERunPositionProfile->Text == "") ERunPositionProfile->Text = IntToStr(this->UDRunPositionProfile->Min);

  if(StrToInt(ERunPositionProfile->Text) > this->UDRunPositionProfile->Max)
  {
	ERunPositionProfile->Text = IntToStr(this->UDRunPositionProfile->Max);
  }

  if (StrToInt(ERunPositionProfile->Text) == 1)
  {
	std::vector<BYTE> sendpaket;
	sendpaket.push_back(START_BYTE);
	sendpaket.push_back(0x36);
	sendpaket.push_back(0x31);

	  sendpaket.push_back(0x30);
	  sendpaket.push_back(0x30);
	  sendpaket.push_back(0x30);
	  sendpaket.push_back(0x30);
	  sendpaket.push_back(0x30);
	  sendpaket.push_back(0x30);
	  sendpaket.push_back(END_BYTE);

	  this->aPeriphery.aRSMaster.RSSend(sendpaket);

	  this->AddToLogMemo("Значение RunPositionProfile изменено на " + ERunPositionProfile->Text);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EPosStepInt_MRevChange(TObject *Sender)
{
  if(EPosStepInt_MRev->Text == "") EPosStepInt_MRev->Text = IntToStr(this->UDPosStepInt_MRev->Min);

  if(StrToInt(EPosStepInt_MRev->Text) > this->UDPosStepInt_MRev->Max)
  {
	EPosStepInt_MRev->Text = IntToStr(this->UDPosStepInt_MRev->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x36);
  sendpaket.push_back(0x32);
  sendpaket.push_back(0x30);

  BYTE accel1 = EPosStepInt_MRev->Text/1000;
  BYTE accel2 = (EPosStepInt_MRev->Text %1000)/100;
  BYTE accel3 = ((EPosStepInt_MRev->Text %1000)%100)/10;
  BYTE accel4 = (((EPosStepInt_MRev->Text %1000)%100)%10);

  sendpaket.push_back(accel1+ASCII_OFFSET);
  sendpaket.push_back(accel2+ASCII_OFFSET);
  sendpaket.push_back(accel3+ASCII_OFFSET);
  sendpaket.push_back(accel4+ASCII_OFFSET);

  sendpaket.push_back(0x30);

  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение PosStepInt_MRev изменено на " + EPosStepInt_MRev->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EPosStepFrac_MRevChange(TObject *Sender)
{
  if(EPosStepFrac_MRev->Text == "") EPosStepFrac_MRev->Text = IntToStr(this->UDPosStepFrac_MRev->Min);

  if(StrToInt(EPosStepFrac_MRev->Text) > this->UDPosStepFrac_MRev->Max)
  {
	EPosStepFrac_MRev->Text = IntToStr(this->UDPosStepFrac_MRev->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x36);
  sendpaket.push_back(0x33);

  if (StrToInt(EPosStepFrac_MRev->Text)>= 0)
  {
	sendpaket.push_back(0x30);  //this->AddToLogMemo("плюс");
  }
  else
  {
	sendpaket.push_back(0x31);//this->AddToLogMemo("минус");    }
  }

  BYTE speed1 = (abs(StrToInt(EPosStepFrac_MRev->Text)))/1000;
  BYTE speed2 = ((abs(StrToInt(EPosStepFrac_MRev->Text))) %1000)/100;
  BYTE speed3 = (((abs(StrToInt(EPosStepFrac_MRev->Text))) %1000)%100)/10;
  BYTE speed4 = ((((abs(StrToInt(EPosStepFrac_MRev->Text))) %1000)%100)%10);

  sendpaket.push_back(speed1+ASCII_OFFSET);
  sendpaket.push_back(speed2+ASCII_OFFSET);
  sendpaket.push_back(speed3+ASCII_OFFSET);
  sendpaket.push_back(speed4+ASCII_OFFSET);

  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение PosStepFrac_MRev изменено на " + EPosStepFrac_MRev->Text);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EMaxVel_krpmChange(TObject *Sender)
{
  if(EMaxVel_krpm->Text == "") EMaxVel_krpm->Text = IntToStr(this->UDMaxVel_krpm->Min);

  if(StrToInt(EMaxVel_krpm->Text) > this->UDMaxVel_krpm->Max)
  {
	EMaxVel_krpm->Text = IntToStr(this->UDMaxVel_krpm->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x36);
  sendpaket.push_back(0x34);
  sendpaket.push_back(0x30);

  BYTE accel1 = EMaxVel_krpm->Text/1000;
  BYTE accel2 = (EMaxVel_krpm->Text %1000)/100;
  BYTE accel3 = ((EMaxVel_krpm->Text %1000)%100)/10;
  BYTE accel4 = (((EMaxVel_krpm->Text %1000)%100)%10);

  sendpaket.push_back(accel1+ASCII_OFFSET);
  sendpaket.push_back(accel2+ASCII_OFFSET);
  sendpaket.push_back(accel3+ASCII_OFFSET);
  sendpaket.push_back(accel4+ASCII_OFFSET);

  sendpaket.push_back(0x30);

  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение MaxVel_krpm изменено на " + EMaxVel_krpm->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EPeriod_msChange(TObject *Sender)
{
 if(EPeriod_ms->Text == "") EPeriod_ms->Text = IntToStr(this->UDPeriod_ms->Min);

  if(StrToInt(EPeriod_ms->Text) > this->UDPeriod_ms->Max)
  {
	EPeriod_ms->Text = IntToStr(this->UDPeriod_ms->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x35);
  sendpaket.push_back(0x34);
  sendpaket.push_back(0x30);

  BYTE accel1 = EPeriod_ms->Text/1000;
  BYTE accel2 = (EPeriod_ms->Text %1000)/100;
  BYTE accel3 = ((EPeriod_ms->Text %1000)%100)/10;
  BYTE accel4 = (((EPeriod_ms->Text %1000)%100)%10);

  sendpaket.push_back(accel1+ASCII_OFFSET);
  sendpaket.push_back(accel2+ASCII_OFFSET);
  sendpaket.push_back(accel3+ASCII_OFFSET);
  sendpaket.push_back(accel4+ASCII_OFFSET);

  sendpaket.push_back(0x30);

  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение Period_ms изменено на " + EPeriod_ms->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BESTOPClick(TObject *Sender)
{
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x39);
  sendpaket.push_back(0x37);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос ESTOP");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TMainForm::Edest_posChange(TObject *Sender)
{
  if(Edest_pos->Text == "") Edest_pos->Text = IntToStr(this->UDdest_pos->Min);

  if(StrToInt(Edest_pos->Text) > this->UDdest_pos->Max)
  {
	Edest_pos->Text = IntToStr(this->UDdest_pos->Max);
  }

  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x31);
  sendpaket.push_back(0x37);
  sendpaket.push_back(0x30);


  BYTE speed1 = (abs(StrToInt(EPosStepFrac_MRev->Text)))/10000;
  BYTE speed2 = ((abs(StrToInt(EPosStepFrac_MRev->Text))) %10000)/1000;
  BYTE speed3 = (((abs(StrToInt(EPosStepFrac_MRev->Text))) %10000)%1000)/100;
  BYTE speed4 = ((((abs(StrToInt(EPosStepFrac_MRev->Text))) %10000)%1000)/100)/10;
  BYTE speed5 = ((((abs(StrToInt(EPosStepFrac_MRev->Text))) %10000)%1000)/100)%10;

  sendpaket.push_back(speed1+ASCII_OFFSET);
  sendpaket.push_back(speed2+ASCII_OFFSET);
  sendpaket.push_back(speed3+ASCII_OFFSET);
  sendpaket.push_back(speed4+ASCII_OFFSET);
  sendpaket.push_back(speed5+ASCII_OFFSET);

  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Значение dest_pos изменено на " + Edest_pos->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BSAVEClick(TObject *Sender)
{
  std::vector<BYTE> sendpaket;
  sendpaket.push_back(START_BYTE);
  sendpaket.push_back(0x35);
  sendpaket.push_back(0x35);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(0x30);
  sendpaket.push_back(END_BYTE);

  this->aPeriphery.aRSMaster.RSSend(sendpaket);

  this->AddToLogMemo("Отправлен запрос SAVE");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::BChartClearClick(TObject *Sender)
{
	for (int i = 0; i < MainForm->Chart->SeriesCount(); i++)
	{
		MainForm->Chart->Series[i]->Clear();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer2Timer(TObject *Sender)
{
  mytime++;

  this->ESpeedRef_krpm->Text = IntToStr(rand() % 100);
  this->ESpeed_krpm->Text = IntToStr(rand() % 100  + 500);

  if(this->cbEnableChart->Checked == true)
  {
	this->aChart.Run();
  }
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::EPeriod2_msChange(TObject *Sender)
{
  if(EPeriod2_ms->Text == "") EPeriod2_ms->Text = IntToStr(this->UDPeriod2_ms->Min);

  if(StrToInt(EPeriod2_ms->Text) > this->UDPeriod2_ms->Max)
  {
	EPeriod2_ms->Text = IntToStr(this->UDPeriod2_ms->Max);
  }

  if(StrToInt(EPeriod2_ms->Text) < this->UDPeriod2_ms->Min)
  {
	EPeriod2_ms->Text = IntToStr(this->UDPeriod2_ms->Min);
  }


  this->Timer2->Interval = (StrToInt(this->EPeriod2_ms->Text));
}
//---------------------------------------------------------------------------


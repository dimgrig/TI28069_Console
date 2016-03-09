//---------------------------------------------------------------------------


#pragma hdrstop

#include "UPeriphery.h"
#include "UConstants.h"
#include "UMainForm.h"

bool Periphery::TurnOn(int COM_num, int speed)
{
  if(Running) return false;

	bool ret = aRSMaster.RSInit(COM_num, speed);

	if (ret)
  {
  	Running = true;
    return true;
  }
  else
  {
  	Running = false;
	return false;
  }


}

bool Periphery::Run()
{
    if(this->IsRunning() == false)
    {
    	return false;
    }

	std::vector<BYTE> paket;
	bool RS_Status = aRSMaster.RSProcess(paket);
    if(RS_Status == false)
    {
        return false;
	}

    DispatchPaket(paket);

    return true;
}

void Periphery::TurnOff()
{
  aRSMaster.RSClose();
  Running = false;
}

int Periphery::DispatchPaket( std::vector<BYTE> paket)
{
	//BYTE CRC;
	//BYTE CRC1;
	//BYTE CRC2;

		//проверка на то, что сообщение ///
		if(/*paket.size() == 10 &&*/ paket[0] == START_BYTE && paket[9] == END_BYTE)
		{
			BYTE mode = (((paket[1] - ASCII_OFFSET) << 4) | ((paket[2] - ASCII_OFFSET) << 0));

			switch (mode)
			{
			case 0x21:
				MainForm->EFlag_enableSys->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[4])) >> 3) & 0x01);
				MainForm->EFlag_Run_Identify->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[4])) >> 2) & 0x01);
				MainForm->EFlag_MotorIdentified->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[4])) >> 1) & 0x01);
				MainForm->EFlag_enableUserParams->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[4])) ) & 0x01);
				MainForm->AddToLogMemo("Значение Flag_enableSys составляет " + MainForm->EFlag_enableSys->Text);
				MainForm->AddToLogMemo("Значение Flag_Run_Identify составляет " + MainForm->EFlag_Run_Identify->Text);
				MainForm->AddToLogMemo("Значение Flag_MotorIdentified составляет " + MainForm->EFlag_MotorIdentified->Text);
				MainForm->AddToLogMemo("Значение Flag_enableUserParams составляет " + MainForm->EFlag_enableUserParams->Text);

				MainForm->EFlag_enableRsRecalc->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[5])) >> 3) & 0x01);
				MainForm->EFlag_enableForceAngle->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[5])) >> 2) & 0x01);
				MainForm->EFlag_enableOffsetcalc->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[5])) >> 1) & 0x01);
				MainForm->EFlag_enableFieldWeakening->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[5])) ) & 0x01);
				MainForm->AddToLogMemo("Значение Flag_enableRsRecalc составляет " + MainForm->EFlag_enableRsRecalc->Text);
				MainForm->AddToLogMemo("Значение Flag_enableForceAngle составляет " + MainForm->EFlag_enableForceAngle->Text);
				MainForm->AddToLogMemo("Значение Flag_enableOffsetcalc составляет " + MainForm->EFlag_enableOffsetcalc->Text);
				MainForm->AddToLogMemo("Значение Flag_enableFieldWeakening составляет " + MainForm->EFlag_enableFieldWeakening->Text);

				//MainForm->AddToLogMemo(IntToStr(aRSMaster.RSAsciiToInt(paket[4])) + "   " + IntToStr(aRSMaster.RSAsciiToInt(paket[5])));
			break;
			case 0x22:
				//MainForm->ESpeed_krpm->Text = IntToStr(((paket[4] - ASCII_OFFSET) << 12) |  ((paket[5] - ASCII_OFFSET) << 8) | ((paket[6] - ASCII_OFFSET) << 4) | ((paket[7] - ASCII_OFFSET) << 0));

				if (paket[3] == 0x31)
				{
					MainForm->ESpeed_krpm->Text = IntToStr((-1)*(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)));
					MainForm->AddToLogMemo("Значение Speed_krpm составляет  -" + MainForm->ESpeed_krpm->Text);
				}
				else
				{
					MainForm->ESpeed_krpm->Text = IntToStr((((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)));
					MainForm->AddToLogMemo("Значение Speed_krpm составляет " + MainForm->ESpeed_krpm->Text);
				}

			break;
			case 0x23:
				MainForm->EUserErrorCode->Text = USER_ErrorCode[((paket[4] - ASCII_OFFSET)*100) + ((paket[5] - ASCII_OFFSET)*10) + ((paket[6] - ASCII_OFFSET)*1)];
				MainForm->AddToLogMemo("Значение UserErrorCode составляет " + MainForm->EUserErrorCode->Text);
				MainForm->EEST_ErrorCode->Text = EST_ErrorCode[((paket[7] - ASCII_OFFSET)*1)];
				MainForm->AddToLogMemo("Значение EST_ErrorCode составляет " + MainForm->EEST_ErrorCode->Text);
			break;
			case 0x24:
				MainForm->EKp_Idq->Text = FloatToStr(((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)))/1000);
				MainForm->AddToLogMemo("Значение Kp_Idq составляет " + MainForm->EKp_Idq->Text);
			break;
			case 0x25:
				MainForm->EKi_Idq->Text = FloatToStr(((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)))/1000);
				MainForm->AddToLogMemo("Значение Ki_Idq составляет " + MainForm->EKi_Idq->Text);
			break;
			case 0x26:
				MainForm->ECtrlState->Text = CTRL_State[((paket[4] - ASCII_OFFSET)) ];
				MainForm->AddToLogMemo("Значение CtrlState составляет " + MainForm->ECtrlState->Text);
				//MainForm->EEstState->Text = IntToStr(((paket[5] - ASCII_OFFSET)*10) + ((paket[6] - ASCII_OFFSET)*1));
				MainForm->EEstState->Text = EST_State[(((paket[5] - ASCII_OFFSET)*10) + ((paket[6] - ASCII_OFFSET)*1))];
				MainForm->AddToLogMemo("Значение EstState составляет " + MainForm->EEstState->Text);
				MainForm->EVelCtlStatus->Text = VEL_State[((paket[7] - ASCII_OFFSET)) ];
				MainForm->AddToLogMemo("Значение VelCtlStatus составляет " + MainForm->EVelCtlStatus->Text);
			break;
			case 0x31:
				MainForm->ERs_Ohm->Text = FloatToStr(((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))/1000);
				MainForm->AddToLogMemo("Значение Rs_Ohm составляет " + MainForm->ERs_Ohm->Text);
			break;
			case 0x32:
				MainForm->EMagnCurr_A->Text = FloatToStr(((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))/1000);
				MainForm->AddToLogMemo("Значение MagnCurr_A составляет " + MainForm->EMagnCurr_A->Text);
			break;
			case 0x33:
				MainForm->ELsd_H->Text = FloatToStr(((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))/100000);
				MainForm->AddToLogMemo("Значение Lsd_H составляет " + MainForm->ELsd_H->Text);
			break;
			case 0x34:
				MainForm->ELsq_H->Text = FloatToStr(((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))/100000);
				MainForm->AddToLogMemo("Значение Lsq_H составляет " + MainForm->ELsq_H->Text);
			break;
			case 0x35:
				MainForm->EFlux_VpHz->Text = FloatToStr(((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))/1000);
				MainForm->AddToLogMemo("Значение Flux_VpHz составляет " + MainForm->EFlux_VpHz->Text);
			break;
			case 0x36:
				if (paket[3] == 0x31)
				{
					MainForm->ETorque_Nm->Text = FloatToStr(((-1)*((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)))/1);
					MainForm->AddToLogMemo("Значение Torque_Nm составляет  -" + MainForm->ETorque_Nm->Text);
				}
				else
				{
					MainForm->ETorque_Nm->Text = FloatToStr((((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)))/1);
					MainForm->AddToLogMemo("Значение Torque_Nm составляет " + MainForm->ETorque_Nm->Text);
				}
			break;



			case 0x39:
				//MainForm->ESpeedRef_krpm->Text = IntToStr(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1));
				//MainForm->AddToLogMemo("Значение SpeedRef_krpm!!!!!!!!!!!!!!!!!!!!! составляет " + IntToStr(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)));
			break;
			case 0x40:
				//MainForm->EMaxAccel_krpmps->Text = IntToStr(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1));
				//MainForm->AddToLogMemo("Значение MaxAccel_krpmps составляет " + IntToStr(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)));
			break;

			case 0x41:
				MainForm->EPOSITION->Text = FloatToStr(((float)((((paket[3] - ASCII_OFFSET)*100000) +  (paket[4] - ASCII_OFFSET)*10000) + ((paket[5] - ASCII_OFFSET)*1000) + ((paket[6] - ASCII_OFFSET)*100) + ((paket[7] - ASCII_OFFSET)*10) +  ((paket[8] - ASCII_OFFSET)*1)))/1);
				MainForm->AddToLogMemo("Значение POSITION составляет " + MainForm->EPOSITION->Text);
			break;
			case 0x42:
				if (paket[3] == 0x31)
				{
					MainForm->EDUTY1->Text = FloatToStr(((-1)*((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))))/10);
					MainForm->AddToLogMemo("Значение DUTY1 составляет  -" + MainForm->EDUTY1->Text);
				}
				else
				{
					MainForm->EDUTY1->Text = FloatToStr(((1)*((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))))/10);
					MainForm->AddToLogMemo("Значение DUTY1 составляет " + MainForm->EDUTY1->Text);
				}
			break;
			case 0x71:
				MainForm->EPosCtlStatus->Text = ST_CtlStatus[((paket[4] - ASCII_OFFSET)*1)];
				MainForm->AddToLogMemo("Значение PosCtlStatus составляет " + MainForm->EPosCtlStatus->Text);
				MainForm->EPosMoveStatus->Text = ST_MoveStatus[((paket[4] - ASCII_OFFSET)*1)];
				MainForm->AddToLogMemo("Значение PosMoveStatus составляет " + MainForm->EPosMoveStatus->Text);
				MainForm->EPosMoveCurveType->Text = ST_MoveCurveType[((paket[4] - ASCII_OFFSET)*1)];
				MainForm->AddToLogMemo("Значение PosMoveCurveType составляет " + MainForm->EPosMoveCurveType->Text);
				MainForm->EPosMoveDone->Text = IntToStr((paket[4] - ASCII_OFFSET)*1);
				MainForm->AddToLogMemo("Значение PosMoveDone составляет " + MainForm->EPosMoveDone->Text);
			break;
			case 0x72:
				MainForm->EPosCtlErrorID->Text = IntToStr(((((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1) ))/1);
				MainForm->AddToLogMemo("Значение PosCtlErrorID составляет " + MainForm->EPosCtlErrorID->Text);
			break;
			case 0x73:
				MainForm->EPosMoveErrorID->Text = IntToStr(((((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1) ))/1);
				MainForm->AddToLogMemo("Значение PosMoveErrorID составляет " + MainForm->EPosMoveErrorID->Text);
			break;
			case 0x74:
				if (paket[3] == 0x31)
				{
					MainForm->EPositionError_MRev->Text = FloatToStr((-1)*((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)   ))/100);
					MainForm->AddToLogMemo("Значение PositionError_MRev составляет  -" + MainForm->EPositionError_MRev->Text);
				}
				else
				{
					MainForm->EPositionError_MRev->Text = FloatToStr(((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)  ))/100);
					MainForm->AddToLogMemo("Значение PositionError_MRev составляет " + MainForm->EPositionError_MRev->Text) ;
				}
			break;
			default:
				;
			}


			//проверяем контрольную сумму
			//CRC = paket[0]+paket[1]+paket[2]+paket[3];
			//CRC1 = CRC/10;
			//CRC2 = CRC-(CRC/10)*10;
			//if(CRC1 + ASCII_OFFSET == paket[4] && CRC2 + ASCII_OFFSET == paket[5])
			//{

                //MainForm->AddToLogMemo("От БУ-ЭХМ-А поступил пакет данных для ЭХМ-К");

			  //  if (((paket[3] - ASCII_OFFSET)&(1<<0))>>0 == 1)
			   //		SetEHMKPuskBUEHM(true);
			  //	else
			  //		SetEHMKPuskBUEHM(false);

				//MainForm->AddToLogMemo("Модуль ЭХМ-К послал БУ-ЭХМ-А ответ");
			//}
			//else
			//{
			//	MainForm->AddToLogMemo("Ошибка приема данных");
			//    return 2;
			//}
		}

	return 0;
}

//---------------------------------------------------------------------------

#pragma package(smart_init)

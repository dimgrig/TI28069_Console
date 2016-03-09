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

		//�������� �� ��, ��� ��������� ///
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
				MainForm->AddToLogMemo("�������� Flag_enableSys ���������� " + MainForm->EFlag_enableSys->Text);
				MainForm->AddToLogMemo("�������� Flag_Run_Identify ���������� " + MainForm->EFlag_Run_Identify->Text);
				MainForm->AddToLogMemo("�������� Flag_MotorIdentified ���������� " + MainForm->EFlag_MotorIdentified->Text);
				MainForm->AddToLogMemo("�������� Flag_enableUserParams ���������� " + MainForm->EFlag_enableUserParams->Text);

				MainForm->EFlag_enableRsRecalc->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[5])) >> 3) & 0x01);
				MainForm->EFlag_enableForceAngle->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[5])) >> 2) & 0x01);
				MainForm->EFlag_enableOffsetcalc->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[5])) >> 1) & 0x01);
				MainForm->EFlag_enableFieldWeakening->Text = IntToStr(((aRSMaster.RSAsciiToInt(paket[5])) ) & 0x01);
				MainForm->AddToLogMemo("�������� Flag_enableRsRecalc ���������� " + MainForm->EFlag_enableRsRecalc->Text);
				MainForm->AddToLogMemo("�������� Flag_enableForceAngle ���������� " + MainForm->EFlag_enableForceAngle->Text);
				MainForm->AddToLogMemo("�������� Flag_enableOffsetcalc ���������� " + MainForm->EFlag_enableOffsetcalc->Text);
				MainForm->AddToLogMemo("�������� Flag_enableFieldWeakening ���������� " + MainForm->EFlag_enableFieldWeakening->Text);

				//MainForm->AddToLogMemo(IntToStr(aRSMaster.RSAsciiToInt(paket[4])) + "   " + IntToStr(aRSMaster.RSAsciiToInt(paket[5])));
			break;
			case 0x22:
				//MainForm->ESpeed_krpm->Text = IntToStr(((paket[4] - ASCII_OFFSET) << 12) |  ((paket[5] - ASCII_OFFSET) << 8) | ((paket[6] - ASCII_OFFSET) << 4) | ((paket[7] - ASCII_OFFSET) << 0));

				if (paket[3] == 0x31)
				{
					MainForm->ESpeed_krpm->Text = IntToStr((-1)*(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)));
					MainForm->AddToLogMemo("�������� Speed_krpm ����������  -" + MainForm->ESpeed_krpm->Text);
				}
				else
				{
					MainForm->ESpeed_krpm->Text = IntToStr((((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)));
					MainForm->AddToLogMemo("�������� Speed_krpm ���������� " + MainForm->ESpeed_krpm->Text);
				}

			break;
			case 0x23:
				MainForm->EUserErrorCode->Text = USER_ErrorCode[((paket[4] - ASCII_OFFSET)*100) + ((paket[5] - ASCII_OFFSET)*10) + ((paket[6] - ASCII_OFFSET)*1)];
				MainForm->AddToLogMemo("�������� UserErrorCode ���������� " + MainForm->EUserErrorCode->Text);
				MainForm->EEST_ErrorCode->Text = EST_ErrorCode[((paket[7] - ASCII_OFFSET)*1)];
				MainForm->AddToLogMemo("�������� EST_ErrorCode ���������� " + MainForm->EEST_ErrorCode->Text);
			break;
			case 0x24:
				MainForm->EKp_Idq->Text = FloatToStr(((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)))/1000);
				MainForm->AddToLogMemo("�������� Kp_Idq ���������� " + MainForm->EKp_Idq->Text);
			break;
			case 0x25:
				MainForm->EKi_Idq->Text = FloatToStr(((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)))/1000);
				MainForm->AddToLogMemo("�������� Ki_Idq ���������� " + MainForm->EKi_Idq->Text);
			break;
			case 0x26:
				MainForm->ECtrlState->Text = CTRL_State[((paket[4] - ASCII_OFFSET)) ];
				MainForm->AddToLogMemo("�������� CtrlState ���������� " + MainForm->ECtrlState->Text);
				//MainForm->EEstState->Text = IntToStr(((paket[5] - ASCII_OFFSET)*10) + ((paket[6] - ASCII_OFFSET)*1));
				MainForm->EEstState->Text = EST_State[(((paket[5] - ASCII_OFFSET)*10) + ((paket[6] - ASCII_OFFSET)*1))];
				MainForm->AddToLogMemo("�������� EstState ���������� " + MainForm->EEstState->Text);
				MainForm->EVelCtlStatus->Text = VEL_State[((paket[7] - ASCII_OFFSET)) ];
				MainForm->AddToLogMemo("�������� VelCtlStatus ���������� " + MainForm->EVelCtlStatus->Text);
			break;
			case 0x31:
				MainForm->ERs_Ohm->Text = FloatToStr(((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))/1000);
				MainForm->AddToLogMemo("�������� Rs_Ohm ���������� " + MainForm->ERs_Ohm->Text);
			break;
			case 0x32:
				MainForm->EMagnCurr_A->Text = FloatToStr(((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))/1000);
				MainForm->AddToLogMemo("�������� MagnCurr_A ���������� " + MainForm->EMagnCurr_A->Text);
			break;
			case 0x33:
				MainForm->ELsd_H->Text = FloatToStr(((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))/100000);
				MainForm->AddToLogMemo("�������� Lsd_H ���������� " + MainForm->ELsd_H->Text);
			break;
			case 0x34:
				MainForm->ELsq_H->Text = FloatToStr(((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))/100000);
				MainForm->AddToLogMemo("�������� Lsq_H ���������� " + MainForm->ELsq_H->Text);
			break;
			case 0x35:
				MainForm->EFlux_VpHz->Text = FloatToStr(((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))/1000);
				MainForm->AddToLogMemo("�������� Flux_VpHz ���������� " + MainForm->EFlux_VpHz->Text);
			break;
			case 0x36:
				if (paket[3] == 0x31)
				{
					MainForm->ETorque_Nm->Text = FloatToStr(((-1)*((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)))/1);
					MainForm->AddToLogMemo("�������� Torque_Nm ����������  -" + MainForm->ETorque_Nm->Text);
				}
				else
				{
					MainForm->ETorque_Nm->Text = FloatToStr((((float)((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)))/1);
					MainForm->AddToLogMemo("�������� Torque_Nm ���������� " + MainForm->ETorque_Nm->Text);
				}
			break;



			case 0x39:
				//MainForm->ESpeedRef_krpm->Text = IntToStr(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1));
				//MainForm->AddToLogMemo("�������� SpeedRef_krpm!!!!!!!!!!!!!!!!!!!!! ���������� " + IntToStr(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)));
			break;
			case 0x40:
				//MainForm->EMaxAccel_krpmps->Text = IntToStr(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1));
				//MainForm->AddToLogMemo("�������� MaxAccel_krpmps ���������� " + IntToStr(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)));
			break;

			case 0x41:
				MainForm->EPOSITION->Text = FloatToStr(((float)((((paket[3] - ASCII_OFFSET)*100000) +  (paket[4] - ASCII_OFFSET)*10000) + ((paket[5] - ASCII_OFFSET)*1000) + ((paket[6] - ASCII_OFFSET)*100) + ((paket[7] - ASCII_OFFSET)*10) +  ((paket[8] - ASCII_OFFSET)*1)))/1);
				MainForm->AddToLogMemo("�������� POSITION ���������� " + MainForm->EPOSITION->Text);
			break;
			case 0x42:
				if (paket[3] == 0x31)
				{
					MainForm->EDUTY1->Text = FloatToStr(((-1)*((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))))/10);
					MainForm->AddToLogMemo("�������� DUTY1 ����������  -" + MainForm->EDUTY1->Text);
				}
				else
				{
					MainForm->EDUTY1->Text = FloatToStr(((1)*((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1))))/10);
					MainForm->AddToLogMemo("�������� DUTY1 ���������� " + MainForm->EDUTY1->Text);
				}
			break;
			case 0x71:
				MainForm->EPosCtlStatus->Text = ST_CtlStatus[((paket[4] - ASCII_OFFSET)*1)];
				MainForm->AddToLogMemo("�������� PosCtlStatus ���������� " + MainForm->EPosCtlStatus->Text);
				MainForm->EPosMoveStatus->Text = ST_MoveStatus[((paket[4] - ASCII_OFFSET)*1)];
				MainForm->AddToLogMemo("�������� PosMoveStatus ���������� " + MainForm->EPosMoveStatus->Text);
				MainForm->EPosMoveCurveType->Text = ST_MoveCurveType[((paket[4] - ASCII_OFFSET)*1)];
				MainForm->AddToLogMemo("�������� PosMoveCurveType ���������� " + MainForm->EPosMoveCurveType->Text);
				MainForm->EPosMoveDone->Text = IntToStr((paket[4] - ASCII_OFFSET)*1);
				MainForm->AddToLogMemo("�������� PosMoveDone ���������� " + MainForm->EPosMoveDone->Text);
			break;
			case 0x72:
				MainForm->EPosCtlErrorID->Text = IntToStr(((((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1) ))/1);
				MainForm->AddToLogMemo("�������� PosCtlErrorID ���������� " + MainForm->EPosCtlErrorID->Text);
			break;
			case 0x73:
				MainForm->EPosMoveErrorID->Text = IntToStr(((((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1) ))/1);
				MainForm->AddToLogMemo("�������� PosMoveErrorID ���������� " + MainForm->EPosMoveErrorID->Text);
			break;
			case 0x74:
				if (paket[3] == 0x31)
				{
					MainForm->EPositionError_MRev->Text = FloatToStr((-1)*((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)   ))/100);
					MainForm->AddToLogMemo("�������� PositionError_MRev ����������  -" + MainForm->EPositionError_MRev->Text);
				}
				else
				{
					MainForm->EPositionError_MRev->Text = FloatToStr(((float)(((paket[4] - ASCII_OFFSET)*1000) + ((paket[5] - ASCII_OFFSET)*100) + ((paket[6] - ASCII_OFFSET)*10) + ((paket[7] - ASCII_OFFSET)*1)  ))/100);
					MainForm->AddToLogMemo("�������� PositionError_MRev ���������� " + MainForm->EPositionError_MRev->Text) ;
				}
			break;
			default:
				;
			}


			//��������� ����������� �����
			//CRC = paket[0]+paket[1]+paket[2]+paket[3];
			//CRC1 = CRC/10;
			//CRC2 = CRC-(CRC/10)*10;
			//if(CRC1 + ASCII_OFFSET == paket[4] && CRC2 + ASCII_OFFSET == paket[5])
			//{

                //MainForm->AddToLogMemo("�� ��-���-� �������� ����� ������ ��� ���-�");

			  //  if (((paket[3] - ASCII_OFFSET)&(1<<0))>>0 == 1)
			   //		SetEHMKPuskBUEHM(true);
			  //	else
			  //		SetEHMKPuskBUEHM(false);

				//MainForm->AddToLogMemo("������ ���-� ������ ��-���-� �����");
			//}
			//else
			//{
			//	MainForm->AddToLogMemo("������ ������ ������");
			//    return 2;
			//}
		}

	return 0;
}

//---------------------------------------------------------------------------

#pragma package(smart_init)

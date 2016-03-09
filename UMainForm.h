//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "UPeriphery.h"
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//#include <pngimage.hpp>
#include <Graphics.hpp>

//extern "C" {
//#include "IQmathLib.h"
//}
//#include "IQmathCPP.h"

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMemo *MLog;
	TStatusBar *StatusBar;
	TTimer *Timer;
	TGroupBox *GBParameters;
	TLabel *LSpeedRef_krpm;
	TLabel *LFlag_enableSys;
	TLabel *LMaxAccel_krpmps;
	TLabel *LSpeed_krpm;
	TLabel *LFlagMotorIdentified;
	TUpDown *UDSpeedRef_krpm;
	TUpDown *UDFlag_enableSys;
	TUpDown *UDMaxAccel_krpmps;
	TEdit *ESpeed_krpm;
	TUpDown *UDFlag_MotorIdentified;
	TEdit *EUserErrorCode;
	TLabel *LUserErrorCode;
	TEdit *EKp_Idq;
	TLabel *LKp_Idq;
	TEdit *EKi_Idq;
	TLabel *LKi_Idq;
	TEdit *ECtrlState;
	TLabel *LCtrlState;
	TEdit *EEstState;
	TLabel *LEstState;
	TEdit *EVelCtlStatus;
	TLabel *LVelCtlStatus;
	TLabel *LFlag_Run_Identify;
	TUpDown *UDFlag_Run_Identify;
	TEdit *ERs_Ohm;
	TLabel *LRs_Ohm;
	TEdit *EMagnCurr_A;
	TLabel *LMagnCurr_A;
	TEdit *ELsd_H;
	TLabel *LLsd_H;
	TEdit *ELsq_H;
	TLabel *L;
	TEdit *EFlux_VpHz;
	TLabel *LFlux_VpHz;
	TEdit *ETorque_Nm;
	TLabel *LTorque_Nm;
	TLabel *LEST_ErrorCode;
	TEdit *EEST_ErrorCode;
	TLabel *LFlag_enableFieldWeakening;
	TUpDown *UDFlag_enableFieldWeakening;
	TLabel *LFlag_enableRsRecalc;
	TUpDown *UDFlag_enableRsRecalc;
	TLabel *Label3;
	TUpDown *UDFlag_enableForceAngle;
	TLabel *LFlag_enableOffsetcalc;
	TUpDown *UDFlag_enableOffsetcalc;
	TLabel *LFlag_enableUserParams;
	TUpDown *UDFlag_enableUserParams;
	TButton *BIDENTIFY;
	TButton *BStop1;
	TButton *BStart1;
	TButton *BGetALL;
	TEdit *EMaxAccel_krpmps;
	TEdit *ESpeedRef_krpm;
	TEdit *EFlag_enableSys;
	TEdit *EFlag_Run_Identify;
	TEdit *EFlag_MotorIdentified;
	TEdit *EFlag_enableUserParams;
	TEdit *EFlag_enableRsRecalc;
	TEdit *EFlag_enableForceAngle;
	TEdit *EFlag_enableOffsetcalc;
	TEdit *EFlag_enableFieldWeakening;
	TEdit *EDUTY1;
	TLabel *LDUTY1;
	TLabel *LPOSITION;
	TEdit *EPOSITION;
	TGroupBox *GBMain;
	TLabel *LPortNum;
	TLabel *LBaudrate;
	TButton *BStart;
	TButton *BStop;
	TComboBox *CBCOMNum;
	TComboBox *CBCOMSpeed;
	TButton *BESTOP;
	TEdit *ERunPositionProfile;
	TLabel *LRunPositionProfile;
	TUpDown *UDRunPositionProfile;
	TUpDown *UDPosStepInt_MRev;
	TLabel *LPosStepInt_MRev;
	TLabel *LPosStepFrac_MRev;
	TEdit *EPosStepFrac_MRev;
	TUpDown *UDPosStepFrac_MRev;
	TUpDown *UDMaxVel_krpm;
	TEdit *EMaxVel_krpm;
	TLabel *LMaxVel_krpm;
	TEdit *EPosStepInt_MRev;
	TEdit *Edest_pos;
	TLabel *Ldest_pos;
	TUpDown *UDdest_pos;
	TLabel *LPosCtlStatus;
	TEdit *EPosCtlStatus;
	TEdit *EPosMoveStatus;
	TLabel *LPosMoveStatus;
	TLabel *LPosMoveCurveType;
	TEdit *EPosMoveCurveType;
	TEdit *EPosMoveDone;
	TLabel *LPosMoveDone;
	TLabel *LPosCtlErrorID;
	TEdit *EPosCtlErrorID;
	TEdit *EPosMoveErrorID;
	TLabel *LPosMoveErrorID;
	TLabel *LPeriod_ms;
	TEdit *EPeriod_ms;
	TUpDown *UDPeriod_ms;
	TEdit *EPositionError_MRev;
	TLabel *LPositionError_MRev;
	TButton *BSAVE;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall BStartClick(TObject *Sender);
	void __fastcall BStopClick(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall BExtendClick(TObject *Sender);
	void __fastcall ESpeedRef_krpmChange(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall EFlag_enableSysChange(TObject *Sender);
	void __fastcall EMaxAccel_krpmpsChange(TObject *Sender);
	void __fastcall EFlag_MotorIdentifiedChange(TObject *Sender);
	void __fastcall BGetSpeed_krpmClick(TObject *Sender);
	void __fastcall BGetErorrCodeClick(TObject *Sender);
	void __fastcall BKp_IdqClick(TObject *Sender);
	void __fastcall BGetKi_IdqClick(TObject *Sender);
	void __fastcall BGetStateClick(TObject *Sender);
	void __fastcall EFlag_Run_IdentifyChange(TObject *Sender);
	void __fastcall BGetFlagsClick(TObject *Sender);
	void __fastcall BGetMotorParamsClick(TObject *Sender);
	void __fastcall EFlag_enableUserParamsChange(TObject *Sender);
	void __fastcall EFlag_enableRsRecalcChange(TObject *Sender);
	void __fastcall EFlag_enableForceAngleChange(TObject *Sender);
	void __fastcall EFlag_enableOffsetcalcChange(TObject *Sender);
	void __fastcall EFlag_enableFieldWeakeningChange(TObject *Sender);
	void __fastcall BStart1Click(TObject *Sender);
	void __fastcall BStop1Click(TObject *Sender);
	void __fastcall BIDENTIFYClick(TObject *Sender);
	void __fastcall BGetALLClick(TObject *Sender);
	void __fastcall ERunPositionProfileChange(TObject *Sender);
	void __fastcall EPosStepInt_MRevChange(TObject *Sender);
	void __fastcall EPosStepFrac_MRevChange(TObject *Sender);
	void __fastcall EMaxVel_krpmChange(TObject *Sender);
	void __fastcall EPeriod_msChange(TObject *Sender);
	void __fastcall BESTOPClick(TObject *Sender);
	void __fastcall Edest_posChange(TObject *Sender);
	void __fastcall BSAVEClick(TObject *Sender);

private:	// User declarations

	Periphery aPeriphery;
	void __fastcall UpdateComponents();


public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
    void __fastcall AddToLogMemo(String Text);

	bool ExtendedMode;
	unsigned long CS_Timer;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

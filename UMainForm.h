//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "UPeriphery.h"
#include "MChart.h"
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//#include <pngimage.hpp>
#include <Graphics.hpp>
#include "Chart.hpp"
#include "Series.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"


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
	TButton *BIDENTIFY;
	TButton *BStop1;
	TButton *BStart1;
	TButton *BGetALL;
	TGroupBox *GBMain;
	TLabel *LPortNum;
	TLabel *LBaudrate;
	TButton *BStart;
	TButton *BStop;
	TComboBox *CBCOMNum;
	TComboBox *CBCOMSpeed;
	TButton *BESTOP;
	TLabel *LPeriod_ms;
	TEdit *EPeriod_ms;
	TUpDown *UDPeriod_ms;
	TButton *BSAVE;
	TTimer *Timer2;
	TPageControl *PageControl1;
	TTabSheet *Параметры;
	TTabSheet *Графики;
	TGroupBox *GBParameters;
	TLabel *LSpeedRef_krpm;
	TLabel *LFlag_enableSys;
	TLabel *LMaxAccel_krpmps;
	TLabel *LSpeed_krpm;
	TLabel *LFlagMotorIdentified;
	TLabel *LUserErrorCode;
	TLabel *LKp_Idq;
	TLabel *LKi_Idq;
	TLabel *LCtrlState;
	TLabel *LEstState;
	TLabel *LVelCtlStatus;
	TLabel *LFlag_Run_Identify;
	TLabel *LRs_Ohm;
	TLabel *LMagnCurr_A;
	TLabel *LLsd_H;
	TLabel *L;
	TLabel *LFlux_VpHz;
	TLabel *LTorque_Nm;
	TLabel *LEST_ErrorCode;
	TLabel *LFlag_enableFieldWeakening;
	TLabel *LFlag_enableRsRecalc;
	TLabel *Label3;
	TLabel *LFlag_enableOffsetcalc;
	TLabel *LFlag_enableUserParams;
	TLabel *LDUTY1;
	TLabel *LPOSITION;
	TLabel *LRunPositionProfile;
	TLabel *LPosStepInt_MRev;
	TLabel *LPosStepFrac_MRev;
	TLabel *LMaxVel_krpm;
	TLabel *Ldest_pos;
	TLabel *LPosCtlStatus;
	TLabel *LPosMoveStatus;
	TLabel *LPosMoveCurveType;
	TLabel *LPosMoveDone;
	TLabel *LPosCtlErrorID;
	TLabel *LPosMoveErrorID;
	TLabel *LPositionError_MRev;
	TUpDown *UDSpeedRef_krpm;
	TUpDown *UDFlag_enableSys;
	TUpDown *UDMaxAccel_krpmps;
	TEdit *ESpeed_krpm;
	TUpDown *UDFlag_MotorIdentified;
	TEdit *EUserErrorCode;
	TEdit *EKp_Idq;
	TEdit *EKi_Idq;
	TEdit *ECtrlState;
	TEdit *EEstState;
	TEdit *EVelCtlStatus;
	TUpDown *UDFlag_Run_Identify;
	TEdit *ERs_Ohm;
	TEdit *EMagnCurr_A;
	TEdit *ELsd_H;
	TEdit *ELsq_H;
	TEdit *EFlux_VpHz;
	TEdit *ETorque_Nm;
	TEdit *EEST_ErrorCode;
	TUpDown *UDFlag_enableFieldWeakening;
	TUpDown *UDFlag_enableRsRecalc;
	TUpDown *UDFlag_enableForceAngle;
	TUpDown *UDFlag_enableOffsetcalc;
	TUpDown *UDFlag_enableUserParams;
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
	TEdit *EPOSITION;
	TEdit *ERunPositionProfile;
	TUpDown *UDRunPositionProfile;
	TUpDown *UDPosStepInt_MRev;
	TEdit *EPosStepFrac_MRev;
	TUpDown *UDPosStepFrac_MRev;
	TUpDown *UDMaxVel_krpm;
	TEdit *EMaxVel_krpm;
	TEdit *EPosStepInt_MRev;
	TEdit *Edest_pos;
	TUpDown *UDdest_pos;
	TEdit *EPosCtlStatus;
	TEdit *EPosMoveStatus;
	TEdit *EPosMoveCurveType;
	TEdit *EPosMoveDone;
	TEdit *EPosCtlErrorID;
	TEdit *EPosMoveErrorID;
	TEdit *EPositionError_MRev;
	TChart *Chart;
	TImage *i1;
	TImage *i2;
	TLabel *Label1;
	TComboBox *cb1;
	TButton *BChartClear;
	TCheckBox *cbEnableChart;
	TComboBox *cb2;
	TEdit *EPeriod2_ms;
	TUpDown *UDPeriod2_ms;
	TImage *i3;
	TComboBox *cb3;
	TEdit *ed00;
	TEdit *ed01;
	TEdit *ed02;
	TEdit *ed10;
	TEdit *ed11;
	TEdit *ed12;
	TEdit *ed20;
	TEdit *ed21;
	TEdit *ed22;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
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
	void __fastcall BChartClearClick(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall EPeriod2_msChange(TObject *Sender);


private:	// User declarations

	Periphery aPeriphery;
	void __fastcall UpdateComponents();
	MChart aChart;


public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
	void __fastcall AddToLogMemo(String Text);

	long mytime;

	bool ExtendedMode;
	unsigned long CS_Timer;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

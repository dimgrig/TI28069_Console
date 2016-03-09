//---------------------------------------------------------------------------

#ifndef UPeripheryH
#define UPeripheryH

#include "URSMaster.h"
#include <vector>

class Periphery
{
  private:

  public:
	RSMaster aRSMaster;
	bool Running;

	std::vector<BYTE> LastPaket;



  	Periphery(){};  //конструктор

	//Функции соединения с RS-232
    bool TurnOn(int COM_num, int speed);
    void TurnOff();
	bool Run();
	int DispatchPaket( std::vector<BYTE> paket);

   //Методы доступа

    std::vector<BYTE> GetLastPaket(){return LastPaket;};

   	bool IsRunning() {return Running;};
};

char* EST_State[] =
{
  "Error",            //!< error
  "Idle",		        //!< idle
  "RoverL",             //!< R/L estimation
  "Rs",                 //!< Rs estimation state
  "RampUp",             //!< ramp up the speed
  "IdRated",            //!< control Id and estimate the rated flux
  "RatedFlux_OL",       //!< estimate the open loop rated flux
  "RatedFlux",          //!< estimate the rated flux
  "RampDown",           //!< ramp down the speed
  "LockRotor",          //!< lock the rotor
  "Ls",                 //!< stator inductance estimation state
  "Rr",                 //!< rotor resistance estimation state
  "MotorIdentified",    //!< motor identified state
  "OnLine"             //!< online parameter estimation
} ;

char* CTRL_State[] =
{
  "Error",           //!< the controller error state
  "Idle",              //!< the controller idle state
  "OffLine",           //!< the controller offline state
  "OnLine"            //!< the controller online state
};

char* VEL_State[] =
{
  "Idle",	//!< ST_CTL in idle state
  "Init",		//!< ST_CTL in init state
  "Conf",		//!< ST_CTL in conf state
  "Busy"		//!< ST_CTL in busy state
};

char* USER_ErrorCode[] =
{
"NoError",//=0,                           //!< no error error code
"qFullScaleCurrent_A_High",//=1,         //!< iqFullScaleCurrent_A too high error code
"iqFullScaleCurrent_A_Low",//=2,          //!< iqFullScaleCurrent_A too low error code
"iqFullScaleVoltage_V_High",//=3,         //!< iqFullScaleVoltage_V too high error code
"iqFullScaleVoltage_V_Low",//=4,          //!< iqFullScaleVoltage_V too low error code
"iqFullScaleFreq_Hz_High",//=5,           //!< iqFullScaleFreq_Hz too high error code
"iqFullScaleFreq_Hz_Low",//=6,            //!< iqFullScaleFreq_Hz too low error code
"numPwmTicksPerIsrTick_High",//=7,        //!< numPwmTicksPerIsrTick too high error code
"numPwmTicksPerIsrTick_Low",//=8,         //!< numPwmTicksPerIsrTick too low error code
"numIsrTicksPerCtrlTick_High",//=9,       //!< numIsrTicksPerCtrlTick too high error code
"numIsrTicksPerCtrlTick_Low",//=10,       //!< numIsrTicksPerCtrlTick too low error code
"numCtrlTicksPerCurrentTick_High",//=11,  //!< numCtrlTicksPerCurrentTick too high error code
"numCtrlTicksPerCurrentTick_Low",//=12,   //!< numCtrlTicksPerCurrentTick too low error code
"numCtrlTicksPerEstTick_High",//=13,      //!< numCtrlTicksPerEstTick too high error code
"numCtrlTicksPerEstTick_Low",//=14,       //!< numCtrlTicksPerEstTick too low error code
"numCtrlTicksPerSpeedTick_High",//=15,    //!< numCtrlTicksPerSpeedTick too high error code
"numCtrlTicksPerSpeedTick_Low",//=16,     //!< numCtrlTicksPerSpeedTick too low error code
"numCtrlTicksPerTrajTick_High",//=17,     //!< numCtrlTicksPerTrajTick too high error code
"numCtrlTicksPerTrajTick_Low",//=18,      //!< numCtrlTicksPerTrajTick too low error code
"numCurrentSensors_High",//=19,           //!< numCurrentSensors too high error code
"numCurrentSensors_Low",//=20,            //!< numCurrentSensors too low error code
"numVoltageSensors_High",//=21,           //!< numVoltageSensors too high error code
"numVoltageSensors_Low",//=22,            //!< numVoltageSensors too low error code
"offsetPole_rps_High",//=23,              //!< offsetPole_rps too high error code
"offsetPole_rps_Low",//=24,               //!< offsetPole_rps too low error code
"fluxPole_rps_High",//=25,                //!< fluxPole_rps too high error code
"fluxPole_rps_Low",//=26,                 //!< fluxPole_rps too low error code
"zeroSpeedLimit_High",//=27,              //!< zeroSpeedLimit too high error code
"zeroSpeedLimit_Low",//=28,               //!< zeroSpeedLimit too low error code
"forceAngleFreq_Hz_High",//=29,           //!< forceAngleFreq_Hz too high error code
"forceAngleFreq_Hz_Low",//=30,            //!< forceAngleFreq_Hz too low error code
"maxAccel_Hzps_High",//=31,               //!< maxAccel_Hzps too high error code
"maxAccel_Hzps_Low",//=32,                //!< maxAccel_Hzps too low error code
"maxAccel_est_Hzps_High",//=33,           //!< maxAccel_est_Hzps too high error code
"maxAccel_est_Hzps_Low",//=34,            //!< maxAccel_est_Hzps too low error code
"directionPole_rps_High",//=35,           //!< directionPole_rps too high error code
"directionPole_rps_Low",//=36,            //!< directionPole_rps too low error code
"speedPole_rps_High",//=37,               //!< speedPole_rps too high error code
"speedPole_rps_Low",//=38,                //!< speedPole_rps too low error code
"dcBusPole_rps_High",//=39,               //!< dcBusPole_rps too high error code
"dcBusPole_rps_Low",//=40,                //!< dcBusPole_rps too low error code
"fluxFraction_High",//=41,                //!< fluxFraction too high error code
"fluxFraction_Low",//=42,                 //!< fluxFraction too low error code
"indEst_speedMaxFraction_High",//=43,     //!< indEst_speedMaxFraction too high error code
"indEst_speedMaxFraction_Low",//=44,      //!< indEst_speedMaxFraction too low error code
"powerWarpGain_High",//=45,               //!< powerWarpGain too high error code
"powerWarpGain_Low",//=46,                //!< powerWarpGain too low error code
"systemFreq_MHz_High",//=47,              //!< systemFreq_MHz too high error code
"systemFreq_MHz_Low",//=48,               //!< systemFreq_MHz too low error code
"pwmFreq_kHz_High",//=49,                 //!< pwmFreq_kHz too high error code
"pwmFreq_kHz_Low",//=50,                  //!< pwmFreq_kHz too low error code
"voltage_sf_High",//=51,                  //!< voltage_sf too high error code
"voltage_sf_Low",//=52,                   //!< voltage_sf too low error code
"current_sf_High",//=53,                  //!< current_sf too high error code
"current_sf_Low",//=54,                   //!< current_sf too low error code
"voltageFilterPole_Hz_High",//=55,        //!< voltageFilterPole_Hz too high error code
"voltageFilterPole_Hz_Low",//=56,         //!< voltageFilterPole_Hz too low error code
"maxVsMag_pu_High",//=57,                 //!< maxVsMag_pu too high error code
"maxVsMag_pu_Low",//=58,                  //!< maxVsMag_pu too low error code
"estKappa_High",//=59,                    //!< estKappa too high error code
"estKappa_Low",//=60,                     //!< estKappa too low error code
"motor_type_Unknown",//61,               //!< motor type unknown error code
"motor_numPolePairs_High",//=62,          //!< motor_numPolePairs too high error code
"motor_numPolePairs_Low",//=63,           //!< motor_numPolePairs too low error code
"motor_ratedFlux_High",//=64,             //!< motor_ratedFlux too high error code
"motor_ratedFlux_Low",//=65,              //!< motor_ratedFlux too low error code
"motor_Rr_High",//=66,                    //!< motor_Rr too high error code
"motor_Rr_Low",//=67,                     //!< motor_Rr too low error code
"motor_Rs_High",//=68,                    //!< motor_Rs too high error code
"motor_Rs_Low",//=69,                     //!< motor_Rs too low error code
"motor_Ls_d_High",//=70,                  //!< motor_Ls_d too high error code
"motor_Ls_d_Low",//=71,                   //!< motor_Ls_d too low error code
"motor_Ls_q_High",//=72,                  //!< motor_Ls_q too high error code
"motor_Ls_q_Low",//=73,                   //!< motor_Ls_q too low error code
"maxCurrent_High",//=74,                  //!< maxCurrent too high error code
"maxCurrent_Low",//=75,                   //!< maxCurrent too low error code
"maxCurrent_resEst_High",//=76,           //!< maxCurrent_resEst too high error code
"maxCurrent_resEst_Low",//=77,            //!< maxCurrent_resEst too low error code
"maxCurrent_indEst_High",//=78,           //!< maxCurrent_indEst too high error code
"maxCurrent_indEst_Low",//=79,            //!< maxCurrent_indEst too low error code
"maxCurrentSlope_High",//=80,             //!< maxCurrentSlope too high error code
"maxCurrentSlope_Low",//=81,              //!< maxCurrentSlope too low error code
"maxCurrentSlope_powerWarp_High",//=82,   //!< maxCurrentSlope_powerWarp too high error code
"maxCurrentSlope_powerWarp_Low",//=83,    //!< maxCurrentSlope_powerWarp too low error code
"IdRated_High",//=84,                     //!< IdRated too high error code
"IdRated_Low",//=85,                      //!< IdRated too low error code
"IdRatedFraction_indEst_High",//=86,      //!< IdRatedFraction_indEst too high error code
"IdRatedFraction_indEst_Low",//=87,       //!< IdRatedFraction_indEst too low error code
"IdRatedFraction_ratedFlux_High",//=88,   //!< IdRatedFraction_ratedFlux too high error code
"IdRatedFraction_ratedFlux_Low",//=89,    //!< IdRatedFraction_ratedFlux too low error code
"IdRated_delta_High",//=90,               //!< IdRated_delta too high error code
"IdRated_delta_Low",//=91,                //!< IdRated_delta too low error code
"fluxEstFreq_Hz_High",//=92,              //!< fluxEstFreq_Hz too high error code
"fluxEstFreq_Hz_Low",//=93,               //!< fluxEstFreq_Hz too low error code
"ctrlFreq_Hz_High",//=94,                 //!< ctrlFreq_Hz too high error code
"ctrlFreq_Hz_Low",//=95,                  //!< ctrlFreq_Hz too low error code
"estFreq_Hz_High",//=96,                  //!< estFreq_Hz too high error code
"estFreq_Hz_Low",//=97,                   //!< estFreq_Hz too low error code
"RoverL_estFreq_Hz_High",//=98,           //!< RoverL_estFreq_Hz too high error code
"RoverL_estFreq_Hz_Low",//=99,            //!< RoverL_estFreq_Hz too low error code
"trajFreq_Hz_High",//=100,                //!< trajFreq_Hz too high error code
"rajFreq_Hz_Low",//=101,                 //!< trajFreq_Hz too low error code
"ctrlPeriod_sec_High",//=102,             //!< ctrlPeriod_sec too high error code
"ctrlPeriod_sec_Low",//=103,              //!< ctrlPeriod_sec too low error code
"maxNegativeIdCurrent_a_High",//=104,     //!< maxNegativeIdCurrent_a too high error code
"maxNegativeIdCurrent_a_Low"//=105,      //!< maxNegativeIdCurrent_a too low error code
};

char* EST_ErrorCode[] =
{
  "NoError",               //!< no error error code
  "Flux_OL_ShiftOverFlow",   //!< flux open loop shift overflow error code
  "FluxError",               //!< flux estimator error code
  "Dir_ShiftOverFlow",       //!< direction shift overflow error code
  "Ind_ShiftOverFlow"       //!< inductance shift overflow error code
};


char* ST_CtlStatus[] =
{
  "IDLE",	//!< ST_CTL in idle state
  "INIT",		//!< ST_CTL in init state
  "CONF",		//!< ST_CTL in conf state
  "BUSY"		//!< ST_CTL in busy state
};

char* ST_MoveStatus[] =
{
  "IDLE",	//!< Move is in idle state, holding position
  "INIT",		//!< Move is in init state, validating configured parameters
  "CONF",		//!< Move is in conf state, determining the curves
  "BUSY",		//!< Move is in busy state, providing the curves
  "HALT"		//!< Move is in busy state, ramping velocity to zero
};

char*  ST_MoveCurveType[] =
{
  "TRAP",	//!< Trapezoidal curve
  "SCRV",		//!< S-Curve
  "SSTCRV"		//!< ST-Curve
};
//---------------------------------------------------------------------------
#endif

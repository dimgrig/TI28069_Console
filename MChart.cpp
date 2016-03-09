//---------------------------------------------------------------------------


#pragma hdrstop

#include "MChart.h"
#include "UConstants.h"
#include "UMainForm.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

using namespace std;

TColor cl[8] = {clBlue, clRed, clGreen, clPurple, clYellow, clGray, clBlack, clAqua};

MChart::MChart()
{
	//MainForm->Chart->ClearChart();

	for (int i = 0; i < MainForm->Chart->SeriesCount(); i++)
	{
		MainForm->Chart->Series[i]->Clear();
	}

	MainForm->i1->Canvas->Brush->Color = cl[0];
	MainForm->i1->Canvas->Brush->Style=bsSolid;
	MainForm->i1->Canvas->FillRect(TRect(0,0,MainForm->i1->Width-1,MainForm->i1->Height-1));

	MainForm->i2->Canvas->Brush->Color = cl[1];
	MainForm->i2->Canvas->Brush->Style=bsSolid;
	MainForm->i2->Canvas->FillRect(TRect(0,0,MainForm->i2->Width-1,MainForm->i2->Height-1));


	TLineSeries  *Series1 = new TLineSeries(MainForm->Chart);
	TLineSeries  *Series2 = new TLineSeries(MainForm->Chart);
	//Series->Clear();
	MainForm->Chart->AddSeries(Series1);
	MainForm->Chart->AddSeries(Series2);
}

int cbtoarr(int index)
{
	int a;
	switch (index)
	{
	case 1:
		a = StrToInt(MainForm->ESpeedRef_krpm->Text);
	break;
	case 2:
		a = StrToInt(MainForm->ESpeed_krpm->Text);
	break;
	default:
		a = 0;
	}

	return a;
}

bool MChart::Run()
{
	int YValue[8];

	YValue[0] = cbtoarr(MainForm->cb1->ItemIndex);
	YValue[1] = cbtoarr(MainForm->cb2->ItemIndex);

	int i = 0;
	for (i = 0; i < MainForm->Chart->SeriesCount(); i++)
	{
			MainForm->Chart->Series[i]->AddXY(MainForm->mytime, YValue[i], "", cl[i]);
			//MainForm->Chart->Series[1]->AddXY(MainForm->mytime, StrToInt(MainForm->ESpeed_krpm->Text), "", MainForm->i2->Canvas->Brush->Color);
	}
	return true;
}





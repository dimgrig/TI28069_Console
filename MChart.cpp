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

	MainForm->i3->Canvas->Brush->Color = cl[2];
	MainForm->i3->Canvas->Brush->Style=bsSolid;
	MainForm->i3->Canvas->FillRect(TRect(0,0,MainForm->i3->Width-1,MainForm->i3->Height-1));


	TLineSeries  *Series1 = new TLineSeries(MainForm->Chart);
	TLineSeries  *Series2 = new TLineSeries(MainForm->Chart);
	TLineSeries  *Series3 = new TLineSeries(MainForm->Chart);
	//Series->Clear();
	MainForm->Chart->AddSeries(Series1);
	MainForm->Chart->AddSeries(Series2);
	MainForm->Chart->AddSeries(Series3);
}

int cbtoarr(int index)
{
	int a;
	switch (index)
	{
	case 0:
		a = NULL;
	break;
	case 1:
		a = StrToInt(MainForm->ESpeedRef_krpm->Text);
	break;
	case 2:
		a = StrToInt(MainForm->ESpeed_krpm->Text);
	break;
	case 3:
		a = StrToInt(MainForm->EMaxAccel_krpmps->Text);
	break;
	default:
		a = 0;
	}

	return a;
}

bool MChart::Run()
{
	int cb[3];
	int ed[3][3];
	cb[0] = MainForm->cb1->ItemIndex;
	cb[1] = MainForm->cb2->ItemIndex;
	cb[2] = MainForm->cb3->ItemIndex;

	int i = 0;
	for (i = 0; i < MainForm->Chart->SeriesCount(); i++)
	{
			if (cb[i] != 0)
			{
				MainForm->Chart->Series[i]->AddXY(MainForm->mytime, cbtoarr(cb[i]), "", cl[i]);
			}

			ed[i][2] = MainForm->Chart->Series[i]->MaxYValue();
			ed[i][1] = MainForm->Chart->Series[i]->MinYValue();
			ed[i][0] = cbtoarr(cb[i]);
			//MainForm->Chart->Series[1]->AddXY(MainForm->mytime, StrToInt(MainForm->ESpeed_krpm->Text), "", MainForm->i2->Canvas->Brush->Color);
	}

	MainForm->ed00->Text = IntToStr(ed[0][0]);
	MainForm->ed01->Text = IntToStr(ed[0][1]);
	MainForm->ed02->Text = IntToStr(ed[0][2]);
	MainForm->ed10->Text = IntToStr(ed[1][0]);
	MainForm->ed11->Text = IntToStr(ed[1][1]);
	MainForm->ed12->Text = IntToStr(ed[1][2]);
	MainForm->ed20->Text = IntToStr(ed[2][0]);
	MainForm->ed21->Text = IntToStr(ed[2][1]);
	MainForm->ed22->Text = IntToStr(ed[2][2]);
	return true;
}





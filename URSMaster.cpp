//---------------------------------------------------------------------------


#pragma hdrstop

#include "URSMaster.h"
#include <vcl.h>
#include "UConstants.h"

#include "UMainForm.h"

RSMaster::RSMaster()
{
    hSerial = NULL;
    BytesWrittenLastTime = 0;
    Online = false;
    DataBufer.clear();
    MessageBufer.clear();
}

bool RSMaster::RSInit(int COM_num, int COM_speed)
{
  LPCTSTR sPortName;
  switch(COM_num)
  {
      case(1):
      sPortName = L"\\\\.\\COM1";
      break;
      case(2):
      sPortName = L"\\\\.\\COM2";
      break;
      case(3):
      sPortName = L"\\\\.\\COM3";
      break;
      case(4):
      sPortName = L"\\\\.\\COM4";
      break;
      case(5):
      sPortName = L"\\\\.\\COM5";
      break;
      case(6):
      sPortName = L"\\\\.\\COM6";
      break;
      case(7):
      sPortName = L"\\\\.\\COM7";
      break;
      case(8):
      sPortName = L"\\\\.\\COM8";
      break;
      case(9):
      sPortName = L"\\\\.\\COM9";
      break;
      case(10):
      sPortName = L"\\\\.\\COM10";
      break;
      case(11):
      sPortName = L"\\\\.\\COM11";
      break;
      case(12):
      sPortName = L"\\\\.\\COM12";
      break;
      case(13):
      sPortName = L"\\\\.\\COM13";
      break;
      case(14):
      sPortName = L"\\\\.\\COM14";
      break;
      case(15):
      sPortName = L"\\\\.\\COM15";
      break;
      case(16):
      sPortName = L"\\\\.\\COM16";
      break;
      case(17):
      sPortName = L"\\\\.\\COM17";
      break;
      case(18):
      sPortName = L"\\\\.\\COM18";
      break;
      case(19):
      sPortName = L"\\\\.\\COM19";
      break;
      case(20):
      sPortName = L"\\\\.\\COM20";
      break;
      default:
      sPortName = L"\\\\.\\\COM1";
  }

  hSerial = CreateFile(sPortName,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,0, NULL);
  if(hSerial==INVALID_HANDLE_VALUE)
	{
		Application->MessageBoxW(L"���� �� ���������� ��� ��� ������",
			L"������ �������� COM �����", MB_OK|MB_ICONEXCLAMATION);
    return false;
	}

  COMMTIMEOUTS ct;
  ct.ReadIntervalTimeout=10;
	ct.ReadTotalTimeoutMultiplier=ct.ReadTotalTimeoutConstant=10;
	ct.WriteTotalTimeoutMultiplier=ct.WriteTotalTimeoutConstant=10;

  SetCommTimeouts(hSerial,&ct);

  DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams))
	{
		Application->MessageBoxW(L"�� ������� ��������� ��������� COM �����",
			L"������ COM �����", MB_OK|MB_ICONEXCLAMATION);
    return false;
	}

  switch(COM_speed)
  {
      case(110):
      dcbSerialParams.BaudRate=CBR_110;
      break;
      case(300):
      dcbSerialParams.BaudRate=CBR_300;
      break;
      case(600):
      dcbSerialParams.BaudRate=CBR_600;
      break;
      case(1200):
      dcbSerialParams.BaudRate=CBR_1200;
      break;
      case(2400):
     	dcbSerialParams.BaudRate=CBR_2400;
      break;
      case(4800):
      dcbSerialParams.BaudRate=CBR_4800;
      break;
      case(9600):
      dcbSerialParams.BaudRate=CBR_9600;
      break;
      case(14400):
      dcbSerialParams.BaudRate=CBR_14400;
      break;
      case(19200):
      dcbSerialParams.BaudRate=CBR_19200;
      break;
      case(38400):
      dcbSerialParams.BaudRate=CBR_38400;
      break;
      case(56000):
      dcbSerialParams.BaudRate=CBR_56000;
      break;
      case(57600):
      dcbSerialParams.BaudRate=CBR_57600;
      break;
      case(115200):
      dcbSerialParams.BaudRate=CBR_115200;
      break;
      default:
      dcbSerialParams.BaudRate=CBR_57600;
      break;
	}
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=ONESTOPBIT;
	dcbSerialParams.Parity=NOPARITY;
	if(!SetCommState(hSerial, &dcbSerialParams))
	{
		Application->MessageBoxW(L"�� ��������� COM ����",
			L"������ COM �����", MB_OK|MB_ICONEXCLAMATION);
    return false;
	}

  Online = true;
	return true;
}

void RSMaster::RSClose()
{
	CloseHandle(hSerial);
  Online = false;
}

bool RSMaster::RSSend( std::vector<BYTE> data)
{
  DWORD dwSize = data.size();   // ������ ������-�������
  BYTE* conv_data = new BYTE[dwSize];
  for(unsigned int i = 0; i<dwSize; i++)
  {
      conv_data[i] = data[i];
  }
	DWORD dwBytesWritten;    // ��� ����� ���������� ���������� ���������� ����
  BOOL iRet = WriteFile (hSerial,conv_data,dwSize,&dwBytesWritten,NULL);
  BytesWrittenLastTime = dwBytesWritten;
  delete[] conv_data;
  return iRet;
}

bool RSMaster::RSProcess( std::vector<BYTE> &paket)
{
//�������������� ������ ����������
bool ret = false;
bool FoundMessage1 = false;
bool FoundMessage2 = false;
bool FoundMessage = false;
int Start_Of_Message = 0;
int End_Of_Message = 0;
unsigned int How_Much_To_Count;

//��� 1 - ��������� ������ �� RS-485 (���� ����) � ��������� ������

   std::vector<BYTE> RSData;
  DWORD iSize;
  BYTE sReceivedChar;

  int one_time_count = 0;

  while(1)
  {
  	ReadFile(hSerial, &sReceivedChar, 1, &iSize, 0);  // �������� 1 ����
    if (iSize > 0)   // ���� ���-�� �������, �������
  	{
  		RSData.push_back(sReceivedChar);
        one_time_count++;
    }
    else break;
    if (one_time_count >= ONE_TIME_LIMIT)
    {
    /*    MainForm->Timer->Enabled = false;

		Application->MessageBoxW(L"�������� �� �������� ������������ �������",
			L"��������� ������", MB_OK|MB_ICONERROR);

        exit(1);    */
        //MainForm->StatusBar->SimpleText = "�������� �� �������� ������������ �������";
        break;
    }
  }

//��� 2 - ���� ��� �� ��������� - ��������� ��������� ��������� ������ � �����
//������� ����� ������, ��� ���������� ���������

  if (RSData.size() > 0)
  {
    for(unsigned int i=0; i<RSData.size(); i++)
	{
    	DataBufer.push_back(RSData[i]);
    }
  }

//��� 3 - ���� � ������ ��� �� ����, �� ���������� �� ������ � �������
//��������� ��������� - ��� ���������� ������ START_BYTE � ������������� ������ END_BYTE

//��� 3.1 - ������ ��������� �� ��������� 32 �����, ������� ���������� �� ����� ������ �� ����� ������ - ���������� �������� ���� �� ������ 32 ������,
//����, ���� ������ ������ ������ 32 ����, �� ���� ��� ����
  if(DataBufer.size()>0)
  {
    if(DataBufer.size()>32)
    {
      How_Much_To_Count = 32;
    }
    else
	{
    	How_Much_To_Count = DataBufer.size();
	}

	for(unsigned int i=0; i<How_Much_To_Count; i++)
    {
    	if(DataBufer[i] == START_BYTE) //����� ���������� �����
	  {
        FoundMessage1 = true;
        Start_Of_Message = i;
        break;
      }
    }

	if(FoundMessage1 == true) //����� ��������� ����� ���������� ������ ���� ������ ��������� ����
    {
    	for(unsigned int i=0; i<How_Much_To_Count; i++)
    	{
    		if(DataBufer[i] == END_BYTE) //����� ��������� �����
      	{
        	FoundMessage2 = true;
          End_Of_Message = i;
          break;
      	}
    	}
    }

    //���� ���� ����������, ���� ������� ������� ����� ������ � ����� ���������
    FoundMessage = FoundMessage1 && FoundMessage2 && (End_Of_Message > Start_Of_Message);

    //��� 3.2 - ���� �� ������ ��������� ���� ���������, �� ������������ ������
    //�� �������� ��������� - ������� �� �� ������ ������

    if(FoundMessage1 == false)
    {
        //���� �� ����������� �� ����� ������, �� ����� ������ �������� ��� ������
		if(How_Much_To_Count == DataBufer.size())
        {
			RSMaster::RSspecmsg(DataBufer);

			DataBufer.clear();

			//��� ��� ��������� �������� ����, ���������� ������ ���������� � ��������� ������
      			//���������� ���������, ������� �������� �� ��������� �� ��������� ��������
      			FoundMessage = false;
        }
        else
        {
            for(unsigned int i=0; i<DataBufer.size() - How_Much_To_Count; i++)
			{
				RSMaster::RSspecmsg(DataBufer);

				//������� �� ������ ������ ������ ���������� ����
				DataBufer.erase(DataBufer.begin());

			}

            //��� ��� ��������� �������� ����, ���������� ������ ���������� � ��������� ������
            //���������� ���������, ������� �������� �� ��������� �� ��������� ��������
            FoundMessage = false;
        }
    }
  }


//��� 4 - �������������� ��������� ������ � ������
 	if (DataBufer.size() > 0)
  {
  	//��� 4.1 - �������� ���� ������ � ������ �� ������� ���������� �����, ��� ��� ����� �� �����
    if(FoundMessage1 == true && Start_Of_Message > 0)
    {


		//RSMaster::RSspecmsg(buffer);
			String Text = "";

         	for(int i=0; i<Start_Of_Message; i++)
	  {
		 Text += (char)(DataBufer[i]);
	  }

		MainForm->MLog->Lines->Add(Text);

		for(int i=0; i<Start_Of_Message; i++)
	  {

		//������� �� ������ ������ ������ ���������� ����
		DataBufer.erase(DataBufer.begin());

	  }

	  //��� ��� ��������� �������� ����, ���������� ������ ���������� � ��������� ������
	  //���������� ���������, ������� �������� �� ��������� �� ��������� ��������
	  FoundMessage = false;
	}

	//��� 4.2 - ���� ������ ������ ������ 32, � ���� ���������(��) ����(�), �� ��� �� ������
		//��������� �����, �� ��� ��������� ��������, ������� ������� �����
	if (FoundMessage1 == true && FoundMessage2 == false && DataBufer.size() > 32)
   	{
		//RSMaster::RSspecmsg(DataBufer);

		DataBufer.clear();

      //��� ��� ��������� �������� ����, ���������� ������ ���������� � ��������� ������
      //���������� ���������, ������� �������� �� ��������� �� ��������� ��������
      FoundMessage = false;
	}
  }

//��� 5 - ���� ��������� �������, ��������� ����������� ��� � ����� �������� ���������
	if(FoundMessage == true)
  {
  	 std::vector<BYTE> aMessage;  //��������� ������ � �������������� ����������
	for(int i = Start_Of_Message; i<End_Of_Message+1; i++)
    {
        aMessage.push_back(DataBufer[i]);
    }
    MessageBufer.push_back(aMessage);  //���������� ������ � ���������� � ������ ��������� (������� ������)

    //������ ��������� ������� ������ �� �������� ������,
    //������� ����� ��� ����� �� ������ ������ �� ����� ��������� ���������
    for(int i = 0; i<End_Of_Message+1; i++)
    {
     	//������� �� ������ ������ ������ ���������� ����
      DataBufer.erase(DataBufer.begin());
    }
  }

//��� 6 - ���� � ������ �������� ��������� ���� ��������� - ����� ������� ������ �� ��� �� �������
// � ������� �� ������

  if (MessageBufer.size() > 0)
  {
      ret = true;
      paket = MessageBufer[0];
      MessageBufer.erase(MessageBufer.begin());
  }
  else
  {
      ret = false;
  }

/*  /////////////���������� ���/////////////////////////////////////////////////////////////////

  String Text;
  Text += "MessageBufer["+IntToStr((int)MessageBufer.size())+"]:";
  Text+="\r\n";
  if(MessageBufer.size()>0)
  {
  	for(unsigned int i=0; i<MessageBufer.size();i++)
  	{
    	Text+="[" + IntToStr((int)i)+"] : ";
      for(unsigned int j=0; j<MessageBufer[i].size();j++)
      {
      	Text+= IntToStr((int)MessageBufer[i][j]) + "; ";
      }
      Text+= "\r\n";
  	}
  }
  Text+="\r\n";

  Text += "DataBufer["+IntToStr((int)DataBufer.size())+"]:";
  Text+="\r\n";

  if(DataBufer.size()>0)
  {
  	for(unsigned int i=0; i<DataBufer.size();i++)
  	{
			Text+= IntToStr((int)DataBufer[i]) + "; ";
    }
  }

  MainForm->Memo1->Text = Text;

  ////////////////////////////////////////////////////////////////////////////// */

  return ret;

}


//---------------------------------------------------------------------------

BYTE RSMaster::RSAsciiToInt(BYTE data)
{
	BYTE data_out;
	switch (data)
	{
	case 0x30:
		data_out = 0x00;
	break;
	case 0x31:
		data_out = 0x01;
	break;
	case 0x32:
		data_out = 0x02;
	break;
	case 0x33:
		data_out = 0x03;
	break;
	case 0x34:
		data_out = 0x04;
	break;
	case 0x35:
		data_out = 0x05;
	break;
	case 0x36:
		data_out = 0x06;
	break;
	case 0x37:
		data_out = 0x07;
	break;
	case 0x38:
		data_out = 0x08;
	break;
	case 0x39:
		data_out = 0x09;
	break;
	case 0x41:
		data_out = 0x0A;
	break;
	case 0x42:
		data_out = 0x0B;
	break;
	case 0x43:
		data_out = 0x0C;
	break;
	case 0x44:
		data_out = 0x0D;
	break;
	case 0x45:
		data_out = 0x0E;
	break;
	case 0x46:
		data_out = 0x0F;
	break;
	default:
		data_out = 0x00;
	}
  return data_out;
}

void RSMaster::RSspecmsg( std::vector<BYTE>  data)
{
	String Text;
	for (int i = 0; i < data.size(); i++)
	Text += (char)(data[i]);
	MainForm->MLog->Lines->Add(Text);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)

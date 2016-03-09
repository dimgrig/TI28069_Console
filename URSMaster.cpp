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
		Application->MessageBoxW(L"Порт не существует или уже открыт",
			L"Ошибка открытия COM порта", MB_OK|MB_ICONEXCLAMATION);
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
		Application->MessageBoxW(L"Не удается запросить состояние COM порта",
			L"Ошибка COM порта", MB_OK|MB_ICONEXCLAMATION);
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
		Application->MessageBoxW(L"Не настроить COM порт",
			L"Ошибка COM порта", MB_OK|MB_ICONEXCLAMATION);
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
  DWORD dwSize = data.size();   // размер вектор-массива
  BYTE* conv_data = new BYTE[dwSize];
  for(unsigned int i = 0; i<dwSize; i++)
  {
      conv_data[i] = data[i];
  }
	DWORD dwBytesWritten;    // тут будет количество собственно переданных байт
  BOOL iRet = WriteFile (hSerial,conv_data,dwSize,&dwBytesWritten,NULL);
  BytesWrittenLastTime = dwBytesWritten;
  delete[] conv_data;
  return iRet;
}

bool RSMaster::RSProcess( std::vector<BYTE> &paket)
{
//инициализируем нужные переменные
bool ret = false;
bool FoundMessage1 = false;
bool FoundMessage2 = false;
bool FoundMessage = false;
int Start_Of_Message = 0;
int End_Of_Message = 0;
unsigned int How_Much_To_Count;

//шаг 1 - считываем данные из RS-485 (если есть) в маленький массив

   std::vector<BYTE> RSData;
  DWORD iSize;
  BYTE sReceivedChar;

  int one_time_count = 0;

  while(1)
  {
  	ReadFile(hSerial, &sReceivedChar, 1, &iSize, 0);  // получаем 1 байт
    if (iSize > 0)   // если что-то принято, выводим
  	{
  		RSData.push_back(sReceivedChar);
        one_time_count++;
    }
    else break;
    if (one_time_count >= ONE_TIME_LIMIT)
    {
    /*    MainForm->Timer->Enabled = false;

		Application->MessageBoxW(L"Имитатор не успевает обрабатывать запросы",
			L"Фатальная ошибка", MB_OK|MB_ICONERROR);

        exit(1);    */
        //MainForm->StatusBar->SimpleText = "Имитатор не успевает обрабатывать запросы";
        break;
    }
  }

//шаг 2 - если что то считалось - требуется перенести считанные данные в общий
//большой буфер данных, для дальнейшей обработки

  if (RSData.size() > 0)
  {
    for(unsigned int i=0; i<RSData.size(); i++)
	{
    	DataBufer.push_back(RSData[i]);
    }
  }

//шаг 3 - если в буфере что то есть, то проходимся по буферу в поисках
//полезного сообщения - оно начинается байтом START_BYTE и заканчивается байтом END_BYTE

//шаг 3.1 - размер сообщения не превышает 32 байта, поэтому проходится по всему буферу не имеет смысла - достаточно пройтись либо по первым 32 байтам,
//либо, если размер буфера меньше 32 байт, по тому что есть
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
    	if(DataBufer[i] == START_BYTE) //поиск стартового байта
	  {
        FoundMessage1 = true;
        Start_Of_Message = i;
        break;
      }
    }

	if(FoundMessage1 == true) //поиск конечного байта производим только если найден начальный байт
    {
    	for(unsigned int i=0; i<How_Much_To_Count; i++)
    	{
    		if(DataBufer[i] == END_BYTE) //поиск конечного байта
      	{
        	FoundMessage2 = true;
          End_Of_Message = i;
          break;
      	}
    	}
    }

    //этот флаг выставится, если успешно найдены байты начала и конца сообщения
    FoundMessage = FoundMessage1 && FoundMessage2 && (End_Of_Message > Start_Of_Message);

    //шаг 3.2 - если не найден стартовый байт сообщения, то обработанные данные
    //не являются полезными - удаляем их из общего буфера

    if(FoundMessage1 == false)
    {
        //если мы проходились по всему буферу, то можно просто обнулить его размер
		if(How_Much_To_Count == DataBufer.size())
        {
			RSMaster::RSspecmsg(DataBufer);

			DataBufer.clear();

			//так как произошло смещение байт, нарушились адреса стартового и конечного байтов
      			//найденного сообщения, поэтому проведем их обработку на следующей итерации
      			FoundMessage = false;
        }
        else
        {
            for(unsigned int i=0; i<DataBufer.size() - How_Much_To_Count; i++)
			{
				RSMaster::RSspecmsg(DataBufer);

				//удаляем из начала буфера нужное количество байт
				DataBufer.erase(DataBufer.begin());

			}

            //так как произошло смещение байт, нарушились адреса стартового и конечного байтов
            //найденного сообщения, поэтому проведем их обработку на следующей итерации
            FoundMessage = false;
        }
    }
  }


//шаг 4 - дополнительная обработка данных в буфере
 	if (DataBufer.size() > 0)
  {
  	//шаг 4.1 - удаление всех байтов в буфере до первого стартового байта, они все равно не нужны
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

		//удаляем из начала буфера нужное количество байт
		DataBufer.erase(DataBufer.begin());

	  }

	  //так как произошло смещение байт, нарушились адреса стартового и конечного байтов
	  //найденного сообщения, поэтому проведем их обработку на следующей итерации
	  FoundMessage = false;
	}

	//шаг 4.2 - если размер буфера больше 32, и есть стартовый(ые) байт(ы), но нет ни одного
		//конечного байта, то это аварийная ситуация, поэтому очищаем буфер
	if (FoundMessage1 == true && FoundMessage2 == false && DataBufer.size() > 32)
   	{
		//RSMaster::RSspecmsg(DataBufer);

		DataBufer.clear();

      //так как произошло смещение байт, нарушились адреса стартового и конечного байтов
      //найденного сообщения, поэтому проведем их обработку на следующей итерации
      FoundMessage = false;
	}
  }

//шаг 5 - если сообщение найдено, требуется переместить его в буфер полезных сообщений
	if(FoundMessage == true)
  {
  	 std::vector<BYTE> aMessage;  //временный массив с сформированным сообщением
	for(int i = Start_Of_Message; i<End_Of_Message+1; i++)
    {
        aMessage.push_back(DataBufer[i]);
    }
    MessageBufer.push_back(aMessage);  //запихиваем массив с сообщением в массив сообщений (классно звучит)

    //теперь требуется удалить лишнее из большого буфера,
    //удалять будем все байты от начала буфера до конца полезного сообщения
    for(int i = 0; i<End_Of_Message+1; i++)
    {
     	//удаляем из начала буфера нужное количество байт
      DataBufer.erase(DataBufer.begin());
    }
  }

//шаг 6 - если в буфере полезных сообщений есть сообщения - нужно вернуть первое из них из функции
// и удалить из буфера

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

/*  /////////////отладочный код/////////////////////////////////////////////////////////////////

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

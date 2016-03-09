//---------------------------------------------------------------------------

#ifndef URSMasterH
#define URSMasterH

#include <vcl.h>
#include <vector>



class RSMaster
{
	private:

	HANDLE hSerial;
    DWORD BytesWrittenLastTime;
    bool Online;
	std::vector<BYTE> DataBufer;
	std::vector<  std::vector<BYTE> > MessageBufer;

	public:

    RSMaster();   //конструктор

    //Функции соединения с RS-232
	bool RSInit(int COM_num, int speed);
	void RSClose();
	bool RSSend( std::vector<BYTE> data);
	bool RSProcess( std::vector<BYTE> &paket);
	BYTE RSAsciiToInt(BYTE data);
	void RSMaster::RSspecmsg( std::vector<BYTE> data);


    //Методы доступа
	DWORD GetBytesWrittenLastTime() {return BytesWrittenLastTime;};
	bool IsOnline() {return Online;};
};

//---------------------------------------------------------------------------
#endif

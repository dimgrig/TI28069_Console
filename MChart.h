//---------------------------------------------------------------------------

#ifndef MChartH
#define MChartH


class MChart
{
	private:

	//HANDLE hSerial;
	//DWORD BytesWrittenLastTime;
	//bool Online;
	//std::vector<BYTE> DataBufer;

	public:

	MChart();   //конструктор

	//Функции
	bool Run();

	//Методы доступа
	//DWORD GetBytesWrittenLastTime() {return BytesWrittenLastTime;};
	//bool IsOnline() {return Online;};
};




 //---------------------------------------------------------------------------
#endif
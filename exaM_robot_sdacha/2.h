#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;

class Baban_kkkk
{
public:
	Baban_kkkk() {}
	virtual int blanas_karty() = 0;
	virtual void polozit_dengi() = 0;
	virtual void dobavit_traty() = 0;
	virtual bool IsPin() = 0;
	virtual void Read() = 0;
	virtual void Clear() = 0;
	virtual void rashodi_za_den(int d, int day) = 0;
	virtual void rashodi_za_nedely(int d, int day) = 0;
	virtual void rashodi_za_mesavibor(int d) = 0;
	~Baban_kkkk() = default;

private:

};


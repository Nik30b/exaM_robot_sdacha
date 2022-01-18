#include "1.h"
/*Файл с реализацией класса родителя и виртуальных функций*/
class Bank
{
public:
	Bank() {}
	virtual int blanas_karty() = 0;
	virtual void polozit_dengi() = 0;
	virtual void dobavit_traty() = 0;
	virtual bool IsPin() = 0;
	virtual void Read() = 0;
	virtual void Clear() = 0;
	virtual void rashodi_za_den(int d, int day) = 0;
	virtual void rashodi_za_nedely(int d, int day) = 0;
	virtual void rashodi_za_mesavibor(int d) = 0;
	~Bank() = default;

private:

};


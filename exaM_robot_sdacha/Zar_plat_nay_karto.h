#include "2.h"


//Зарплатная карта
class Debit : public Bank
{
public:

	Debit()
	{
		ifstream fin("balanse_carto.txt");
		string buf;

		getline(fin, buf);

		balance = stoi(buf);

		fin.close();
	}

	int blanas_karty() { return balance; }
	//Функция пополнения карты
	void polozit_dengi()
	{
		int pokypka;
		if (this->IsPin() == true) 
		{
			cout << "Введите сумму\n";
			cin >> pokypka;
			if (pokypka <= 0)
			{
				cout << "\nErrooor 404\n";
			}
			else
			{
				balance += pokypka;
				cout << "\nНовый баланс карты-" << this->blanas_karty() << "$";
			}
		}
	}
	
	//Проверка пин кода
	bool IsPin() 
	{
		cout << "\nВведите PIN-код: ";
		int buf;
		cin >> buf;
		if (buf == pin)
		{
			return true;
		}
		else 
		{
			cout << "\nНеверный PIN-код\n";
			return false;
		}
	}
	//Считывания затрат по категориям
	void Read()
	{
		string str;

		ifstream fin(files[0]);
		while (getline(fin, str))
			if (str.size() != 0)
				buf1.push_back(stoi(str));
		fin.close();

		fin.open(files[1]);
		while (getline(fin, str))
			if (str.size() != 0)
				buf2.push_back(stoi(str));
		fin.close();


		fin.open(files[2]);
		while (getline(fin, str))
			if (str.size() != 0)
				buf3.push_back(stoi(str));
		fin.close();


		fin.open(files[3]);
		while (getline(fin, str))
			if (str.size() != 0)
				buf4.push_back(stoi(str));
		fin.close();
	}
	//Функция очистки вект.
	void Clear()
	{
		buf.clear();
		buf = { 0,0,0,0,0,0 };
		buf1.clear();
		buf2.clear();
		buf3.clear();
		buf4.clear();
	}

	//Расход по карте
	void dobavit_traty()
	{
		int d, m, vibor, pokypka;
		cout << "\t$$$$Расход$$$$";
		cout << "\nВведите сумму\n";
		cin >> pokypka;
		if (pokypka > this->balance)
		{
			cout << "\nНе хватает $ на карте\n";
		}
		else
		{
			cout << "Какой день?\n";
			cin >> d;
			cout << "Какой месяц?\n";
			cin >> m;
			cout << "|$Категория   $|\n";
			cout << "|$1-Машины    $|\n";
			cout << "|$2-Кафе      $|\n";
			cout << "|$3-Рестораны $|\n";
			cout << "|$4-Одежда    $|\n";
			cin >> vibor;
			ofstream fout(files[vibor - 1]);
			fout << m << "\n";
			fout << d << "\n";
			fout << pokypka << "\n";
			balance -= pokypka;
			fout.close();
		}
	}

	//Подсчет всех расходов какого-то дня какого-то месяца
	void rashodi_za_den(int pokypka, int day) {
		this->Read();
		if (buf1.empty() == false)
			for (size_t i = 0; i < buf1.size(); i += 3)
			{
				if (buf1[i] == pokypka && day >= buf1[i + 1]) 
				{
					buf[0] += buf1[i + 2];
				}
			}
		if (buf2.empty() == false)
			for (size_t i = 0; i < buf2.size(); i += 3)
			{
				if (buf2[i] == pokypka && day >= buf2[i + 1]) {
					buf[1] += buf2[i + 2];
				}
			}
		if (buf3.empty() == false)
			for (size_t i = 0; i < buf3.size(); i += 3)
			{
				if (buf3[i] == pokypka && day >= buf3[i + 1]) {
					buf[2] += buf3[i + 2];
				}
			}
		if (buf4.empty() == false)
			for (size_t i = 0; i < buf4.size(); i += 3)
			{
				if (buf4[i] == pokypka && day >= buf4[i + 1]) {
					buf[3] += buf4[i + 2];
				}
			}

		cout << "\n$Затраты за день$\n";
		ofstream fout("zatraty.txt", ios::app);
		fout << "\n$Затраты за день$\n";

		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " $\n";
			fout << categories[i] << " - " << buf[i] << " $\n";
		}
		fout.close();
		this->Clear();
	}
	//Подсчет всех расходов за  какой-то месяц начиная с какого-то дня
	void rashodi_za_nedely(int pokypka, int day)
	{
		this->Read();
		if (buf1.empty() == false)
			for (size_t i = 0; i < buf1.size(); i += 3)
			{
				if (buf1[i] == pokypka && day >= buf1[i + 1] && day <= buf1[i + 1] + 7)
				{
					buf[0] += buf1[i + 2];
				}
			}
		if (buf2.empty() == false)
			for (size_t i = 0; i < buf2.size(); i += 3)
			{
				if (buf2[i] == pokypka && day >= buf2[i + 1] && day <= buf2[i + 1] + 7)
				{
					buf[1] += buf2[i + 2];
				}
			}
		if (buf3.empty() == false)
			for (size_t i = 0; i < buf3.size(); i += 3)
			{
				if (buf3[i] == pokypka && day >= buf3[i + 1] && day <= buf3[i + 1] + 7)
				{
					buf[2] += buf3[i + 2];
				}
			}
		if (buf4.empty() == false)
			for (size_t i = 0; i < buf4.size(); i += 3)
			{
				if (buf4[i] == pokypka && day >= buf4[i + 1] && day <= buf4[i + 1] + 7)
				{
					buf[3] += buf4[i + 2];
				}
			}


		ofstream fout("zatraty.txt", ios::app);
		cout << "\n$Затраты за неделю$\n";
		fout << "\n$Затраты за неделю$\n";

		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " $\n";
			fout << categories[i] << " - " << buf[i] << " $\n";
		}
		fout.close();
		this->Clear();
	}
	/*Функция подсчета всех расходов за определенный месяц*/
	void rashodi_za_mesavibor(int pokypka) 
	{
		this->Read();
		if (buf1.empty() == false)
			for (size_t i = 0; i < buf1.size(); i += 3)
			{
				if (buf1[i] == pokypka) {
					buf[0] += buf1[i + 2];
				}
			}
		if (buf2.empty() == false)
			for (size_t i = 0; i < buf2.size(); i += 3)
			{
				if (buf2[i] == pokypka) {
					buf[1] += buf2[i + 2];
				}
			}
		if (buf3.empty() == false)
			for (size_t i = 0; i < buf3.size(); i += 3)
			{
				if (buf3[i] == pokypka) {
					buf[2] += buf3[i + 2];
				}
			}
		if (buf4.empty() == false)
			for (size_t i = 0; i < buf4.size(); i += 3)
			{
				if (buf4[i] == pokypka) {
					buf[3] += buf4[i + 2];
				}
			}
		cout << "\n$Затраты за месяц$\n";
		ofstream fout("zatraty.txt", ios::app);
		fout << "\n$Затраты за месяц$\n";
		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " $\n";
			fout << categories[i] << " - " << buf[i] << " $\n";
		}
		fout.close();
		this->Clear();
	}
	/*Деструктор сохраняющий баланс в файл*/
	~Debit()
	{
		ofstream fout("balanse_carto.txt");
		fout << to_string(balance);
		fout.close();

	}

private:

	int balance;
	int pin = 6666;
	/*Вектор категорий*/

	vector<string> categories = { "Машины","Кафе","Рестораны","Одежда" };

	/*Вектор названий файлов с расходами по категориям*/

	vector <string> files = { "car.txt","caphe.txt","rest.txt","closes.txt" };

	vector<int> buf = { 0,0,0,0 };
	vector<int> buf1;
	vector<int> buf2;
	vector<int> buf3;
	vector<int> buf4;
};


#include "Zar_plat_nay_karto.h"
//Файл с реализацией кредитной карты
class Credit : public Bank
{
public:
	//Конструктор*/
	Credit() {
		ifstream fin("balans_credito.txt");
		string buf;
		getline(fin, buf);
		balance = stoi(buf);
		fin.close();
	}
	//Возвращает текущий баланс
	int blanas_karty() { return balance; }
	//Функция пополнения карты
	void polozit_dengi()
	{
		int mon;
		if (this->IsPin() == true)
		{
			cout << "Введите сумму: ";
			cin >> mon;
			if (mon <= 0)
				cout << "\nError 404\n";
			else
				balance += mon;
			cout << "\nНовый баланс: " << this->blanas_karty() << "$";
		}
	}
	//Функция добавляющая расход по карте (сумма,категория,дата)
	void dobavit_traty()
	{
		int d, m, ch, mon;
		cout << "\t$$$$Расход$$$$";
		cout << "\nВведите сумму: ";
		cin >> mon;

		cout << "Введите день: ";
		cin >> d;
		cout << "Введите месяц: ";
		cin >> m;
		cout << "|$Категория   $|\n";
		cout << "|$1-Машины    $|\n";
		cout << "|$2-Кафе      $|\n";
		cout << "|$3-Рестораны $|\n";
		cout << "|$4-Одежда    $|\n";

		cin >> ch;

		ofstream fout(files[ch - 1]);
		fout << m << "\n";
		fout << d << "\n";
		fout << mon << "\n";
		balance -= mon;
		fout.close();

	}
	//Функция проверки пин-кода
	bool IsPin()
	{
		cout << "\nВведите PIN-код: ";
		int buf;
		cin >> buf;
		if (buf == pin)
			return true;
		else
		{
			cout << "\nНеверный PIN-код\n";
			return false;
		}
	}
	//Функция считывания затрат по категориям(дата,сумма)
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
	//Функция очистки вектогров хранящих затраты
	void Clear() {
		buf.clear();
		buf = { 0,0,0,0,0,0 };
		buf1.clear();
		buf2.clear();
		buf3.clear();
		buf4.clear();
	}


	//Функция подсчета всех расходов за определенный день определенного месяца
	void rashodi_za_den(int mon, int day) {
		this->Read();
		for (size_t i = 0; i < buf1.size(); i += 3)
		{
			if (buf1[i] == mon && day >= buf1[i + 1]) {
				buf[0] += buf1[i + 2];
			}
		}

		for (size_t i = 0; i < buf2.size(); i += 3)
		{
			if (buf2[i] == mon && day >= buf2[i + 1]) {
				buf[1] += buf2[i + 2];
			}
		}

		for (size_t i = 0; i < buf3.size(); i += 3)
		{
			if (buf3[i] == mon && day >= buf3[i + 1]) {
				buf[2] += buf3[i + 2];
			}
		}

		for (size_t i = 0; i < buf4.size(); i += 3)
		{
			if (buf4[i] == mon && day >= buf4[i + 1]) {
				buf[3] += buf4[i + 2];
			}
		}


		cout << "\n$Затраты за день$\n";
		ofstream fout("zatratyCredit.txt", ios::app);
		fout << "\n$Затраты за день$\n";
		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " $\n";
			fout << categories[i] << " - " << buf[i] << " $\n";
		}
		fout.close();
		this->Clear();
	}
	//Функция подсчета всех расходов за неделю определенного месяца начиная с определенного дня*/
	void rashodi_za_nedely(int mon, int day) {
		this->Read();
		for (size_t i = 0; i < buf1.size(); i += 3)
		{
			if (buf1[i] == mon && day >= buf1[i + 1] && day <= buf1[i + 1] + 7) {
				buf[0] += buf1[i + 2];
			}
		}

		for (size_t i = 0; i < buf2.size(); i += 3)
		{
			if (buf2[i] == mon && day >= buf2[i + 1] && day <= buf2[i + 1] + 7) {
				buf[1] += buf2[i + 2];
			}
		}

		for (size_t i = 0; i < buf3.size(); i += 3)
		{
			if (buf3[i] == mon && day >= buf3[i + 1] && day <= buf3[i + 1] + 7) {
				buf[2] += buf3[i + 2];
			}
		}

		for (size_t i = 0; i < buf4.size(); i += 3)
		{
			if (buf4[i] == mon && day >= buf4[i + 1] && day <= buf4[i + 1] + 7) {
				buf[3] += buf4[i + 2];
			}
		}

		ofstream fout("zatratyCredit.txt", ios::app);
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
	//Функция подсчета всех расходов за определенный месяц
	void rashodi_za_mesavibor(int mon) {
		this->Read();
		for (size_t i = 0; i < buf1.size(); i += 3)
		{
			if (buf1[i] == mon) {
				buf[0] += buf1[i + 2];
			}
		}

		for (size_t i = 0; i < buf2.size(); i += 3)
		{
			if (buf2[i] == mon) {
				buf[1] += buf2[i + 2];
			}
		}

		for (size_t i = 0; i < buf3.size(); i += 3)
		{
			if (buf3[i] == mon) {
				buf[2] += buf3[i + 2];
			}
		}

		for (size_t i = 0; i < buf4.size(); i += 3)
		{
			if (buf4[i] == mon) {
				buf[3] += buf4[i + 2];
			}
		}
		cout << "\nЗатраты за месяц\n";
		ofstream fout("zatratyCredit.txt", ios::app);
		fout << "\nЗатраты за месяц\n";
		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " $\n";
			fout << categories[i] << " - " << buf[i] << " $\n";
		}
		fout.close();
		this->Clear();
	}
	//Деструктор сохраняющий баланс в файл*/
	~Credit()
	{
		ofstream fout("balans_credito.txt");
		fout << to_string(balance);
		fout.close();

	}

private:
	int balance;
	int pin = 6666;
	//Вектор категорий*/
	vector<string> categories = { "Машины","Кафе","Рестораны","Одежда" };
	//Вектор названий файлов с расходами по категориям*/
	vector <string> files = { "car.txt","caphe.txt","rest.txt","closes.txt" };

	//Векторы хранящие информацию во время выполнения программы */

	vector<int> buf = { 0,0,0,0 };
	vector<int> buf1;
	vector<int> buf2;
	vector<int> buf3;
	vector<int> buf4;
};

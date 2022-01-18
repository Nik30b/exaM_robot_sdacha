#include "2.h"


//���������� �����
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
	//������� ���������� �����
	void polozit_dengi()
	{
		int pokypka;
		if (this->IsPin() == true) 
		{
			cout << "������� �����\n";
			cin >> pokypka;
			if (pokypka <= 0)
			{
				cout << "\nErrooor 404\n";
			}
			else
			{
				balance += pokypka;
				cout << "\n����� ������ �����-" << this->blanas_karty() << "$";
			}
		}
	}
	
	//�������� ��� ����
	bool IsPin() 
	{
		cout << "\n������� PIN-���: ";
		int buf;
		cin >> buf;
		if (buf == pin)
		{
			return true;
		}
		else 
		{
			cout << "\n�������� PIN-���\n";
			return false;
		}
	}
	//���������� ������ �� ����������
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
	//������� ������� ����.
	void Clear()
	{
		buf.clear();
		buf = { 0,0,0,0,0,0 };
		buf1.clear();
		buf2.clear();
		buf3.clear();
		buf4.clear();
	}

	//������ �� �����
	void dobavit_traty()
	{
		int d, m, vibor, pokypka;
		cout << "\t$$$$������$$$$";
		cout << "\n������� �����\n";
		cin >> pokypka;
		if (pokypka > this->balance)
		{
			cout << "\n�� ������� $ �� �����\n";
		}
		else
		{
			cout << "����� ����?\n";
			cin >> d;
			cout << "����� �����?\n";
			cin >> m;
			cout << "|$���������   $|\n";
			cout << "|$1-������    $|\n";
			cout << "|$2-����      $|\n";
			cout << "|$3-��������� $|\n";
			cout << "|$4-������    $|\n";
			cin >> vibor;
			ofstream fout(files[vibor - 1]);
			fout << m << "\n";
			fout << d << "\n";
			fout << pokypka << "\n";
			balance -= pokypka;
			fout.close();
		}
	}

	//������� ���� �������� ������-�� ��� ������-�� ������
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

		cout << "\n$������� �� ����$\n";
		ofstream fout("zatraty.txt", ios::app);
		fout << "\n$������� �� ����$\n";

		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " $\n";
			fout << categories[i] << " - " << buf[i] << " $\n";
		}
		fout.close();
		this->Clear();
	}
	//������� ���� �������� ��  �����-�� ����� ������� � ������-�� ���
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
		cout << "\n$������� �� ������$\n";
		fout << "\n$������� �� ������$\n";

		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " $\n";
			fout << categories[i] << " - " << buf[i] << " $\n";
		}
		fout.close();
		this->Clear();
	}
	/*������� �������� ���� �������� �� ������������ �����*/
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
		cout << "\n$������� �� �����$\n";
		ofstream fout("zatraty.txt", ios::app);
		fout << "\n$������� �� �����$\n";
		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " $\n";
			fout << categories[i] << " - " << buf[i] << " $\n";
		}
		fout.close();
		this->Clear();
	}
	/*���������� ����������� ������ � ����*/
	~Debit()
	{
		ofstream fout("balanse_carto.txt");
		fout << to_string(balance);
		fout.close();

	}

private:

	int balance;
	int pin = 6666;
	/*������ ���������*/

	vector<string> categories = { "������","����","���������","������" };

	/*������ �������� ������ � ��������� �� ����������*/

	vector <string> files = { "car.txt","caphe.txt","rest.txt","closes.txt" };

	vector<int> buf = { 0,0,0,0 };
	vector<int> buf1;
	vector<int> buf2;
	vector<int> buf3;
	vector<int> buf4;
};


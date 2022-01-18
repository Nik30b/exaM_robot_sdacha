#include "Zar_plat_nay_karto.h"
//���� � ����������� ��������� �����
class Credit : public Bank
{
public:
	//�����������*/
	Credit() {
		ifstream fin("balans_credito.txt");
		string buf;
		getline(fin, buf);
		balance = stoi(buf);
		fin.close();
	}
	//���������� ������� ������
	int blanas_karty() { return balance; }
	//������� ���������� �����
	void polozit_dengi()
	{
		int mon;
		if (this->IsPin() == true)
		{
			cout << "������� �����: ";
			cin >> mon;
			if (mon <= 0)
				cout << "\nError 404\n";
			else
				balance += mon;
			cout << "\n����� ������: " << this->blanas_karty() << "$";
		}
	}
	//������� ����������� ������ �� ����� (�����,���������,����)
	void dobavit_traty()
	{
		int d, m, ch, mon;
		cout << "\t$$$$������$$$$";
		cout << "\n������� �����: ";
		cin >> mon;

		cout << "������� ����: ";
		cin >> d;
		cout << "������� �����: ";
		cin >> m;
		cout << "|$���������   $|\n";
		cout << "|$1-������    $|\n";
		cout << "|$2-����      $|\n";
		cout << "|$3-��������� $|\n";
		cout << "|$4-������    $|\n";

		cin >> ch;

		ofstream fout(files[ch - 1]);
		fout << m << "\n";
		fout << d << "\n";
		fout << mon << "\n";
		balance -= mon;
		fout.close();

	}
	//������� �������� ���-����
	bool IsPin()
	{
		cout << "\n������� PIN-���: ";
		int buf;
		cin >> buf;
		if (buf == pin)
			return true;
		else
		{
			cout << "\n�������� PIN-���\n";
			return false;
		}
	}
	//������� ���������� ������ �� ����������(����,�����)
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
	//������� ������� ��������� �������� �������
	void Clear() {
		buf.clear();
		buf = { 0,0,0,0,0,0 };
		buf1.clear();
		buf2.clear();
		buf3.clear();
		buf4.clear();
	}


	//������� �������� ���� �������� �� ������������ ���� ������������� ������
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


		cout << "\n$������� �� ����$\n";
		ofstream fout("zatratyCredit.txt", ios::app);
		fout << "\n$������� �� ����$\n";
		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " $\n";
			fout << categories[i] << " - " << buf[i] << " $\n";
		}
		fout.close();
		this->Clear();
	}
	//������� �������� ���� �������� �� ������ ������������� ������ ������� � ������������� ���*/
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
	//������� �������� ���� �������� �� ������������ �����
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
		cout << "\n������� �� �����\n";
		ofstream fout("zatratyCredit.txt", ios::app);
		fout << "\n������� �� �����\n";
		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " $\n";
			fout << categories[i] << " - " << buf[i] << " $\n";
		}
		fout.close();
		this->Clear();
	}
	//���������� ����������� ������ � ����*/
	~Credit()
	{
		ofstream fout("balans_credito.txt");
		fout << to_string(balance);
		fout.close();

	}

private:
	int balance;
	int pin = 6666;
	//������ ���������*/
	vector<string> categories = { "������","����","���������","������" };
	//������ �������� ������ � ��������� �� ����������*/
	vector <string> files = { "car.txt","caphe.txt","rest.txt","closes.txt" };

	//������� �������� ���������� �� ����� ���������� ��������� */

	vector<int> buf = { 0,0,0,0 };
	vector<int> buf1;
	vector<int> buf2;
	vector<int> buf3;
	vector<int> buf4;
};

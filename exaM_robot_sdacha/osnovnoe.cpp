#include "C_redito_carto.h"

int main()
{

	setlocale(0, "");

	int vibor_meny = 1, viboR;

	Debit d;
	Credit c;
	Bank* ptr[2] = { &d,&c };
	do
	{
		system("color F0");
		cout << "\t\t\t\t    |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n";
		cout << "\t\t\t\t      |$$$$$$$$$$$$$$$$$$$$$$$$$$|\n";
		cout << "\t\t\t\t\t|$$$$$$$$$$$$$$$$$$$$$$|\n";
		cout << "\t\t\t\t\t|$$$$$$$$$$$$$$$$$$$$$$|\n";
		cout << "\t\t\t\t\t|$ 1-���������� ����� $|\n";
		cout << "\t\t\t\t\t|$ 2-���������  ����� $|\n";
		cout << "\t\t\t\t\t|$$$$$$$$$$$$$$$$$$$$$$|\n";
		cout << "\t\t\t\t\t|$$$$$$$$$$$$$$$$$$$$$$|\n";
		cout << "\t\t\t\t      |$$$$$$$$$$$$$$$$$$$$$$$$$$|\n";
		cout << "\t\t\t\t    |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n";
		cin >> viboR;
		viboR--;
		system("cls");
		do
		{
			int mon, day;
			cout << "\n|$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n|1-������� ������           |\n|2-�������� ������ �� ����� |\n|3-��� ������� �� ����      |\n|4-��� ������� �� ������    |\n|5-��� ������� �� �����     |\n|6-�������� ������ �� ����  |\n|0-� ���� ������ ����       |\n|$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n";
			cout << "$$$";
			cin >> vibor_meny;
			system("cls");
			switch (vibor_meny)
			{
			case 1:
			{
				system("color F1");
				cout << "\n������: " << ptr[viboR]->blanas_karty() << "$\n";
				break;
			}
			case 2:
			{
				system("color F2");
				ptr[viboR]->dobavit_traty();
				break;
			}
			case 3:
			{
				system("color F3");
				cout << "������� �����: ";
				cin >> mon;
				cout << "������� ����: ";
				cin >> day;
				ptr[viboR]->rashodi_za_den(mon, day);
				break;
			}
			case 4:
			{
				system("color F4");
				cout << "������� �����: ";
				cin >> mon;
				cout << "������� ����(������ ������): ";
				cin >> day;
				ptr[viboR]->rashodi_za_nedely(mon, day);
				break;
			}
			case 5:
			{
				system("color F5");
				cout << "������� �����: ";
				cin >> mon;
				ptr[viboR]->rashodi_za_mesavibor(mon);
				break;
			}
			case 6:
			{
				ptr[viboR]->polozit_dengi();
				break;
			}
			default:
				system("cls");
				break;
			}

		} while (vibor_meny != 0);

	} while (viboR != 2);


}

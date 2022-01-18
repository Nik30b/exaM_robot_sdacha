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
		cout << "\t\t\t\t\t|$ 1-Зарплатная карта $|\n";
		cout << "\t\t\t\t\t|$ 2-Кредитная  карта $|\n";
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
			cout << "\n|$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n|1-Текущий баланс           |\n|2-Добавить расход по карте |\n|3-Все расходы за день      |\n|4-Все расходы за неделю    |\n|5-Все расходы за месяц     |\n|6-Положить деньги на счет  |\n|0-В меню выбора карт       |\n|$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n";
			cout << "$$$";
			cin >> vibor_meny;
			system("cls");
			switch (vibor_meny)
			{
			case 1:
			{
				system("color F1");
				cout << "\nБаланс: " << ptr[viboR]->blanas_karty() << "$\n";
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
				cout << "Введите месяц: ";
				cin >> mon;
				cout << "Введите день: ";
				cin >> day;
				ptr[viboR]->rashodi_za_den(mon, day);
				break;
			}
			case 4:
			{
				system("color F4");
				cout << "Введите месяц: ";
				cin >> mon;
				cout << "Введите день(начало недели): ";
				cin >> day;
				ptr[viboR]->rashodi_za_nedely(mon, day);
				break;
			}
			case 5:
			{
				system("color F5");
				cout << "Введите месяц: ";
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

#include "Header.h"
using namespace std;

void Import(int *SIZEDOG, int *SIZECAT);
void Buy(int* SIZEDOG, int* SIZECAT);

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);

	int SIZEDOG = 0;							// Объявление локальной переменной, отвечающей за текущее количество собак в наличии
	int SIZECAT = 0;							// Объявление локальной переменной, отвечающей за текущее количество котов в наличии



	string SIZEDogCat = "SIZEDogCat.txt";
	fstream fSIZE;
	int dost; //Локальная переменная отвечающая за выбор прав доступа.
	int agane;


	fSIZE.open(SIZEDogCat, ios::in);
	if (!fSIZE.is_open())
	{
		cout << "Error opening a file recording information from the number of animals\n" << endl;
	}
	else 
	{
		if (!fSIZE.eof())
		{
			fSIZE >> SIZEDOG >> SIZECAT;
		}
	}
	fSIZE.close();

	
	bool end = false;							// Булевая переменная отвечающая за выход из выбора кода доступа
	while (!end)								// Реализация выбора ключа доступа
	{
		cout << "Welcome!\n" 		// Реализация интерфейса выбора доступа
			<< "Select access rights:\n"	//
			<< "1. Administrator\n"			//
			<< "2. Buyer\n" << endl;	//

		cout << "Access code: "; cin >> dost; cout << endl;
		if (dost == 1)
		{
			Import(&SIZEDOG, &SIZECAT);
			cout << "return to the main menu?\n" << "1.Yes\t" << "2.No" << endl; cin >> agane; cout << endl;
			if (agane==1)
			{
				end = false;
			}
			else
			{
				end = true;
			}

		}
		else if (dost == 2) 
		{
			Buy(&SIZEDOG, &SIZECAT);
			end = true;
		}
		else 
		{
			cout << "The access code is incorrectly selected" << endl;
			
		}
	}
	fSIZE.open(SIZEDogCat, ios::out);
	if (!fSIZE.is_open())
	{
		cout << "Error opening a file recording information from the number of animals" << endl;
	}
	else
	{
		fSIZE << SIZEDOG << "\t";
		fSIZE << SIZECAT;
	}
	fSIZE.close();
	return 0;
}

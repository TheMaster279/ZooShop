#include "Header.h"

using namespace std;

class Animal
{
public:
	
	 Animal()
	{
		 name = "No data available";
		 sex = "No data available";
		 age = 0;
		 prise = 0;
	}
	 ~Animal() 
	 {

	 }
	 void SetName(string name) 
	 {
		 this->name = name;
	 }
	 string GetName() 
	 {
		 return name;
	 }

	 void SetSex(string sex)
	 {
		 this->sex = sex;
	 }
	 string GetSex()
	 {
		 return sex;
	 }

	 void SetAge(int age) 
	 {
		 this->age = age;
	 }
	 int GetAge() 
	 {
		 return age;
	 }

	 void SetPrise(int prise)
	 {
		 this->prise = prise;
	 }
	 int GetPrise()
	 {
		 return prise;
	 }

protected:
	string name;
	string sex;
	int age;
	int prise;
};

class Dog : public Animal
{
public:
	Dog() : Animal()
	{
		breadDog = "No data available";
	}
	~Dog() 
	{

	}
	void SetBreadDog(string breadDog)
	{
		this->breadDog = breadDog;
	}
	string GetBreadDog()
	{
		return breadDog;
	}
	void PrintInfoDog()
	{
		cout << "Name:\t\t" << name << endl
			 << "BreadDog:\t\t" << breadDog << endl
			 << "Gender:\t\t" << sex << endl
			 << "Age:\t" << age << endl
			 << "Prise:\t\t" << prise << "\n" << endl;
	}
private:
	string breadDog;
};

class Cat : public Animal
{
public:
	Cat() : Animal()
{
	breadCat = "No data available";
}

	  void SetBreadCat(string breadCat)
	  {
		  this->breadCat = breadCat;
	  }
	  string GetBreadCat()
	  {
		  return breadCat;
	  }

	  void PrintInfoCat()
	  {
		  cout<< "Name:\t\t" << name << endl
			  << "BreadDog:\t\t" << breadCat << endl
			  << "Gender:\t\t" << sex << endl
			  << "Age:\t" << age << endl
			  << "Prise:\t\t" << prise << "\n" << endl;
	  }
private:
	string breadCat;
};

string pathInvCat = "InvCat.txt";
string pathInvDog = "InvDog.txt";
ifstream writeindog;
ifstream writeincat;
ofstream fileoutdog;
ofstream fileoutcat;
void Import(int* SIZEDOG, int* SIZECAT)
{
	int TVSIZEDOG = *SIZEDOG;						//¬ременна€ переменна€ отвечающа€ за сумму было+добавленно
	int TVSIZECAT = *SIZECAT;


	int type;
	
	bool end = false;								// Ѕулева€ переменна€ отвечающа€ за выход из выбора вида животного
	while (!end)									// –еализаци€ выбора животного
	{
		cout << "Add:\n" << "1.Dog\n" << "2.Cat\n" << endl;
		cout << "Who to add: "; cin >> type; cout << endl;
		if (type == 1)							
		{
				int NewSizeDog;						// ќбъ€вление локальной переменной, отвечающей за количество добавл€емых собак 
				cout << "Number of added dogs: "; cin >> NewSizeDog; cout << endl;
				*SIZEDOG = TVSIZEDOG + NewSizeDog;
				Dog* pntD = new Dog[TVSIZEDOG];
				Dog* InvDog = new Dog[*SIZEDOG];				// ќбъ€вление динамичного массива собак
				Dog* NSDog = new Dog  [NewSizeDog];
					for (int i = 0; i < NewSizeDog; i++)
					{
						cout << "Dog data number " << i + 1 << ":" << endl;
						string name;
						cout << "Name: "; cin >> name;

						string breadDog;
						cout << "Breed: "; cin >> breadDog;

						string sex;
						cout << "Gender: "; cin >> sex;

						int age;
						cout << "Age: "; cin >> age;

						int prise;
						cout << "Prise: "; cin >> prise; cout << endl;

						NSDog[i].SetName(name);
						NSDog[i].SetBreadDog(breadDog);
						NSDog[i].SetSex(sex);
						NSDog[i].SetAge(age);
						NSDog[i].SetPrise(prise);
						
					}
				if (TVSIZEDOG == 0)
				{

					for (int i = 0; i < *SIZEDOG; i++)
					{
						InvDog[i] = NSDog[i];
					}
				}
				else if (TVSIZEDOG > 0)
				{
					for (int i = 0; i < *SIZEDOG; i++)
					{
						if (i < TVSIZEDOG)
						{
							writeindog.open(pathInvDog);
							if (!writeindog.is_open())
							{
								cout << "File opening error" << endl;
							}
							else
							{
									writeindog.read((char*)&pntD[i], sizeof(Dog));
									InvDog[i] = pntD[i];	
							}
							writeindog.close();
						}
						else if (i >= TVSIZEDOG)
						{
							for (int j = 0; j < NewSizeDog; j++)
							{
								InvDog[i] = NSDog[j];
							}
						}
					}
				}
				fileoutdog.open(pathInvDog);
				if (!fileoutdog.is_open())
				{
					cout << "File opening error" << endl;
				}
				else
				{
					for (int i = 0; i < *SIZEDOG; i++)
					{
						fileoutdog.write((char*)&InvDog[i], sizeof(Dog));
					}
				}
				fileoutdog.close();


				int agane;
				cout << "Add more animals?\n" << "1.Yes\t" << "2.No" << endl;
				cin >> agane; cout << endl;
				if (agane==1)
				{
					end = false;
				}
				else  
				{
					end = true;
				}
				delete[] NSDog;
				delete[] InvDog;
		}
		else if (type == 2)
		{
			int NewSizeCat;						// ќбъ€вление локальной переменной, отвечающей за количество добавл€емых собак 
			cout << "Number of cats to add: "; cin >> NewSizeCat; cout << endl;
			*SIZECAT = TVSIZECAT + NewSizeCat;
			Cat* pntC = new Cat[TVSIZECAT];
			Cat* InvCat = new Cat[*SIZECAT];
			Cat* NSCat = new Cat[NewSizeCat];
			for (int i = 0; i < NewSizeCat; i++)
			{
				cout << "Cat data number " << i + 1 << ":" << endl;
				string name;
				cout << "Name: "; cin >> name;

				string breadCat;
				cout << "Breed: "; cin >> breadCat;

				string sex;
				cout << "Gender: "; cin >> sex;

				int age;
				cout << "Age: "; cin >> age;

				int prise;
				cout << "Price: "; cin >> prise; cout << endl;

				NSCat[i].SetName(name);
				NSCat[i].SetBreadCat(breadCat);
				NSCat[i].SetSex(sex);
				NSCat[i].SetAge(age);
				NSCat[i].SetPrise(prise);

			}
			if (TVSIZECAT == 0)
			{

				for (int i = 0; i < *SIZECAT; i++)
				{
					InvCat[i] = NSCat[i];
				}
			}
			else if (TVSIZECAT > 0)
			{
				for (int i = 0; i < *SIZECAT; i++)
				{
					if (i < TVSIZECAT)
					{
						writeincat.open(pathInvCat);
						if (!writeincat.is_open())
						{
							cout << "File opening error" << endl;
						}
						else
						{
								writeincat.read((char*)&pntC[i], sizeof(Cat));
								InvCat[i] = pntC[i];
						}
						writeindog.close();
					}
					else if (i >= TVSIZECAT)
					{
						for (int j = 0; j < NewSizeCat; j++)
						{
							InvCat[i] = NSCat[j];
						}
					}
				}
			}
			fileoutcat.open(pathInvCat);
			if (!fileoutcat.is_open())
			{
				cout << "File opening error" << endl;
			}
			else
			{
				for (int i = 0; i < *SIZECAT; i++)
				{
					fileoutcat.write((char*)&InvCat[i], sizeof(Cat));
				}
			}
			fileoutcat.close();
			delete[] NSCat;
			delete[] InvCat;
			int agane;
			cout << "Add more animals?\n" << "1.Yes\t" << "2.No" << endl;
			cin >> agane; cout << endl;
			if (agane == 1)
			{
				end = false;
			}
			else
			{
				end = true;
			}
		}
		else
		{
			cout << "The type of animal is incorrectly selected!" << endl;
		}
	}

}
void Buy(int* SIZEDOG, int* SIZECAT)
{
	Dog *pntDR = new Dog[*SIZEDOG];
	Cat* pntCR = new Cat[*SIZECAT];
	int DogCat;
	int NewDogCat;
	int NumDog;
	int NumCat;
	
	
	bool end = false;
	while (end == false)
	{
		cout << "Who do you want to buy:\n" << "1.Dog\n" << "2.Cat" << endl;
		cout << "Type of animal: "; cin >> DogCat; cout << "\n";
		if (DogCat == 1)
		{
			if (*SIZEDOG!=0)
			{
					cout << "Dogs in stock: \n" << endl;
				writeindog.open(pathInvDog);
				if (!writeindog.is_open())
				{
					cout << "File opening error" << endl;
				}
				else
				{
					for (int i = 0; i < *SIZEDOG; i++)
					{
						cout << "Number: " << i + 1 << endl;
						writeindog.read((char*)&pntDR[i], sizeof(Dog));
						pntDR[i].PrintInfoDog();
					}
					writeindog.close();
				}

				cout << "(To return to the selection menu, enter 0)\t Enter the number of the purchased animal: "; cin >> NumDog; cout <<"\n";
				if (NumDog != 0)
				{

					fileoutdog.open(pathInvDog);
					if (!fileoutdog.is_open())
					{
						cout << "File opening error" << endl;
					}
					else
					{
						for (int i = 0; i < *SIZEDOG; i++)
						{
							if (i != NumDog - 1)
							{
							fileoutdog.write((char*)&pntDR[i], sizeof(Dog));
							}

						}
					}
					fileoutdog.close();
					*SIZEDOG = *SIZEDOG - 1;
					cout << "Congratulations on getting a new pet!\n\n" << "Would you like to buy another pet?\n" << "1. Yes \t" << "2. No\n"; cin >> NewDogCat;
					
						if (NewDogCat == 1)
						{
							end = false;
						}
						else
						{
							cout << "Goodbye, come to us again!";
							end = true;
						}
					
				}
				else
				{
					end = false;
				}

				
			}
			else
			{
				cout << "Now the dogs are not available, come to us later\n\n" << "Are you considering buying pets of other species?\n" << "1. Yes \t" << "2. No\n"; cin >> NewDogCat;
				
					if (NewDogCat == 1)
					{
						end = false;
					}
					else
					{
						cout << "Goodbye, come to us again!\n";
						end = true;
					}
			}
			
			
		}
		else if (DogCat == 2)
		{
			if (*SIZECAT != 0)
			{
				cout << "Cats in stock: " << endl;
				writeincat.open(pathInvCat);
				if (!writeincat.is_open())
				{
					cout << "File opening error" << endl;
				}
				else
				{
					for (int i = 0; i < *SIZECAT; i++)
					{
						cout << "Number: " << i + 1 << endl;
						writeincat.read((char*)&pntCR[i], sizeof(Cat));
						pntCR[i].PrintInfoCat();
					}
					writeincat.close();
				}
				cout << "(To return to the selection menu, enter 0)\t Enter the number of the purchased animal: "; cin >> NumCat; cout << "\n";
				if (NumCat != 0)
				{

					fileoutcat.open(pathInvCat);
					if (!fileoutcat.is_open())
					{
						cout << "File opening error" << endl;
					}
					else
					{
						for (int i = 0; i < *SIZECAT; i++)
						{
							if (i != NumCat - 1)
							{
								fileoutcat.write((char*)&pntCR[i], sizeof(Cat));
							}

						}
					}
					fileoutcat.close();
					*SIZECAT = *SIZECAT - 1;
					cout << "Congratulations on getting a new pet!\n\n" << "Would you like to buy another pet?\n" << "1. Yes \t" << "2. No\n"; cin >> NewDogCat;

						if (NewDogCat == 1)
						{
							end = false;
						}
						else
						{
							cout << "Goodbye, come to us again!";
							end = true;
						}
				}

				
			}
			else 
			{
				cout << "Cats are out of stock now, come to us later\n\n" << "Are you considering buying pets of other species?\n" << "1. Yes \t" << "2. No\n"; cin >> NewDogCat;

					if (NewDogCat == 1)
					{
						end = false;
					}
					else
					{
						cout << "Goodbye, come to us again!";
						end = true;
					}
			}
		}
		else
		{
			cout << "The type of animal is incorrectly selected" << endl;
		}
	}

}
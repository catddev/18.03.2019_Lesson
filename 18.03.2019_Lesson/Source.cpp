#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<fstream>

using namespace std;

struct student {
	char name[30];
	char surname[30];
	int age;
	int grades[5];

	void enter() {
		cin >> name >> surname >> age;
		for (int i = 0; i < 5; i++)
			cin >> grades[i];
	}
	void print() { // метод для печати
		cout << endl;
		cout << name << " " << surname << " " << age << endl;;
		for (int i = 0; i < 5; i++)
			cout << grades[i] << " ";
		cout << endl;
	}
};



int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			student s1, s2;
			strcpy_s(s1.name, "Denis"); //char массив заполняется через strcpy
			strcpy_s(s1.surname, "Perepelkin");
			cout << endl;
			s1.age = 25;
			s1.grades[0] = 11;
			s1.grades[1] = 12;
			s1.grades[2] = 12;
			s1.grades[3] = 10;
			s1.grades[4] = 12;
		/*	cout << s1.name << " " << s1.surname << " " << s1.age <<endl;
			for (int i = 0; i < 5; i++)
				cout << s1.grades[i] << " ";
			cout << endl;*/
			s1.print(); // внутренная локальная функция ничего не принимает

			cin >> s2.name >> s2.surname >> s2.age;
			for (int i = 0; i < 5; i++)
				cin >> s2.grades[i];
			s2.print();
		}
		break;
		case 2:
		{
			student s[2]; // через массив
		/*	strcpy_s(s[0].name, "Denis");
			strcpy_s(s[0].surname, "Perepelkin");
			cout << endl;
			s[0].age = 25;
			s[0].grades[0] = 11;
			s[0].grades[1] = 12;
			s[0].grades[2] = 12;
			s[0].grades[3] = 10;
			s[0].grades[4] = 12;*/

			/*cin >> s[1].name >> s[1].surname >> s[1].age;
			for (int i = 0; i < 5; i++)
				cin >> s[1].grades[i];*/

			for (int i = 0; i < 2; i++)
				s[i].enter();

			for(int i=0; i<2; i++)
				s[i].print();
		}
		break;
		case 3:
		{
			ifstream in_file("in.txt");
			student s[2];

			for (int i = 0; i < 2; i++) //считывание с файла
			{
				in_file >> s[i].name >> s[i].surname >> s[i].age; 
				for (int j = 0; j < 5; j++)
				{
					in_file >> s[i].grades[j];
				}
				s[i].print();
			}

		}
		break;
		case 4:
		{
			ifstream in_file("in.txt");
			student *s;
			int n;
			in_file >> n;
			s = new student[n];
			for (int i = 0; i < n; i++)
			{
				in_file >> s[i].name >> s[i].surname >> s[i].age;
				for (int j = 0; j < 5; j++)
				{
					in_file >> s[i].grades[j];
				}
				s[i].print();
			}
			delete[] s;
		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}
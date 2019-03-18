#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<fstream>
#include<Windows.h>

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
	bool otlichniki() {
		int k = 0;
		for (int i = 0; i < 5; i++)
			if (grades[i] >= 10)
				k++;
		if (double(k) / 5 >= 0.75) return true;
		else return false;
	}
	bool dvoechniki() {
		int k = 0;
		for (int i = 0; i < 5; i++)
			if (grades[i] <= 6)
				k++;
		if (double(k) / 5 >= 0.5) return true;
		else return false;
	}
};

//2.	Описать структуру билет (название маршрута, время, дата, стоимость).
// А) *Создать экземпляр структуры билет и написать для него функции заполнения и печати.
// Б) **Создать массив билетов и написать  программу, позволяющую:
// -динамически изменять размер массива;
// -выводить список билетов на конкретную дату;
// -выводить список  билетов не дороже определенной суммы;
// -печать всего списка билетов.
struct ticket {
	char route[30];
	char time[6];
	char date[11];
	int price;

	void print() {
		cout << endl;
		cout << route << " " << time << " " << date << " " << price << endl;;
	}
};

//**Описать структуру Data(день, месяц, год).
// Описать структуру Student(фамилия, группа, дата поступления).
// Проиллюстрировать работу с этим классом.
struct Date {
	int day, month, year;
};
struct Student {
	char surname[30];
	char group[10];
	Date regist;

	void print() {
		cout << surname << " " << group << " ";
		cout << regist.day << "." << regist.month << "." << regist.year << endl;
	}
};



int main()
{
	SetConsoleCP(1251); // ввод
	SetConsoleOutputCP(1251); // и вывод на русском на консоли

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
			char c;
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
			cout << "Enter character to search" << endl;
			cin >> c;
			for (int i = 0; i < n; i++)
				if (s[i].name[0] == c) // проверка первой буквы имени
					s[i].print();

		//**Описать структуру Student(фамилия, группа, успеваемость(массив из 5 int)).
		// Создать массив студентов и написать программу, позволяющую:
		//-динамически изменять размер массива;
		//-выводить список отличников(> 75 % отл оценок);
		//-выводить список двоечников(> 50 % оценок 2 и 3);
			cout << "Отличники:" << endl;
			for (int i = 0; i < n; i++)
				if (s[i].otlichniki() == true)
					s[i].print();

			cout << "Двоечники:" << endl;
			for (int i = 0; i < n; i++)
				if (s[i].dvoechniki() == true)
					s[i].print();
			
			delete[] s;
		}
		break;
		case 5:
		{
			ifstream in_file("in2.txt");
			ticket *t;
			int n;
			in_file >> n;
			t = new ticket[n];

			for (int i = 0; i < n; i++)
			{
				in_file >> t[i].route >> t[i].time >> t[i].date >> t[i].price;
			}

			int choice;
			while (true)
			{
				cout << "Enter 1 to search by date" << endl;
				cout << "Enter 2 to search by price" << endl;
				cout << "Enter 3 to print all" << endl;
				cout << "Enter 0 to exit" << endl;
				cin >> choice;
				if (choice == 0) break;
				switch (choice)
				{
				case 1:
					char d[11];
					cout << "Enter needed date" << endl;
					cin >> d;
					for (int i = 0; i < n; i++)
						if (strcmp(d, t[i].date) == 0)
							t[i].print();
				break;
				case 2:
					int p;
					cout << "Enter needed price" << endl;
					cin >> p;
					for (int i = 0; i < n; i++)
						if (p >= t[i].price)
							t[i].print();

				break;
				case 3:
					for (int i = 0; i < n; i++)
						t[i].print();
				break;
				}
			}
		}
		break;
		case 6:
		{
			ifstream in_file("in3.txt");
			Student *s;
			Date *regist;
			int n;
			in_file >> n;
			s = new Student[n];
			regist = new Date[n];

			for (int i = 0; i < n; i++)
				in_file >> s[i].surname >> s[i].group >> regist[i].day >> regist[i].month >> regist[i].year;
				
			for(int i=0; i<n; i++)
				s[i].print();



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
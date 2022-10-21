#include"Animal.h"
#include <list>
#include <conio.h>

void Menu();
void Add(list<string>& list_Animals);                                           //добавление в конец
void Delete(list<string>& list_Animals, list<string>::iterator it);             //удаление
void Search(list<string>& list_Animals, list<string>::iterator it);             //поиск по позиции
void Add_In_Position(list<string>& list_Animals, list<string>::iterator it);    //добавление в позицию
void Output(list<string>& list_Animals, list<string>::iterator it);             //вывод
void Search_And_Edit(list<string>& list_Animals, list<string>::iterator it);    //поиск по позиции и вывод

int main()
{
	list<string> list_Animals = { "Lion", "Pinguin", "Cat", "Dog" };  //список
	list<string>::iterator it = list_Animals.begin();                 //указатель на начало списка

	while (1) {
		system("cls");

		Menu();

		int answ;
		cin >> answ;

		system("cls");

		switch(answ) 
		{
		case 1:
			Add(list_Animals);
			break;
		case 2:
			Delete(list_Animals, it);
			break;
		case 3:
			Search(list_Animals, it);
			break;
		case 4:
			Add_In_Position(list_Animals, it);
			break;
		case 5:
			Output(list_Animals, it);
			break;
		case 6:
			Search_And_Edit(list_Animals, it);
			break;
		}

		_getch();
	}
}


void Menu() 
{
	cout << "1. Add" << endl
		<< "2. Delete" << endl
		<< "3. Search" << endl
		<< "4. Add in position" << endl
		<< "5. Output" << endl
		<< "6. Search and edit" << endl << endl;
}


//добавление в конец
void Add(list<string>& list_Animals)
{
	cout << "Enter animal to add: ";
	string new_animal;
	cin >> new_animal;

	list_Animals.push_back(new_animal);
}


//удаление
void Delete(list<string>& list_Animals, list<string>::iterator it)
{
	cout << "Enter animal to delete: ";
	string del_animal;
	cin >> del_animal;

	while (*it != del_animal) {
		it++;
	}

	if (*it == del_animal) {
		list_Animals.erase(it);
	}
	else cout << "No such animal";
}


//поиск по позиции
void Search(list<string>& list_Animals, list<string>::iterator it)
{
	cout << "Enter animal position to search: ";
	int position;
	cin >> position;

	if (position >= 0 && position < list_Animals.size()) {
		for (int i = 0; i <= position; i++) 
		{
			if(i == position) cout << "Animal: " << *it;
			it++;
		}
	}
	else cout << "No such position";
}


//добавление в позицию
void Add_In_Position(list<string>& list_Animals, list<string>::iterator it)
{
	cout << "Enter animal to add: ";
	string new_animal;
	cin >> new_animal;

	cout << "Enter animal position to add: ";
	int position;
	cin >> position;

	if (position >= 0 && position < list_Animals.size()) {
		for (int i = 0; i <= position; i++)
		{
			if (i == position) list_Animals.insert(it, new_animal);
			it++;
		}
	}
	else cout << "No such position";	
}


//вывод
void Output(list<string>& list_Animals, list<string>::iterator it)
{
	while (it != list_Animals.end()) {
		cout << *it << endl;
		it++;
	}
}


//поиск по позиции и вывод
void Search_And_Edit(list<string>& list_Animals, list<string>::iterator it)
{
	cout << "Enter animal to edit: ";
	string edit_animal;
	cin >> edit_animal;

	cout << "Enter new animal: ";
	string new_animal;
	cin >> new_animal;

	while (*it != edit_animal) {
		it++;
	}

	if (*it == edit_animal) {
		*it = new_animal;
	}
	else cout << "No such animal";
}
#include "Header.h"
int сhoice;

void Menu() {
	cout << "Виберіть вашу дію \n";
	cout << "1.Ввід даних \n";				 //Готово
	cout << "2.Вивід даних \n";				 //Готово
	cout << "3.Пошук даних \n";			     //Готово
	cout << "4.Видаленння даних \n";		 //Готово
	cout << "5.Редагування даних \n";		 //Готово
	cout << "6.Показати дані за умовою \n";		 //Готово
	cout << "7.Вихід \n";					 //Готово
	cout << "Виберіть пункт меню: ";
	cin >> сhoice;
}

int main() {
	SetConsoleCP(1251);		  //Підключання укр мови, і букви "і"
	SetConsoleOutputCP(1251); //Підключання укр мови, і букви "і"
	setlocale(LC_ALL, ".1251");//проверяет, какая кодировка установлена сейчас, и если она не 1251, то меняет ее на 1251, а если уже 1251, то ничего не делает
	Menu();

	while(сhoice != 7) {
		switch(сhoice) {
		case 1:
			system("cls"); //Очистити консоль
			EnterDate();
			system("pause"); //Очікування на ввід
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			ReadingData();
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			Find();
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			DeleteData();
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			Change();
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			ConditionalData();
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
	return 0;
}
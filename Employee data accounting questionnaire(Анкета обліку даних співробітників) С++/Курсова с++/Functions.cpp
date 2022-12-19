#include "Header.h"
Questionnaire Arr[10];
DaetOfStartWork ArrDate[10];
using namespace std;

//Внесення даних
void EnterDate() {
	ofstream file("Test.txt", ios::app);
	ofstream file2("Test2.txt", ios::app);
	const int SIZE = 20;
	//char ex[] = { "Так" };
	//char ex1[] = { "Одружений" };

	int c;
	cout << "Введіть дані: " << endl;
	for(int i = 0; i < SIZE; i++) {

		cout << "Введіть id: ";
		cin >> Arr[i].id;
		ValidationData(Arr, i);

		if(true == Check(Arr[i].id)) {
			cout << "Введіть інший id: ";
			cin >> Arr[i].id;
		}

		file << Arr[i].id << endl;

		cout << "Введіть Прізвище: ";
		cin >> Arr[i].surname;
		file << Arr[i].surname << endl;

		cout << "Введіть Ім'я: ";
		cin >> Arr[i].name;
		file << Arr[i].name << endl;

		cout << "Введіть по батькові: ";
		cin >> Arr[i].fathername;
		file << Arr[i].fathername << endl;

		cout << "Посада: ";
		cin >> Arr[i].position;
		file << Arr[i].position << endl;

		cout << "Введіть сімейний стан: ";
		cin >> Arr[i].maritalStatus;
		file << Arr[i].maritalStatus << endl;

		cout << "Введіть чи є неповнолітні діти: ";
		cin >> Arr[i].minorChildren;
		file << Arr[i].minorChildren << endl;

		//Date of start work
		cout << "Введіть день прийому на роботу: ";
		cin >> ArrDate[i].day;
		if(ArrDate[i].day < 0 || ArrDate[i].day > 31) {
			cout << "Введено не коректне число... Введіть заново " << endl;
			cin >> ArrDate[i].day;
		}
		file << ArrDate[i].day << endl;

		cout << "Введіть місяць прийому на роботу: ";
		cin >> ArrDate[i].month;
		if(ArrDate[i].month < 1 || ArrDate[i].month > 12) {
			cout << "Ви ввели не коректний місяць... Введіть заново " << endl;
			cin >> ArrDate[i].month;
		}
		file << ArrDate[i].month << endl;

		cout << "Введіть рік прийому на роботу: ";
		cin >> ArrDate[i].year;
		if(ArrDate[i].year > 2021 || ArrDate[i].year < 1990) {
			cout << "Ви ввели некоректний рік... Введіть заново " << endl;
			cin >> ArrDate[i].year;
		}
		file << ArrDate[i].year << endl;

		string a = "Одружений", b = "Так", ab = "Одружена";
		string maritalSTATUS = Arr[i].maritalStatus, minorCHILDREN = Arr[i].minorChildren;

		if(maritalSTATUS == a || maritalSTATUS == ab && minorCHILDREN == b) {
			file2 << Arr[i].id << endl;
			file2 << Arr[i].surname << endl;
			file2 << Arr[i].name << endl;
			file2 << Arr[i].fathername << endl;
			file2 << Arr[i].position << endl;
			file2 << Arr[i].maritalStatus << endl;
			file2 << Arr[i].minorChildren << endl;
			file2 << ArrDate[i].day << endl;
			file2 << ArrDate[i].month << endl;
			file2 << ArrDate[i].year << endl;
		}

		cout << "\nЗупинити ввід даних?\n1.Так\n2.Ні" << endl;
		cin >> c;
		if(c == 1) break;
	}
	file.close();
	file2.close();
}

//Читання файлу
void ReadingData() {
	if(Check_if_empty() != true) {
		ifstream fileread("Test.txt");
		ofstream file("Test.txt", ios::app);
		string from_file; //Строка файлу
		int i_number_line_now_check = 1;

		Cap(); //Виклик шапки

		int num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5, num6 = 6, num7 = 7, num8 = 8, num9 = 9;
		while(getline(fileread, from_file)) {
			if(i_number_line_now_check == num1) {
				num1 += 10;
				cout << "| " << left << setw(3) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num2) {
				num2 += 10;
				cout << left << setw(15) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num3) {
				num3 += 10;
				cout << left << setw(10) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num4) {
				num4 += 10;
				cout << left << setw(15) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num5) {
				num5 += 10;
				cout << left << setw(15) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num6) {
				num6 += 10;
				cout << left << setw(17) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num7) {
				num7 += 10;
				cout << left << setw(18) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num8) {
				num8 += 10;
				cout << left << setw(6) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num9) {
				num9 += 10;
				cout << left << setw(8) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check % 10 == 0) {
				cout << left << setw(5) << from_file << setw(1) << "|";
				cout << endl;
				cout << "+----+---------------+----------+---------------+---------------+-----------------+------------------+------+--------+-----+" << endl;
			}
			i_number_line_now_check++;
		}
	}
	else {
		cout << "Файл пустий.\n";
	}
}

//Редагування записів
void Change() {
	if(Check_if_empty() != true) {
		Questionnaire Arr[10];
		DaetOfStartWork ArrDate[10];

		string surname_for_change, name_for_change, fathername_for_change, maritalStatus_for_change, minorChildren_for_change;
		string id_for_change, day_for_change, month_for_change, year_for_change, position_for_change;

		ifstream fileread("Test.txt");
		ifstream fileread1("Test.txt");

		int i_number_line_delete = 0, i_number_line_now_find = 0; //для хранения номера строки который нужно удалить
		string find_id; //id для пошуку
		string from_file, from_file1;

		cout << "Введіть id для пошуку " << endl;
		cin >> find_id;
		string find = find_id;

		while(getline(fileread1, from_file1)) {
			if(from_file1 == find) {
				i_number_line_delete = i_number_line_now_find;
			}
			i_number_line_now_find++;
		}

		int i_number_line_now = 0; //лічильник рядків
		string line; //для зберігання рядка
		string line_file_text; //для зберігання тексту файлу

		cout << "Ви хочете змінити цей запис :\n " << endl;
		while(getline(fileread, line)) {
			if(i_number_line_delete == i_number_line_now) {
				id_for_change = line;
				cout << "Id: " << id_for_change << endl;
			}
			else if(i_number_line_delete + 1 == i_number_line_now) {
				surname_for_change = line;
				cout << "Прізвище: " << surname_for_change << endl;
			}
			else if(i_number_line_delete + 2 == i_number_line_now) {
				name_for_change = line;
				cout << "Ім'я: " << name_for_change << endl;
			}
			else if(i_number_line_delete + 3 == i_number_line_now) {
				fathername_for_change = line;
				cout << "По батькові: " << fathername_for_change << endl;
			}
			else if(i_number_line_delete + 4 == i_number_line_now) {
				position_for_change = line;
				cout << "Посада: " << position_for_change << endl;
			}
			else if(i_number_line_delete + 5 == i_number_line_now) {
				maritalStatus_for_change = line;
				cout << "Сімейний стан: " << maritalStatus_for_change << endl;
			}
			else if(i_number_line_delete + 6 == i_number_line_now) {
				minorChildren_for_change = line;
				cout << "Неповнолітні діти: " << minorChildren_for_change << endl;
			}
			else if(i_number_line_delete + 7 == i_number_line_now) {
				day_for_change = line;
				cout << "День: " << day_for_change << endl;
			}
			else if(i_number_line_delete + 8 == i_number_line_now) {
				month_for_change = line;
				cout << "Місяць: " << month_for_change << endl;
			}
			else if(i_number_line_delete + 9 == i_number_line_now) {
				year_for_change = line;
				cout << "Рік: " << year_for_change << endl;
			}

			else if(!(i_number_line_now == i_number_line_delete)) {
				line_file_text.insert(line_file_text.size(), line);
				/*добавляє строку*/
				/*добавити перенесення на іншу строку*/
				line_file_text.insert(line_file_text.size(), "\r\n");
			}
			i_number_line_now++;
		}
		fileread.close();

		//тепер в line_file_text буде содержаться змінений текст файла, тепер можна перезаписувати файл
		std::ofstream file;
		file.open("Test.txt", std::ios::trunc | std::ios::binary); //Відкрити і обрізати
		//запис

		file.write(line_file_text.c_str(), line_file_text.size());
		file.clear();
		file.close();

		ofstream file_1("test.txt", ios::app);
		int i = 1;

		int choice_surname, choice_name, choice_fathername, choice_maritalStatus, choice_minorChildren;
		int choice_id, choice_day, choice_month, choice_year, choice_position;

		cout << "\nId: " << endl;
		cout << "1.Залишити\n2.Змінити " << endl;
		cin >> choice_id;
		if(choice_id == 1) {
			file_1 << id_for_change << endl;
		}
		else {
			cout << "Id: ";
			cin >> Arr[i].id;
			file_1 << Arr[i].id << endl;
		}

		cout << "Прізвище: " << endl;
		cout << "1.Залишити\n2.Змінити " << endl;
		cin >> choice_surname;
		if(choice_surname == 1) {
			file_1 << surname_for_change << endl;
		}
		else {
			cout << "Прізвище: ";
			cin >> Arr[i].surname;
			file_1 << Arr[i].surname << endl;
		}

		cout << "Ім'я: " << endl;
		cout << "1.Залишити\n2.Змінити " << endl;
		cin >> choice_name;
		if(choice_name == 1) {
			file_1 << name_for_change << endl;
		}
		else {
			cout << "Ім'я: ";
			cin >> Arr[i].name;
			file_1 << Arr[i].name << endl;
		}

		cout << "По батькові: " << endl;
		cout << "1.Залишити\n2.Змінити " << endl;
		cin >> choice_fathername;
		if(choice_fathername == 1) {
			file_1 << fathername_for_change << endl;
		}
		else {
			cout << "По батькові: ";
			cin >> Arr[i].fathername;
			file_1 << Arr[i].fathername << endl;
		}

		cout << "Посада: " << endl;
		cout << "1.Залишити\n2.Змінити " << endl;
		cin >> choice_position;
		if(choice_position == 1) {
			file_1 << position_for_change << endl;
		}
		else {
			cout << "Посада: ";
			cin >> Arr[i].position;
			file_1 << Arr[i].position << endl;
		}

		cout << "Сімейни стан: " << endl;
		cout << "1.Залишити\n2.Змінити " << endl;
		cin >> choice_maritalStatus;
		if(choice_maritalStatus == 1) {
			file_1 << maritalStatus_for_change << endl;
		}
		else {
			cout << "Сімейний стан: ";
			cin >> Arr[i].maritalStatus;
			file_1 << Arr[i].maritalStatus << endl;
		}

		cout << "Стан неповнолітніх дітей: " << endl;
		cout << "1.Залишити\n2.Змінити " << endl;
		cin >> choice_minorChildren;
		if(choice_minorChildren == 1) {
			file_1 << minorChildren_for_change << endl;
		}
		else {
			cout << "Неповнолітні діти: ";
			cin >> Arr[i].minorChildren;
			file_1 << Arr[i].minorChildren << endl;
		}

		cout << "День: " << endl;
		cout << "1.Залишити\n2.Змінити " << endl;
		cin >> choice_day;
		if(choice_day == 1) {
			file_1 << day_for_change << endl;
		}
		else {
			cout << "День: ";
			cin >> ArrDate[i].day;
			file_1 << ArrDate[i].day << endl;
		}

		cout << "Місяць: " << endl;
		cout << "1.Залишити\n2.Змінити " << endl;
		cin >> choice_month;
		if(choice_month == 1) {
			file_1 << month_for_change << endl;
		}
		else {
			cout << "Місяць: ";
			cin >> ArrDate[i].month;
			file_1 << ArrDate[i].month << endl;
		}

		cout << "Рік: " << endl;
		cout << "1.Залишити\n2.Змінити " << endl;
		cin >> choice_year;
		if(choice_year == 1) {
			file_1 << year_for_change << endl;
		}
		else {
			cout << "Рік: ";
			cin >> ArrDate[i].year;
			file_1 << ArrDate[i].year << endl;
		}
	}
	else {
		cout << "Файл пустий." << endl;
	}
}

//Пошук даних про користувача по id
void Find() {
	int i_number_line_now_0 = 0, save = 0;
	ifstream fileread("Test.txt");
	ifstream fileread1("Test.txt");
	string find_id;
	string from_file, from_file1;
	int i_number_line_now = 0;

	if(Check_if_empty() != true) {
		cout << "Введіть id: ";
		cin >> find_id;
		string find = find_id;

		Cap();

		while(getline(fileread, from_file)) {
			if(from_file == find) {
				save = i_number_line_now;
			}
			else
				i_number_line_now++;
		}
		if(save > -1) {
			while(getline(fileread1, from_file1)) {
				if(save == i_number_line_now_0) {
					//cout << right << setw(3) << from_file1 << setw(3) << "|";
					cout << "| " << left << setw(3) << from_file1 << setw(1) << "|";

				}
				else if(save + 1 == i_number_line_now_0) {
					//cout << right << setw(15) << from_file1 << setw(1) << "|";
					cout << left << setw(15) << from_file1 << setw(1) << "|";

				}
				else if(save + 2 == i_number_line_now_0) {
					//cout << right << setw(10) << from_file1 << setw(1) << "|";
					cout << left << setw(10) << from_file1 << setw(1) << "|";

				}
				else if(save + 3 == i_number_line_now_0) {
					//cout << right << setw(15) << from_file1 << setw(1) << "|";
					cout << left << setw(15) << from_file1 << setw(1) << "|";

				}
				else if(save + 4 == i_number_line_now_0) {
					//cout << right << setw(15) << from_file1 << setw(1) << "|";
					cout << left << setw(15) << from_file1 << setw(1) << "|";

				}
				else if(save + 5 == i_number_line_now_0) {
					//cout << right << setw(17) << from_file1 << setw(1) << "|";
					cout << left << setw(17) << from_file1 << setw(1) << "|";

				}
				else if(save + 6 == i_number_line_now_0) {
					//cout << right << setw(12) << from_file1 << setw(7) << "|";
					cout << left << setw(18) << from_file1 << setw(1) << "|";

				}
				else if(save + 7 == i_number_line_now_0) {
					//cout << right << setw(4) << from_file1 << setw(3) << "|";
					cout << left << setw(6) << from_file1 << setw(1) << "|";

				}
				else if(save + 8 == i_number_line_now_0) {
					//cout << right << setw(5) << from_file1 << setw(4) << "|";
					cout << left << setw(8) << from_file1 << setw(1) << "|";

				}
				else if(save + 9 == i_number_line_now_0) {
					//cout << right << setw(0) << from_file1 << setw(2) << "|";
					cout << left << setw(5) << from_file1 << setw(1) << "|";

					cout << "\n+----+---------------+----------+---------------+---------------+-----------------+------------------+------+--------+-----+" << endl;
				}
				i_number_line_now_0++;
			}
		}
		else {
			cout << "У файлі немає такого id " << endl;
		}
	}
	else {
		cout << "Файл пустий" << endl;
	}
}


//Показати дані за умовою
void ConditionalData() {
	if(Check_if_empty2() != true) {
		ifstream fileread("Test2.txt");
		ofstream file("Test2.txt", ios::app);
		string from_file; //Строка файлу
		int i_number_line_now_check = 1;

		Cap(); //Виклик шапки

		int num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5, num6 = 6, num7 = 7, num8 = 8, num9 = 9;
		while(getline(fileread, from_file)) {
			if(i_number_line_now_check == num1) {
				num1 += 10;
				cout << "| " << left << setw(3) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num2) {
				num2 += 10;
				cout << left << setw(15) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num3) {
				num3 += 10;
				cout << left << setw(10) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num4) {
				num4 += 10;
				cout << left << setw(15) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num5) {
				num5 += 10;
				cout << left << setw(15) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num6) {
				num6 += 10;
				cout << left << setw(17) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num7) {
				num7 += 10;
				cout << left << setw(18) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num8) {
				num8 += 10;
				cout << left << setw(6) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check == num9) {
				num9 += 10;
				cout << left << setw(8) << from_file << setw(1) << "|";
			}
			if(i_number_line_now_check % 10 == 0) {
				cout << left << setw(5) << from_file << setw(1) << "|";
				cout << endl;
				cout << "+----+---------------+----------+---------------+---------------+-----------------+------------------+------+--------+-----+" << endl;
			}
			i_number_line_now_check++;
		}
	}
	else {
		cout << "Файл пустий.\n";
	}
}

//Видалення даних
void DeleteData() {
	ifstream fileread("Test.txt");
	ifstream fileread1("Test.txt");

	cout << "1.Очистити 1 файл.\n2.Видалити дані по Id.\n3.Очистити 2 файл." << endl;
	cout << "Виберіть пункт меню: ";
	int ChoiceDelete;
	cin >> ChoiceDelete;
	system("cls");

	if(ChoiceDelete == 1) {
		remove("Test.txt");
		ofstream file("Test.txt");
		cout << "Дані видалено " << endl;
	}
	else if(ChoiceDelete == 2) {
		if(Check_if_empty() != true) {

			int i_number_line_delete = 0, i_number_line_now_find = 0; //для хранения номера строки который нужно удалить    
			string find_id;
			string from_file, from_file1;

			cout << "Введіть id для пошуку: " << endl;
			cin >> find_id;
			//string find = "Serial_number: " + find_ser;

			while(getline(fileread1, from_file1)) {
				if(from_file1 == find_id) {
					i_number_line_delete = i_number_line_now_find;
				}
				i_number_line_now_find++;
			}

			int i_number_line_now = 0; //счётчик строк
			string line; //для хранения строки
			string line_file_text; //для хранения текста файла

			while(getline(fileread, line)) {
				if(i_number_line_delete + 1 == i_number_line_now) {

				}
				else if(i_number_line_delete + 2 == i_number_line_now) {

				}
				else if(i_number_line_delete + 3 == i_number_line_now) {

				}
				else if(i_number_line_delete + 4 == i_number_line_now) {

				}
				else if(i_number_line_delete + 5 == i_number_line_now) {

				}
				else if(i_number_line_delete + 6 == i_number_line_now) {

				}
				else if(i_number_line_delete + 7 == i_number_line_now) {

				}
				else if(i_number_line_delete + 8 == i_number_line_now) {

				}
				else if(i_number_line_delete + 9 == i_number_line_now) {

				}
				else if(!(i_number_line_now == i_number_line_delete)) {
					line_file_text.insert(line_file_text.size(), line);
					line_file_text.insert(line_file_text.size(), "\r\n");
				}
				i_number_line_now++;
			}
			fileread.close();

			//теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

			std::ofstream file;
			file.open("Test.txt", std::ios::trunc | std::ios::binary);
			file.write(line_file_text.c_str(), line_file_text.size());
			file.clear();
			cout << "Даний id видалено " << endl;
		}
	}
	else if(ChoiceDelete == 3) {
		remove("Test2.txt");
		ofstream file("Test2.txt");
		cout << "Дані №2 видалено " << endl;
	}
	else {
		if(Check_if_empty() != true) {
			int i_number_line_delete = 0;
			cout << "Вибачте, але я не вмію цього робити" << endl;
		}
		else {
			cout << "Файл порожній." << endl;
		}
	}
}

///////////////////////////////////////////////
///////////////////////////////////////////////
void Cap() {
	cout << "+----+---------------+----------+---------------+---------------+-----------------+------------------+------+--------+-----+" << endl;
	cout << "| id |    Прізвище   |   Ім'я   |  По батькові  |     Посада    |  Сімейний стан  | Неповнолітні діти| День | Місяць | Рік |" << endl;
	cout << "+----+---------------+----------+---------------+---------------+-----------------+------------------+------+--------+-----+" << endl;
}

//Перевірка індивідуальності Id;
bool Check(int id_for_cheak) {
	ifstream fileread("Test.txt");
	string from_file;
	bool q = false;

	string idX = to_string(id_for_cheak);
	while(getline(fileread, from_file)) {
		if(idX == from_file) {
			cout << "Такий id уже є у файлі " << endl;
			q = true;
			if(q == true)
				break;
		}
	}
	return q;
}

//Перевірка чи файл пустий
bool Check_if_empty() {
	bool d = false;
	ifstream fileread_check("Test.txt");
	fileread_check.seekg(0, ios::end);
	size_t size = fileread_check.tellg();
	if(size == 0) {
		d == true;
	}
	return d;
}

bool Check_if_empty2() {
	bool d = false;
	ifstream fileread_check("Test2.txt");
	fileread_check.seekg(0, ios::end);
	size_t size = fileread_check.tellg();
	if(size == 0) {
		d == true;
	}
	return d;
}

//Валідація змінної id
void ValidationData(Questionnaire* (Arr), int& i) {
	if(cin.fail()) { //якщо введено не правильно
		cin.clear();
		cin.ignore(32767, '\n'); //видаляє неправильно введений id
		cout << "Помилка!!! id не може бути символом спробуйте ще раз: " << endl;
		cin >> Arr[i].id;

	}
}
#include <iostream> //for cout, cin 
#include <fstream> //for work with file
#include <Windows.h> //for SetConsoleCP(1251);
#include <sstream>   //for getline()
#include <iomanip> //for ������������ �����
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <CString>
// //#include <stdio.h>
//#include <cctype>
//#include <string>
using namespace std; // for not std::cout

struct Questionnaire { //������
	int id; //��������� �����
	char surname[15];//ϲ�
	char name[10];
	char fathername[15];//�� �������
	char position[15]; //������
	//DaetOfStartWork daetOfStartWork[10]; //���� ������� �� ������
	char maritalStatus[13];//ѳ������ ����
	char minorChildren[3];
};
struct DaetOfStartWork {
	int day;
	int month;
	int year;
};

void EnterDate();
void ReadingData();
void Cap();
void Find();
bool Check_if_empty();
void ValidationData(Questionnaire* (Arr), int& i);
void DeleteData();
void Change();
bool Check(int id_for_cheak);
void ConditionalData();
bool Check_if_empty2();
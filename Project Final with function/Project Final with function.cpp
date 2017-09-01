#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <ctime>

#pragma warning(disable : 4996)

using namespace std;

//************************************* Signature **************************************

void Login();
void Student_Menu();
void Admin_Menu();
void Titr(int x, int y, string str, int len);
void Reserv_food_Users_Now_Week();
void Reserv_food_Users_Next_Week();
void List_reservid_Now_Week();
void List_reservid_Next_Week();
void Edit_list_Food_Now_Week();
void Edit_list_Food_Next_Week();

//************************************* Struct *****************************************

struct Student
{
	int ID;
	string name;
	string family;
	string username;
	string password;
	string student_number;
	string birth;
	string national_code;
	string discipline;
	int money;
};

struct Card
{
	string CardNumber;
	string Pass;
	string Cvv2;
	string mount;
	string year;
	long int money;
};

struct Food
{
	string Day;

	string Breakfast1;
	string BreakfastPrice1;
	string Lunch1;
	string LunchPrice1;
	string Dinner1;
	string DinnerPrice1;

	string Breakfast2;
	string BreakfastPrice2;
	string Lunch2;
	string LunchPrice2;
	string Dinner2;
	string DinnerPrice2;

	string Breakfast3;
	string BreakfastPrice3;
	string Lunch3;
	string LunchPrice3;
	string Dinner3;
	string DinnerPrice3;
};

struct UsersFood
{
	int Breakfast1_1;
	int Lunch1_1;
	int Dinner1_1;
	int Breakfast1_2;
	int Lunch1_2;
	int Dinner1_2;
	int Breakfast1_3;
	int Lunch1_3;
	int Dinner1_3;
	int Breakfast1_4;
	int Lunch1_4;
	int Dinner1_4;
	int Breakfast1_5;
	int Lunch1_5;
	int Dinner1_5;
	int Breakfast1_6;
	int Lunch1_6;
	int Dinner1_6;
	int Breakfast1_7;
	int Lunch1_7;
	int Dinner1_7;

	int Breakfast2_1;
	int Lunch2_1;
	int Dinner2_1;
	int Breakfast2_2;
	int Lunch2_2;
	int Dinner2_2;
	int Breakfast2_3;
	int Lunch2_3;
	int Dinner2_3;
	int Breakfast2_4;
	int Lunch2_4;
	int Dinner2_4;
	int Breakfast2_5;
	int Lunch2_5;
	int Dinner2_5;
	int Breakfast2_6;
	int Lunch2_6;
	int Dinner2_6;
	int Breakfast2_7;
	int Lunch2_7;
	int Dinner2_7;

	int Breakfast3_1;
	int Lunch3_1;
	int Dinner3_1;
	int Breakfast3_2;
	int Lunch3_2;
	int Dinner3_2;
	int Breakfast3_3;
	int Lunch3_3;
	int Dinner3_3;
	int Breakfast3_4;
	int Lunch3_4;
	int Dinner3_4;
	int Breakfast3_5;
	int Lunch3_5;
	int Dinner3_5;
	int Breakfast3_6;
	int Lunch3_6;
	int Dinner3_6;
	int Breakfast3_7;
	int Lunch3_7;
	int Dinner3_7;
};

enum StatusFood
{
	NotReserved,
	Reserved,
	Consumed
};

struct Transactions
{
	string time;
	int price;
	int statusTransactions;
	string through;
	int stock;
};

enum StatusTransactions
{
	Removal,
	Settle
};

struct Feedback
{
	int q_breackfast;
	int q_lunch;
	int q_dinner;
	int b_Personal;
	int t_breackfast;
	int t_lunch;
	int t_dinner;
};

enum Status_assent
{
	assent,
	disagreement,
	unknown
};

struct Request
{
	int ID;
	string iteam;
	string correct;
	bool StatusRequest;
	int assent;
};

//************************************ Variable Public ***********************************

int ID_temp;
Student strStudent[50];
Food strFood[50];
UsersFood strUsersFood[50];
Card strCard[50];
Transactions strTransactions[200];
Feedback strFeedback[50];
Request strRequest[100];
wchar_t f;
int sizeAccount;
int sizeCard;
int sizeTransactions;
int sizeFeedback;
int sizeRequest;
time_t now = time(0);
tm *ltm = localtime(&now);

//*********************************** Public Functions ***************************************

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

enum Colors {
	blue = 1,
	green,
	cyan,
	red,
	purple,
	yellow,
	grey,
	dgrey,
	hblue,
	hgreen,
	hcyan,
	hred,
	hpurple,
	hyellow,
	hwhite };

void coutc(int color, char* output)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
	cout << output << flush;
}

//************************************** File ******************************************

void Load_Account(){
	fstream profile;
	profile.open("users.txt", ios::in);
	if (profile)
	{
		int i = 0;
		while (!profile.eof())
		{
			profile >> strStudent[i].ID >> strStudent[i].name >> strStudent[i].family >> strStudent[i].username >>
				strStudent[i].password >> strStudent[i].student_number >> strStudent[i].birth >>
				strStudent[i].national_code >> strStudent[i].discipline >> strStudent[i].money >>
				strUsersFood[i].Breakfast1_1 >> strUsersFood[i].Breakfast1_2 >> strUsersFood[i].Breakfast1_3 >>
				strUsersFood[i].Breakfast1_4 >> strUsersFood[i].Breakfast1_5 >> strUsersFood[i].Breakfast1_6 >>
				strUsersFood[i].Breakfast1_7 >> strUsersFood[i].Breakfast2_1 >> strUsersFood[i].Breakfast2_2 >>
				strUsersFood[i].Breakfast2_3 >> strUsersFood[i].Breakfast2_4 >> strUsersFood[i].Breakfast2_5 >>
				strUsersFood[i].Breakfast2_6 >> strUsersFood[i].Breakfast2_7 >> strUsersFood[i].Breakfast3_1 >>
				strUsersFood[i].Breakfast3_2 >> strUsersFood[i].Breakfast3_3 >> strUsersFood[i].Breakfast3_4 >>
				strUsersFood[i].Breakfast3_5 >> strUsersFood[i].Breakfast3_6 >> strUsersFood[i].Breakfast3_7 >>
				strUsersFood[i].Lunch1_1 >> strUsersFood[i].Lunch1_2 >> strUsersFood[i].Lunch1_3 >>
				strUsersFood[i].Lunch1_4 >> strUsersFood[i].Lunch1_5 >> strUsersFood[i].Lunch1_6 >>
				strUsersFood[i].Lunch1_7 >> strUsersFood[i].Lunch2_1 >> strUsersFood[i].Lunch2_2 >>
				strUsersFood[i].Lunch2_3 >> strUsersFood[i].Lunch2_4 >> strUsersFood[i].Lunch2_5 >>
				strUsersFood[i].Lunch2_6 >> strUsersFood[i].Lunch2_7 >> strUsersFood[i].Lunch3_1 >>
				strUsersFood[i].Lunch3_2 >> strUsersFood[i].Lunch3_3 >> strUsersFood[i].Lunch3_4 >>
				strUsersFood[i].Lunch3_5 >> strUsersFood[i].Lunch3_6 >> strUsersFood[i].Lunch3_7 >>
				strUsersFood[i].Dinner1_1 >> strUsersFood[i].Dinner1_2 >> strUsersFood[i].Dinner1_3 >>
				strUsersFood[i].Dinner1_4 >> strUsersFood[i].Dinner1_5 >> strUsersFood[i].Dinner1_6 >>
				strUsersFood[i].Dinner1_7 >> strUsersFood[i].Dinner2_1 >> strUsersFood[i].Dinner2_2 >>
				strUsersFood[i].Dinner2_3 >> strUsersFood[i].Dinner2_4 >> strUsersFood[i].Dinner2_5 >>
				strUsersFood[i].Dinner2_6 >> strUsersFood[i].Dinner2_7 >> strUsersFood[i].Dinner3_1 >>
				strUsersFood[i].Dinner3_2 >> strUsersFood[i].Dinner3_3 >> strUsersFood[i].Dinner3_4 >>
				strUsersFood[i].Dinner3_5 >> strUsersFood[i].Dinner3_6 >> strUsersFood[i].Dinner3_7;
			i++;
		}
		sizeAccount = i;
	}
	profile.close();
}

void Load_Food(){
	fstream listFood;
	listFood.open("Food.txt", ios::in);
	if (listFood)
	{
		for (int i = 0; i < 7; i++)
		{
			listFood >> strFood[i].Day >> strFood[i].Breakfast1 >> strFood[i].BreakfastPrice1 >>
				strFood[i].Lunch1 >> strFood[i].LunchPrice1 >> strFood[i].Dinner1 >>
				strFood[i].DinnerPrice1;
		}
		for (int i = 0; i < 7; i++)
		{
			listFood >> strFood[i].Day >> strFood[i].Breakfast2 >> strFood[i].BreakfastPrice2 >>
				strFood[i].Lunch2 >> strFood[i].LunchPrice2 >> strFood[i].Dinner2 >>
				strFood[i].DinnerPrice2;
		}
		for (int i = 0; i < 7; i++)
		{
			listFood >> strFood[i].Day >> strFood[i].Breakfast3 >> strFood[i].BreakfastPrice3 >>
				strFood[i].Lunch3 >> strFood[i].LunchPrice3 >> strFood[i].Dinner3 >>
				strFood[i].DinnerPrice3;
		}
	}
	listFood.close();
}

void Load_Card_Bank(){
	fstream card;
	card.open("Card.txt", ios::in);
	if (card)
	{
		int i = 0;
		while (!card.eof())
		{
			card >> strCard[i].CardNumber >> strCard[i].Pass >> strCard[i].Cvv2 >>
				strCard[i].mount >> strCard[i].year >> strCard[i].money;
			i++;
		}
		sizeCard = i;
	}
	card.close();
}

void Load_Transactions(){
	fstream trans;
	trans.open(to_string(ID_temp) + "_Trans.txt", ios::in);
	if (trans)
	{
		int i = 0;
		while (!trans.eof())
		{
			trans >> strTransactions[i].time >> strTransactions[i].price >>
				strTransactions[i].statusTransactions >> strTransactions[i].through
				>> strTransactions[i].stock;
			i++;
		}
		sizeTransactions = i;
	}
	trans.close();
}

void Load_Feedback(){
	fstream survey;
	survey.open("Feedback.txt", ios::in);
	if (survey)
	{
		int i = 0;
		while (!survey.eof())
		{
			survey >> strFeedback[i].q_breackfast >> strFeedback[i].q_lunch >>
				strFeedback[i].q_dinner >> strFeedback[i].b_Personal >>
				strFeedback[i].t_breackfast >> strFeedback[i].t_lunch >> strFeedback[i].t_dinner;
			i++;
		}
		sizeFeedback = i;
	}
	survey.close();
}

void Load_Request(){
	fstream Request;
	Request.open("Request.txt", ios::in);
	int i = 0;
	if (Request)
	{
		while (!Request.eof())
		{
			Request >> strRequest[i].ID >> strRequest[i].iteam >> strRequest[i].correct
				>> strRequest[i].StatusRequest >> strRequest[i].assent;
			i++;
		}
	}
	sizeRequest = i;
	Request.close();
}

void Save_Change_Account(){
	fstream profile;
	profile.open("users.txt", ios::out);
	if (profile)
	{
		for (int i = 0; i < sizeAccount; i++)
		{
			if (i == sizeAccount - 1)
			{
				profile << strStudent[i].ID << " " << strStudent[i].name << " " << strStudent[i].family << " " <<
					strStudent[i].username << " " << strStudent[i].password << " " <<
					strStudent[i].student_number << " " << strStudent[i].birth << " " <<
					strStudent[i].national_code << " " << strStudent[i].discipline << " " <<
					strStudent[i].money << endl << strUsersFood[i].Breakfast1_1 << " " <<
					strUsersFood[i].Breakfast1_2 << " " << strUsersFood[i].Breakfast1_3
					<< " " << strUsersFood[i].Breakfast1_4 << " " << strUsersFood[i].Breakfast1_5
					<< " " << strUsersFood[i].Breakfast1_6 << " " << strUsersFood[i].Breakfast1_7
					<< "  " << strUsersFood[i].Breakfast2_1 << " " << strUsersFood[i].Breakfast2_2
					<< " " << strUsersFood[i].Breakfast2_3 << " " << strUsersFood[i].Breakfast2_4
					<< " " << strUsersFood[i].Breakfast2_5 << " " << strUsersFood[i].Breakfast2_6
					<< " " << strUsersFood[i].Breakfast2_7 << "  " << strUsersFood[i].Breakfast3_1
					<< " " << strUsersFood[i].Breakfast3_2 << " " << strUsersFood[i].Breakfast3_3
					<< " " << strUsersFood[i].Breakfast3_4 << " " << strUsersFood[i].Breakfast3_5
					<< " " << strUsersFood[i].Breakfast3_6 << " " << strUsersFood[i].Breakfast3_7
					<< " " << endl << strUsersFood[i].Lunch1_1 << " " << strUsersFood[i].Lunch1_2
					<< " " << strUsersFood[i].Lunch1_3 << " " << strUsersFood[i].Lunch1_4 << " " <<
					strUsersFood[i].Lunch1_5 << " " << strUsersFood[i].Lunch1_6 << " " <<
					strUsersFood[i].Lunch1_7 << "  " << strUsersFood[i].Lunch2_1 << " " <<
					strUsersFood[i].Lunch2_2 << " " << strUsersFood[i].Lunch2_3 << " " <<
					strUsersFood[i].Lunch2_4 << " " << strUsersFood[i].Lunch2_5 << " " <<
					strUsersFood[i].Lunch2_6 << " " << strUsersFood[i].Lunch2_7 << "  " <<
					strUsersFood[i].Lunch3_1 << " " << strUsersFood[i].Lunch3_2 << " " <<
					strUsersFood[i].Lunch3_3 << " " << strUsersFood[i].Lunch3_4 << " " <<
					strUsersFood[i].Lunch3_5 << " " << strUsersFood[i].Lunch3_6 << " " <<
					strUsersFood[i].Lunch3_7 << " " << endl << strUsersFood[i].Dinner1_1
					<< " " << strUsersFood[i].Dinner1_2 << " " << strUsersFood[i].Dinner1_3
					<< " " << strUsersFood[i].Dinner1_4 << " " << strUsersFood[i].Dinner1_5
					<< " " << strUsersFood[i].Dinner1_6 << " " << strUsersFood[i].Dinner1_7
					<< "  " << strUsersFood[i].Dinner2_1 << " " << strUsersFood[i].Dinner2_2
					<< " " << strUsersFood[i].Dinner2_3 << " " << strUsersFood[i].Dinner2_4
					<< " " << strUsersFood[i].Dinner2_5 << " " << strUsersFood[i].Dinner2_6
					<< " " << strUsersFood[i].Dinner2_7 << "  " << strUsersFood[i].Dinner3_1
					<< " " << strUsersFood[i].Dinner3_2 << " " << strUsersFood[i].Dinner3_3
					<< " " << strUsersFood[i].Dinner3_4 << " " << strUsersFood[i].Dinner3_5
					<< " " << strUsersFood[i].Dinner3_6 << " " << strUsersFood[i].Dinner3_7;
			}
			else
			{
				profile << strStudent[i].ID << " " << strStudent[i].name << " " << strStudent[i].family << " " <<
					strStudent[i].username << " " << strStudent[i].password << " " <<
					strStudent[i].student_number << " " << strStudent[i].birth << " " <<
					strStudent[i].national_code << " " << strStudent[i].discipline << " " <<
					strStudent[i].money << endl << strUsersFood[i].Breakfast1_1 << " " <<
					strUsersFood[i].Breakfast1_2 << " " << strUsersFood[i].Breakfast1_3
					<< " " << strUsersFood[i].Breakfast1_4 << " " << strUsersFood[i].Breakfast1_5
					<< " " << strUsersFood[i].Breakfast1_6 << " " << strUsersFood[i].Breakfast1_7
					<< "  " << strUsersFood[i].Breakfast2_1 << " " << strUsersFood[i].Breakfast2_2
					<< " " << strUsersFood[i].Breakfast2_3 << " " << strUsersFood[i].Breakfast2_4
					<< " " << strUsersFood[i].Breakfast2_5 << " " << strUsersFood[i].Breakfast2_6
					<< " " << strUsersFood[i].Breakfast2_7 << "  " << strUsersFood[i].Breakfast3_1
					<< " " << strUsersFood[i].Breakfast3_2 << " " << strUsersFood[i].Breakfast3_3
					<< " " << strUsersFood[i].Breakfast3_4 << " " << strUsersFood[i].Breakfast3_5
					<< " " << strUsersFood[i].Breakfast3_6 << " " << strUsersFood[i].Breakfast3_7
					<< " " << endl << strUsersFood[i].Lunch1_1 << " " << strUsersFood[i].Lunch1_2
					<< " " << strUsersFood[i].Lunch1_3 << " " << strUsersFood[i].Lunch1_4 << " " <<
					strUsersFood[i].Lunch1_5 << " " << strUsersFood[i].Lunch1_6 << " " <<
					strUsersFood[i].Lunch1_7 << "  " << strUsersFood[i].Lunch2_1 << " " <<
					strUsersFood[i].Lunch2_2 << " " << strUsersFood[i].Lunch2_3 << " " <<
					strUsersFood[i].Lunch2_4 << " " << strUsersFood[i].Lunch2_5 << " " <<
					strUsersFood[i].Lunch2_6 << " " << strUsersFood[i].Lunch2_7 << "  " <<
					strUsersFood[i].Lunch3_1 << " " << strUsersFood[i].Lunch3_2 << " " <<
					strUsersFood[i].Lunch3_3 << " " << strUsersFood[i].Lunch3_4 << " " <<
					strUsersFood[i].Lunch3_5 << " " << strUsersFood[i].Lunch3_6 << " " <<
					strUsersFood[i].Lunch3_7 << " " << endl << strUsersFood[i].Dinner1_1
					<< " " << strUsersFood[i].Dinner1_2 << " " << strUsersFood[i].Dinner1_3
					<< " " << strUsersFood[i].Dinner1_4 << " " << strUsersFood[i].Dinner1_5
					<< " " << strUsersFood[i].Dinner1_6 << " " << strUsersFood[i].Dinner1_7
					<< "  " << strUsersFood[i].Dinner2_1 << " " << strUsersFood[i].Dinner2_2
					<< " " << strUsersFood[i].Dinner2_3 << " " << strUsersFood[i].Dinner2_4
					<< " " << strUsersFood[i].Dinner2_5 << " " << strUsersFood[i].Dinner2_6
					<< " " << strUsersFood[i].Dinner2_7 << "  " << strUsersFood[i].Dinner3_1
					<< " " << strUsersFood[i].Dinner3_2 << " " << strUsersFood[i].Dinner3_3
					<< " " << strUsersFood[i].Dinner3_4 << " " << strUsersFood[i].Dinner3_5
					<< " " << strUsersFood[i].Dinner3_6 << " " << strUsersFood[i].Dinner3_7 
					<< endl;
			}
		}
	}
	profile.close();
}

void Save_Change_Food(){
	fstream listFood;
	listFood.open("Food.txt", ios::out);
	if (listFood)
	{
		for (int i = 0; i < 7; i++)
		{
			listFood << strFood[i].Day << " " << strFood[i].Breakfast1 << " " << strFood[i].BreakfastPrice1 << " " <<
				strFood[i].Lunch1 << " " << strFood[i].LunchPrice1 << " " << strFood[i].Dinner1 << " " <<
				strFood[i].DinnerPrice1 << endl;
		}
		listFood << endl;
		for (int i = 0; i < 7; i++)
		{
			listFood << strFood[i].Day << " " << strFood[i].Breakfast2 << " " << strFood[i].BreakfastPrice2 << " " <<
				strFood[i].Lunch2 << " " << strFood[i].LunchPrice2 << " " << strFood[i].Dinner2 << " " <<
				strFood[i].DinnerPrice2 << endl;
		}
		listFood << endl;
		for (int i = 0; i < 7; i++)
		{
			listFood << strFood[i].Day << " " << strFood[i].Breakfast3 << " " << strFood[i].BreakfastPrice3 << " " <<
				strFood[i].Lunch3 << " " << strFood[i].LunchPrice3 << " " << strFood[i].Dinner3 << " " <<
				strFood[i].DinnerPrice3 << endl;
		}
	}
	listFood.close();
}

void Save_Change_Card_Bank(){
	fstream card;
	card.open("Card.txt", ios::out);
	if (card)
	{
		for (int i = 0; i < sizeCard-1; i++)
		{
			card << strCard[i].CardNumber << " " << strCard[i].Pass << " " << strCard[i].Cvv2 << " " <<
				strCard[i].mount << " " << strCard[i].year << " " << strCard[i].money << endl;
		}
		card << strCard[sizeCard - 1].CardNumber << " " << strCard[sizeCard - 1].Pass << " " << strCard[sizeCard - 1].Cvv2 << " " <<
			strCard[sizeCard - 1].mount << " " << strCard[sizeCard - 1].year << " " << strCard[sizeCard - 1].money;
	}
	card.close();
}

void Save_Change_Transactions(){
	fstream trans;
	trans.open(to_string(ID_temp) + "_Trans.txt", ios::out | ios::app);
	if (trans)
	{
		trans << strTransactions[sizeTransactions - 1].time << " "
			<< strTransactions[sizeTransactions - 1].price
			<< " " << strTransactions[sizeTransactions - 1].statusTransactions
			<< " " << strTransactions[sizeTransactions - 1].through 
			<< " " << strTransactions[sizeTransactions - 1].stock << endl;
	}
	trans.close();
}

void Save_Change_survey(){
	fstream survey;
	survey.open("Feedback.txt", ios::out | ios::app);
	if (survey)
	{
		survey << strFeedback[sizeFeedback].q_breackfast << " " << strFeedback[sizeFeedback].q_lunch
			<< " " << strFeedback[sizeFeedback].q_dinner << " " << strFeedback[sizeFeedback].b_Personal
			<< " " << strFeedback[sizeFeedback].t_breackfast << " " << strFeedback[sizeFeedback].t_lunch
			<< " " << strFeedback[sizeFeedback] .t_dinner<< endl;
	}
	survey.close();
}

void Save_Change_Request(){
	fstream Request;
	Request.open("Request.txt", ios::out | ios::app);
	if (Request)
	{
		Request << strRequest[sizeRequest].ID << " " << strRequest[sizeRequest].iteam
			<< " " << strRequest[sizeRequest].correct << " " << strRequest[sizeRequest].StatusRequest 
			<< " " << strRequest[sizeRequest].assent << endl;
	}
	Request.close();
}

void Save_Change_Request_Admin(){
	fstream Request;
	Request.open("Request.txt", ios::out);
	if (Request)
	{
		for (int i = 0; i < sizeRequest; i++)
		{
				Request << strRequest[i].ID << " " << strRequest[i].iteam
					<< " " << strRequest[i].correct << " " << strRequest[i].StatusRequest
					<< " " << strRequest[i].assent << endl;
		}
	}
	Request.close();
}

//******************************** Graphic & Animation ************************************

void Kadr(int x,int y,int length,int width){
	for (int i = x+1; i < x+length; i++)
	{
		f = 196;
		gotoxy(i, y);
		wcout << f ;
	}
	f = 218;
	gotoxy(x, y);
	wcout << f;
	f = 191;
	gotoxy(x+length, y);
	wcout << f;
	for (int i = y+1; i < y+width; i++)
	{
		f = 179;
		gotoxy(x, i);
		wcout << f;
		gotoxy(x + length, i);
		wcout << f;
	}
	f = 192;
	gotoxy(x, y + width);
	wcout << f;
	for (int i = x+1; i < x+length; i++)
	{
		f = 196;
		gotoxy(i, y + width);
		wcout << f;
	}
	f = 217;
	gotoxy(x+length, y + width);
	wcout << f;
}

void Kadr2(int x, int y, int length, int width){
	int had = 120 - (x + length);
	for (int i = y; i <= y + width; i++)
	{
		for (int j = 0; j < x; j++)
		{
			gotoxy(j, i);
			f = 219;
			wcout << f;
		}
	}
	for (int i = y; i <= y + width; i++)
	{
		for (int j = x + length + 1; j < x + length + had; j++)
		{
			gotoxy(j, i);
			f = 219;
			wcout << f;
		}
	}
	for (int i = x + 1; i < x + length; i++)
	{
		f = 196;
		gotoxy(i, y);
		wcout << f;
	}
	f = 218;
	gotoxy(x, y);
	wcout << f;
	f = 191;
	gotoxy(x + length, y);
	wcout << f;
	for (int i = y + 1; i < y + width; i++)
	{
		f = 179;
		gotoxy(x, i);
		wcout << f;
		gotoxy(x + length, i);
		wcout << f;
	}
	f = 192;
	gotoxy(x, y + width);
	wcout << f;
	for (int i = x + 1; i < x + length; i++)
	{
		f = 196;
		gotoxy(i, y + width);
		wcout << f;
	}
	f = 217;
	gotoxy(x + length, y + width);
	wcout << f;
}

void Titr(int x, int y, string str, int len){
	gotoxy(x, y);
	for (int i = 0; i < len; i++)
	{
		f = 196;
		wcout << f;
	}
	f = 182;
	wcout << f;
	coutc(15, "");
	cout << str;
	coutc(7, "");
	f = 199;
	wcout << f;
	for (int i = 0; i < len; i++)
	{
		f = 196;
		wcout << f;
	}
}

void Watch(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	if (ltm->tm_hour > 12)
	{
		cout << ltm->tm_hour - 12 << ":";
		cout << ltm->tm_min;
		cout << " PM ";
	}
	else
	{
		cout << ltm->tm_hour << ":";
		cout << ltm->tm_min;
		cout << " AM ";
	}
}

void Date(){
	char week[7][10] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

	time_t now = time(0);
	tm *ltm = localtime(&now);
	cout << 1900 + ltm->tm_year << "/";
	cout << 1 + ltm->tm_mon << "/";
	cout << ltm->tm_mday << " ";
	cout << week[ltm->tm_wday - 1];
}

string TimeString(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	string TimeTransactions = to_string(ltm->tm_hour) + ":" +
		to_string(ltm->tm_min) + "-" + to_string(1900 + ltm->tm_year)
		+ "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(ltm->tm_mday);
	return TimeTransactions;
}

void Animation(string str)
{
	for (int i = 0; i < 50; i++)
	{
		gotoxy(15+i, 10);
		cout << str;
		Sleep(70);
		system("cls");
	}
}

void loading(){
	system("color 8F");
	gotoxy(20, 15);
	cout << "Loading : ";
	Kadr(32, 14, 63, 2);
	f = 219;
	gotoxy(33, 15);
	for (int i = 0; i < 62; i++)
	{
		wcout << f;
		Sleep(50);
	}
	system("cls");
	system("color 07");
}

void Food_table(){
	gotoxy(8, 2);
	for (int i = 0; i < 41; i++)
	{
		f = 196;
		wcout << f;
	}
	f = 182;
	wcout << f;
	coutc(hwhite, "");
	cout << " Selection Dish ";
	coutc(grey, "");
	f = 199;
	wcout << f;
	for (int i = 0; i < 44; i++)
	{
		f = 196;
		wcout << f;
	}
	gotoxy(8, 7);                                   // char ╔
	f = 201;
	wcout << f;
	gotoxy(110, 7);									// char ╗
	f = 187;
	wcout << f;
	for (int i = 0; i < 9; i++)                     // char ═
	{
		for (int j = 0; j < 101; j++)
		{
			gotoxy(9 + j, 7 + (i * 2));
			f = 205;
			wcout << f;
		}
	}
	for (int i = 0; i < 8; i++)                     // char ║
	{
		f = 186;
		gotoxy(8, 8 + (2 * i));
		wcout << f;
		gotoxy(20, 8 + (2 * i));
		wcout << f;
		gotoxy(50, 8 + (2 * i));
		wcout << f;
		gotoxy(80, 8 + (2 * i));
		wcout << f;
		gotoxy(110, 8 + (2 * i));
		wcout << f;
		if (i != 0)									// char [ ]
		{
			gotoxy(107, 8 + (2 * i));
			cout << "[ ]";
		}
	}
	for (int i = 0; i < 8; i++)                     // char │
	{
		f = 179;
		gotoxy(50, 8 + (2 * i));
		wcout << f;
		gotoxy(80, 8 + (2 * i));
		wcout << f;
		if (i != 0)									// char [ ]
		{
			gotoxy(47, 8 + (2 * i));
			cout << "[ ]";
			gotoxy(77, 8 + (2 * i));
			cout << "[ ]";
		}
	}
	for (int i = 0; i < 7; i++)						// char ╠
	{
		gotoxy(8, 8 + (2 * i) + 1);
		f = 204;
		wcout << f;
	}
	for (int i = 0; i < 7; i++)						// char ╣
	{
		gotoxy(110, 8 + (2 * i) + 1);
		f = 185;
		wcout << f;
	}
	for (int i = 0; i < 7; i++)						// char ╬
	{
		f = 206;
		gotoxy(20, 8 + (2 * i) + 1);
		wcout << f;
	}
	for (int i = 0; i < 7; i++)						// char ╪
	{
		f = 216;
		gotoxy(50, 8 + (2 * i) + 1);
		wcout << f;
		gotoxy(80, 8 + (2 * i) + 1);
		wcout << f;
	}
	for (int i = 0; i < 3; i++)						// char ╦
	{
		gotoxy(20 + (i * 30), 7);
		f = 203;
		wcout << f;
	}
	for (int i = 0; i < 2; i++)						// char ╤
	{
		gotoxy(50 + (i * 30), 7);
		f = 209;
		wcout << f;
	}
	gotoxy(20, 23);									// char ╩
	f = 202;
	wcout << f;
	for (int i = 0; i < 2; i++)						// char ╧
	{
		gotoxy(50 + (i * 30), 23);
		f = 207;
		wcout << f;
	}
	gotoxy(8, 23);									// char ╚
	f = 200;
	wcout << f;
	gotoxy(110, 23);								// char ╝
	f = 188;
	wcout << f;
	for (int i = 0; i < 7; i++)
	{
		gotoxy(10, 10 + (i * 2));
		cout << strFood[i].Day;
	}
	gotoxy(10, 8);									// titel
	cout << "Day";
	gotoxy(22, 8);
	cout << "Breakfast";
	gotoxy(52, 8);
	cout << "Lunch";
	gotoxy(82, 8);
	cout << "Dinner";
	Kadr2(3, 0, 113, 29);
}

void Kerkere(){
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			if (i % 2 == 0)
			{
				coutc(grey, "");
				f = 219;
				wcout << f << f;
			}
			else
			{
				coutc(hred, "");
				f = 219;
				wcout << f << f;
			}
		}
		Sleep(50);
	}
	system("cls");
	system("color 07");
}

//************************************** Student Menu ********************************

void Request_Menu_Student(int ID1, int Iteam){
	system("cls");
	string Correct;
	int numKey;
	Kadr2(35, 0, 50, 29);
	Titr(40, 3, " Request For Editing ", 9);
	switch (Iteam)
	{
	case 1:
		gotoxy(41, 6 );
		cout << "Wrong First Name : " << setw(20) << strStudent[ID1].name;
		gotoxy(46, 10);
		cout << "Enter The Correct First Name";
		Kadr(40, 9, 40, 5);
		Kadr(42, 11, 36, 2);
		gotoxy(43, 12);
		cin >> Correct;
		break;
	case 2:
		gotoxy(41, 6);
		cout << "Wrong Last Name : " << setw(21) << strStudent[ID1].family;
		gotoxy(46, 10);
		cout << "Enter The Correct Last Name";
		Kadr(40, 9, 40, 5);
		Kadr(42, 11, 36, 2);
		gotoxy(43, 12);
		cin >> Correct;
		break;
	case 3:
		gotoxy(41, 6);
		cout << "Wrong Student Number : " << setw(16) << strStudent[ID1].student_number;
		gotoxy(45, 10);
		cout << "Enter The Correct Student Number";
		Kadr(40, 9, 40, 5);
		Kadr(42, 11, 36, 2);
		gotoxy(43, 12);
		cin >> Correct;
		break;
	case 4:
		gotoxy(41, 6);
		cout << "Wrong Year of Birth  : " << setw(16) << strStudent[ID1].birth;
		gotoxy(48, 10);
		cout << "Enter The Correct Brthday";
		Kadr(40, 9, 40, 5);
		Kadr(42, 11, 36, 2);
		gotoxy(43, 12);
		cin >> Correct;
		break;
	case 5:
		gotoxy(41, 6);
		cout << "Wrong National Code  : " << setw(16) << strStudent[ID1].national_code;
		gotoxy(45, 10);
		cout << "Enter The Correct National code";
		Kadr(40, 9, 40, 5);
		Kadr(42, 11, 36, 2);
		gotoxy(43, 12);
		cin >> Correct;
		break;
	case 6:
		gotoxy(41, 6);
		cout << "Wrong Discipline : " << setw(20) << strStudent[ID1].discipline;
		gotoxy(46, 10);
		cout << "Enter The Correct Discipline";
		Kadr(40, 9, 40, 5);
		Kadr(42, 11, 36, 2);
		gotoxy(43, 12);
		cin >> Correct;
		break;
	default:
		break;
	}
	gotoxy(35, 27);
	f = 195;
	wcout << f;
	for (int i = 1; i < 50; i++)
	{

		gotoxy(35 + i, 27);
		f = 196;
		wcout << f;
	}
	gotoxy(85, 27);
	f = 180;
	wcout << f;
	gotoxy(45, 28);
	cout << "1. Send" << setw(25) << "0. Back ";
	cin >> numKey;
	if (numKey == 1)
	{
		Load_Request();
		switch (Iteam)
		{
		case 1:
			strRequest[sizeRequest].ID = ID1;
			strRequest[sizeRequest].correct = Correct;
			strRequest[sizeRequest].iteam = "f.n";
			strRequest[sizeRequest].StatusRequest = false;
			strRequest[sizeRequest].assent = unknown;
			break;
		case 2:
			strRequest[sizeRequest].ID = ID1;
			strRequest[sizeRequest].correct = Correct;
			strRequest[sizeRequest].iteam = "l.n";
			strRequest[sizeRequest].StatusRequest = false;
			strRequest[sizeRequest].assent = unknown;
			break;
		case 3:
			strRequest[sizeRequest].ID = ID1;
			strRequest[sizeRequest].correct = Correct;
			strRequest[sizeRequest].iteam = "s.n";
			strRequest[sizeRequest].StatusRequest = false;
			strRequest[sizeRequest].assent = unknown;
			break;
		case 4:
			strRequest[sizeRequest].ID = ID1;
			strRequest[sizeRequest].correct = Correct;
			strRequest[sizeRequest].iteam = "y.b";
			strRequest[sizeRequest].StatusRequest = false;
			strRequest[sizeRequest].assent = unknown;
			break;
		case 5:
			strRequest[sizeRequest].ID = ID1;
			strRequest[sizeRequest].correct = Correct;
			strRequest[sizeRequest].iteam = "n.c";
			strRequest[sizeRequest].StatusRequest = false;
			strRequest[sizeRequest].assent = unknown;
			break;
		case 6:
			strRequest[sizeRequest].ID = ID1;
			strRequest[sizeRequest].correct = Correct;
			strRequest[sizeRequest].iteam = "d";
			strRequest[sizeRequest].StatusRequest = false;
			strRequest[sizeRequest].assent = unknown;
			break;
		default:
			break;
		}
		Save_Change_Request();
		sizeRequest++;
	}
}

void Profile(){
	Kadr2(35, 0, 50, 29);
	int cursor = 1;
	int numKey;
	Titr(43, 3, " Profile ", 12);
	gotoxy(43, 4 + 2 * cursor); cursor++;
	cout << "First Name : " << setw(22) << strStudent[ID_temp].name;
	gotoxy(43, 4 + 2 * cursor); cursor++;
	cout << "Last Name : " << setw(23) << strStudent[ID_temp].family;
	gotoxy(43, 4 + 2 * cursor); cursor++;
	cout << "Student Number : " << setw(18)<< strStudent[ID_temp].student_number;
	gotoxy(43, 4 + 2 * cursor); cursor++;
	cout << "Year of Birth  : " << setw(18) << strStudent[ID_temp].birth;
	gotoxy(43, 4 + 2 * cursor); cursor++;
	cout << "National Code  : " << setw(18) << strStudent[ID_temp].national_code;
	gotoxy(43, 4 + 2 * cursor); cursor++;
	cout << "Discipline : " << setw(22) << strStudent[ID_temp].discipline;
	gotoxy(35, 27);
	f = 195;
	wcout << f;
	for (int i = 1; i < 50; i++)
	{

		gotoxy(35 + i, 27);
		f = 196;
		wcout << f;
	}
	gotoxy(85, 27);
	f = 180;
	wcout << f;
	cursor++;
	gotoxy(43, 28);
	cout << "1.Request For Edit" << setw(18) << "0.Back ";
	cin >> numKey;
	if (numKey == 1)
	{
		for (int i = 1; i <= 6; i++)
		{
			gotoxy(40, 4 + (2 * i));
			cout << i << ". ";
		}
		gotoxy(43, 28);
		cout << "\t\t\t\t\t  ";
		gotoxy(42, 28);
		cout << "Enter Num of Iteam : ";
		cin >> numKey;
		system("cls");
		Request_Menu_Student(ID_temp, numKey);
	}
}

void Change_Password(){
	Kadr2(35, 0, 50, 29);
	int cursor = 2;
	string oldpass, newpass, passConfrim;
	Titr(42, 3, " Change Password ", 9);
	gotoxy(42, 3 + 2 * cursor); cursor++;
	cout << "Enter Old Password : " ;
	cin >> oldpass;
	while (oldpass!=strStudent[ID_temp].password)
	{
		coutc(hred, "");
		Kadr(42, 10, 38, 2);
		gotoxy(55, 11);
		cout << "It is Wrong !!";
		Sleep(1000);
		coutc(grey, "");
		gotoxy(42, 7);
		cout << "\t\t\t\t\t  ";
		gotoxy(42,10);
		cout << "\t\t\t\t\t  ";
		gotoxy(42, 11);
		cout << "\t\t\t\t\t  ";
		gotoxy(42, 12);
		cout << "\t\t\t\t\t  ";
		gotoxy(42, 5);
		cout << "\t\t\t\t\t";
		gotoxy(42, 7);
		cout << "Enter Old Password : ";
		cin >> oldpass;
	}
	gotoxy(42, 3 + 2 * cursor); cursor++;
	cout << "Enter New Password : " ;
	cin >> newpass;
	gotoxy(42, 3 + 2 * cursor); cursor++;
	cout << "Confrim Your Password : " ;
	cin >> passConfrim;
	while (passConfrim != newpass)
	{
		
		gotoxy(55, 14);
		coutc(hred, "It is Wrong !!");
		Kadr(42, 13, 38, 2);
		Sleep(1000);
		system("color 07");
		gotoxy(42, 13);
		cout << "\t\t\t\t\t  ";
		gotoxy(42, 14);
		cout << "\t\t\t\t\t  ";
		gotoxy(42, 15);
		cout << "\t\t\t\t\t  ";
		gotoxy(42, 7);
		cout << "\t\t\t\t\t";
		gotoxy(42, 9);
		cout << "\t\t\t\t\t";
		gotoxy(42, 11);
		cout << "\t\t\t\t\t";
		gotoxy(42, 9);
		cout << "Confrim Your Password : ";
		gotoxy(42, 7); ;
		cout << "Enter New Password : ";
		cin >> newpass;
		gotoxy(42, 9);
		cout << "Confrim Your Password : ";
		cin >> passConfrim;
	}
	strStudent[ID_temp].password = newpass;
	Save_Change_Account();
	gotoxy(47, 14);
	coutc(hcyan, "Your Password is Changed !!");
	Kadr(42, 13, 38, 2);
	Sleep(2000);
	system("color 07");
}

void Check_Status_Food_Last_Week(){
	int cursor = 0;
	coutc(dgrey, "");
	switch (strUsersFood[ID_temp].Breakfast1_1)
	{
	case NotReserved :
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed :
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Breakfast1_2)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Breakfast1_3)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Breakfast1_4)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Breakfast1_5)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Breakfast1_6)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Breakfast1_7)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	cursor = 0;
	switch (strUsersFood[ID_temp].Lunch1_1)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Lunch1_2)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Lunch1_3)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Lunch1_4)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Lunch1_5)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Lunch1_6)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	switch (strUsersFood[ID_temp].Lunch1_7)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	cursor = 0;

	switch (strUsersFood[ID_temp].Dinner1_1)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner1_2)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner1_3)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner1_4)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner1_5)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner1_6)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner1_7)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	coutc(hwhite, "");
	gotoxy(50, 27);
	cout << "101. Next Week >";
	coutc(grey, "");
}

void Check_Status_Food_Now_Week(){
	int cursor = 0;
	coutc(hwhite, "");
	switch (strUsersFood[ID_temp].Breakfast2_1)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast2_2)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast2_3)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast2_4)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast2_5)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast2_6)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast2_7)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	cursor = 0;

	switch (strUsersFood[ID_temp].Lunch2_1)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch2_2)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch2_3)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch2_4)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch2_5)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch2_6)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch2_7)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	cursor = 0;

	switch (strUsersFood[ID_temp].Dinner2_1)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner2_2)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner2_3)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner2_4)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner2_5)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner2_6)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner2_7)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;
	coutc(grey, "");

	coutc(hwhite, "");
	gotoxy(40, 27);
	cout << "< 99. Last Week  |  101. Next Week >";
	coutc(grey, "");
}

void Check_Status_Food_Next_Week(){
	int cursor = 0;
	switch (strUsersFood[ID_temp].Breakfast3_1)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast3_2)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast3_3)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast3_4)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast3_5)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast3_6)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Breakfast3_7)
	{
	case NotReserved:
		gotoxy(48, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(48, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(48, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	cursor = 0;

	switch (strUsersFood[ID_temp].Lunch3_1)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch3_2)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch3_3)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch3_4)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch3_5)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch3_6)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Lunch3_7)
	{
	case NotReserved:
		gotoxy(78, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(78, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(78, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	cursor = 0;

	switch (strUsersFood[ID_temp].Dinner3_1)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner3_2)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner3_3)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner3_4)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner3_5)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner3_6)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	switch (strUsersFood[ID_temp].Dinner3_7)
	{
	case NotReserved:
		gotoxy(108, 10 + cursor);
		cout << "-";
		break;
	case Reserved:
		gotoxy(108, 10 + cursor);
		f = 251;
		wcout << f;
		break;
	case Consumed:
		gotoxy(108, 10 + cursor);
		f = 254;
		wcout << f;
		break;
	default:
		break;
	}cursor += 2;

	coutc(hwhite, "");
	gotoxy(50, 27);
	cout << "99. Last Week >";
	coutc(grey, "");
}

void Reserv_Food_Last_Week(){
	int count = 1;
	Load_Food();
	Food_table();
	for (int i = 0; i < 7; i++)
	{
		gotoxy(10, 10 + (i * 2));
		cout << strFood[i].Day;
		gotoxy(22, 10 + (i * 2));
		cout << count << ". " << strFood[i].Breakfast1;	count++;
		gotoxy(52, 10 + (i * 2));
		cout << count << ". " << strFood[i].Lunch1; count++;
		gotoxy(82, 10 + (i * 2));
		cout << count << ". " << strFood[i].Dinner1; count++;
	}
	Check_Status_Food_Last_Week();
}

void Reserv_Food_Now_Week(){
	int count = 1;
	Load_Food();
	Food_table();
	for (int i = 0; i < 7; i++)
	{
		gotoxy(10, 10 + (i * 2));
		cout << strFood[i].Day;
		gotoxy(22, 10 + (i * 2));
		cout << count << ". " << strFood[i].Breakfast2;	count++;
		gotoxy(52, 10 + (i * 2));
		cout << count << ". " << strFood[i].Lunch2; count++;
		gotoxy(82, 10 + (i * 2));
		cout << count << ". " << strFood[i].Dinner2; count++;
	}
	Check_Status_Food_Now_Week();
}

void Reserv_Food_Next_Week(){
	int count = 1;
	Load_Food();
	Food_table();
	for (int i = 0; i < 7; i++)
	{
		gotoxy(10, 10 + (i * 2));
		cout << strFood[i].Day;
		gotoxy(22, 10 + (i * 2));
		cout << count << ". " << strFood[i].Breakfast3;	count++;
		gotoxy(52, 10 + (i * 2));
		cout << count << ". " << strFood[i].Lunch3; count++;
		gotoxy(82, 10 + (i * 2));
		cout << count << ". " << strFood[i].Dinner3; count++;
	}
	Check_Status_Food_Next_Week();
}

void Reserv_food_Users_Last_Week(){
	int numFood;
	int numKey;
	do
	{
		system("cls");
		Reserv_Food_Last_Week();
		Kadr(8, 4, 102, 2);
		gotoxy(10, 5);
		cout << "Name : " << strStudent[ID_temp].name << "\t" << strStudent[ID_temp].family << setw(36) <<
			"2016/1/9 - 2016/1/15 ";
		coutc(hred, "(Last Week)");
		coutc(grey, "");
		cout << setw(25) << " | Money :";
		if (strStudent[ID_temp].money >= 10000)
		{
			coutc(11, " ");
		}
		else if (strStudent[ID_temp].money < 10000 && strStudent[ID_temp].money >= 5000)
		{
			coutc(14, " ");
		}
		else
		{
			coutc(12, " ");
		}
		cout << strStudent[ID_temp].money;
		coutc(7, " ");
		gotoxy(12, 2);
		cout << " ";
		Watch();
		gotoxy(95, 2);
		cout << " ";
		Date();
		cout << " ";
		Kadr(8, 24, 102, 4);
		gotoxy(100, 27);
		cout << "0. Back";
		gotoxy(10, 25);
		cout << "Enter Food Number : ";
		cin >> numFood;
		gotoxy(100, 27);
		cout << "       ";
		if (numFood == 0)
		{
			break;
		}
		else if (numFood == 101)
		{
			Reserv_food_Users_Now_Week();
			break;
		}
		else if ((numFood - 1) % 3 == 0)
		{
			gotoxy(50, 25);
			cout << "Name Of Breakfast : " << strFood[(numFood - 1) / 3].Breakfast1;
			gotoxy(95, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].BreakfastPrice1;
			gotoxy(10, 27);
			if ((numFood + 2) / 3 == 1)
			{
				coutc(hyellow, "");
				gotoxy(22, 10);
				cout << "1. " << strFood[0].Breakfast1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 9)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast1_1 == NotReserved)
				{
					cout << "Enter Number For" << setw(20);
					coutc(15, "1. reserv");
					cout << setw(40) << "2. Back To Reselection" << setw(20) << "0. Back";
					coutc(7, " ");
					cin >> numKey;
					if (numKey == 1)
					{
						gotoxy(10, 27);
						cout << "\t\t\t\t\t\t\t\t\t\t";
						gotoxy(10, 27);
						coutc(12, "Not Possible  !!!");
						Sleep(2000);
						system("color 07");
					}
				}
				else if (strUsersFood[ID_temp].Breakfast1_1 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast1_1 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].through = "d.f.b";
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 2)
			{
				coutc(hyellow, "");
				gotoxy(22, 12);
				cout << "4. " << strFood[1].Breakfast1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 10)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast1_2 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1))
						{
							strUsersFood[ID_temp].Breakfast1_2 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].through = "r.f.b";
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast1_2 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast1_2 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].through = "d.f.b";
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 3)
			{
				coutc(hyellow, "");
				gotoxy(22, 14);
				cout << "7. " << strFood[2].Breakfast1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 11)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast1_3 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1))
						{
							strUsersFood[ID_temp].Breakfast1_3 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].through = "r.f.b";
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast1_3 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast1_3 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].through = "d.f.b";
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 4)
			{
				coutc(hyellow, "");
				gotoxy(22, 16);
				cout << "10. " << strFood[3].Breakfast1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 12)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast1_4 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1))
						{
							strUsersFood[ID_temp].Breakfast1_4 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].through = "r.f.b";
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast1_4 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast1_4 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].through = "d.f.b";
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 5)
			{
				coutc(hyellow, "");
				gotoxy(22, 18);
				cout << "13. " << strFood[4].Breakfast1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 13)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast1_5 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1))
						{
							strUsersFood[ID_temp].Breakfast1_5 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].through = "r.f.b";
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast1_5 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast1_5 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].through = "d.f.b";
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 6)
			{
				coutc(hyellow, "");
				gotoxy(22, 20);
				cout << "16. " << strFood[5].Breakfast1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 14)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast1_6 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1))
						{
							strUsersFood[ID_temp].Breakfast1_6 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].through = "r.f.b";
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast1_6 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast1_6 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].through = "d.f.b";
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 7)
			{
				coutc(hyellow, "");
				gotoxy(22, 22);
				cout << "19. " << strFood[6].Breakfast1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 15)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast1_7 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1))
						{
							strUsersFood[ID_temp].Breakfast1_7 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].through = "r.f.b";
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast1_7 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast1_7 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].through = "d.f.b";
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
		}
		else if ((numFood - 1) % 3 == 1)
		{
			gotoxy(50, 25);
			cout << "Name Of Lunch : " << strFood[(numFood - 1) / 3].Lunch1;
			gotoxy(95, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].LunchPrice1;
			gotoxy(10, 27);
			if ((numFood + 2) / 3 == 1)
			{
				coutc(hyellow, "");
				gotoxy(52, 10);
				cout << "2. " << strFood[0].Lunch1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 9)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch1_1 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1))
						{
							strUsersFood[ID_temp].Lunch1_1 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].through = "r.f.l";
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch1_1 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch1_1 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2.Back        0.Exit ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 2)
			{
				coutc(hyellow, "");
				gotoxy(52, 12);
				cout << "5. " << strFood[1].Lunch1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 10)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch1_2 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1))
						{
							strUsersFood[ID_temp].Lunch1_2 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch1_2 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch1_2 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 3)
			{
				coutc(hyellow, "");
				gotoxy(52, 14);
				cout << "8. " << strFood[2].Lunch1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 11)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch1_3 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1))
						{
							strUsersFood[ID_temp].Lunch1_3 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch1_3 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch1_3 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].through = "d.f.l";
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 4)
			{
				coutc(hyellow, "");
				gotoxy(52, 16);
				cout << "11. " << strFood[3].Lunch1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 12)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch1_4 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1))
						{
							strUsersFood[ID_temp].Lunch1_4 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch1_4 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch1_4 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 5)
			{
				coutc(hyellow, "");
				gotoxy(52, 18);
				cout << "14. " << strFood[4].Lunch1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 13)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch1_5 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1))
						{
							strUsersFood[ID_temp].Lunch1_5 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch1_5 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch1_5 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 6)
			{
				coutc(hyellow, "");
				gotoxy(52, 20);
				cout << "17. " << strFood[5].Lunch1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 14)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch1_6 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1))
						{
							strUsersFood[ID_temp].Lunch1_6 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch1_6 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch1_6 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 7)
			{
				coutc(hyellow, "");
				gotoxy(52, 22);
				cout << "20. " << strFood[6].Lunch1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 15)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch1_7 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1))
						{
							strUsersFood[ID_temp].Lunch1_7 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch1_7 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch1_7 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
		}
		else
		{
			gotoxy(50, 25);
			cout << "Name Of Dinner : " << strFood[(numFood - 1) / 3].Dinner1;
			gotoxy(95, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].DinnerPrice1;
			gotoxy(10, 27);
			if ((numFood + 2) / 3 == 1)
			{
				coutc(hyellow, "");
				gotoxy(82, 10);
				cout << "3. " << strFood[0].Dinner1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 9)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner1_1 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1))
						{
							strUsersFood[ID_temp].Dinner1_1 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner1_1 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner1_1 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 2)
			{
				coutc(hyellow, "");
				gotoxy(82, 12);
				cout << "6. " << strFood[1].Dinner1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 10)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner1_2 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1))
						{
							strUsersFood[ID_temp].Dinner1_2 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner1_2 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner1_2 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 3)
			{
				coutc(hyellow, "");
				gotoxy(82, 14);
				cout << "9. " << strFood[2].Dinner1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 11)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner1_3 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1))
						{
							strUsersFood[ID_temp].Dinner1_3 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner1_3 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner1_3 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 4)
			{
				coutc(hyellow, "");
				gotoxy(82, 16);
				cout << "12. " << strFood[3].Dinner1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 12)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner1_4 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1))
						{
							strUsersFood[ID_temp].Dinner1_4 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner1_4 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner1_4 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 5)
			{
				coutc(hyellow, "");
				gotoxy(82, 18);
				cout << "15. " << strFood[4].Dinner1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 13)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner1_5 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1))
						{
							strUsersFood[ID_temp].Dinner1_5 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner1_5 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner1_5 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 6)
			{
				coutc(hyellow, "");
				gotoxy(82, 20);
				cout << "18. " << strFood[5].Dinner1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 14)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner1_6 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1))
						{
							strUsersFood[ID_temp].Dinner1_6 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner1_6 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner1_6 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 7)
			{
				coutc(hyellow, "");
				gotoxy(82, 22);
				cout << "21. " << strFood[6].Dinner1;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 15)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner1_7 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1))
						{
							strUsersFood[ID_temp].Dinner1_7 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner1_7 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner1_7 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice1);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
		}
	}while (numKey != 0);
	Save_Change_Account();
}

void Reserv_food_Users_Now_Week(){
	int numFood;
	int numKey;
	do
	{
		system("cls");
		Reserv_Food_Now_Week();
		Kadr(8, 4, 102, 2);
		gotoxy(10, 5);
		cout << "Name : " << strStudent[ID_temp].name << "\t" << strStudent[ID_temp].family << setw(36) <<
			"2016/1/16 - 2016/1/22 ";
		coutc(hwhite, "(This Week)");
		cout << setw(25) << " | Money :";
		if (strStudent[ID_temp].money >= 10000)
		{
			coutc(11, " ");
		}
		else if (strStudent[ID_temp].money < 10000 && strStudent[ID_temp].money >= 5000)
		{
			coutc(14, " ");
		}
		else
		{
			coutc(12, " ");
		}
		cout << strStudent[ID_temp].money;
		coutc(7, " ");
		gotoxy(12, 2);
		cout << " ";
		Watch();
		gotoxy(95, 2);
		cout << " ";
		Date();
		cout << " ";
		Kadr(8, 24, 102, 4);
		gotoxy(100, 27);
		cout << "0. Back";
		gotoxy(10, 25);
		cout << "Enter Food Number : ";
		cin >> numFood;
		gotoxy(100, 27);
		cout << "       ";
		if (numFood == 0)
		{
			break;
		}
		else if (numFood == 99)
		{
			Reserv_food_Users_Last_Week();
			break;
		}
		else if (numFood == 101)
		{
			Reserv_food_Users_Next_Week();
			break;
		}
		else if ((numFood - 1) % 3 == 0)
		{
			gotoxy(50, 25);
			cout << "Name Of Breakfast : " << strFood[(numFood - 1) / 3].Breakfast2;
			gotoxy(95, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].BreakfastPrice2;
			gotoxy(10, 27);
			if ((numFood + 2) / 3 == 1)
			{
				coutc(hyellow, "");
				gotoxy(22, 10);
				cout << "1. " << strFood[0].Breakfast2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 16)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast2_1 == NotReserved)
				{
					cout << "Enter Number For" << setw(20);
					coutc(15, "1. reserv");
					cout << setw(40) << "2. Back To Reselection" << setw(20) << "0. Back";
					coutc(7, " ");
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2))
						{
							strUsersFood[ID_temp].Breakfast2_1 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast2_1 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast2_1 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 2)
			{
				coutc(hyellow, "");
				gotoxy(22, 12);
				cout << "4. " << strFood[1].Breakfast2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 17)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast2_2 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2))
						{
							strUsersFood[ID_temp].Breakfast2_2 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast2_2 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast2_2 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 3)
			{
				coutc(hyellow, "");
				gotoxy(22, 14);
				cout << "7. " << strFood[2].Breakfast2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 18)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast2_3 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2))
						{
							strUsersFood[ID_temp].Breakfast2_3 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast2_3 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast2_3 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 4)
			{
				coutc(hyellow, "");
				gotoxy(22, 16);
				cout << "10. " << strFood[3].Breakfast2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 19)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast2_4 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2))
						{
							strUsersFood[ID_temp].Breakfast2_4 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast2_4 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast2_4 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 5)
			{
				coutc(hyellow, "");
				gotoxy(22, 18);
				cout << "13. " << strFood[4].Breakfast2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 20)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast2_5 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2))
						{
							strUsersFood[ID_temp].Breakfast2_5 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast2_5 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast2_5 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 6)
			{
				coutc(hyellow, "");
				gotoxy(22, 20);
				cout << "13. " << strFood[5].Breakfast2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 21)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast2_6 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2))
						{
							strUsersFood[ID_temp].Breakfast2_6 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast2_6 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast2_6 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 7)
			{
				coutc(hyellow, "");
				gotoxy(22, 22);
				cout << "19. " << strFood[6].Breakfast2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 22)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Breakfast2_7 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2))
						{
							strUsersFood[ID_temp].Breakfast2_7 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast2_7 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast2_7 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
		}
		else if ((numFood - 1) % 3 == 1)
		{
			gotoxy(50, 25);
			cout << "Name Of Lunch : " << strFood[(numFood - 1) / 3].Lunch2;
			gotoxy(95, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].LunchPrice2;
			gotoxy(10, 27);
			if ((numFood + 2) / 3 == 1)
			{
				coutc(hyellow, "");
				gotoxy(52, 10);
				cout << "2. " << strFood[0].Lunch2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 16)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch2_1 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2))
						{
							strUsersFood[ID_temp].Lunch2_1 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch2_1 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch2_1 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2.Back        0.Exit ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 2)
			{
				coutc(hyellow, "");
				gotoxy(52, 12);
				cout << "5. " << strFood[1].Lunch2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 17)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch2_2 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2))
						{
							strUsersFood[ID_temp].Lunch2_2 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch2_2 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch2_2 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 3)
			{
				coutc(hyellow, "");
				gotoxy(52, 14);
				cout << "8. " << strFood[2].Lunch2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 18)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch2_3 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2))
						{
							strUsersFood[ID_temp].Lunch2_3 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch2_3 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch2_3 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 4)
			{
				coutc(hyellow, "");
				gotoxy(52, 16);
				cout << "11. " << strFood[3].Lunch2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 19)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch2_4 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2))
						{
							strUsersFood[ID_temp].Lunch2_4 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch2_4 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch2_4 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 5)
			{
				coutc(hyellow, "");
				gotoxy(52, 18);
				cout << "14. " << strFood[4].Lunch2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 20)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch2_5 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2))
						{
							strUsersFood[ID_temp].Lunch2_5 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch2_5 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch2_5 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 6)
			{
				coutc(hyellow, "");
				gotoxy(52, 20);
				cout << "17. " << strFood[5].Lunch2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 21)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch2_6 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2))
						{
							strUsersFood[ID_temp].Lunch2_6 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch2_6 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch2_6 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 7)
			{
				coutc(hyellow, "");
				gotoxy(52, 22);
				cout << "20. " << strFood[6].Lunch2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 22)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Lunch2_7 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2))
						{
							strUsersFood[ID_temp].Lunch2_7 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch2_7 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch2_7 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
		}
		else
		{
			gotoxy(50, 25);
			cout << "Name Of Dinner : " << strFood[(numFood - 1) / 3].Dinner2;
			gotoxy(95, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].DinnerPrice2;
			gotoxy(10, 27);
			if ((numFood + 2) / 3 == 1)
			{
				coutc(hyellow, "");
				gotoxy(82, 10);
				cout << "3. " << strFood[0].Dinner2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 16)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner2_1 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2))
						{
							strUsersFood[ID_temp].Dinner2_1 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner2_1 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner2_1 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 2)
			{
				coutc(hyellow, "");
				gotoxy(82, 12);
				cout << "6. " << strFood[1].Dinner2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 17)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner2_2 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2))
						{
							strUsersFood[ID_temp].Dinner2_2 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner2_2 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner2_2 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 3)
			{
				coutc(hyellow, "");
				gotoxy(82, 14);
				cout << "9. " << strFood[2].Dinner2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 18)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner2_3 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2))
						{
							strUsersFood[ID_temp].Dinner2_3 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner2_3 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner2_3 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 4)
			{
				coutc(hyellow, "");
				gotoxy(82, 16);
				cout << "12. " << strFood[3].Dinner2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 19)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner2_4 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2))
						{
							strUsersFood[ID_temp].Dinner2_4 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner2_4 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner2_4 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 5)
			{
				coutc(hyellow, "");
				gotoxy(82, 18);
				cout << "15. " << strFood[4].Dinner2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 20)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner2_5 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2))
						{
							strUsersFood[ID_temp].Dinner2_5 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner2_5 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner2_5 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 6)
			{
				coutc(hyellow, "");
				gotoxy(82, 20);
				cout << "18. " << strFood[5].Dinner2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 21)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner2_6 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2))
						{
							strUsersFood[ID_temp].Dinner2_6 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner2_6 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner2_6 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 7)
			{
				coutc(hyellow, "");
				gotoxy(82, 22);
				cout << "21. " << strFood[6].Dinner2;
				coutc(grey, "");
				gotoxy(10, 27);
				if (ltm->tm_mday >= 22)
				{
					gotoxy(10, 27);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					gotoxy(50, 25);
					cout << "\t\t\t\t\t\t\t   ";
					gotoxy(52, 26);
					coutc(12, "Not Possible  !!!");
					Sleep(2000);
					system("color 07");
					numKey = 50;
				}
				else if (strUsersFood[ID_temp].Dinner2_7 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2))
						{
							strUsersFood[ID_temp].Dinner2_7 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner2_7 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner2_7 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice2);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
		}
	}while (numKey != 0);
	Save_Change_Account();
}

void Reserv_food_Users_Next_Week(){
	int numFood;
	int numKey;
	do
	{
		system("cls");
		Reserv_Food_Next_Week();
		Kadr(8, 4, 102, 2);
		gotoxy(10, 5);
		cout << "Name : " << strStudent[ID_temp].name << "\t" << strStudent[ID_temp].family << setw(36) <<
			"2016/1/23 - 2016/1/29 ";
		coutc(hgreen, "(Next Week)");
		coutc(grey, "");
		cout << setw(25) << " | Money :";
		if (strStudent[ID_temp].money >= 10000)
		{
			coutc(11, " ");
		}
		else if (strStudent[ID_temp].money < 10000 && strStudent[ID_temp].money >= 5000)
		{
			coutc(14, " ");
		}
		else
		{
			coutc(12, " ");
		}
		cout << strStudent[ID_temp].money;
		coutc(7, " ");
		gotoxy(12, 2);
		cout << " ";
		Watch();
		gotoxy(95, 2);
		cout << " ";
		Date();
		cout << " ";
		Kadr(8, 24, 102, 4);
		gotoxy(100, 27);
		cout << "0. Back";
		gotoxy(10, 25);
		cout << "Enter Food Number : ";
		cin >> numFood;
		gotoxy(100, 27);
		cout << "       ";
		if (numFood == 0)
		{
			break;
		}
		else if (numFood == 99)
		{
			Reserv_food_Users_Now_Week();
			break;
		}
		else if ((numFood - 1) % 3 == 0)
		{
			gotoxy(50, 25);
			cout << "Name Of Breakfast : " << strFood[(numFood - 1) / 3].Breakfast3;
			gotoxy(95, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].BreakfastPrice3;
			gotoxy(10, 27);
			if ((numFood + 2) / 3 == 1)
			{
				coutc(hyellow, "");
				gotoxy(22, 10);
				cout << "1. " << strFood[0].Breakfast3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Breakfast3_1 == NotReserved)
				{
					cout << "Enter Number For" << setw(20);
					coutc(15, "1. reserv");
					cout << setw(40) << "2. Back To Reselection" << setw(20) << "0. Back";
					coutc(7, " ");
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3))
						{
							strUsersFood[ID_temp].Breakfast3_1 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast3_1 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast3_1 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 2)
			{
				coutc(hyellow, "");
				gotoxy(22, 12);
				cout << "4. " << strFood[1].Breakfast3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Breakfast3_2 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3))
						{
							strUsersFood[ID_temp].Breakfast3_2 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast3_2 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast3_2 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 3)
			{
				coutc(hyellow, "");
				gotoxy(22, 14);
				cout << "7. " << strFood[2].Breakfast3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Breakfast3_3 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3))
						{
							strUsersFood[ID_temp].Breakfast3_3 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast3_3 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast3_3 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 4)
			{
				coutc(hyellow, "");
				gotoxy(22, 16);
				cout << "10. " << strFood[3].Breakfast3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Breakfast3_4 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3))
						{
							strUsersFood[ID_temp].Breakfast3_4 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast3_4 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast3_4 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 5)
			{
				coutc(hyellow, "");
				gotoxy(22, 18);
				cout << "13. " << strFood[4].Breakfast3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Breakfast3_5 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3))
						{
							strUsersFood[ID_temp].Breakfast3_5 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast3_5 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast3_5 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 6)
			{
				coutc(hyellow, "");
				gotoxy(22, 20);
				cout << "16. " << strFood[5].Breakfast3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Breakfast3_6 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3))
						{
							strUsersFood[ID_temp].Breakfast3_6 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast3_6 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast3_6 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 7)
			{
				coutc(hyellow, "");
				gotoxy(22, 22);
				cout << "19. " << strFood[6].Breakfast3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Breakfast3_7 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3))
						{
							strUsersFood[ID_temp].Breakfast3_7 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.b";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Breakfast3_7 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Breakfast3_7 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].BreakfastPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.b";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
		}
		else if ((numFood - 1) % 3 == 1)
		{
			gotoxy(50, 25);
			cout << "Name Of Lunch : " << strFood[(numFood - 1) / 3].Lunch3;
			gotoxy(95, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].LunchPrice3;
			gotoxy(10, 27);
			if ((numFood + 2) / 3 == 1)
			{
				coutc(hyellow, "");
				gotoxy(52, 10);
				cout << "2. " << strFood[0].Lunch3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Lunch3_1 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3))
						{
							strUsersFood[ID_temp].Lunch3_1 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch3_1 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch3_1 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2.Back        0.Exit ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 2)
			{
				coutc(hyellow, "");
				gotoxy(52, 12);
				cout << "5. " << strFood[1].Lunch3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Lunch3_2 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3))
						{
							strUsersFood[ID_temp].Lunch3_2 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch3_2 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch3_2 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 3)
			{
				coutc(hyellow, "");
				gotoxy(52, 14);
				cout << "8. " << strFood[2].Lunch3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Lunch3_3 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3))
						{
							strUsersFood[ID_temp].Lunch3_3 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch3_3 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch3_3 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 4)
			{
				coutc(hyellow, "");
				gotoxy(52, 16);
				cout << "11. " << strFood[3].Lunch3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Lunch3_4 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3))
						{
							strUsersFood[ID_temp].Lunch3_4 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch3_4 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch3_4 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 5)
			{
				coutc(hyellow, "");
				gotoxy(52, 18);
				cout << "14. " << strFood[4].Lunch3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Lunch3_5 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3))
						{
							strUsersFood[ID_temp].Lunch3_5 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch3_5 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch3_5 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 6)
			{
				coutc(hyellow, "");
				gotoxy(52, 20);
				cout << "17. " << strFood[5].Lunch3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Lunch3_6 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3))
						{
							strUsersFood[ID_temp].Lunch3_6 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch3_6 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch3_6 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 7)
			{
				coutc(hyellow, "");
				gotoxy(52, 22);
				cout << "20. " << strFood[6].Lunch3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Lunch3_7 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3))
						{
							strUsersFood[ID_temp].Lunch3_7 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.l";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Lunch3_7 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Lunch3_7 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].LunchPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.l";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
		}
		else
		{
			gotoxy(50, 25);
			cout << "Name Of Dinner : " << strFood[(numFood - 1) / 3].Dinner3;
			gotoxy(95, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].DinnerPrice3;
			gotoxy(10, 27);
			if ((numFood + 2) / 3 == 1)
			{
				coutc(hyellow, "");
				gotoxy(82, 10);
				cout << "3. " << strFood[0].Dinner3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Dinner3_1 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3))
						{
							strUsersFood[ID_temp].Dinner3_1 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner3_1 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner3_1 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 2)
			{
				coutc(hyellow, "");
				gotoxy(82, 12);
				cout << "6. " << strFood[1].Dinner3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Dinner3_2 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3))
						{
							strUsersFood[ID_temp].Dinner3_2 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner3_2 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner3_2 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 3)
			{
				coutc(hyellow, "");
				gotoxy(82, 14);
				cout << "9. " << strFood[2].Dinner3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Dinner3_3 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3))
						{
							strUsersFood[ID_temp].Dinner3_3 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner3_3 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner3_3 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 4)
			{
				coutc(hyellow, "");
				gotoxy(82, 16);
				cout << "12. " << strFood[3].Dinner3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Dinner3_4 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3))
						{
							strUsersFood[ID_temp].Dinner3_4 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner3_4 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner3_4 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 5)
			{
				coutc(hyellow, "");
				gotoxy(82, 18);
				cout << "15. " << strFood[4].Dinner3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Dinner3_5 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3))
						{
							strUsersFood[ID_temp].Dinner3_5 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner3_5 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner3_5 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 6)
			{
				coutc(hyellow, "");
				gotoxy(82, 20);
				cout << "18. " << strFood[5].Dinner3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Dinner3_6 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3))
						{
							strUsersFood[ID_temp].Dinner3_6 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner3_6 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner3_6 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
			else if ((numFood + 2) / 3 == 7)
			{
				coutc(hyellow, "");
				gotoxy(82, 22);
				cout << "21. " << strFood[6].Dinner3;
				coutc(grey, "");
				gotoxy(10, 27);
				if (strUsersFood[ID_temp].Dinner3_7 == NotReserved)
				{
					cout << "Enter Number For    1. reserv          2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						if (strStudent[ID_temp].money >= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3))
						{
							strUsersFood[ID_temp].Dinner3_7 = Reserved;
							strStudent[ID_temp].money -= std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

							strTransactions[sizeTransactions].time = TimeString();
							strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
							strTransactions[sizeTransactions].statusTransactions = Removal;
							strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
							strTransactions[sizeTransactions].through = "r.f.d";
							sizeTransactions++;
							Save_Change_Transactions();
						}
						else
						{
							gotoxy(10, 27);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							gotoxy(10, 27);
							coutc(12, "Don't Have Enough Money  !!!");
							Sleep(2000);
							system("color 07");
						}
					}
				}
				else if (strUsersFood[ID_temp].Dinner3_7 == Reserved)
				{
					cout << "Enter Number For     1. Delete this food       2. Back To Reselection           0. Back ";
					cin >> numKey;
					if (numKey == 1)
					{
						strUsersFood[ID_temp].Dinner3_7 = NotReserved;
						strStudent[ID_temp].money += std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);

						strTransactions[sizeTransactions].time = TimeString();
						strTransactions[sizeTransactions].price = std::stoi(strFood[(numFood - 1) / 3].DinnerPrice3);
						strTransactions[sizeTransactions].statusTransactions = Settle;
						strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
						strTransactions[sizeTransactions].through = "d.f.d";
						sizeTransactions++;
						Save_Change_Transactions();
					}
				}
				else
				{
					cout << "You Consumed This food         2. Back To Reselection           0. Back ";
					cin >> numKey;
				}
			}
		}
	}while (numKey != 0);
	Save_Change_Account();
}

bool Bank(int x){
	Load_Card_Bank();
	string cardNum;
	string cardNumTemp;
	string secendPass;
	string cvv2;
	string mount;
	string year;
	Kadr2(25, 0, 70, 29);
	Titr(32, 2, " Bank ", 24);
	Kadr(50, 6, 7, 2);
	gotoxy(58, 7);
	cout << "-";
	Kadr(59, 6, 7, 2);
	gotoxy(67, 7);
	cout << "-";
	Kadr(68, 6, 7, 2);
	gotoxy(76, 7);
	cout << "-";
	Kadr(77, 6, 7, 2);
	gotoxy(32, 7);
	cout << "Card Number";
	gotoxy(32, 10);
	cout << "secend Password";
	Kadr(50, 9, 16, 2);
	gotoxy(32, 13);
	cout << "CVV2";
	Kadr(50, 12, 10, 2);
	gotoxy(32, 16);
	cout << "Extended Card";
	Kadr(50, 15, 4, 2);
	gotoxy(55, 16);
	cout << "/";
	gotoxy(65, 16);
	cout << "yy / mm";
	Kadr(56, 15, 4, 2);
	gotoxy(52, 7);
	cin >> cardNum;
	gotoxy(61, 7);
	cin >> cardNumTemp;
	cardNum.append(cardNumTemp);
	gotoxy(70, 7);
	cin >> cardNumTemp;
	cardNum.append(cardNumTemp);
	gotoxy(79, 7);
	cin >> cardNumTemp;
	cardNum.append(cardNumTemp);
	gotoxy(52, 10);
	cin >> secendPass;
	gotoxy(52, 13);
	cin >> cvv2;
	gotoxy(52, 16);
	cin >> year;
	gotoxy(58, 16);
	cin >> mount;
	bool Action = false;
	for (int i = 0; i < sizeCard; i++)
	{
		if (cardNum == strCard[i].CardNumber)
		{
			if (secendPass == strCard[i].Pass&&cvv2 == strCard[i].Cvv2&&
				mount == strCard[i].mount&&year == strCard[i].year)
			{
				if (strCard[i].money >= x)
				{
					strCard[i].money -= x;
					strStudent[ID_temp].money += x;
					gotoxy(55, 23);
					coutc(hgreen, "Seccsessful !!!");
					Kadr(40, 22, 40, 2);
					Sleep(2000);
					system("color 07");
					strTransactions[sizeTransactions].time = TimeString();
					strTransactions[sizeTransactions].price = x;
					strTransactions[sizeTransactions].statusTransactions = Settle;
					strTransactions[sizeTransactions].through = "bank";
					strTransactions[sizeTransactions].stock = strStudent[ID_temp].money;
					sizeTransactions++;
					Save_Change_Transactions();
					Save_Change_Card_Bank();
					Save_Change_Account();
					Action = true;
					return true;
				}
				else
				{
					gotoxy(45, 23);
					coutc(hred, "You Don't have Eynof money !!!");
					Kadr(40, 22, 40, 2);
					Sleep(2000);
					system("color 07");
					Action = true;
					return false;
				}
			}
			else
			{
				gotoxy(45, 23);
				coutc(hred, "Information is not corect !!!");
				Kadr(40, 22, 40, 2);
				Sleep(2000);
				system("color 07");
				Action = true;
				return false;
			}
		}
	}
	if (!Action)
	{
		gotoxy(45, 23);
		coutc(hred, "Information is not corect !!!");
		Kadr(40, 22, 40, 2);
		Sleep(2000);
		system("color 07");
		return false;
	}
	return 0;
}

void Charge_Account(){
	Kadr2(35, 0, 50, 29);
	int num;
	Titr(39, 3, " Charge Account ", 12);
	gotoxy(40, 6);
	cout << "Your Account money : " << setw(18) << strStudent[ID_temp].money << " T";
	Kadr(39, 8, 42, 2);
	gotoxy(35, 27);
	f = 195;
	wcout << f;
	for (int i = 1; i < 50; i++)
	{
		gotoxy(35 + i, 27);
		f = 196;
		wcout << f;
	}
	gotoxy(85, 27);
	f = 180;
	wcout << f;
	gotoxy(44, 28);
	cout << "0.Back";
	gotoxy(41, 9);
	cout << "Requesting amount To Charg : ";
	cin >> num;
	if (num == 0)
	{
		system("cls");
		Student_Menu();
	}
	system("cls");
	if (Bank(num))
	{
		system("cls");
		gotoxy(55, 17);
		coutc(hgreen, "Seccsessful !!!");
		Kadr(40, 16, 40, 2);
		Sleep(2000);
		system("color 07");
	}
	else
	{
		system("cls");
		gotoxy(52, 17);
		coutc(hred,"Not Seccsessful !!!");
		Kadr(40, 16, 40, 2);
		Sleep(2000);
		system("color 07");
	}
}

void Feedback_Menu(){
	Kadr2(35, 0, 50, 29);
	Titr(40, 2, " Survey Menu ", 13);
	gotoxy(42, 4);
	coutc(hwhite, "");
	cout << "Please enter numerical between 0 to 10";
	coutc(grey, "");
	int cursor = 1;
	int q_b, q_l, q_d, b_p, t_b, t_l, t_d;
	gotoxy(42, 5 + 2 * cursor);
	cout << "Breackfast Quality : ";
	gotoxy(67, 5 + 2 * cursor);
	cin >> q_b;
	strFeedback[sizeFeedback].q_breackfast = q_b;
	gotoxy(67, 5 + 2 * cursor);	cursor++;
	int i;

	for (i = 0; i < q_b; i++)
	{
		coutc(hcyan, "");
		cout << "*";
		coutc(grey, "");
	}
	for (int j = i+1; j <= 10; j++)
	{
		cout << "*";
	}

	gotoxy(42, 5 + 2 * cursor);
	cout << "Lunch Quality : ";
	gotoxy(67, 5 + 2 * cursor);
	cin >> q_l;
	strFeedback[sizeFeedback].q_lunch = q_l;
	gotoxy(67, 5 + 2 * cursor);	cursor++;
	
	for (i = 0; i < q_l; i++)
	{
		coutc(hcyan, "");
		cout << "*";
		coutc(grey, "");
	}
	for (int j = i + 1; j <= 10; j++)
	{
		cout << "*";
	}

	gotoxy(42, 5 + 2 * cursor);
	cout << "Dinner Quality : ";
	gotoxy(67, 5 + 2 * cursor);
	cin >> q_d;
	strFeedback[sizeFeedback].q_dinner = q_d;
	gotoxy(67, 5 + 2 * cursor);	cursor++;

	for (i = 0; i < q_d; i++)
	{
		coutc(hcyan, "");
		cout << "*";
		coutc(grey, "");
	}
	for (int j = i + 1; j <= 10; j++)
	{
		cout << "*";
	}

	gotoxy(42, 5 + 2 * cursor);
	cout << "Behavior Of Personal : ";
	gotoxy(67, 5 + 2 * cursor);
	cin >> b_p;
	strFeedback[sizeFeedback].b_Personal = b_p;
	gotoxy(67, 5 + 2 * cursor);	cursor++;

	for (i = 0; i < b_p; i++)
	{
		coutc(hcyan, "");
		cout << "*";
		coutc(grey, "");
	}
	for (int j = i + 1; j <= 10; j++)
	{
		cout << "*";
	}

	gotoxy(42, 5 + 2 * cursor);
	cout << "Time Of Breackfast : ";
	gotoxy(67, 5 + 2 * cursor);
	cin >> t_b;
	strFeedback[sizeFeedback].t_breackfast = t_b;
	gotoxy(67, 5 + 2 * cursor);	cursor++;

	for (i = 0; i < t_b; i++)
	{
		coutc(hcyan, "");
		cout << "*";
		coutc(grey, "");
	}
	for (int j = i + 1; j <= 10; j++)
	{
		cout << "*";
	}

	gotoxy(42, 5 + 2 * cursor);
	cout << "Time Of Lunch : ";
	gotoxy(67, 5 + 2 * cursor);
	cin >> t_l;
	strFeedback[sizeFeedback].t_lunch = t_l;
	gotoxy(67, 5 + 2 * cursor);	cursor++;

	for (i = 0; i < t_l; i++)
	{
		coutc(hcyan, "");
		cout << "*";
		coutc(grey, "");
	}
	for (int j = i + 1; j <= 10; j++)
	{
		cout << "*";
	}

	gotoxy(42, 5 + 2 * cursor);
	cout << "Time Of Dinner : ";
	gotoxy(67, 5 + 2 * cursor);
	cin >> t_d;
	strFeedback[sizeFeedback].t_dinner = t_d;
	gotoxy(67, 5 + 2 * cursor);	cursor++;

	for (i = 0; i < t_d; i++)
	{
		coutc(hcyan, "");
		cout << "*";
		coutc(grey, "");
	}
	for (int j = i + 1; j <= 10; j++)
	{
		cout << "*";
	}
	Save_Change_survey();
	sizeFeedback++;
	_getch();
}

void Transactions_Menu(){
	Load_Transactions();
	string temp;
	Kadr2(35, 0, 50, ((sizeTransactions - 1) * 12) + 4);
	Titr(39, 3, " Transactions ", 14);
	int cursor = 1;
	for (int i = 0; i < sizeTransactions-1; i++)
	{
		gotoxy(38, 4 + 2 * cursor);	cursor++;
		cout << i + 1 << ".";
		gotoxy(41, 4 + 2 * cursor); cursor++;
		cout << "Date :"<< setw(36) << strTransactions[i].time;
		if (strTransactions[i].statusTransactions == Removal)
		{
			gotoxy(41, 4 + 2 * cursor); cursor++;
			cout << "Price :";
			coutc(hred, "");
			temp = "- " + to_string(strTransactions[i].price);
			cout << setw(35) <<temp ;
			coutc(grey, "");
		}
		else if (strTransactions[i].statusTransactions == Settle)
		{
			gotoxy(41, 4 + 2 * cursor); cursor++;
			cout << "Price :";
			coutc(hgreen, "");
			temp = "+ " + to_string(strTransactions[i].price);
			cout << setw(35) << temp;
			coutc(grey, "");
		}
		gotoxy(41, 4 + 2 * cursor); cursor++;
		cout << "Stock :" << setw(35) << strTransactions[i].stock;
		if (strTransactions[i].through == "bank")
		{
			gotoxy(41, 4 + 2 * cursor); cursor++;
			cout << "Through :" << setw(33) << "Charge account of the port bank";
		}
		else if (strTransactions[i].through == "r.f.b")
		{
			gotoxy(41, 4 + 2 * cursor); cursor++;
			cout << "Through :" << setw(33) << "Breakfast reservations";
		}
		else if (strTransactions[i].through == "d.f.b")
		{
			gotoxy(41, 4 + 2 * cursor); cursor++;
			cout << "Through :" << setw(33) << "Returned Breakfast reservations";
		}
		else if (strTransactions[i].through == "r.f.l")
		{
			gotoxy(41, 4 + 2 * cursor); cursor++;
			cout << "Through :" << setw(33) << "Lunch reservations";
		}
		else if (strTransactions[i].through == "d.f.l")
		{
			gotoxy(41, 4 + 2 * cursor); cursor++;
			cout << "Through :" << setw(33) << "Returned Lunch reservations";
		}
		else if (strTransactions[i].through == "r.f.d")
		{
			gotoxy(41, 4 + 2 * cursor); cursor++;
			cout << "Through :" << setw(33) << "Dinner reservations";
		}
		else if (strTransactions[i].through == "d.f.d")
		{
			gotoxy(41, 4 + 2 * cursor); cursor++;
			cout << "Through :" << setw(33) << "Returned Dinner reservations";
		}

		if (i < sizeTransactions - 2)
		{
			gotoxy(35, 4 + 2 * cursor);
			f = 195;
			wcout << f;
			for (int i = 1; i < 50; i++)
			{

				gotoxy(35 + i, 4 + 2 * cursor);
				f = 196;
				wcout << f;
			}
			gotoxy(85, 4 + 2 * cursor);
			f = 180;
			wcout << f;
			cursor++;
		}
	}
	_getch();
}

void Student_Menu(){
	int keyNum ;
	do
	{
		Kadr2(35, 0, 50, 29);
		int cursor = 0;
		gotoxy(44, 3 + 2 * cursor); cursor++;
		Titr(44, 3, " Student Menu ", 9);
		gotoxy(44, 4 + 2 * cursor ); cursor++;
		cout << "1. Order Food";
		gotoxy(44, 4 + 2 * cursor ); cursor++;
		cout << "2. Charge Account";
		gotoxy(44, 4 + 2 * cursor ); cursor++;
		cout << "3. Transactions";
		gotoxy(44, 4 + 2 * cursor ); cursor++;
		cout << "4. Change Password";
		gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "5. Show My Profile";
		gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "6. Survey";
		/*gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "7.\n";
		gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "8.\n";*/
		gotoxy(35, 27);
		f = 195;
		wcout << f;
		for (int i = 1; i < 50; i++)
		{

			gotoxy(35 + i, 27);
			f = 196;
			wcout << f;
		}
		gotoxy(85, 27);
		f = 180;
		wcout << f;
		cursor++;
		gotoxy(44, 28);
		cout << "0.Back" << setw(25) << "9.Exit ";
		cin >> keyNum;
		switch (keyNum)
		{
		case 1:	//Order Food
			system("cls");
			Reserv_food_Users_Now_Week();
			break;
		case 2:	//Charge Account
			system("cls");
			Charge_Account();
			break;
		case 3:	//Transactions
			system("cls");
			Transactions_Menu();
			break;
		case 4:	//Change Password
			system("cls");
			Change_Password();
			break;
		case 5:	//Show My Profile
			system("cls");
			Profile();
			break;
		case 6:	//Survey
			system("cls");
			Feedback_Menu();
			break;
		case 0:	//Back
			system("cls");
			Login();
			break;
		default:
			continue;
		}
		Sleep(10);
		system("cls");
	} while (keyNum!=9);
	cout << endl;
	for (int i = 0; i < 120; i++)
	{
		coutc(grey, "");
		f = 219;
		wcout << f;
	}
	exit(0);
}

//*********************************** Admin Menu ***************************

void Edit_profile(int x){
	Kadr2(35, 0, 50, 29);
	int cursor = 1;
	int numKey;
	string newIteam;
	Titr(40, 2, " Edit Profile ", 11);
	gotoxy(40, 3 + 2 * cursor); cursor++;
	cout << "1. First Name : " << setw(22) << strStudent[x].name;
	gotoxy(40, 3 + 2 * cursor); cursor++;
	cout << "2. Last Name : " << setw(23) << strStudent[x].family;
	gotoxy(40, 3 + 2 * cursor); cursor++;
	cout << "3. Student Number : " << setw(18) << strStudent[x].student_number;
	gotoxy(40, 3 + 2 * cursor); cursor++;
	cout << "4. Year of Birth  : " << setw(18) << strStudent[x].birth;
	gotoxy(40, 3 + 2 * cursor); cursor++;
	cout << "5. National Code  : " << setw(18) << strStudent[x].national_code;
	gotoxy(40, 3 + 2 * cursor); cursor++;
	cout << "6. Discipline : " << setw(22) << strStudent[x].discipline; cursor++;
	gotoxy(35, 1 + 2 * cursor);
	f = 195;
	wcout << f;
	for (int i = 1; i < 50; i++)
	{

		gotoxy(35 + i, 1 + 2 * cursor);
		f = 196;
		wcout << f;
	}
	gotoxy(85, 1 + 2 * cursor); cursor++;
	f = 180;
	wcout << f;
	Kadr(40, 2 * cursor, 38, 2);
	gotoxy(42, 1 + 2 * cursor);
	cout << "Enter code of Iteam : ";
	cin >> numKey;	cursor++;
	switch (numKey)
	{
	case 1:
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "First Name : " << setw(26) << strStudent[x].name;
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "Enter New First Name : " ; cursor++;
		cin >> newIteam;
		strStudent[x].name = newIteam;
		break;
	case 2:
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "Last Name : " << setw(27) << strStudent[x].family;
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "Enter New Last Name : "; cursor++;
		cin >> newIteam;
		strStudent[x].family = newIteam;
		break;
	case 3:
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "Student Number : " << setw(22) << strStudent[x].student_number;
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "Enter New Student Number : "; cursor++;
		cin >> newIteam;
		strStudent[x].student_number = newIteam;
		break;
	case 4:
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "Year of Birth  : " << setw(22) << strStudent[x].birth;
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "Enter New Year of Birth : "; cursor++;
		cin >> newIteam;
		strStudent[x].birth = newIteam;
		break;
	case 5:
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "National Code  : " << setw(22) << strStudent[x].national_code;
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "Enter New National Code : "; cursor++;
		cin >> newIteam;
		strStudent[x].national_code = newIteam;
		break;
	case 6:
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "Discipline : " << setw(26) << strStudent[x].discipline; cursor++;
		gotoxy(40, 3 + 2 * cursor); cursor++;
		cout << "Enter New Discipline : "; cursor++;
		cin >> newIteam;
		strStudent[x].discipline = newIteam;
		break;
	default:
		break;
	}
	Save_Change_Account();
}

void Show_Profile(){
	int cursor = 1;
	int numKey;
	int len = 50;
	Kadr2(35, 0, len, 23 * sizeAccount-2);
	Titr(42, 3, " Profile Students ", 9);
	for (int i = 0; i < sizeAccount; i++)
	{
		gotoxy(38, 3 + 2 * cursor); cursor++;
		cout << i+1 << ".";
		gotoxy(43, 3 + 2 * cursor); cursor++;
		cout << "First Name : " << setw(23) << strStudent[i].name;
		gotoxy(43, 3 + 2 * cursor); cursor++;
		cout << "Last Name : " << setw(24) << strStudent[i].family;
		gotoxy(43, 3 + 2 * cursor); cursor++;
		cout << "Student Number : " << setw(19) << strStudent[i].student_number;
		gotoxy(43, 3 + 2 * cursor); cursor++;
		cout << "Year of Birth  : " << setw(19) << strStudent[i].birth;
		gotoxy(43, 3 + 2 * cursor); cursor++;
		cout << "National Code  : " << setw(19) << strStudent[i].national_code;
		gotoxy(43, 3 + 2 * cursor); cursor++;
		cout << "Discipline : " << setw(23) << strStudent[i].discipline;
		gotoxy(43, 3 + 2 * cursor); cursor++;
		cout << "Username : " << setw(25) << strStudent[i].username;
		gotoxy(43, 3 + 2 * cursor); cursor++;
		cout << "Password : " << setw(25) << strStudent[i].password; cursor++;
		gotoxy(35, 3 + 2 * cursor);
		f = 195;
		wcout << f;
		for (int i = 1; i < len; i++)
		{

			gotoxy(35 + i, 3 + 2 * cursor);
			f = 196;
			wcout << f;
		}
		gotoxy(85, 3 + 2 * cursor);
		f = 180;
		wcout << f;
		cursor++;
	}
	gotoxy(43, 3 + 2 * cursor); cursor++;
	cout << "1. Edit" << setw(29) << "0. Back";
	Kadr(43, 3 + 2 * cursor, 36, 2);
	gotoxy(45, 4 + 2 * cursor);
	cout << "Enter Key : ";
	cin >> numKey;
	if (numKey == 1){
		gotoxy(45, 4 + 2 * cursor);
		cout << "\t\t\t";
		gotoxy(45, 4 + 2 * cursor);
		cout << "Enter ID_temp of User : ";
		cin >> numKey;
		system("cls");
		Edit_profile(numKey-1);
	}
}

void Edit_list_Food_Last_Week(){
	int numFood;
	string nameFood;
	string prise;
	int numKey;
	do
	{
		system("cls");
		Reserv_Food_Last_Week();
		for (int i = 0; i < 101; i++)
		{
			gotoxy(9 + i, 26);
			cout << " ";
			gotoxy(9 + i, 27);
			cout << " ";
			gotoxy(8 + i, 28);
			cout << " ";
		}
		Kadr(8, 24, 102, 4);
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				gotoxy(47 + (j * 30), 10 + (i * 2));
				cout << "   ";
			}
		}
		Kadr(8, 4, 102, 2);
		gotoxy(42, 5);
		cout << "2016/1/9 - 2016/1/15 ";
		coutc(hred, "(Last Week)");
		coutc(grey, "");
		gotoxy(10, 25);
		cout << "\t\t\t\t\t\t\t\t";
		gotoxy(100, 27);
		cout << "0. Back";
		Titr(8, 2, " Edit List Food ", 41);
		gotoxy(50, 27);
		cout << "101. Next Week >";
		gotoxy(10, 25);
		cout << "Enter Num Food : ";
		cin >> numFood;
		if (numFood == 0)
		{
			system("cls");
			Admin_Menu();
		}
		else if (numFood == 101)
		{
			Edit_list_Food_Now_Week();
		}
		else if ((numFood - 1) % 3 == 0)
		{
			coutc(hyellow, "");
			gotoxy(22, 10 + (((numFood - 1) / 3) * 2));
			cout << to_string(numFood) + ". " << strFood[(numFood - 1) / 3].Breakfast1;
			coutc(grey, "");
			gotoxy(40, 27);
			cout << "\t\t\t\t\t\t\t";
			gotoxy(35, 25);
			cout << "Name Of Breakfast : " << strFood[(numFood - 1) / 3].Breakfast1;
			gotoxy(85, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].BreakfastPrice1;
			gotoxy(100, 27);
			cout << "\t   ";
			gotoxy(85, 27);
			cout << "1. Return To Edition";
			gotoxy(35, 27);
			cout << "New Name Of Breakfast : ";
			cin >> nameFood;
			if (nameFood == "0")
			{
				system("cls");
				Admin_Menu();
			}
			else if (nameFood == "1")
			{
				numKey = 1;
				continue;
			}
			else
			{
				gotoxy(85, 27);
				cout << "\t\t\t   ";
			}
			strFood[(numFood - 1) / 3].Breakfast1 = nameFood;
			gotoxy(85, 27);
			cout << "Prise : ";
			cin >> prise;
			strFood[(numFood - 1) / 3].BreakfastPrice1 = prise;
		}
		else if ((numFood - 1) % 3 == 1)
		{
			coutc(hyellow, "");
			gotoxy(52, 10 + (((numFood - 2) / 3) * 2));
			cout << to_string(numFood) + ". " << strFood[(numFood - 1) / 3].Lunch1;
			coutc(grey, "");
			gotoxy(40, 27);
			cout << "\t\t\t\t\t\t\t";
			gotoxy(35, 25);
			cout << "Name Of Lunch : " << strFood[(numFood - 1) / 3].Lunch1;
			gotoxy(85, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].LunchPrice1;
			gotoxy(100, 27);
			cout << "\t   ";
			gotoxy(85, 27);
			cout << "1. Return To Edition";
			gotoxy(35, 27);
			cout << "New Name Of Lunch : ";
			cin >> nameFood;
			if (nameFood == "0")
			{
				system("cls");
				Admin_Menu();
			}
			else if (nameFood == "1")
			{
				numKey = 1;
				continue;
			}
			else
			{
				gotoxy(85, 27);
				cout << "\t\t\t   ";
			}
			strFood[(numFood - 1) / 3].Lunch1 = nameFood;
			gotoxy(85, 27);
			cout << "Prise : ";
			cin >> prise;
			strFood[(numFood - 1) / 3].LunchPrice1 = prise;
		}
		else
		{
			coutc(hyellow, "");
			gotoxy(82, 10 + (((numFood - 3) / 3) * 2));
			cout << to_string(numFood) + ". " << strFood[(numFood - 1) / 3].Dinner1;
			coutc(grey, "");
			gotoxy(40, 27);
			cout << "\t\t\t\t\t\t\t";
			gotoxy(35, 25);
			cout << "Name Of Dinner : " << strFood[(numFood - 1) / 3].Dinner1;
			gotoxy(85, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].DinnerPrice1;
			gotoxy(100, 27);
			cout << "\t   ";
			gotoxy(85, 27);
			cout << "1. Return To Edition";
			gotoxy(35, 27);
			cout << "New Name Of Dinner : ";
			cin >> nameFood;
			if (nameFood == "0")
			{
				system("cls");
				Admin_Menu();
			}
			else if (nameFood == "1")
			{
				numKey = 1;
				continue;
			}
			else
			{
				gotoxy(85, 27);
				cout << "\t\t\t   ";
			}
			strFood[(numFood - 1) / 3].Dinner1 = nameFood;
			gotoxy(85, 27);
			cout << "Prise : ";
			cin >> prise;
			strFood[(numFood - 1) / 3].DinnerPrice1 = prise;
		}
		Save_Change_Food();
		Kadr(8, 24, 102, 2);
		for (int i = 0; i < 101; i++)
		{
			gotoxy(9 + i, 25);
			cout << " ";
			gotoxy(8 + i, 27);
			cout << " ";
			gotoxy(8 + i, 28);
			cout << " ";
		}
		gotoxy(108, 28);
		cout << "     ";
		gotoxy(108, 27);
		cout << "     ";
		gotoxy(10, 25);
		cout << "Enter Key For           1. continue            0. Back  ";
		cin >> numKey;
		system("cls");
	} while (numKey != 0);
	
}

void Edit_list_Food_Now_Week(){
	int numFood;
	string nameFood;
	string prise;
	int numKey;
	do
	{
		system("cls");
		Reserv_Food_Now_Week();
		for (int i = 0; i < 101; i++)
		{
			gotoxy(9 + i, 26);
			cout << " ";
			gotoxy(9 + i, 27);
			cout << " ";
			gotoxy(8 + i, 28);
			cout << " ";
		}
		Kadr(8, 24, 102, 4);
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				gotoxy(47 + (j * 30), 10 + (i * 2));
				cout << "   ";
			}
		}
		Kadr(8, 4, 102, 2);
		gotoxy(42, 5);
		cout << "2016/1/16 - 2016/1/22 ";
		coutc(hwhite, "(This Week)");
		coutc(grey, "");
		gotoxy(10, 25);
		cout << "\t\t\t\t\t\t\t\t";
		gotoxy(100, 27);
		cout << "0. Back";
		Titr(8, 2, " Edit List Food ", 41);
		gotoxy(40, 27);
		cout << "< 99. Last Week  |  101. Next Week >";
		gotoxy(10, 25);
		cout << "Enter Num Food : ";
		cin >> numFood;
		if (numFood == 0)
		{
			system("cls");
			Admin_Menu();
		}
		else if (numFood == 99)
		{
			Edit_list_Food_Last_Week();
		}
		else if (numFood == 101)
		{
			Edit_list_Food_Next_Week();
		}
		else if ((numFood - 1) % 3 == 0)
		{
			coutc(hyellow, "");
			gotoxy(22, 10 + (((numFood - 1) / 3) * 2));
			cout << to_string(numFood)+ ". " << strFood[(numFood - 1) / 3].Breakfast2;
			coutc(grey, "");
			gotoxy(40, 27);
			cout << "\t\t\t\t\t\t\t";
			gotoxy(35, 25);
			cout << "Name Of Breakfast : " << strFood[(numFood - 1) / 3].Breakfast2;
			gotoxy(85, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].BreakfastPrice2;
			gotoxy(100, 27);
			cout << "\t   ";
			gotoxy(85, 27);
			cout << "1. Return To Edition";
			gotoxy(35, 27);
			cout << "New Name Of Breakfast : ";
			cin >> nameFood;
			if (nameFood == "0")
			{
				system("cls");
				Admin_Menu();
			}
			else if (nameFood == "1")
			{
				numKey = 1;
				continue;
			}
			else
			{
				gotoxy(85, 27);
				cout << "\t\t\t   ";
			}
			strFood[(numFood - 1) / 3].Breakfast2 = nameFood;
			gotoxy(85, 27);
			cout << "Prise : ";
			cin >> prise;
			strFood[(numFood - 1) / 3].BreakfastPrice2 = prise;
		}
		else if ((numFood - 1) % 3 == 1)
		{
			coutc(hyellow, "");
			gotoxy(52, 10 + (((numFood - 2) / 3) * 2));
			cout << to_string(numFood) + ". " << strFood[(numFood - 1) / 3].Lunch2;
			coutc(grey, "");
			gotoxy(40, 27);
			cout << "\t\t\t\t\t\t\t";
			gotoxy(35, 25);
			cout << "Name Of Lunch : " << strFood[(numFood - 1) / 3].Lunch2;
			gotoxy(95, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].LunchPrice2;
			gotoxy(100, 27);
			cout << "\t   ";
			gotoxy(85, 27);
			cout << "1. Return To Edition";
			gotoxy(35, 27);
			cout << "New Name Of Lunch : ";
			cin >> nameFood;
			if (nameFood == "0")
			{
				system("cls");
				Admin_Menu();
			}
			else if (nameFood == "1")
			{
				numKey = 1;
				continue;
			}
			else
			{
				gotoxy(85, 27);
				cout << "\t\t\t   ";
			}
			strFood[(numFood - 1) / 3].Lunch2 = nameFood;
			gotoxy(95, 27);
			cout << "Prise : ";
			cin >> prise;
			strFood[(numFood - 1) / 3].LunchPrice2 = prise;
		}
		else
		{
			coutc(hyellow, "");
			gotoxy(82, 10 + (((numFood - 3) / 3) * 2));
			cout << to_string(numFood) + ". " << strFood[(numFood - 1) / 3].Dinner2;
			coutc(grey, "");
			gotoxy(40, 27);
			cout << "\t\t\t\t\t\t\t";
			gotoxy(35, 25);
			cout << "Name Of Dinner : " << strFood[(numFood - 1) / 3].Dinner2;
			gotoxy(85, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].DinnerPrice2;
			gotoxy(100, 27);
			cout << "\t   ";
			gotoxy(85, 27);
			cout << "1. Return To Edition";
			gotoxy(35, 27);
			cout << "New Name Of Dinner : ";
			cin >> nameFood;
			if (nameFood == "0")
			{
				system("cls");
				Admin_Menu();
			}
			else if (nameFood == "1")
			{
				numKey = 1;
				continue;
			}
			else
			{
				gotoxy(85, 27);
				cout << "\t\t\t   ";
			}
			strFood[(numFood - 1) / 3].Dinner2 = nameFood;
			gotoxy(85, 27);
			cout << "Prise : ";
			cin >> prise;
			strFood[(numFood - 1) / 3].DinnerPrice2 = prise;
		}
		Save_Change_Food();
		Kadr(8, 24, 102, 2);
		for (int i = 0; i < 101; i++)
		{
			gotoxy(9 + i, 25);
			cout << " ";
			gotoxy(8 + i, 27);
			cout << " ";
			gotoxy(8 + i, 28);
			cout << " ";
		}
		gotoxy(108, 28);
		cout << "     ";
		gotoxy(108, 27);
		cout << "     ";
		gotoxy(10, 25);
		cout << "Enter Key For           1. continue            0. Back  ";
		cin >> numKey;
		system("cls");
	} while (numKey != 0);

}

void Edit_list_Food_Next_Week(){
	int numFood;
	string nameFood;
	string prise;
	int numKey;
	do
	{
		system("cls");
		Reserv_Food_Next_Week();
		for (int i = 0; i < 101; i++)
		{
			gotoxy(9 + i, 26);
			cout << " ";
			gotoxy(9 + i, 27);
			cout << " ";
			gotoxy(8 + i, 28);
			cout << " ";
		}
		Kadr(8, 24, 102, 4);
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				gotoxy(47 + (j * 30), 10 + (i * 2));
				cout << "   ";
			}
		}
		Kadr(8, 4, 102, 2);
		gotoxy(42, 5);
		cout << "2016/1/23 - 2016/1/29 ";
		coutc(hgreen, "(Next Week)");
		coutc(grey, "");
		gotoxy(10, 25);
		cout << "\t\t\t\t\t\t\t\t";
		gotoxy(100, 27);
		cout << "0. Back";
		Titr(8, 2, " Edit List Food ", 41);
		gotoxy(50, 27);
		cout << "99. Last Week >";
		gotoxy(10, 25);
		cout << "Enter Num Food : ";
		cin >> numFood;
		if (numFood == 0)
		{
			system("cls");
			Admin_Menu();
		}
		else if (numFood == 99)
		{
			Edit_list_Food_Now_Week();
		}
		else if ((numFood - 1) % 3 == 0)
		{
			coutc(hyellow, "");
			gotoxy(22, 10 + (((numFood - 1) / 3) * 2));
			cout << to_string(numFood) + ". " << strFood[(numFood - 1) / 3].Breakfast3;
			coutc(grey, "");
			gotoxy(35, 27);
			cout << "\t\t\t\t\t\t\t";
			gotoxy(35, 25);
			cout << "Name Of Breakfast : " << strFood[(numFood - 1) / 3].Breakfast3;
			gotoxy(85, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].BreakfastPrice3;
			gotoxy(100, 27);
			cout << "\t   ";
			gotoxy(85, 27);
			cout << "1. Return To Edition";
			gotoxy(35, 27);
			cout << "New Name Of Breakfast : ";
			cin >> nameFood;
			if (nameFood == "0")
			{
				system("cls");
				Admin_Menu();
			}
			else if (nameFood == "1")
			{
				numKey = 1;
				continue;
			}
			else
			{
				gotoxy(85, 27);
				cout << "\t\t\t   ";
			}
			strFood[(numFood - 1) / 3].Breakfast3 = nameFood;
			gotoxy(85, 27);
			cout << "Prise : ";
			cin >> prise;
			strFood[(numFood - 1) / 3].BreakfastPrice3 = prise;
		}
		else if ((numFood - 1) % 3 == 1)
		{
			coutc(hyellow, "");
			gotoxy(52, 10 + (((numFood - 2) / 3) * 2));
			cout << to_string(numFood) + ". " << strFood[(numFood - 1) / 3].Lunch3;
			coutc(grey, "");
			gotoxy(40, 27);
			cout << "\t\t\t\t\t\t\t";
			gotoxy(35, 25);
			cout << "Name Of Lunch : " << strFood[(numFood - 1) / 3].Lunch3;
			gotoxy(85, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].LunchPrice3;
			gotoxy(100, 27);
			cout << "\t   ";
			gotoxy(85, 27);
			cout << "1. Return To Edition";
			gotoxy(35, 27);
			cout << "New Name Of Lunch : ";
			cin >> nameFood;
			if (nameFood == "0")
			{
				system("cls");
				Admin_Menu();
			}
			else if (nameFood == "1")
			{
				numKey = 1;
				continue;
			}
			else
			{
				gotoxy(85, 27);
				cout << "\t\t\t   ";
			}
			strFood[(numFood - 1) / 3].Lunch3 = nameFood;
			gotoxy(85, 27);
			cout << "Prise : ";
			cin >> prise;
			strFood[(numFood - 1) / 3].LunchPrice3 = prise;
		}
		else
		{
			coutc(hyellow, "");
			gotoxy(82, 10 + (((numFood - 3) / 3) * 2));
			cout << to_string(numFood) + ". " << strFood[(numFood - 1) / 3].Dinner3;
			coutc(grey, "");
			gotoxy(40, 27);
			cout << "\t\t\t\t\t\t\t";
			gotoxy(35, 25);
			cout << "Name Of Dinner : " << strFood[(numFood - 1) / 3].Dinner3;
			gotoxy(85, 25);
			cout << "Prise : " << strFood[(numFood - 1) / 3].DinnerPrice3;
			gotoxy(100, 27);
			cout << "\t   ";
			gotoxy(85, 27);
			cout << "1. Return To Edition";
			gotoxy(35, 27);
			cout << "New Name Of Dinner : ";
			cin >> nameFood;
			if (nameFood == "0")
			{
				system("cls");
				Admin_Menu();
			}
			else if (nameFood == "1")
			{
				numKey = 1;
				continue;
			}
			else
			{
				gotoxy(85, 27);
				cout << "\t\t\t   ";
			}
			strFood[(numFood - 1) / 3].Dinner3 = nameFood;
			gotoxy(85, 27);
			cout << "Prise : ";
			cin >> prise;
			strFood[(numFood - 1) / 3].DinnerPrice3 = prise;
		}
		Save_Change_Food();
		Kadr(8, 24, 102, 2);
		for (int i = 0; i < 101; i++)
		{
			gotoxy(9 + i, 25);
			cout << " ";
			gotoxy(8 + i, 27);
			cout << " ";
			gotoxy(8 + i, 28);
			cout << " ";
		}
		gotoxy(108, 28);
		cout << "     ";
		gotoxy(108, 27);
		cout << "     ";
		gotoxy(10, 25);
		cout << "Enter Key For           1. continue            0. Back  ";
		cin >> numKey;
		system("cls");
	} while (numKey != 0);

}

void Creat_New_Account(){
	Kadr2(35, 0, 50, 29);
	string name;
	string family;
	string username;
	string password;
	string student_number;
	string birth;
	string national_code;
	string discipline;
	int money = 0;
	int cursor = 1;
	Titr(44, 3, " Creat Account ", 8);
	gotoxy(44, 4 + 2 * cursor); cursor++;
	cout << "Enter First Name : ";
	cin >> name;
	strStudent[sizeAccount].name = name;
	gotoxy(44, 4 + 2 * cursor); cursor++;
	cout << "Enter Last Name : ";
	cin >> family;
	strStudent[sizeAccount].family = family;
	gotoxy(44, 4 + 2 * cursor); cursor++;
	cout << "Enter Student Number : ";
	cin >> student_number;
	strStudent[sizeAccount].student_number = student_number;
	gotoxy(44, 4 + 2 * cursor); cursor++;
	cout << "Enter Year of Birth : ";
	cin >> birth;
	strStudent[sizeAccount].birth = birth;
	gotoxy(44, 4 + 2 * cursor); cursor++;
	cout << "Enter National Code  : ";
	cin >> national_code;
	strStudent[sizeAccount].national_code = national_code;
	gotoxy(44, 4 + 2 * cursor); cursor++;
	cout << "Enter Discipline  : ";	cursor++;
	cin >> discipline;
	strStudent[sizeAccount].discipline = discipline;
	gotoxy(44, 4 + 2 * cursor);	cursor++;
	cout << "Enter User Name : ";
	cin >> username;
	strStudent[sizeAccount].username = username;
	gotoxy(44, 4 + 2 * cursor); cursor++;
	cout << "Enter Password  : ";
	cin >> password;
	strStudent[sizeAccount].password = password;
	strStudent[sizeAccount].money = money;
	strStudent[sizeAccount].ID = sizeAccount;
	sizeAccount++;
	Save_Change_Account();
	gotoxy(53, 24);
	coutc(hgreen, "Seccsessful !!!");
	Kadr(40, 23, 40, 2);
	Sleep(2000);
	system("color 07");
}

void List_reservid_Last_Week(){
	int numKey;
	gotoxy(30, 27);
	cout << "\t\t\t\t\t\t\t\t\t";
	Reserv_Food_Last_Week();
	int Food1 = 0, Food2 = 0, Food3 = 0, Food4 = 0, Food5 = 0, Food6 = 0, Food7 = 0,
		Food8 = 0, Food9 = 0, Food10 = 0, Food11 = 0, Food12 = 0, Food13 = 0, Food14 = 0,
		Food15 = 0, Food16 = 0, Food17 = 0, Food18 = 0, Food19 = 0, Food20 = 0, Food21 = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gotoxy(47 + (j * 30), 10 + (i * 2));
			cout << "   ";
		}
	}
	Titr(8, 2, " List Reservid ", 40);
	Kadr(8, 4, 102, 2);
	gotoxy(35, 5);
	cout << "\t\t\t\t\t\t";
	gotoxy(42, 5);
	cout << "2016/1/9 - 2016/1/15 ";
	coutc(hred, "(Last Week)");
	coutc(grey, "");
	for (int i = 0; i < sizeAccount; i++)
	{
		if (strUsersFood[i].Breakfast1_1 == Reserved)
		{
			Food1++;
		}
		if (strUsersFood[i].Breakfast1_2 == Reserved)
		{
			Food2++;
		}
		if (strUsersFood[i].Breakfast1_3 == Reserved)
		{
			Food3++;
		}
		if (strUsersFood[i].Breakfast1_4 == Reserved)
		{
			Food4++;
		}
		if (strUsersFood[i].Breakfast1_5 == Reserved)
		{
			Food5++;
		}
		if (strUsersFood[i].Breakfast1_6 == Reserved)
		{
			Food6++;
		}
		if (strUsersFood[i].Breakfast1_7 == Reserved)
		{
			Food7++;
		}
		if (strUsersFood[i].Lunch1_1 == Reserved)
		{
			Food8++;
		}
		if (strUsersFood[i].Lunch1_2 == Reserved)
		{
			Food9++;
		}
		if (strUsersFood[i].Lunch1_3 == Reserved)
		{
			Food10++;
		}
		if (strUsersFood[i].Lunch1_4 == Reserved)
		{
			Food11++;
		}
		if (strUsersFood[i].Lunch1_5 == Reserved)
		{
			Food12++;
		}
		if (strUsersFood[i].Lunch1_6 == Reserved)
		{
			Food13++;
		}
		if (strUsersFood[i].Lunch1_7 == Reserved)
		{
			Food14++;
		}
		if (strUsersFood[i].Dinner1_1 == Reserved)
		{
			Food15++;
		}
		if (strUsersFood[i].Dinner1_2 == Reserved)
		{
			Food16++;
		}
		if (strUsersFood[i].Dinner1_3 == Reserved)
		{
			Food17++;
		}
		if (strUsersFood[i].Dinner1_4 == Reserved)
		{
			Food18++;
		}
		if (strUsersFood[i].Dinner1_5 == Reserved)
		{
			Food19++;
		}
		if (strUsersFood[i].Dinner1_6 == Reserved)
		{
			Food20++;
		}
		if (strUsersFood[i].Dinner1_7 == Reserved)
		{
			Food21++;
		}
	}
	gotoxy(48, 10);
	cout << Food1;
	gotoxy(48, 12);
	cout << Food2;
	gotoxy(48, 14);
	cout << Food3;
	gotoxy(48, 16);
	cout << Food4;
	gotoxy(48, 18);
	cout << Food5;
	gotoxy(48, 20);
	cout << Food6;
	gotoxy(48, 22);
	cout << Food7;
	gotoxy(78, 10);
	cout << Food8;
	gotoxy(78, 12);
	cout << Food9;
	gotoxy(78, 14);
	cout << Food10;
	gotoxy(78, 16);
	cout << Food11;
	gotoxy(78, 18);
	cout << Food12;
	gotoxy(78, 20);
	cout << Food13;
	gotoxy(78, 22);
	cout << Food14;
	gotoxy(108, 10);
	cout << Food15;
	gotoxy(108, 12);
	cout << Food16;
	gotoxy(108, 14);
	cout << Food17;
	gotoxy(108, 16);
	cout << Food18;
	gotoxy(108, 18);
	cout << Food19;
	gotoxy(108, 20);
	cout << Food20;
	gotoxy(108, 22);
	cout << Food21;
	gotoxy(100, 27);
	cout << "0. Back";
	gotoxy(10, 25);
	cout << "\t\t\t\t\t\t\t\t";
	gotoxy(10, 25);
	cout << "Enter The Number : ";
	cin >> numKey;
	if (numKey == 101)
	{
		List_reservid_Now_Week();
	}
}

void List_reservid_Now_Week(){
	int numKey;
	gotoxy(30, 27);
	cout << "\t\t\t\t\t\t\t\t\t";
	Reserv_Food_Now_Week();
	int Food1 = 0, Food2 = 0, Food3 = 0, Food4 = 0, Food5 = 0, Food6 = 0, Food7 = 0,
		Food8 = 0, Food9 = 0, Food10 = 0, Food11 = 0, Food12 = 0, Food13 = 0, Food14 = 0,
		Food15 = 0, Food16 = 0, Food17 = 0, Food18 = 0, Food19 = 0, Food20 = 0, Food21 = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gotoxy(47 + (j * 30), 10 + (i * 2));
			cout << "   ";
		}
	}
	Titr(8, 2, " List Reservid ", 40);
	Kadr(8, 4, 102, 2);
	gotoxy(35, 5);
	cout << "\t\t\t\t\t\t";
	gotoxy(42, 5);
	cout << "2016/1/16 - 2016/1/22 ";
	coutc(hwhite, "(This Week)");
	coutc(grey, "");
	Kadr(8, 24, 102, 4);
	for (int i = 0; i < sizeAccount; i++)
	{
		if (strUsersFood[i].Breakfast2_1 == Reserved)
		{
			Food1++;
		}
		if (strUsersFood[i].Breakfast2_2 == Reserved)
		{
			Food2++;
		}
		if (strUsersFood[i].Breakfast2_3 == Reserved)
		{
			Food3++;
		}
		if (strUsersFood[i].Breakfast2_4 == Reserved)
		{
			Food4++;
		}
		if (strUsersFood[i].Breakfast2_5 == Reserved)
		{
			Food5++;
		}
		if (strUsersFood[i].Breakfast2_6 == Reserved)
		{
			Food6++;
		}
		if (strUsersFood[i].Breakfast2_7 == Reserved)
		{
			Food7++;
		}
		if (strUsersFood[i].Lunch2_1 == Reserved)
		{
			Food8++;
		}
		if (strUsersFood[i].Lunch2_2 == Reserved)
		{
			Food9++;
		}
		if (strUsersFood[i].Lunch2_3 == Reserved)
		{
			Food10++;
		}
		if (strUsersFood[i].Lunch2_4 == Reserved)
		{
			Food11++;
		}
		if (strUsersFood[i].Lunch2_5 == Reserved)
		{
			Food12++;
		}
		if (strUsersFood[i].Lunch2_6 == Reserved)
		{
			Food13++;
		}
		if (strUsersFood[i].Lunch2_7 == Reserved)
		{
			Food14++;
		}
		if (strUsersFood[i].Dinner2_1 == Reserved)
		{
			Food15++;
		}
		if (strUsersFood[i].Dinner2_2 == Reserved)
		{
			Food16++;
		}
		if (strUsersFood[i].Dinner2_3 == Reserved)
		{
			Food17++;
		}
		if (strUsersFood[i].Dinner2_4 == Reserved)
		{
			Food18++;
		}
		if (strUsersFood[i].Dinner2_5 == Reserved)
		{
			Food19++;
		}
		if (strUsersFood[i].Dinner2_6 == Reserved)
		{
			Food20++;
		}
		if (strUsersFood[i].Dinner2_7 == Reserved)
		{
			Food21++;
		}
	}
	gotoxy(48, 10);
	cout << Food1;
	gotoxy(48, 12);
	cout << Food2;
	gotoxy(48, 14);
	cout << Food3;
	gotoxy(48, 16);
	cout << Food4;
	gotoxy(48, 18);
	cout << Food5;
	gotoxy(48, 20);
	cout << Food6;
	gotoxy(48, 22);
	cout << Food7;
	gotoxy(78, 10);
	cout << Food8;
	gotoxy(78, 12);
	cout << Food9;
	gotoxy(78, 14);
	cout << Food10;
	gotoxy(78, 16);
	cout << Food11;
	gotoxy(78, 18);
	cout << Food12;
	gotoxy(78, 20);
	cout << Food13;
	gotoxy(78, 22);
	cout << Food14;
	gotoxy(108, 10);
	cout << Food15;
	gotoxy(108, 12);
	cout << Food16;
	gotoxy(108, 14);
	cout << Food17;
	gotoxy(108, 16);
	cout << Food18;
	gotoxy(108, 18);
	cout << Food19;
	gotoxy(108, 20);
	cout << Food20;
	gotoxy(108, 22);
	cout << Food21;
	gotoxy(100, 27);
	cout << "0. Back";
	gotoxy(10, 25);
	cout << "\t\t\t\t\t\t\t";
	gotoxy(10, 25);
	cout << "Enter The Number : ";
	cin >> numKey;
	if (numKey == 101)
	{
		List_reservid_Next_Week();
	}
	else if (numKey == 99)
	{
		List_reservid_Last_Week();
	}
}

void List_reservid_Next_Week(){
	int numKey;
	gotoxy(30, 27);
	cout << "\t\t\t\t\t\t\t\t\t";
	Reserv_Food_Next_Week();
	int Food1 = 0, Food2 = 0, Food3 = 0, Food4 = 0, Food5 = 0, Food6 = 0, Food7 = 0,
		Food8 = 0, Food9 = 0, Food10 = 0, Food11 = 0, Food12 = 0, Food13 = 0, Food14 = 0,
		Food15 = 0, Food16 = 0, Food17 = 0, Food18 = 0, Food19 = 0, Food20 = 0, Food21 = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gotoxy(47 + (j * 30), 10 + (i * 2));
			cout << "   ";
		}
	}
	Titr(8, 2, " List Reservid ", 40);
	Kadr(8, 4, 102, 2);
	gotoxy(35, 5);
	cout << "\t\t\t\t\t\t";
	gotoxy(42, 5);
	cout << "2016/1/23 - 2016/1/29 ";
	coutc(hgreen, "(Next Week)");
	coutc(grey, "");
	for (int i = 0; i < sizeAccount; i++)
	{
		if (strUsersFood[i].Breakfast3_1 == Reserved)
		{
			Food1++;
		}
		if (strUsersFood[i].Breakfast3_2 == Reserved)
		{
			Food2++;
		}
		if (strUsersFood[i].Breakfast3_3 == Reserved)
		{
			Food3++;
		}
		if (strUsersFood[i].Breakfast3_4 == Reserved)
		{
			Food4++;
		}
		if (strUsersFood[i].Breakfast3_5 == Reserved)
		{
			Food5++;
		}
		if (strUsersFood[i].Breakfast3_6 == Reserved)
		{
			Food6++;
		}
		if (strUsersFood[i].Breakfast3_7 == Reserved)
		{
			Food7++;
		}
		if (strUsersFood[i].Lunch3_1 == Reserved)
		{
			Food8++;
		}
		if (strUsersFood[i].Lunch3_2 == Reserved)
		{
			Food9++;
		}
		if (strUsersFood[i].Lunch3_3 == Reserved)
		{
			Food10++;
		}
		if (strUsersFood[i].Lunch3_4 == Reserved)
		{
			Food11++;
		}
		if (strUsersFood[i].Lunch3_5 == Reserved)
		{
			Food12++;
		}
		if (strUsersFood[i].Lunch3_6 == Reserved)
		{
			Food13++;
		}
		if (strUsersFood[i].Lunch3_7 == Reserved)
		{
			Food14++;
		}
		if (strUsersFood[i].Dinner3_1 == Reserved)
		{
			Food15++;
		}
		if (strUsersFood[i].Dinner3_2 == Reserved)
		{
			Food16++;
		}
		if (strUsersFood[i].Dinner3_3 == Reserved)
		{
			Food17++;
		}
		if (strUsersFood[i].Dinner3_4 == Reserved)
		{
			Food18++;
		}
		if (strUsersFood[i].Dinner3_5 == Reserved)
		{
			Food19++;
		}
		if (strUsersFood[i].Dinner3_6 == Reserved)
		{
			Food20++;
		}
		if (strUsersFood[i].Dinner3_7 == Reserved)
		{
			Food21++;
		}
	}
	gotoxy(48, 10);
	cout << Food1;
	gotoxy(48, 12);
	cout << Food2;
	gotoxy(48, 14);
	cout << Food3;
	gotoxy(48, 16);
	cout << Food4;
	gotoxy(48, 18);
	cout << Food5;
	gotoxy(48, 20);
	cout << Food6;
	gotoxy(48, 22);
	cout << Food7;
	gotoxy(78, 10);
	cout << Food8;
	gotoxy(78, 12);
	cout << Food9;
	gotoxy(78, 14);
	cout << Food10;
	gotoxy(78, 16);
	cout << Food11;
	gotoxy(78, 18);
	cout << Food12;
	gotoxy(78, 20);
	cout << Food13;
	gotoxy(78, 22);
	cout << Food14;
	gotoxy(108, 10);
	cout << Food15;
	gotoxy(108, 12);
	cout << Food16;
	gotoxy(108, 14);
	cout << Food17;
	gotoxy(108, 16);
	cout << Food18;
	gotoxy(108, 18);
	cout << Food19;
	gotoxy(108, 20);
	cout << Food20;
	gotoxy(108, 22);
	cout << Food21;
	gotoxy(100, 27);
	cout << "0. Back";
	gotoxy(10, 25);
	cout << "\t\t\t\t\t\t\t\t\t";
	gotoxy(10, 25);
	cout << "Enter The Number : ";
	cin >> numKey;
	if (numKey == 99)
	{
		List_reservid_Now_Week();
	}
}

void Change_Username_Password(int key, int ID_temp){
	Kadr2(35, 0, 50, 29);
	int cursor = 1;
	string newpass, passConfrim, newuser, userConfrim;
	Titr(42, 3, "Change Password", 10);
	gotoxy(42, 3 + 2 * cursor); cursor++;
	switch (key)
	{
	case 1:
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Enter New Password : ";
		cin >> newpass;
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Confrim Your Password : ";
		cin >> passConfrim;
		while (passConfrim != newpass)
		{
			gotoxy(55, 12);
			coutc(hred, "It is Wrong !!");
			Kadr(42, 11, 38, 2);
			Sleep(1000);
			system("color 07");
			gotoxy(42, 11);
			cout << "\t\t\t\t\t  ";
			gotoxy(42, 12);
			cout << "\t\t\t\t\t  ";
			gotoxy(42, 13);
			cout << "\t\t\t\t\t  ";
			gotoxy(42, 7);
			cout << "\t\t\t\t\t";
			gotoxy(42, 9);
			cout << "\t\t\t\t\t";
			gotoxy(42, 9);
			cout << "Confrim Your Password : ";
			gotoxy(42, 7);;
			cout << "Enter New Password : ";
			cin >> newpass;
			gotoxy(42, 9);
			cout << "Confrim Your Password : ";
			cin >> passConfrim;
		}
		strStudent[ID_temp].password = newpass;
		Save_Change_Account();
		gotoxy(47, 14);
		coutc(hcyan, "Your Password is Changed !!");
		Kadr(42, 13, 38, 2);
		Sleep(2000);
		system("color 07");
		break;
	case 2:
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Enter New Username : ";
		cin >> newuser;
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Confrim New Username : ";
		cin >> userConfrim;
		while (userConfrim != newuser)
		{
			gotoxy(55, 12);
			coutc(hred, "It is Wrong !!");
			Kadr(42, 11, 38, 2);
			Sleep(1000);
			system("color 07");
			gotoxy(42, 11);
			cout << "\t\t\t\t\t  ";
			gotoxy(42, 12);
			cout << "\t\t\t\t\t  ";
			gotoxy(42, 13);
			cout << "\t\t\t\t\t  ";
			gotoxy(42, 7);
			cout << "\t\t\t\t\t";
			gotoxy(42, 9);
			cout << "\t\t\t\t\t";
			gotoxy(42, 9);
			cout << "Confrim New Username : ";
			gotoxy(42, 7);;
			cout << "Enter New Username : ";
			cin >> newuser;
			gotoxy(42, 9);
			cout << "Confrim New Username : ";
			cin >> userConfrim;
		}
		strStudent[ID_temp].username = newuser;
		Save_Change_Account();
		gotoxy(53, 14);
		coutc(hcyan, "Username Changed !!");
		Kadr(42, 13, 38, 2);
		Sleep(2000);
		system("color 07");
		break;
	case 3:
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Enter New Username : ";
		cin >> newuser;
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Confrim New Username : ";
		cin >> userConfrim;
		while (userConfrim != newuser)
		{
			gotoxy(55, 4 + 2 * cursor);
			coutc(hred, "It is Wrong !!");
			Kadr(42, 3 + 2 * cursor, 38, 2);
			Sleep(1000);
			system("color 07");
			gotoxy(42, 3 + 2 * cursor);
			cout << "\t\t\t\t\t  ";
			gotoxy(42, 4 + 2 * cursor);
			cout << "\t\t\t\t\t  ";
			gotoxy(42, 5 + 2 * cursor);
			cout << "\t\t\t\t\t  ";
			cursor -= 2;
			gotoxy(42, 3 + 2 * cursor);	cursor++;
			cout << "\t\t\t\t\t";
			gotoxy(42, 3 + 2 * cursor);
			cout << "\t\t\t\t\t";
			gotoxy(42, 3 + 2 * cursor);	cursor--;
			cout << "Confrim New Username : ";
			gotoxy(42, 3 + 2 * cursor);	cursor++;
			cout << "Enter New Username : ";
			cin >> newuser;
			gotoxy(42, 3 + 2 * cursor);	cursor++;
			cout << "Confrim New Username : ";
			cin >> userConfrim;
		}
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Enter New Password : ";
		cin >> newpass;
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Confrim Your Password : ";
		cin >> passConfrim;
		cursor++;
		while (passConfrim != newpass)
		{
			gotoxy(55, 4 + 2 * cursor);
			coutc(hred, "It is Wrong !!");
			Kadr(42, 3 + 2 * cursor, 38, 2);
			Sleep(1000);
			system("color 07");
			gotoxy(42, 3 + 2 * cursor);
			cout << "\t\t\t\t\t  ";
			gotoxy(42, 4 + 2 * cursor);
			cout << "\t\t\t\t\t  ";
			gotoxy(42, 5 + 2 * cursor);
			cout << "\t\t\t\t\t  ";
			cursor -= 3;
			gotoxy(42, 3 + 2 * cursor);	cursor++;
			cout << "\t\t\t\t\t";
			gotoxy(42, 3 + 2 * cursor);
			cout << "\t\t\t\t\t";
			gotoxy(42, 3 + 2 * cursor);	cursor--;
			cout << "Confrim Your Password : ";
			gotoxy(42, 3 + 2 * cursor);	cursor++;
			cout << "Enter New Password : ";
			cin >> newpass;
			gotoxy(42, 3 + 2 * cursor);	cursor++;
			cout << "Confrim Your Password : ";
			cin >> passConfrim;
		}
		strStudent[ID_temp].password = newpass;
		strStudent[ID_temp].username = newuser;
		Save_Change_Account();
		gotoxy(46, 16);
		coutc(hcyan, "Username and Password Changed !!");
		Kadr(42, 15, 38, 2);
		Sleep(2000);
		system("color 07");
		break;
	default:
		break;
	}
}

void Menu_Change_Password_Admin(){
	int cursor = 1;
	int numKey, numID;
	int len = 50;
	Kadr2(35, 0, len, 17 * sizeAccount-2);
	Titr(42, 3, " Profile Students ", 8);
	for (int i = 0; i < sizeAccount; i++)
	{
		gotoxy(38, 3 + 2 * cursor); cursor++;
		cout << i + 1 << ".";
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "First Name : " << setw(23) << strStudent[i].name;
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Last Name : " << setw(24) << strStudent[i].family;
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Student Number : " << setw(19) << strStudent[i].student_number;
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Username : " << setw(25) << strStudent[i].username;
		gotoxy(42, 3 + 2 * cursor); cursor++;
		cout << "Password : " << setw(25) << strStudent[i].password; cursor++;
		gotoxy(35, 3 + 2 * cursor);
		f = 195;
		wcout << f;
		for (int i = 1; i < len; i++)
		{

			gotoxy(35 + i, 3 + 2 * cursor);
			f = 196;
			wcout << f;
		}
		gotoxy(85, 3 + 2 * cursor);
		f = 180;
		wcout << f;
		cursor++;
	}
	gotoxy(40, 3 + 2 * cursor); cursor++;
	cout << "1. Change password" << setw(24) << "2. Change Username";
	gotoxy(45, 3 + 2 * cursor); cursor++;
	cout << "3. Change password and Username";
	Kadr(43, 3 + 2 * cursor, 30, 2);
	gotoxy(45, 4 + 2 * cursor);
	cout << "Enter Key : ";
	cin >> numKey;
	switch (numKey)
	{
	case 1:
		gotoxy(45, 4 + 2 * cursor);
		cout << "\t\t\t";
		gotoxy(45, 4 + 2 * cursor);
		cout << "Enter ID_temp of User : ";
		cin >> numID;
		system("cls");
		Change_Username_Password(numKey, numID - 1);
		break;
	case 2:
		gotoxy(45, 4 + 2 * cursor);
		cout << "\t\t\t";
		gotoxy(45, 4 + 2 * cursor);
		cout << "Enter ID_temp of User : ";
		cin >> numID;
		system("cls");
		Change_Username_Password(numKey, numID - 1);
		break;
	case 3:
		gotoxy(45, 4 + 2 * cursor);
		cout << "\t\t\t";
		gotoxy(45, 4 + 2 * cursor);
		cout << "Enter ID_temp of User : ";
		cin >> numID;
		system("cls");
		Change_Username_Password(numKey, numID - 1);
		break;
	default:
		break;
	}
}

void Survey_Menu(){
	Load_Feedback();
	Kadr2(35, 0, 50, 29);
	Titr(44, 3, " Survey Menu ", 10);
	int q_b = 0, q_l = 0, q_d = 0, b_p = 0, t_b = 0, t_l = 0, t_d = 0;
	for (int i = 0; i < sizeFeedback-1; i++)
	{
		q_b += strFeedback[i].q_breackfast;
		q_l += strFeedback[i].q_lunch;
		q_d += strFeedback[i].q_dinner;
		b_p += strFeedback[i].b_Personal;
		t_b += strFeedback[i].t_breackfast;
		t_l += strFeedback[i].t_lunch;
		t_d += strFeedback[i].t_dinner;
	}
	gotoxy(43, 6);
	cout << "Average Breackfast Quality : ";
	/*if (((q_b) / (sizeFeedback - 1)) >= 7)
	{
		coutc(hgreen, "");
	}
	else if (((q_b) / (sizeFeedback - 1)) >= 4)
	{
		coutc(hyellow, "");
	}
	else
	{
		coutc(hred, "");
	}*/
	cout << setw(7) << ((q_b) / (sizeFeedback - 1));
	gotoxy(43, 8);
	//coutc(grey, "");
	cout << "Average Lunch Quality : ";
	/*if (((q_l) / (sizeFeedback - 1)) >= 7)
	{
		coutc(hgreen, "");
	}
	else if (((q_l) / (sizeFeedback - 1)) >= 4)
	{
		coutc(hyellow, "");
	}
	else
	{
		coutc(hred, "");
	}*/
	cout << setw(12) << ((q_l) / (sizeFeedback - 1));
	gotoxy(43, 10);
	//coutc(grey, "");
	cout << "Average Dinner Quality : ";
	/*if (((q_d) / (sizeFeedback - 1) >= 7)
	{
		coutc(hgreen, "");
	}
	else if (((q_d) / (sizeFeedback - 1) >= 4)
	{
		coutc(hyellow, "");
	}
	else
	{
		coutc(hred, "");
	}*/
	cout << setw(11) << ((q_d) / (sizeFeedback - 1));
	gotoxy(43, 12);
	//coutc(grey, "");
	cout << "Average Behavior Of Personal : ";
	/*if (((b_p) / (sizeFeedback - 1)) >= 7)
	{
		coutc(hgreen, "");
	}
	else if (((b_p) / (sizeFeedback - 1)) >= 4)
	{
		coutc(hyellow, "");
	}
	else
	{
		coutc(hred, "");
	}*/
	cout << setw(5) << ((b_p) / (sizeFeedback - 1));
	gotoxy(43, 14);
	//coutc(grey, "");
	cout << "Average Time Of Breackfast : ";
	/*if (((t_b) / (sizeFeedback - 1)) >= 7)
	{
		coutc(hgreen, "");
	}
	else if (((t_b) / (sizeFeedback - 1)) >= 4)
	{
		coutc(hyellow, "");
	}
	else
	{
		coutc(hred, "");
	}*/
	cout << setw(7) << ((t_b) / (sizeFeedback - 1));
	gotoxy(43, 16);
	//coutc(grey, "");
	cout << "Average Time Of Lunch : ";
	/*if (((t_l) / (sizeFeedback - 1)) >= 7)
	{
		coutc(hgreen, "");
	}
	else if (((t_l) / (sizeFeedback - 1)) >= 4)
	{
		coutc(hyellow, "");
	}
	else
	{
		coutc(hred, "");
	}*/
	cout << setw(12) << ((t_l) / (sizeFeedback - 1));
	gotoxy(43, 18);
	//coutc(grey, "");
	cout << "Average Time Of Dinner : ";
	/*if (((t_d) / (sizeFeedback - 1)) >= 7)
	{
		coutc(hgreen, "");
	}
	else if (((t_d) / (sizeFeedback - 1)) >= 4)
	{
		coutc(hyellow, "");
	}
	else
	{
		coutc(hred, "");
	}*/
	cout << setw(11) << ((t_d) / (sizeFeedback - 1));
	_getch();
}

void Request_Menu_Admin(){
	int numKey;
	Load_Request();
	string temp;
	Kadr2(35, 0, 50, ((sizeRequest - 1) * 10) + 14);
	Titr(39, 3, " Request Menu ", 14);
	int cursor = 1;
	for (int i = 0; i < sizeRequest - 1; i++)
	{
		if (strRequest[i].assent == disagreement || strRequest[i].assent == assent)
		{
			coutc(dgrey, "");
		}
		gotoxy(38, 4 + 2 * cursor);	cursor++;
		cout << i + 1 << ".";
		gotoxy(43, 4 + 2 * cursor); cursor++;
		cout << strStudent[strRequest[i].ID].name << "  " <<
			strStudent[strRequest[i].ID].family << "  " <<
			strStudent[strRequest[i].ID].student_number;
		gotoxy(43, 4 + 2 * cursor); cursor++;
		cout << "Request edit : ";
		if (strRequest[i].iteam == "f.n")
		{
			cout << "First Name";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[i].ID].name << " ===> " <<
				strRequest[i].correct;
		}
		else if (strRequest[i].iteam == "l.n")
		{
			cout << "Last Name";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[i].ID].family << " ===> " <<
				strRequest[i].correct;
		}
		else if (strRequest[i].iteam == "s.n")
		{
			cout << "Student Number";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[i].ID].student_number << " ===> " <<
				strRequest[i].correct;
		}
		else if (strRequest[i].iteam == "y.b")
		{
			cout << "Year of Birth";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[i].ID].birth << " ===> " <<
				strRequest[i].correct;
		}
		else if (strRequest[i].iteam == "n.c")
		{
			cout << "National Code";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[i].ID].national_code << " ===> " <<
				strRequest[i].correct;
		}
		else if (strRequest[i].iteam == "d")
		{
			cout << "Discipline";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[i].ID].discipline << " ===> " <<
				strRequest[i].correct;
		}
		if (strRequest[i].assent == assent)
		{
			gotoxy(78, 4 + 2 * cursor);
			coutc(hgreen, "");
			f = 251;
			wcout << f;
			coutc(grey, "");
		}
		else if (strRequest[i].assent == disagreement)
		{
			gotoxy(78, 4 + 2 * cursor);
			coutc(hred, "");
			cout << '!';
			coutc(grey, "");
		}
		cursor ++;
		if (i < sizeRequest - 1)
		{
			gotoxy(35, 4 + 2 * cursor);
			f = 195;
			wcout << f;
			for (int i = 1; i < 50; i++)
			{

				gotoxy(35 + i, 4 + 2 * cursor);
				f = 196;
				wcout << f;
			}
			gotoxy(85, 4 + 2 * cursor);
			f = 180;
			wcout << f;
			cursor++;
		}
		coutc(grey, "");
	}
	Kadr(40, 5 + 2 * cursor, 40, 2);
	gotoxy(35, 10 + 2 * cursor);
	f = 195;
	wcout << f;
	for (int i = 1; i < 50; i++)
	{

		gotoxy(35 + i, 10 + 2 * cursor);
		f = 196;
		wcout << f;
	}
	gotoxy(85, 10 + 2 * cursor);
	f = 180;
	wcout << f;
	gotoxy(44, 11 + 2 * cursor);
	cout << "0.Back";
	gotoxy(43, 6 + 2 * cursor);
	cout << "Enter ID : ";
	cin >> numKey;
	if (numKey < sizeRequest && numKey!=0)
	{
		cursor = 1;
		system("cls");
		Titr(39, 3, " Request Menu ", 14);
		Kadr2(35, 0, 50, 14);
		gotoxy(43, 4 + 2 * cursor); cursor++;
		cout << strStudent[strRequest[numKey-1].ID].name << "  " <<
			strStudent[strRequest[numKey - 1].ID].family << "  " <<
			strStudent[strRequest[numKey - 1].ID].student_number;
		gotoxy(43, 4 + 2 * cursor); cursor++;
		cout << "Request edit : ";
		if (strRequest[numKey - 1].iteam == "f.n")
		{
			cout << "First Name";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[numKey - 1].ID].name << " ===> " <<
				strRequest[numKey-1].correct;
		}
		else if (strRequest[numKey-1].iteam == "l.n")
		{
			cout << "Last Name";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[numKey-1].ID].family << " ===> " <<
				strRequest[numKey-1].correct;
		}
		else if (strRequest[numKey-1].iteam == "s.n")
		{
			cout << "Student Number";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[numKey-1].ID].student_number << " ===> " <<
				strRequest[numKey-1].correct;
		}
		else if (strRequest[numKey-1].iteam == "y.b")
		{
			cout << "Year of Birth";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[numKey-1].ID].birth << " ===> " <<
				strRequest[numKey-1].correct;
		}
		else if (strRequest[numKey-1].iteam == "n.c")
		{
			cout << "National Code";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[numKey-1].ID].national_code << " ===> " <<
				strRequest[numKey-1].correct;
		}
		else if (strRequest[numKey-1].iteam == "d")
		{
			cout << "Discipline";
			gotoxy(43, 4 + 2 * cursor);
			cout << strStudent[strRequest[numKey-1].ID].discipline << " ===> " <<
				strRequest[numKey-1].correct;
		}
		gotoxy(35, 6 + 2 * cursor);
		f = 195;
		wcout << f;
		for (int i = 1; i < 50; i++)
		{

			gotoxy(35 + i, 6 + 2 * cursor);
			f = 196;
			wcout << f;
		}
		gotoxy(85, 6 + 2 * cursor);
		f = 180;
		wcout << f;
		int numkey2;
		gotoxy(40, 7 + 2 * cursor);
		cout << "1. assent" << setw(19) << "2. disagreement" << setw(13) << "0. Back ";
		cin >> numkey2;
		if (numkey2 == 1 )
		{
			strRequest[numKey - 1].assent = assent;
			strRequest[numKey - 1].StatusRequest = false;
			if (strRequest[numKey - 1].iteam == "f.n")
			{
				strStudent[strRequest[numKey - 1].ID].name = strRequest[numKey - 1].correct;
			}
			else if (strRequest[numKey - 1].iteam == "l.n")
			{
				strStudent[strRequest[numKey - 1].ID].family = strRequest[numKey - 1].correct;
			}
			else if (strRequest[numKey - 1].iteam == "s.n")
			{
				strStudent[strRequest[numKey - 1].ID].student_number = strRequest[numKey - 1].correct;
			}
			else if (strRequest[numKey - 1].iteam == "y.b")
			{
				strStudent[strRequest[numKey - 1].ID].birth = strRequest[numKey - 1].correct;
			}
			else if (strRequest[numKey - 1].iteam == "n.c")
			{
				strStudent[strRequest[numKey - 1].ID].national_code = strRequest[numKey - 1].correct;
			}
			else if (strRequest[numKey - 1].iteam == "d")
			{
				strStudent[strRequest[numKey - 1].ID].discipline = strRequest[numKey - 1].correct;
			}
			Save_Change_Account();
		}
		else if (numkey2 == 2)
		{
			strRequest[numKey - 1].assent = disagreement;
		}
		Save_Change_Request_Admin();
	}
}

void Admin_Menu(){
	int keyNum;
	do
	{
		Kadr2(35, 0, 50, 29);
		int cursor = 1;
		Titr(44, 3, " Admin Menu ", 10);
		gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "1. Edit List Food";
		gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "2. Reserved List";
		gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "3. Show Profiles";
		gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "4. Change Passwords";
		gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "5. Creat New User";
		gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "6. Feedback";
		gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "7. Requests";
		/*gotoxy(44, 4 + 2 * cursor); cursor++;
		cout << "8.\n";*/
		gotoxy(35, 27);
		f = 195;
		wcout << f;
		for (int i = 1; i < 50; i++)
		{

			gotoxy(35 + i, 27);
			f = 196;
			wcout << f;
		}
		gotoxy(85, 27);
		f = 180;
		wcout << f;
		cursor++;
		gotoxy(44, 28);
		cout << "0.Back" << setw(25) << "9.Exit ";
		cin >> keyNum;
		switch (keyNum)
		{
		case 1:	//Edit List Food
			system("cls");
			Edit_list_Food_Now_Week();
			break;
		case 2:	//Reserved List
			system("cls");
			List_reservid_Now_Week();
			break;
		case 3:	//Show Profiles
			system("cls");
			Show_Profile();
			break;
		case 4:	//Change Passwords
			system("cls");
			Menu_Change_Password_Admin();
			break;
		case 5:	//Creat New User
			system("cls");
			Creat_New_Account();
			break;
		case 6:	//Feedback
			system("cls");
			Survey_Menu();
			break;
		case 7:	//Requests
			system("cls");
			Request_Menu_Admin();
			break;
		case 0:	//Back
			system("cls");
			Login();
			break;
		default:
			break;
		}
		Sleep(10);
		system("cls");
	} while (keyNum != 9);
	exit(0);
}

//************************************ Login **********************************

void Login(){
	fstream profile;
	int j;
	Kadr2(29, 0, 60, 29);
	profile.open("users.txt", ios::in);
	if (profile)
	{
		Load_Account();
		string username;
		string password;
		Titr(39, 4, " Welcome To Restaurant ", 7);
		gotoxy(43, 25);
		cout << "Written By Hamid Nasr (Nameless)";
		gotoxy(52, 27);
		cout << "www.sku.ac.ir";
		Kadr(39, 6, 38, 3);
		gotoxy(40, 7);
		cout << " PLEASE ENTER YOUR ACCOUNT USERNAME: ";
		gotoxy(40, 8);
		cout << " USERNAME : ";
		cin >> username;
		bool existUser = false, existPass = false;
		bool existUserAdmin = false, existPassAdmin = false;
		string passAdmin = "admin";
		string userAdmin = "admin";

		if (username == userAdmin)
		{
			existUserAdmin = true;
			existUser = true;
		}
		for (j = 0; j < sizeAccount; j++)
		{
			if (username == strStudent[j].username)
			{
				existUser = true;
				break;
			}
		}
		if (username == userAdmin)
		{
			existUserAdmin = true;
			existUser = true;
		}
		while (existUser == false)
		{
			gotoxy(40, 12);
			coutc(12, "\tUsername is not exist!!");
			Kadr(39, 11, 38, 2);
			gotoxy(52, 8);
			cout << "\t\t\t";
			Sleep(1000);
			system("color 07");
			gotoxy(38, 11);
			cout << "                                              ";
			gotoxy(38, 12);
			cout << "                                              ";
			gotoxy(38, 13);
			cout << "                                              ";
			gotoxy(40, 8);
			cout << " USERNAME : ";
			cin >> username;
			for (j = 0; j < sizeAccount; j++)
			{
				if (username == strStudent[j].username)
				{
					existUser = true;
					break;
				}
			}
			if (username == userAdmin)
			{
				existUserAdmin = true;
				existUser = true;
			}
		}
		if (existUser == true)
		{
			Kadr(39, 11, 38, 3);
			gotoxy(40, 12);
			cout << " PLEASE ENTER YOUR ACCOUNT PASSWORD: ";
			gotoxy(45, 13);
			cout << "\t\t\t";
			gotoxy(40, 13);
			cout << " PASSWORD : ";
			cin >> password;
			if (existUserAdmin = true && password == passAdmin)
			{
				Sleep(10);
				system("cls");
				Admin_Menu();
			}
			while (password != strStudent[j].password)
			{
				gotoxy(40, 17);
				coutc(12, "   Your Password is not corect !!");
				Kadr(39, 16, 38, 2);
				gotoxy(52, 13);
				cout << "\t\t\t";
				Sleep(1000);
				system("color 07");
				gotoxy(38, 16);
				cout << "                                              ";
				gotoxy(38, 17);
				cout << "                                              ";
				gotoxy(38, 18);
				cout << "                                              ";
				gotoxy(40, 13);
				cout << " PASSWORD : ";
				cin >> password;
				if (existUserAdmin = true && password == passAdmin)
				{
					Sleep(10);
					system("cls");
					Admin_Menu();
				}
			}
		}

		ID_temp = j;

		; Sleep(10); system("cls");
		Student_Menu();

	}
	profile.close();
}

//************************************ Main ***********************************

void main()
{
	loading();
	Login();
}
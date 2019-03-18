#include <iostream>

#include "InputValidation.h"
#include "labs.h"

using namespace std;


menuItem choiceOpt = static_cast<menuItem>(0);

void DisplayFirstLabsTask()
{
	cout << "����� ��������� ������ � �� N ����� � � ��������. ���p��p����� ���������� "
		 << "������ � �� ������������� ��������� ������� �, ��������� ��p��p���� ������� � �"
		 << "��p���� ����������." << endl;
}


void DisplayAboutInfo()
{
	cout << "Copyright ������ �.�" << endl << "������ #484" << endl
		<< "2019 year" << endl;
}

void DisplayMainMenu() {
	cout << "________________________________" << endl;
	cout << "|Main Menu\t\t\t|" << endl;
	cout << "|_______________________________|" << endl;
	cout << "|1 - Laba1\t\t\t|" << endl;
	cout << "|2 - Laba2\t\t\t|" << endl;
	cout << "|3 - Laba3\t\t\t|" << endl;
	cout << "|4 - About\t\t\t|" << endl;
	cout << "|5 - Quit\t\t\t|" << endl;
	cout << "|_______________________________|" << endl;
	cout << "Selection: ";
}

void DisplayOptionsMenu() {
	cout << "________________________________" << endl;
	cout << "|Labs Menu\t\t\t|" << endl;
	cout << "|_______________________________|" << endl;
	cout << "|1 - ����������� ����\t\t|" << endl;
	cout << "|2 - ���� ������������ ��������\t|" << endl;
	cout << "|3 - ���� � �����\t\t|" << endl;
	cout << "|4 - Back\t\t\t|" << endl;
	cout << "|_______________________________|" << endl;
	cout << "Selection: ";
}

void SetOptions() {

	do {
		DisplayOptionsMenu();
		choiceOpt = GetMenuItem();
		switch (choiceOpt) {
		case DEFAULT:
			runLaba1();
			break;
		case RANDOM:
			runLaba1();
			break;
		case WITHFILE:
			runLaba1();
			break;
		case BACK:
			break;
		default:
			cout << "������������ ����. �������� ���������� ������� �� ������������� ������." <<endl;
			break;
		}
	} while (choiceOpt != BACK);
}

int getChoice()
{
	return choiceOpt;
}

bool askAboutSaving(int mode)
{
	bool choice;
	if (mode == SAVE_RESULT)
		cout << "��������� ��������� ������?" << endl << "[1] - Yes" << endl << "[0] - No";
	else if (mode == SAVE_INITIAL)
		cout << "��������� �������� ������?" << endl << "[1] - Yes" << endl << "[0] - No";

	cout << endl << "Selection: ";
	choice = GetBoll();
	return choice;
}
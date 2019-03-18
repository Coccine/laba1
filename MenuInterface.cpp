#include <iostream>

#include "InputValidation.h"
#include "labs.h"

using namespace std;


menuItem choiceOpt = static_cast<menuItem>(0);

void DisplayFirstLabsTask()
{
	cout << "Задан двумерный массив А из N строк и М столбцов. Сфоpмиpовать одномерный "
		 << "массив В из отрицательных элементов массива А, выполнить соpтиpовку массива В в"
		 << "поpядке неубывания." << endl;
}


void DisplayAboutInfo()
{
	cout << "Copyright Бабаев Э.И" << endl << "Группа #484" << endl
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
	cout << "|1 - Стандартный ввод\t\t|" << endl;
	cout << "|2 - Ввод произвольных значений\t|" << endl;
	cout << "|3 - Ввод с файла\t\t|" << endl;
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
			cout << "Некорректный ввод. Выберете пожалуйста вариант из предложенного списка." <<endl;
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
		cout << "Сохранить результат работы?" << endl << "[1] - Yes" << endl << "[0] - No";
	else if (mode == SAVE_INITIAL)
		cout << "Сохранить исходные данные?" << endl << "[1] - Yes" << endl << "[0] - No";

	cout << endl << "Selection: ";
	choice = GetBoll();
	return choice;
}
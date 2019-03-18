#include <iostream>

#include "MenuInterface.h"
#include "InputValidation.h"
#include "workWithFile.h"

using namespace std;

void main() {
	setlocale(LC_ALL, "RU");

	menuItem choice = static_cast<menuItem>(0);

	do {
		DisplayMainMenu();
		choice = GetMenuItem();
		switch (choice) {
		case LABA1:
			DisplayFirstLabsTask();
			SetOptions();
			break;
		case LABA2:
			SetOptions();
			break;
		case LABA3:
			SetOptions();
			break;
		case ABOUT:
			DisplayAboutInfo();
			break;
		default:
			cout << "Неверный ввод" <<endl;
			break;
		}
	} while (choice != QUIT);

	system("PAUSE");
}
#include <iostream>
#include "InputValidation.h"

using namespace std;

void DisplayMainMenu() {
	cout << "Main Menu" << endl;
	cout << "Please, make your selection" << endl;
	cout << "1 - Start game" << endl;
	cout << "2 - Options" << endl;
	cout << "3 - Quit" << endl;
	cout << "Selection: ";
}

void DisplayOptionsMenu() {
	cout << "Options Menu" << endl;
	cout << "Please, make your selection" << endl;
	cout << "1 - Difficulty" << endl;
	cout << "2 - Sound" << endl;
	cout << "3 - Back" << endl;
	cout << "Selection: ";
}

void SetOptions() {
	menuItem choice = static_cast<menuItem>(0);
	double soundMode = 0.0;

	do {
		DisplayOptionsMenu();
		choice = GetMenuItem();
		switch (choice) {
		case DIFFICULTY:
			cout << "Difficulty Stuff." << endl << endl;
			break;
		case SOUND:
			cout << "Select Sound Mode: ";
			soundMode = GetDouble();
			cout << soundMode << endl << endl;
			break;
		case BACK:
			cout << endl;
			break;
		default:
			cout << endl;
			break;
		}
	} while (choice != BACK);
}
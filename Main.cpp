#include <iostream>
#include "MenuInterface.h"
#include "InputValidation.h"

using namespace std;

void main() {
	setlocale(0, "");

	menuItem choice = static_cast<menuItem>(0);

	do {
		DisplayMainMenu();
		choice = GetMenuItem();
		switch (choice) {
		case START:
			cout << "You're dead!" << endl << endl;
			break;
		case OPTIONS:
			cout << endl;
			SetOptions();
			break;
		case QUIT:
			cout << "Goodbye!" << endl;
			break;
		default:
			cout << endl;
			break;
		}
	} while (choice != QUIT);

	system("PAUSE");
}
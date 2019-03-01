#include <iostream>
#include "MenuItems.h"

using namespace std;

template<typename T>
T GetInput() {
	T userInput;
	cin >> userInput;
	if (cin.fail()) {
		cout << "Woah bad data, try again." << endl;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> userInput;
		}
	}
	cin.ignore(INT_MAX, '\n');
	return userInput;
}

int GetInt() {
	return GetInput<int>();
}

double GetDouble() {
	return GetInput<double>();
}

menuItem GetMenuItem() {
	return static_cast<menuItem>(GetInt());
}
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <filesystem>

#include "InputValidation.h"

using namespace std;

void outputFile(int mode, int *data = nullptr, int SIZE = 0, int **initMatrix = nullptr, int ROWS = 0, int COLS = 0)
{
	string filePath;
	bool isDataSaved = false;
	do {
		cout << "��������� �:" << endl;
		cin >> filePath;

		if (ifstream(filePath)) {
			cout << "���� ��� ����������." << endl;
			cout << "[0] - ������������ ������������ ����." << endl;
			cout << "[1] - ��������� ����." << endl;
			bool isAnother = GetBoll();
			if (isAnother) {
				continue;
			}
		}

		ofstream myFile(filePath, ofstream::app);

		if (!std::experimental::filesystem::is_regular_file(filePath)) {
			cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			cin.ignore(INT_MAX, '\n');
			continue;
		}

		if (!myFile) {
			cout << "������ ���������. ��������� ����." << endl;
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(filePath, ofstream::trunc);

		if (mode == SAVE_RESULT)
		{
			for (int i = 0; i < SIZE; i++) {
				myFile << data[i];
			}
		}
		else if (mode == SAVE_INITIAL)
		{
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					myFile << initMatrix[i][j] << " ";
				}
				myFile << "\n";
			}
		}

		myFile.close();
		cout << "������ ���������." << endl;
		isDataSaved = true;
	} while (!isDataSaved);

}






int** inputFile(int **matrix,int &COLS, int &ROLS)
{
	string filePath;
	bool isDataLoaded = false;
	COLS = 0, ROLS = 0;
	do {
		cout << "��������� ��:" << endl;
		cin >> filePath;

		if (!ifstream(filePath)) {
			cout << "���� �� ����������. ��������� ����." << endl;
			cin.ignore(INT_MAX, '\n');
			continue;
		}

		if (!std::experimental::filesystem::is_regular_file(filePath)) {
			cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			cin.ignore(INT_MAX, '\n');
			continue;
		}

		ifstream myFile(filePath);

		if (!myFile) {
			cout << "�������� ���������. ��������� ����." << endl;
			myFile.close();
			continue;
		}

		if (!(myFile >> COLS) || COLS <= 0) {
			cout << "������������ ������ �������." << endl;
			myFile.close();
			continue;
		}

		if (!(myFile >> ROLS) || ROLS <= 0) {
			cout << "������������ ������ �������." << endl;
			myFile.close();
			continue;
		}

		int i = 0;
		int j = 0;

		matrix = new int*[ROLS];
		for ( ; i < ROLS; i++)
			matrix[i] = new int[COLS];

		i = 0;
		for (; i < ROLS; i++) {
			j = 0;
			for ( ; j < COLS; j++) {
				if (!(myFile >> matrix[i][j])) {
					cout << "������������ ������." << endl;
					myFile.close();
					break;
				}
			}
		}

		if (i == ROLS || j == COLS) {
			cout << "�������� ���������." << endl;
			isDataLoaded = true;
		}
		else {
			delete[] matrix;
			matrix = nullptr;
		}

		myFile.close();
	} while (!isDataLoaded);

	return matrix;
}
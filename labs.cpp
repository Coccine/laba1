#include <iostream>
#include <time.h>

#include "InputValidation.h"
#include "MenuInterface.h"
#include "workWithFile.h"


using namespace std;


void runLaba1() {

	srand(time(NULL));

	int addMode = getChoice(); // ��������� ������ ���������� �������

	int ROWS = 0, COLS = 0, SIZE = 0;
	int **matrix = nullptr;
	int *resultArray = nullptr;



	switch (addMode)
	{
	case DEFAULT: // ����������� ����
		cout << "������� ���������� ����� � ��������: ";
		ROWS = GetInt();
		COLS = GetInt();

		if (ROWS <= 0 || COLS <= 0) {
			cout << "���������� ����� � �������� �� �� �������������" << endl;
			system("pause");
			return;
		}
		matrix = new int*[ROWS];

		//// �������� ������� � �� ����������
		for (int i = 0; i < ROWS; i++)
		{
			matrix[i] = new int[COLS];
		}



		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << "������� ������� " << i + 1 << " ������ " << j + 1 << " �������: ";
				cin >> matrix[i][j];
			}
		}


		if (askAboutSaving(SAVE_INITIAL)) {  // ���������� �� ���������� �������� ������
			outputFile(SAVE_INITIAL, nullptr, 0, matrix, ROWS, COLS); // ���������� � ����
		}
		break;


	case RANDOM:		 //����� ��������� ������� ���������� ����������
		cout << "������� ���������� ����� � ��������: ";
		ROWS = GetInt();
		COLS = GetInt();
		 
		if (ROWS <= 0 || COLS <= 0) { 
			cout << "���������� ����� � �������� �� �� �������������" << endl;
			system("pause");
			return;
		}
		matrix = new int*[ROWS];

		// �������� ������� � �� ����������
		for (int i = 0; i < ROWS; i++)
		{
			matrix[i] = new int[COLS];
		}


		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				matrix[i][j] = rand() % 10000 - 5000;
			}
		}

		if (askAboutSaving(SAVE_INITIAL)) { // ���������� �� ���������� �������� ������
			outputFile(SAVE_INITIAL, nullptr, 0, matrix, ROWS, COLS); // ���������� � ����
		}
		break;
	case WITHFILE: { // ����� ��������� ������� ����� ���������
					 // ������ �� �������
		matrix = inputFile(matrix, ROWS, COLS);

		break;
	}
	}

	///////// �������� ������ ������� ////////////

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (matrix[i][j] < 0)
				SIZE++;
		}
	}
	resultArray = new int[SIZE];
	SIZE = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (matrix[i][j] < 0) {
				resultArray[SIZE] = matrix[i][j];
				SIZE++;
			}
		}
	}

	//// ���������� ������ ������� /////
	if (SIZE > 1) {
		int temp;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = i + 1; j < COLS; j++) {

				if (resultArray[i] > resultArray[j]) {
					temp = resultArray[i];
					resultArray[i] = resultArray[j];
					resultArray[j] = temp;
				}
			}
		}
	}


	//// ����� �������� ������ � ��������������� �������
	cout << endl <<"Matrix: " << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "Result array: ";
	for (int i = 0; i < SIZE; i++) {
		cout << resultArray[i];
	}
	cout << endl;


	
	if (askAboutSaving(SAVE_RESULT)) { // ���������� �� ���������� ����������
		outputFile(SAVE_RESULT, resultArray, SIZE); // ���������� � ����
	}


	for (int i = 0; i < ROWS; i++)
		delete[] matrix[i];
	delete[] matrix;
	delete[] resultArray;

}



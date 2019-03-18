#include <iostream>
#include <time.h>

#include "InputValidation.h"
#include "MenuInterface.h"
#include "workWithFile.h"


using namespace std;


void runLaba1() {

	srand(time(NULL));

	int addMode = getChoice(); // Получение режима заполнения матрицы

	int ROWS = 0, COLS = 0, SIZE = 0;
	int **matrix = nullptr;
	int *resultArray = nullptr;



	switch (addMode)
	{
	case DEFAULT: // стандартный ввод
		cout << "Введите количество строк и столбцов: ";
		ROWS = GetInt();
		COLS = GetInt();

		if (ROWS <= 0 || COLS <= 0) {
			cout << "Количество строк и столбцов не мб отрицательным" << endl;
			system("pause");
			return;
		}
		matrix = new int*[ROWS];

		//// Создание матрицы и ее заполнение
		for (int i = 0; i < ROWS; i++)
		{
			matrix[i] = new int[COLS];
		}



		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << "Введите элемент " << i + 1 << " строки " << j + 1 << " столбца: ";
				cin >> matrix[i][j];
			}
		}


		if (askAboutSaving(SAVE_INITIAL)) {  // Спращиваем об сохранении исходных данных
			outputFile(SAVE_INITIAL, nullptr, 0, matrix, ROWS, COLS); // Сохранение в файл
		}
		break;


	case RANDOM:		 //Режим заполения массива случайными значениями
		cout << "Введите количество строк и столбцов: ";
		ROWS = GetInt();
		COLS = GetInt();
		 
		if (ROWS <= 0 || COLS <= 0) { 
			cout << "Количество строк и столбцов не мб отрицательным" << endl;
			system("pause");
			return;
		}
		matrix = new int*[ROWS];

		// Создание матрицы и ее заполнение
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

		if (askAboutSaving(SAVE_INITIAL)) { // Спращиваем об сохранении исходных данных
			outputFile(SAVE_INITIAL, nullptr, 0, matrix, ROWS, COLS); // Сохранение в файл
		}
		break;
	case WITHFILE: { // Режим заполения матрицы путем получения
					 // данных из массива
		matrix = inputFile(matrix, ROWS, COLS);

		break;
	}
	}

	///////// Создание нового массива ////////////

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

	//// Сортировка нового массива /////
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


	//// Вывод исходной марицы и результирующего массива
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


	
	if (askAboutSaving(SAVE_RESULT)) { // Спрашиваем об сахронении результата
		outputFile(SAVE_RESULT, resultArray, SIZE); // сохранение в файл
	}


	for (int i = 0; i < ROWS; i++)
		delete[] matrix[i];
	delete[] matrix;
	delete[] resultArray;

}



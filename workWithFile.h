#ifndef _WORK_WITH_FILE_
#define _WORK_WITH_FILE_

#include <list>

void outputFile(int mode, int *data = nullptr, int SIZE = 0, int **initMatrix = nullptr, int ROWS = 0, int COLS = 0);
int** inputFile(int **matrix, int &COLS, int &ROLS);

#endif _WORK_WITH_FILE_
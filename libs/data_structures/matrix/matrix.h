#ifndef INC_13_LABA_MATRIX_H
#define INC_13_LABA_MATRIX_H

#include <stdio.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

//размещает в динамической памяти матрицу размером nRows на nCols. Возвращает матрицу.
matrix getMemMatrix(int nRows, int nCols);

#endif //INC_13_LABA_MATRIX_H

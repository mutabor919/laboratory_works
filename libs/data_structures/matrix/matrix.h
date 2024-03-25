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

/*размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.Возвращает указатель на нулевую матрицу.*/
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

//освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(matrix *m);

//освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);

// ввод матрицы m.
void inputMatrix(matrix *m);

// ввод массива из nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices);

//вывод матрицы m.
void printMatrix(matrix m);

// вывод массива из nMatrices матриц, хранящейся по адресу ms.
void printMatrices(matrix *ms, int nMatrices);

//обмен строк с порядковыми номерами i1 и i2 в матрице m.
void swapRows(matrix m, int i1, int i2);

//обмен колонок с порядковыми номерами j1 и j2 в матрице m.
void swapColumns(matrix m, int j1, int j2);


#endif //INC_13_LABA_MATRIX_H

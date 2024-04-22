#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

position getLeftMin(matrix m) {
    int min = m.values[0][0];
    int min_by_row = 0;
    int min_by_column = 0;

    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++) {
            if (m.values[j][i] < min) {
                min = m.values[j][i];
                min_by_row = j;
                min_by_column = i;
            }
        }
    }
    return (position) {min_by_row, min_by_column};
}

void swapPenultimateRow(matrix m) {
    position min_position = getLeftMin(m);
    int min_element_column[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        min_element_column[i] = m.values[i][min_position.colIndex];
    }

    for (size_t i = 0; i < m.nRows; i++) {
        m.values[m.nRows - 2][i] = min_element_column[i];
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int quantity_rows, quantity_columns;
    printf("Введите количество рядов и столбцов: ");
    scanf("%d %d", &quantity_rows, &quantity_columns);

    matrix m = getMemMatrix(quantity_rows, quantity_columns);
    printf("Введите элементы матрицы: ");
    inputMatrix(&m);
    swapPenultimateRow(m);
    printMatrix(m);

    return 0;
}
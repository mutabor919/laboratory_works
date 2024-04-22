#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

int getNSpecialElement(matrix m) {
    int quantity_special_elements = 0;
    for (int j = 0; j < m.nCols; ++j) {
        for (int i = 0; i < m.nRows; ++i) {
            int sum = 0;
            for (int k = 0; k < m.nRows; ++k) {
                if (k != i) {
                    sum += m.values[k][j];
                }
            }
            if (m.values[i][j] > sum) {
                quantity_special_elements++;
            }
        }
    }
    return quantity_special_elements;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int quantity_rows, quantity_columns;
    printf("Введите количество рядов и столбцов: ");
    scanf("%d %d", &quantity_rows, &quantity_columns);

    matrix m = getMemMatrix(quantity_rows, quantity_columns);
    printf("Введите элементы матрицы: ");
    inputMatrix(&m);
    printf("%d", getNSpecialElement(m));

    return 0;
}
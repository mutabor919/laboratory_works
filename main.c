#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; i++) {
        distance += a[i] * a[i];
    }
    return sqrt(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float criteria_array[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        criteria_array[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 1; i < m.nRows; i++) {
        float t = criteria_array[i];
        int j = i;
        while (j > 0 && criteria_array[j - 1] > t) {
            criteria_array[j] = criteria_array[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        criteria_array[j] = t;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int quantity_rows, quantity_columns;
    printf("Введите количество рядов и столбцов: ");
    scanf("%d %d", &quantity_rows, &quantity_columns);

    matrix m = getMemMatrix(quantity_rows, quantity_columns);
    inputMatrix(&m);
    sortByDistances(m);
    printMatrix(m);

    return 0;
}
#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

int getMin(int *a, int left, int right) {
    int min_element = a[left];
    for (int i = left + 1; i <= right; i++) {
        if (a[i] < min_element)
            min_element = a[i];
    }
    return min_element;
}

int getMinInArea(matrix m) {
    int min_in_selected_area;
    position max_element = getMaxValuePos(m);
    int left = max_element.colIndex;
    int right = max_element.colIndex;
    for (int i = max_element.rowIndex; i >= 0; i--) {
        int minInRow = getMin(m.values[i], left, right);

        if (i == max_element.rowIndex || minInRow < min_in_selected_area)
            min_in_selected_area = minInRow;
        if (right < m.nCols - 1)
            right++;
        if (left > 0)
            left--;
    }
    return min_in_selected_area;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int quantity_rows, quantity_columns;
    printf("Введите количество рядов и столбцов: ");
    scanf("%d %d", &quantity_rows, &quantity_columns);

    matrix m = getMemMatrix(quantity_rows, quantity_columns);
    printf("Введите элементы матрицы: ");
    inputMatrix(&m);
    printf("%d", getMinInArea(m));

    return 0;
}
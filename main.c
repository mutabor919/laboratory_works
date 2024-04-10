#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int quantity_rows,quantity_columns;
    printf("Введите количество рядов и столбцов: ");
    scanf("%d %d",&quantity_rows,&quantity_columns);

    matrix square_matrix = getMemMatrix(quantity_rows,quantity_columns);
    printf("Введите элементы матрицы: ");
    inputMatrix(&square_matrix);
    printMatrix(square_matrix);
    printf("\n");

    position position_min_element= getMinValuePos(square_matrix);
    position position_max_element= getMaxValuePos(square_matrix);

    swapRows(square_matrix,position_min_element.rowIndex,position_max_element.rowIndex);

    printMatrix(square_matrix);

    return 0;
}

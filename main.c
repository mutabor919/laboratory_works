#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

int cmp_long_long(const void *pa, const void *pb) {
    long long a = *(const long long *) pa;
    long long b = *(const long long *) pb;

    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    }
    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int count = 0;
    int unique = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            count++;
        }
        if (count > 0) {
            unique++;
            count = 0;
        }
    }
    return unique;
}

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int countEqClassesByRowsSum(matrix m) {
    long long sum_rows[m.nRows];
    for (int i = 0; i < m.nCols; i++) {
        sum_rows[i] = getSum(m.values[i], m.nCols);
    }
    return countNUnique(sum_rows, m.nRows);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int quantity_rows, quantity_columns;
    printf("Введите количество рядов и столбцов: ");
    scanf("%d %d", &quantity_rows, &quantity_columns);

    matrix m = getMemMatrix(quantity_rows, quantity_columns);
    inputMatrix(&m);
    printf("%d", countEqClassesByRowsSum(m));

    return 0;
}
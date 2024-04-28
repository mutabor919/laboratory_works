#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\tests\test.h"
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

void swapMinAndMaxRows(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);

    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

matrix mulMatrices(matrix m1, matrix m2) {
    matrix result = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < result.nRows; i++) {
        for (int j = 0; j < result.nCols; j++) {
            result.values[i][j] = 0;
            for (size_t k = 0; k < m1.nCols; k++) {
                result.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    return result;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(m)) {
        *m = mulMatrices(*m, *m);
    }
}

bool isUnique(long long *a, int n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (a[i] == a[j])
                return false;
        }
    }
    return true;
}

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumArray[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        sumArray[i] = getSum(m.values[i], m.nCols);
    }
    if (isUnique(sumArray, m.nRows)) {
        transposeSquareMatrix(&m);
    }
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m = mulMatrices(m1, m2);
    return isEMatrix(&m) ? true : false;
}

int max2(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int quantity = m.nRows + m.nCols - 2;
    int max_pseudo_diagonal[quantity];

    for (size_t i = 0; i < quantity; i++) {
        max_pseudo_diagonal[i] = 0;
    }

    int i_pseudo_diagonal;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (j != i) {
                if (i > j) {
                    i_pseudo_diagonal = j - i + m.nRows - 1;
                } else {
                    i_pseudo_diagonal = j - i + m.nRows - 2;
                }
                max_pseudo_diagonal[i_pseudo_diagonal] = max2(max_pseudo_diagonal[i_pseudo_diagonal], m.values[i][j]);
            }
        }
    }
    return getSum(max_pseudo_diagonal, quantity);
}

int getMins(int *a, int left, int right) {
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
        int minInRow = getMins(m.values[i], left, right);

        if (i == max_element.rowIndex || minInRow < min_in_selected_area)
            min_in_selected_area = minInRow;
        if (right < m.nCols - 1)
            right++;
        if (left > 0)
            left--;
    }
    return min_in_selected_area;
}


float getDistance(int *a, int n) {
    double distance = 0;
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

int countEqClassesByRowsSum(matrix m) {
    long long sum_rows[m.nRows];
    for (int i = 0; i < m.nCols; i++) {
        sum_rows[i] = getSum(m.values[i], m.nCols);
    }
    return countNUnique(sum_rows, m.nRows);
}

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

void swapPenultimateRow(matrix *m, int n) {
    if (isSquareMatrix(m)) {
        for (int i = m->nRows - 1; i >= 0; i--)
            m->values[m->nRows - 2][i] = m->values[i][n];
    }
}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        if (!isNonDescendingSorted(m.values[i], m.nCols)) {
            return false;
        }
    }
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int quantity_matrices = 0;
    for (int i = 0; i < nMatrix; i++) {
        if (hasAllNonDescendingRows(ms[i])) {
            quantity_matrices += 1;
        }
    }
    return quantity_matrices;
}

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            count += 1;
        }
    }
    return count;
}

int countZeroRows(matrix m) {
    int count_zero_rows = 0;
    for (int i = 0; i < m.nRows; i++) {
        if (countValues(m.values[i], m.nCols, 0) == m.nCols) {
            count_zero_rows += 1;
        }
    }
    return count_zero_rows;
}

void task1() {
    int value1[] = {3, 12, 4, 2, 8, 12, 6, 4, 0};
    int value2[] = {10, 2, 5, 8, 1, 15, 3, 4, 7, 6, 12, 9, 11, 4, 14, 13};
    int value3[] = {3, 2, 1, 0};
    matrix m1 = createMatrixFromArray(value1, 3, 3);
    matrix m2 = createMatrixFromArray(value2, 4, 4);
    matrix m3 = createMatrixFromArray(value3, 2, 2);

    swapMinAndMaxRows(m1);
    swapMinAndMaxRows(m2);
    swapMinAndMaxRows(m3);

    assert(m1.values[0][0] == 6 && m1.values[1][1] == 8 && m1.values[2][2] == 4);
    assert(m2.values[0][0] == 10 && m2.values[1][1] == 15 && m2.values[2][2] == 12 && m2.values[3][0] == 11);
    assert(m3.values[0][0] == 1 && m3.values[0][1] == 0 && m3.values[1][1] == 2);
}

void task2() {
    int values1[] = {7, 1, 2, 1, 8, 1, 3, 2, 3};
    int values2[] = {2, 5, 2, 8, 4, 1, 4, 8, 3, 8, 3, 6, 1, 2, 7, 8};

    matrix m1 = createMatrixFromArray(values1, 3, 3);
    matrix m2 = createMatrixFromArray(values2, 4, 4);

    insertionSortRowsMatrixByRowCriteria(m1, getMax);
    insertionSortRowsMatrixByRowCriteria(m2, getMax);

    assert(m1.values[0][0] == 3 && m1.values[0][1] == 2 && m1.values[1][1] == 1 && m1.values[2][2] == 1);
    assert(m2.values[0][0] == 2 && m2.values[0][1] == 5 && m2.values[1][1] == 1 && m2.values[2][0] == 3 &&
           m2.values[3][1] == 2);
}

void task3() {
    int values1[] = {3, 5, 2, 4, 3, 3, 2, 5, 1, 8, 2, 7, 6, 1, 4, 4, 8, 3};
    int values2[] = {2, 5, 12, 8, 1, 4, 1, 4, 8, 6, 3, 1, 3, 6, 11, 1, 2, 7, 8, 15};

    matrix m1 = createMatrixFromArray(values1, 3, 6);
    matrix m2 = createMatrixFromArray(values2, 4, 5);

    selectionSortColsMatrixByColCriteria(m1, getMin);
    selectionSortColsMatrixByColCriteria(m2, getMin);

    assert(m1.values[0][0] == 5 && m1.values[1][1] == 1 && m1.values[1][4] == 7 && m1.values[2][2] == 6);
    assert(m2.values[0][0] == 2 && m2.values[1][3] == 4 && m2.values[2][4] == 6 && m2.values[3][3] == 7);
}

void task4() {
    int values1[] = {1, 2, 3, 2, 4, 5, 3, 5, 6};
    int values2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    matrix m1 = createMatrixFromArray(values1, 3, 3);
    matrix m2 = createMatrixFromArray(values2, 3, 3);

    getSquareOfMatrixIfSymmetric(&m1);
    getSquareOfMatrixIfSymmetric(&m2);

    assert(m1.values[0][0] == 14 && m1.values[1][0] == 25 && m1.values[2][1] == 56);
    assert(m2.values[0][0] == 1 && m2.values[1][0] == 4 && m2.values[2][1] == 8);
}

void task5() {
    int values1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int values2[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    matrix m1 = createMatrixFromArray(values1, 3, 3);
    matrix m2 = createMatrixFromArray(values2, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m1);
    transposeIfMatrixHasNotEqualSumOfRows(m2);

    assert(m1.values[0][0] == 1 && m1.values[0][1] == 4 && m1.values[2][1] == 6);
    assert(m2.values[0][0] == 1 && m2.values[0][1] == 2 && m2.values[2][1] == 2);
}

void task6() {
    int values1[] = {1, 0, 0, 1};
    int values2[] = {1, 0, 0, 1};
    int values3[] = {1, 2, 3, 4};
    int values4[] = {1, 2, 3, 4, 5, 6};

    matrix m1 = createMatrixFromArray(values1, 2, 2);
    matrix m2 = createMatrixFromArray(values2, 2, 2);
    matrix m3 = createMatrixFromArray(values3, 2, 2);
    matrix m4 = createMatrixFromArray(values4, 3, 2);

    assert(isMutuallyInverseMatrices(m1, m2));
    assert(!isMutuallyInverseMatrices(m3, m4));
}

void task7() {
    int values1[] = {3, 2, 5, 4, 1, 3, 6, 3, 3, 2, 1, 2};
    int values2[] = {-3, -2, -5, -4, -1, -3, -6, -3};

    matrix m1 = createMatrixFromArray(values1, 3, 4);
    matrix m2 = createMatrixFromArray(values2, 4, 2);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 20);
    assert(findSumOfMaxesOfPseudoDiagonal(m2) == 0);
}

void task8() {
    int values1[] = {10, 7, 5, 6, 3, 11, 8, 9, 4, 1, 12, 2};
    int values2[] = {6, 8, 9, 2, 7, 12, 3, 4, 10, 11, 5, 1};

    matrix m1 = createMatrixFromArray(values1, 3, 4);
    matrix m2 = createMatrixFromArray(values2, 3, 4);

    assert(getMinInArea(m1) == 5 && getMinInArea(m2) == 6);
}

void task9() {
    int values1[] = {10, 7, 5, 6, 3, 11, 8, 9, 4, 1, 12, 2};
    int values2[] = {6, 8, 9, 2, 7, 12, 3, 4, 10, 11, 5, 1};

    matrix m1 = createMatrixFromArray(values1, 3, 4);
    matrix m2 = createMatrixFromArray(values2, 3, 4);

    sortByDistances(m1);
    sortByDistances(m2);

    assert(m1.values[0][0] == 4 && m1.values[1][0] == 10 && m1.values[2][1] == 11);
    assert(m2.values[0][0] == 6 && m2.values[1][0] == 7 && m2.values[2][1] == 11);
}

void task10() {
    int values1[] = {1, 2, 3, 4, 2, 3, 1, 2, 3};
    matrix m1 = createMatrixFromArray(values1, 3, 3);

    int values2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    matrix m2 = createMatrixFromArray(values2, 3, 3);

    assert(countEqClassesByRowsSum(m1) == 1 && countEqClassesByRowsSum(m2) == 2);
}

void task11() {
    int values1[] = {3, 5, 5, 4, 2, 3, 6, 7, 12, 2, 1, 2};
    matrix m1 = createMatrixFromArray(values1, 3, 4);

    int values2[] = {3, 6, 9, 12, 5, 8, 11, 14, 7};
    matrix m2 = createMatrixFromArray(values2, 3, 3);

    assert(getNSpecialElement(m1) == 2 && getNSpecialElement(m2) == 1);
}

void task12() {
    int values1[] = {1, 2, 3, 4, 5, 6, 7, 8, 1};
    matrix m1 = createMatrixFromArray(values1, 3, 3);

    int values2[] = {1, 2, 1, 4, 5, 0, 7, 8, 1};
    matrix m2 = createMatrixFromArray(values2, 3, 3);

    swapPenultimateRow(&m1, 0);
    swapPenultimateRow(&m2, 0);

    assert(m1.values[1][0] == 1 && m1.values[1][1] == 4 && m1.values[1][2] == 7);
    assert(m2.values[0][1] == 2 && m1.values[1][1] == 4 && m1.values[1][2] == 7);
}

void task13() {
    int values1a[] = {7, 1, 1, 1};
    int values1b[] = {1, 6, 2, 2};
    int values1c[] = {5, 4, 2, 3};
    int values1d[] = {1, 3, 7, 9};
    matrix m1a = createMatrixFromArray(values1a, 2, 2);
    matrix m1b = createMatrixFromArray(values1b, 2, 2);
    matrix m1c = createMatrixFromArray(values1c, 2, 2);
    matrix m1d = createMatrixFromArray(values1d, 2, 2);
    matrix matrices1[] = {m1a, m1b, m1c, m1d};

    int values2a[] = {1, 2, 3, 4, 5, 6};
    int values2b[] = {1, 3, 2, 4, 5, 1};
    matrix m2a = createMatrixFromArray(values2a, 2, 3);
    matrix m2b = createMatrixFromArray(values2b, 2, 3);
    matrix matrices2[] = {m2a, m2b};

    assert(countNonDescendingRowsMatrices(matrices1, 4) == 2);
    assert(countNonDescendingRowsMatrices(matrices2, 2) == 1);
}

void task14() {
    int values1[] = {0, 1, 1, 0, 0, 0};
    int values2[] = {1, 1, 2, 1, 1, 1};
    int values3[] = {0, 0, 0, 0, 4, 7};
    int values4[] = {0, 0, 0, 1, 0, 0};
    int values5[] = {0, 1, 0, 2, 0, 3};

    matrix m1 = createMatrixFromArray(values1, 3, 2);
    matrix m2 = createMatrixFromArray(values2, 3, 2);
    matrix m3 = createMatrixFromArray(values3, 3, 2);
    matrix m4 = createMatrixFromArray(values4, 3, 2);
    matrix m5 = createMatrixFromArray(values5, 3, 2);

    assert(countZeroRows(m1) == 1 && countZeroRows(m2) == 0 && countZeroRows(m3) == 2 && countZeroRows(m4) == 2 &&
           countZeroRows(m5) == 0);
}



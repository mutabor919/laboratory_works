#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

int main() {
    matrix m = getMemMatrix(3,3);
    inputMatrix(&m);
    printMatrix(m);
    printf("\n");
    swapRows(m, 0, 2);
    printMatrix(m);
    return 0;
}

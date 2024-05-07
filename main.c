#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\test_string\tests.h"

void test() {
    testStrlen();
    testFind();
    testFindNonSpace();
    testFindSpace();
    testFindSpaceReverse();
    testFindNonSpaceReverse();
    testStrcmp();
    testCopy();
    testCopyIf();
    testCopyIfReverse();
}

int main() {
    test();

    return 0;
}
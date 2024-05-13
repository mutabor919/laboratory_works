#include <assert.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

void testStrlen() {
    char *str = "";
    char *str2 = "Test for laboratory 17";
    size_t length1 = strlen_(str);
    size_t length2 = strlen_(str2);
    assert(length1 == 0 && length2 == 22);
}

void testFind() {
    char str[] = "Test for laboratory 17";
    char *found = find(str, str + 22, 'f');
    char *found2 = find(str, str + 22, 'l');
    assert(*found == 'f' && *found2 == 'l');
}

void testFindNonSpace() {
    char str[] = "Test for laboratory 17";
    char str2[] = "   Test for ";
    char *nonSpace = findNonSpace(str);
    char *nonSpace2 = findNonSpace(str2);
    assert(*nonSpace == 'T' && *nonSpace2 == 'T');
}

void testFindSpace() {
    char str[] = "Test for laboratory 17";
    char str2[] = "test ";
    char *space = findSpace(str);
    char *space2 = findSpace(str2);
    assert(*space == ' ' && *space2 == ' ');
}

void testFindSpaceReverse() {
    char str[] = "Test for laboratory 17";
    char str2[] = "lab o r a t o r y 1 7";
    char *rend = str - 1;
    char *rbegin = findSpaceReverse(str + 22, rend);
    char *rbegin2 = findSpaceReverse(str2 + 22, rend);
    assert(*rbegin == ' ' && *rbegin2 == ' ');
}

void testFindNonSpaceReverse() {
    char str[] = "Test for laboratory    ";
    char str2[] = "   Test for laboratory 17   ";
    char *rend = str - 1;
    char *rend2 = str2 - 1;
    char *rbegin = findNonSpaceReverse(str + 22, rend);
    char *rbegin2 = findNonSpaceReverse(str2 + 15, rend2);
    assert(*rbegin == 'y' && *rbegin2 == 'o');

}

void testStrcmp() {
    const char *str1 = "Test";
    const char *str2 = "Test";
    const char *str3 = "laboratory";
    assert(strcmp(str1, str2) >= 0 && strcmp(str1, str3) < 0);
}

void testCopy() {
    const char *str = "Test for laboratory 17";
    const char *str2 = "laboratory 17";
    char destination[30];
    char *nextFree = copy(str, str + 20, destination);
    char *nextFree2 = copy(str2, str2 + 9, destination);
    assert(nextFree - destination == 20 && nextFree2 - destination == 9);
}

int isLetter(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isDigit(int c) {
    return c >= '0' && c <= '9';
}

void testCopyIf() {
    char *str = "T2st f0r lab0ra7or9 17";
    char destination[20];
    char destination2[40];
    copyIf(str, str + 23, destination, isDigit);
    copyIf(str, str + 23, destination2, isLetter);

    assert(*destination == '2' && *(destination + 1) == '0' && *(destination + 2) == '0' && *(destination + 3) == '7' &&
           *(destination + 4) == '9' && *(destination + 5) == '1' && *(destination + 6) == '7');

    assert(*destination2 == 'T' && *(destination2 + 1) == 's' && *(destination2 + 2) == 't' &&
           *(destination2 + 3) == 'f' && *(destination2 + 4) == 'r' &&
           *(destination2 + 5) == 'l' && *(destination2 + 6) == 'a' && *(destination2 + 7) == 'b' &&
           *(destination2 + 8) == 'r' && *(destination2 + 9) == 'a' &&
           *(destination2 + 10) == 'o' && *(destination2 + 11) == 'r');

}

void testCopyIfReverse() {
    char *str = "T2st f0r lab0ra7or9 17";
    char destination[20];
    char destination2[40];
    copyIfReverse(str + 23, str, destination, isDigit);
    copyIfReverse(str + 23, str, destination2, isLetter);

    assert(*destination2 == 'r' && *(destination2 + 1) == 'o' && *(destination2 + 2) == 'a' &&
           *(destination2 + 3) == 'r' && *(destination2 + 4) == 'b' &&
           *(destination2 + 5) == 'a' && *(destination2 + 6) == 'l' && *(destination2 + 7) == 'r' &&
           *(destination2 + 8) == 'f' && *(destination2 + 9) == 't' &&
           *(destination2 + 10) == 's' && *(destination2 + 11) == 'T');
    assert(*destination == '7' && *(destination + 1) == '1' && *(destination + 2) == '9' && *(destination + 3) == '7' &&
           *(destination + 4) == '0' && *(destination + 5) == '0' && *(destination + 6) == '2');
}

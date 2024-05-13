#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

void replaceDigitsToNumOfSpaces(char *s) {
    copy(s, getEndOfString(s), _stringBuffer);
    char *recPtr = s;
    char *readPtr = _stringBuffer;
    for (int i = 0; i < strlen(_stringBuffer); ++i) {
        if (strlen(s) >= MAX_STRING_SIZE) {
            exit(1);
        }
        if (!isdigit(_stringBuffer[i])) {
            *recPtr = *readPtr;
            recPtr++;
            readPtr++;
        } else {
            int counter = _stringBuffer[i] - '0';
            for (int j = counter; j > 0; --j) {
                *recPtr = ' ';
                recPtr++;
            }
            readPtr++;
        }
    }
    _stringBuffer[0] = '\0';
    *recPtr = '\0';
}

void test_replaceEachNumberWithSpaces_nonDigits() {
    char s[] = "Test for laboratory 18";
    replaceDigitsToNumOfSpaces(s);
    ASSERT_STRING("Test for laboratory 18", s);
}

void test_replaceEachNumberWithSpaces_nonWords() {
    char s[] = "";
    replaceDigitsToNumOfSpaces(s);
    ASSERT_STRING("", s);
}

void test_replaceEachNumberWithSpaces_withDigits() {
    char s[] = "Test2 for2 laboratory8";
    replaceDigitsToNumOfSpaces(s);
    ASSERT_STRING("Test for laboratory", s);
}

int main() {
    test_replaceEachNumberWithSpaces_nonWords();
    test_replaceEachNumberWithSpaces_nonDigits();
    test_replaceEachNumberWithSpaces_withDigits();

    return 0;
}
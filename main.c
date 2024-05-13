#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

int countPalindromes(char *s) {
    char *endSearch = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPalindromes = 0;
    char *commaPos = find(beginSearch, endSearch, ',');
    bool isLastComma = *commaPos == '\0' && endSearch != beginSearch;

    while (*commaPos != '\0' || isLastComma) {
        beginSearch = findNonSpace(beginSearch);
        countPalindromes += isPalindrome(beginSearch, commaPos);
        beginSearch = commaPos + 1;
        if (isLastComma)
            break;
        commaPos = find(beginSearch, endSearch, ',');
        isLastComma = *commaPos == '\0';
    }
    return countPalindromes;
}

void test_countPalindromes() {
    char s[] = "Test,for,laboratory,eighteen";
    assert(countPalindromes(s) == 0);

    char s2[] = "";
    assert(countPalindromes(s2) == 0);

    char s3[] = "Test,ror";
    assert(countPalindromes(s3) == 1);
}

int main() {
    test_countPalindromes();
    return 0;
}
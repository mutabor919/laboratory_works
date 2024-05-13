#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

void removeAdjacentEqualLetters(char *s) {
    if ((s == NULL || strlen(s) == 0))
        return;
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] != s[i + 1]) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}

void test_removeAdjacentEqualLetters_nonEqualLetters() {
    char s[] = "Test";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("Test", s);
}

void test_removeAdjacentEqualLetters_noWords() {
    char s[] = " ";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(" ", s);
}

void test_removeAdjacentEqualLetters_EqualLetters() {
    char s[] = "TTTTeesssttttttffooooorr";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("Testfor", s);
}

int main() {
    test_removeAdjacentEqualLetters_noWords();
    test_removeAdjacentEqualLetters_nonEqualLetters();
    test_removeAdjacentEqualLetters_EqualLetters();

    return 0;
}
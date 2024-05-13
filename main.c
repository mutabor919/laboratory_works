#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

void combiningTwoStrings(char *s, char *s1, char *s2) {
    char *beginCopy = s;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    WordDescriptor word1, word2;
    bool isW1Found = true, isW2Found;
    while (isW1Found || isW2Found) {
        isW1Found = getWord(beginSearch1, &word1);
        isW2Found = getWord(beginSearch2, &word2);
        if (isW1Found) {
            beginCopy = copy(word1.begin, word1.end, beginCopy);
            *beginCopy++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            beginCopy = copy(word2.begin, word2.end, beginCopy);
            *beginCopy++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    *(beginCopy - 1) = '\0';
}

void test_combiningTwoStrings() {
    char s1[] = "T e s t f o r";
    char s2[] = "l a b o r a t o r y";
    char str[15];
    combiningTwoStrings(str, s1, s2);
    ASSERT_STRING("T l e a s b t o f r o a r t o r y", str);

    char s3[] = "a b c";
    char s4[] = "d e f";
    char str2[10];
    combiningTwoStrings(str2, s3, s4);
    ASSERT_STRING("a d b e c f", str2);
}

int main() {
    test_combiningTwoStrings();

    return 0;
}
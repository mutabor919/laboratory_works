#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    WordDescriptor word;
    char *ptr = s;
    char *prevWordEnd = NULL;
    int foundAWord = 0;

    while (getWord(&ptr, &word)) {
        if (find(word.begin, word.end, 'a') != word.end) {
            if (!foundAWord) {
                *w = word;
                return FIRST_WORD_WITH_A;
            } else {
                if (prevWordEnd != NULL) {
                    w->begin = s;
                    w->end = prevWordEnd;
                    return WORD_FOUND;
                } else {
                    return EMPTY_STRING;
                }
            }
        }

        prevWordEnd = word.end;
        foundAWord = 1;
    }

    if (ptr == s) {
        return EMPTY_STRING;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void test_getWordBeforeFirstWordWithA() {
    WordDescriptor word;

    char s1[] = "ab for test";
    char s2[] = "Test for eighteen";
    char s3[] = "";
    char s4[] = "Test for aboratory";

    assert(getWordBeforeFirstWordWithA(s1, &word) == FIRST_WORD_WITH_A &&
           getWordBeforeFirstWordWithA(s2, &word) == NOT_FOUND_A_WORD_WITH_A &&
           getWordBeforeFirstWordWithA(s3, &word) == EMPTY_STRING &&
           getWordBeforeFirstWordWithA(s4, &word) == WORD_FOUND);

}

int main() {
    test_getWordBeforeFirstWordWithA();

    return 0;
}
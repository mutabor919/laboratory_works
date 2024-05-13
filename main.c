#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

void digitToStartWithReverse(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartWithReverseForEveryWord(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithReverse(word);
        beginSearch = word.end;
    }
}

void test_digitToStartWithReverseForEveryWord_nonDigits() {
    char s[] = "Test for laboratory";
    digitToStartWithReverseForEveryWord(s);
    ASSERT_STRING("Test for laboratory", s);
}

void test_digitToStartWithReverseForEveryWord_nonWords() {
    char s[] = " ";
    digitToStartWithReverseForEveryWord(s);
    ASSERT_STRING("", s);
}

void test_digitToStartWithReverseForEveryWord_withDigits() {
    char s[] = "T29 f33";
    digitToStartWithReverseForEveryWord(s);
    ASSERT_STRING("92T 33f", s);
}

int main() {
    test_digitToStartWithReverseForEveryWord_nonWords();
    test_digitToStartWithReverseForEveryWord_nonDigits();
    test_digitToStartWithReverseForEveryWord_withDigits();

    return 0;
}
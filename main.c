#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char *ptr1 = w1.begin;
    char *ptr2 = w2.begin;

    while (ptr1 != w1.end && ptr2 != w2.end) {
        if (*ptr1 != *ptr2) {
            return 0;
        }
        ptr1++;
        ptr2++;
    }

    return ptr1 == w1.end && ptr2 == w2.end;
}

WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    BagOfWords bag1, bag2;
    getBagOfWords(&bag1, s1);
    getBagOfWords(&bag2, s2);

    for (int i = bag1.size - 1; i >= 0; i--) {
        WordDescriptor word = bag1.words[i];
        for (int j = 0; j < bag2.size; j++) {
            if (areWordsEqual(word, bag2.words[j])) {
                return word;
            }
        }
    }

    WordDescriptor emptyWord = {"", ""};
    return emptyWord;
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
    char *ptr = destination;
    char *wordPtr = word.begin;
    while (wordPtr != word.end) {
        *ptr++ = *wordPtr++;
    }
    *ptr = '\0';
}

void test_lastWordInFirstStringInSecondString() {
    char s1[] = "Test for laboratory eighteen";
    char s2[] = "lab eighteen";
    char s3[] = "laboratory";
    char s4[] = "tests";

    char result[MAX_WORD_SIZE];
    WordDescriptor word;

    word = lastWordInFirstStringInSecondString(s1, s2);
    wordDescriptorToString(word, result);
    ASSERT_STRING("eighteen", result);

    word = lastWordInFirstStringInSecondString(s1, s3);
    wordDescriptorToString(word, result);
    ASSERT_STRING("laboratory", result);

    word = lastWordInFirstStringInSecondString(s1, s4);
    wordDescriptorToString(word, result);
    ASSERT_STRING("", result);
}

int main() {
    test_lastWordInFirstStringInSecondString();

    return 0;
}
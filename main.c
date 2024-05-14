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

bool hasDuplicateWords(char *s) {
    BagOfWords bag;
    getBagOfWords(&bag, s);

    for (int i = 0; i < bag.size - 1; i++) {
        for (int j = i + 1; j < bag.size; j++) {
            if (areWordsEqual(bag.words[i], bag.words[j])) {
                return true;
            }
        }
    }

    return false;
}

void test_hasDuplicateWords() {
    char s1[] = "Test for for lab eighteen";
    char s2[] = "Test for laboratory eighteen";
    assert(hasDuplicateWords(s1) == true && hasDuplicateWords(s2) == false);
}

int main() {
    test_hasDuplicateWords();

    return 0;
}
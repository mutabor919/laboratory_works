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

void sortWord(WordDescriptor *word) {
    for (char *i = word->begin; i < word->end - 1; i++) {
        for (char *j = word->begin; j < word->end - 1; j++) {
            if (*j > *(j + 1)) {
                char temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
}

bool hasPairOfWordsWithSameLetters(char *s) {
    BagOfWords bag;
    getBagOfWords(&bag, s);

    for (int i = 0; i < bag.size; i++) {
        for (int j = i + 1; j < bag.size; j++) {
            sortWord(&bag.words[i]);
            sortWord(&bag.words[j]);
            if (areWordsEqual(bag.words[i], bag.words[j])) {
                return true;
            }
        }
    }

    return false;
}

void test_hasPairOfWordsWithSameLetters() {
    char s1[] = "Test for lab eighteen";
    char s2[] = "";
    char s4[] = "test tset";
    char s5[] = "eighteen eenhtieg";

    assert(hasPairOfWordsWithSameLetters(s1) == false);
    assert(hasPairOfWordsWithSameLetters(s2) == false);
    assert(hasPairOfWordsWithSameLetters(s4) == true);
    assert(hasPairOfWordsWithSameLetters(s5) == true);
}

int main() {
    test_hasPairOfWordsWithSameLetters();

    return 0;
}
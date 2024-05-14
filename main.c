#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

char *getWordsExceptLast(char *s) {
    BagOfWords bag;
    getBagOfWords(&bag, s);

    if (bag.size <= 1) {
        char *result = malloc(1);
        result[0] = '\0';
        return result;
    }
    size_t totalLength = 0;

    for (int i = 0; i < bag.size - 1; i++) {
        totalLength += strlen_(bag.words[i].begin) + 1;
    }

    char *result = malloc(totalLength + 1);

    char *ptr = result;
    for (int i = 0; i < bag.size - 1; i++) {
        ptr = copy(bag.words[i].begin, bag.words[i].end, ptr);
        *ptr++ = ' ';
    }
    *--ptr = '\0';

    return result;
}

void test_getWordsExceptLast() {
    char s1[] = "Test for lab eighteen";
    char s2[] = "Test for lab";
    char s3[] = "";

    ASSERT_STRING("Test for lab", getWordsExceptLast(s1));
    ASSERT_STRING("Test for", getWordsExceptLast(s2));
    ASSERT_STRING("", getWordsExceptLast(s3));

}

int main() {
    test_getWordsExceptLast();

    return 0;
}
#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

void reverseWords(char *s) {
    BagOfWords bag;
    getBagOfWords(&bag, s);
    for (int i = bag.size - 1; i >= 0; i--) {
        char *ptr = bag.words[i].begin;
        while (ptr != bag.words[i].end) {
            printf("%c", *ptr);
            ptr++;
        }
        printf(" ");
    }
}

int main() {
    char srt[] = "Test for laboratory eighteen";
    reverseWords(srt);

    return 0;
}
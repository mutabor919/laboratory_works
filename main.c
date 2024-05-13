#include <stdio.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

void printWord(WordDescriptor w) {
    char *endBuffer = copy(w.begin, w.end, _stringBuffer);
    *endBuffer = '\0';
    printf("%s", _stringBuffer);
}

void printWordsRevers(char *str) {
    BagOfWords w;
    getBagOfWords(&w, str);
    for (int i = w.size - 1; i >= 0; --i) {
        printWord(w.words[i]);
        printf("\n");
    }
}

int main() {
    char s[] = "Test for laboratory 18";
    printWordsRevers(s);

    return 0;
}
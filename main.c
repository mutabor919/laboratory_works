#include "C:\Users\mutab\CLionProjects\13_laba\libs\str\string\string_.h"

void replace(char *source, char *w1, char *w2) {
    size_t size_w1 = strlen(w1);
    size_t size_w2 = strlen(w2);
    WordDescriptor word1 = {w1, w1 + size_w1};
    WordDescriptor word2 = {w2, w2 + size_w2};
    char *readPtr, *recPtr;
    if (size_w1 >= size_w2) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }
    while (*readPtr != '\0') {
        if (memcmp(readPtr, w1, size_w1) == 0) {
            for (int i = 0; i < size_w2; i++) {
                *recPtr = w2[i];
                recPtr++;
            }
            readPtr += size_w1;
        } else {
            *recPtr = *readPtr;
            readPtr++;
            recPtr++;
        }
    }
}

void test_replace() {
    char s[] = "Test for";
    replace(s, "laboratory", "eighteen");
    ASSERT_STRING("Test for", s);

    char s2[] = "";
    replace(s2, "laboratory", "eighteen");
    ASSERT_STRING("", s2);

    char s3[] = "Test for";
    replace(s3, "for", "laboratory");
    ASSERT_STRING("Test laboratory", s3);
}

int main() {
    test_replace();

    return 0;
}
#ifndef INC_13_LABA_STRING__H
#define INC_13_LABA_STRING__H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>


#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

//char _stringBuffer[MAX_STRING_SIZE + 1];



//возвращает количество символов в строке.
size_t strlen_(char *begin);

/*возвращает указатель на первый элемент с кодом ch,расположенным на ленте памяти между адресами begin и end не включая end.*/
char *find(char *begin, char *end, int ch);

//возвращает указатель на первый символ, отличный от пробельных,расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.*/
char *findNonSpace(char *begin);

/*возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ.*/
char *findSpace(char *begin);

/*возвращает указатель на первый справа символ, отличный от пробельных,расположенный на ленте памяти, начиная с rbegin и заканчивая rend.*/
char *findNonSpaceReverse(char *rbegin, const char *rend);

//возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти, начиная с rbegin и заканчивая rend.*/
char *findSpaceReverse(char *rbegin, const char *rend);

/*возвращает отрицательное значение, если lhs располагается до rhs в лексикографическом порядке (как в словаре),
 значение 0, если lhs и rhs равны, иначе – положительное значение.*/
int strcmp(const char *lhs, const char *rhs);

/*записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
Возвращает указатель на следующий свободный фрагмент памяти в destination.*/
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

/*записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource заканчивая endSource,
удовлетворяющие функции-предикату f,возвращает указатель на следующий свободный для записи фрагмент в памяти.*/
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

/*записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource заканчивая rendSource,
удовлетворяющие функции-предикату f, возвращает значение beginDestination по окончанию работы функции.*/
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

//вернёт значение 0, если слово не было считано, в противном случае будет возвращено значение 1 и
// в переменную word будут записаны позиции начала слова и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

//возвращает указатель на конец строки
char *getEndOfString(char *s);

void getBagOfWords(BagOfWords *bag, char *s);

//возвращает значение 'истина', если слово является палиндромом
bool isPalindrome(char *begin, char *end);

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination);

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

#endif //INC_13_LABA_STRING__H

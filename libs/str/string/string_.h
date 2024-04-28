#ifndef INC_13_LABA_STRING__H
#define INC_13_LABA_STRING__H

#include <stdio.h>
#include <ctype.h>

//возвращает количество символов в строке.
size_t strlen_(const char *begin);

/*возвращает указатель на первый элемент с кодом ch,расположенным на ленте памяти между адресами begin и end не включая end.*/
char *find(char *begin, char *end, int ch);

//возвращает указатель на первый символ, отличный от пробельных,расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.*/
char *findNonSpace(char *begin);

/*возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ.*/
char *findSpace(char *begin);

#endif //INC_13_LABA_STRING__H

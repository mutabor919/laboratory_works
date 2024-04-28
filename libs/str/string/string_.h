#ifndef INC_13_LABA_STRING__H
#define INC_13_LABA_STRING__H

#include <stdio.h>

//возвращает количество символов в строке.
size_t strlen_(const char *begin);

/*возвращает указатель на первый элемент с кодом ch,расположенным на ленте памяти между адресами begin и end не включая end.*/
char *find(char *begin, char *end, int ch);


#endif //INC_13_LABA_STRING__H

//
// Created by 1 on 27.02.2022.
//

#ifndef STR_STRING__H
#define STR_STRING__H

#include <stdio.h>

size_t strlen_(const char *begin);

char *find(char *begin, const char *end, char ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char* copy(const char *beginSource, const char *endSource, char *beginDestination);

char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(char));

char* copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(char));

void removeSpaces(char *s);

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName, int line);

void removeAdjacentEqualLetters(char *s);

void removeExtraSpaces(char *s);

#endif //STR_STRING__H

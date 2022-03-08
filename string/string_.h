//
// Created by 1 on 27.02.2022.
//

#ifndef STR_STRING__H
#define STR_STRING__H

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20


typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end;   // позиция первого символа, после последнего символа слова
} WordDescriptor;

char stringBuffer [MAX_STRING_SIZE + 1];

char *createStringFromArray (char s[]);

bool getWord(char *beginSearch, WordDescriptor *word);

size_t strlen_(const char *begin);

char *find(char *begin, const char *end, char ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(char));

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(char));

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName, int line);


#endif //STR_STRING__H

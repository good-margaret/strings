//
// Created by 1 on 27.02.2022.
//

#include "string_.h"
#include <ctype.h>

size_t strlen_(const char *begin) {
    const char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, const char *end, char ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && *rbegin == ' ')
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    while (beginSource < endSource)
        *beginDestination++ = *beginSource++;

    return beginDestination;
}

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(char)) {
    while (beginSource < endSource) {
        if (f(*beginSource))
            *beginDestination++ = *beginSource;

        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(char)) {
    while (rbeginSource > rendSource) {
        if (f(*rbeginSource))
            *beginDestination++ = *rbeginSource;

        rbeginSource--;
    }

    return beginDestination;
}

int isNotSpace(char a) {
    return !isspace(a);
}

void removeSpaces(char *s) {
    char *destination = copyIf(s, s + strlen_(s), s, isNotSpace);
    *destination = '\0';
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

int isUnique(const char *x) {
    return *x != *(x + 1);
}

char *copyIfV2(char *beginSource, const char *endSource,
               char *beginDestination, int (*f)(const char *)) {
    while (beginSource < endSource) {
        if (f(beginSource))
            *beginDestination++ = *beginSource;

        beginSource++;
    }

    return beginDestination;
}

void removeAdjacentEqualLetters(char *s) {
    char *destination = copyIfV2(s, s + strlen_(s), s, isUnique);
    *destination = '\0';
}

void removeExtraSpaces(char *s) {
    char *destination = copyIf(findSpace(s) + 1, s + strlen_(s), findSpace(s) + 1, isNotSpace);
    *destination = '\0';
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, stringBuffer - 1, word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void changeWordsSequence(char *beginString) {
    char *beginSearch = beginString;

    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);

        beginSearch = word.end;
    }
}
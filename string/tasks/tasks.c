//
// Created by 1 on 27.02.2022.
//

#include "tasks.h"
#include <ctype.h>

int isNotSpace(char a) {
    return !isspace(a);
}

void removeSpaces(char *s) {
    char *destination = copyIf(s, s + strlen_(s), s, isNotSpace);
    *destination = '\0';
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

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    return true;
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

void changeFirstLettersThenReverseNumbers(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf(stringBuffer, endStringBuffer, word.begin, isalpha);
    copyIfReverse(endStringBuffer - 1, stringBuffer - 1, recPosition, isdigit);
}

void changeWordsSequenceFirstLettersThenReverseNumbers(char *beginString) {
    char *beginSearch = beginString;

    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        changeFirstLettersThenReverseNumbers(word);

        beginSearch = word.end;
    }
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);

    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse(word->end, rend);

    return true;
}

void changeDigitsToNSpaces(char *begin) {
    char *endStringBuffer = copy(begin, begin + strlen_(begin), stringBuffer);
    char *_stringBuffer = stringBuffer;

    while (_stringBuffer < endStringBuffer) {
        if (isdigit(*_stringBuffer))
            for (int i = 0; i < *_stringBuffer - '0'; i++)
                *begin++ = ' ';
        else
            *begin++ = *_stringBuffer;

        _stringBuffer++;
    }

    *begin = '\0';
}

bool areEqualWords (WordDescriptor w1, WordDescriptor w2) {
    *w1.end = '\0';
    *w2.end = '\0';
    return strcmp_(w1.begin, w2.begin) == 0;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, source + strlen_(source), stringBuffer);
        readPtr = stringBuffer;
        recPtr = source;
    }

    WordDescriptor word;
    while (getWord(readPtr, &word)) {
        //printf("%d\n", areEqualWords(word, word1));
        /*for (int *i = word.begin; i < word.end; i++) {
            printf("%c", *i);
        }
        printf("\n");*/

        if (areEqualWords(word, word1))
            recPtr = copy(word2.begin, word2.end, recPtr);
        else
            recPtr = copy(readPtr, word.end, recPtr);

        readPtr = word.end;
    }

    char *end = copy(readPtr, readPtr + strlen_(readPtr), recPtr);
    *end = '\0';
}

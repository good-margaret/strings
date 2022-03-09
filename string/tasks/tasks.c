//
// Created by 1 on 27.02.2022.
//

#include "tasks.h"
#include <ctype.h>
#include <memory.h>
#include <malloc.h>

char *createStringFromArray(char s[]) {
    char *str = (char *) malloc(MAX_STRING_SIZE);
    for (int i = 0; i < strlen_(s); i++)
        str[i] = s[i];

    str[strlen_(s)] = '\0';

    return str;
}

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

bool areEqualWords(WordDescriptor w1, WordDescriptor w2) {
    size_t w1Size = w1.end - w1.begin;
    size_t w2Size = w2.end - w2.begin;

    return w1Size == w2Size && memcmp(w1.begin, w2.begin, w1Size) == 0;
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
        copy(source, source + strlen_(source) + 1, stringBuffer);
        readPtr = stringBuffer;
        recPtr = source;
    }

    recPtr = copy(readPtr, findNonSpace(readPtr), recPtr);

    WordDescriptor word;
    while (getWord(readPtr, &word)) {
        if (areEqualWords(word, word1))
            recPtr = copy(word2.begin, word2.end, recPtr);
        else
            recPtr = copy(word.begin, word.end, recPtr);

        readPtr = word.end;
        recPtr = copy(readPtr, findNonSpace(readPtr), recPtr);
    }

    //recPtr = copy(readPtr, readPtr + strlen_(readPtr), recPtr);
    *recPtr = '\0';
}

int compareWords(WordDescriptor w1, WordDescriptor w2) {
    return memcmp(w1.begin, w2.begin, w1.end - w1.begin);
}

bool areNonDecreasingString(char *beginString) {
    WordDescriptor word1, word2;

    if (!getWord(beginString, &word1))
        return true;

    char *iRead = word1.end;

    while (getWord(iRead, &word2)) {
        if (compareWords(word1, word2) > 0)
            return false;

        iRead = word2.end;

        word1 = word2;
    }

    return true;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    WordDescriptor word;

    WordDescriptor *wordAddress = bag->words;

    while (getWord(s, &word)) {
        *wordAddress++ = word;
        s = word.end;
    }

    bag->size = wordAddress - bag->words;
}

void reverseWords(char *s) {
    getBagOfWords(&_bag, s);

    for (size_t i = _bag.size; i > 0; i--) {
        char *wordBegin = _bag.words[i - 1].begin;

        while (wordBegin < _bag.words[i - 1].end)
            printf("%c", *wordBegin++);

        printf("\n");
    }
}

bool getWordComas(char *s, WordDescriptor *word) {
    while (*s == ',')
        s++;

    word->begin = s;

    if (*word->begin == '\0')
        return false;

    word->end = find(s, s + strlen_(s), ',');

    //printf("%d\n", word->end - word->begin);

    return true;
}

bool checkIfPalindrome(WordDescriptor word) {
    while (word.begin < word.end - 1)
        if (*word.begin++ != *(word.end-- - 1))
            return false;

    return true;
}

int getPalindromeWordsAmount(char *s) {
    int nPalindromes = 0;

    WordDescriptor word;
    while (getWordComas(s, &word)) {
        nPalindromes += checkIfPalindrome(word);
        s = word.end;
    }

    return nPalindromes;
}


bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    if (rbegin == rend)
        return false;

    word->end = findNonSpaceReverse(rbegin, rend) + 1;

    if (word->end - 1 == rend)
        return false;

    word->begin = findSpaceReverse(word->end, rend) + 1;

    for (int i = 0; i < word->end - word->begin; i++) {
        printf("%c", *(word->begin + i));
    }

    printf("\n");

    return true;
}

void reverseWordsOrder(char *s) {
    *stringBuffer = ' ';
    memcpy(stringBuffer + 1, s, strlen_(s) + 1);
    printf("0%s\n", stringBuffer);
    WordDescriptor word;
    char *rbegin = stringBuffer + strlen_(stringBuffer);
    while (getWordReverse(rbegin, stringBuffer, &word)) {
        printf("1%s   ", word.begin);
         s = copy(word.begin, word.end, s);
         *s++ = ' ';
         rbegin = word.begin - 1;
        printf("2%s\n", s);
        //rbegin = word.begin;
    }

    *(s - 1) = '\0';

    printf("s=%s", s);
}

bool ifAIsThere(WordDescriptor word) {
    while (word.begin < word.end) {
        if (*word.begin == 'A' || *word.begin == 'a')
            return true;

        word.begin++;
    }

    return false;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore) {
    WordDescriptor prevWord, word;
    if(!getWord(s, &prevWord))
        return EMPTY_STRING;

    if(ifAIsThere(prevWord))
        return FIRST_WORD_WITH_A;

    char *iRead = prevWord.end;
    while (getWord(iRead, &word)) {
        if (ifAIsThere(word)) {
            *beginWordBefore = prevWord.begin;
            *endWordBefore = prevWord.end;

            return WORD_FOUND;
        } else {
            prevWord = word;
            iRead = word.end;
        }
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

char *blendStrings(char *s1, char *s2) {
    char s[strlen_(s1) + strlen_(s2) + 1];
    char *str = s;

    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)), isW1Found || isW2Found) {
        if (isW1Found) {
            str = copy(word1.begin, word1.end, str);
            *str++ = ' ';
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            str = copy(word2.begin, word2.end, str);
            *str++ = ' ';
            beginSearch2 = word2.end;
        }
    }

    *(str - 1) = '\0';

    char *string = s;
    return string;
}
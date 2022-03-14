//
// Created by 1 on 27.02.2022.
//

#include "tasks.h"
#include <ctype.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>

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
    if (rbegin <= rend)
        return false;

    word->end = findNonSpaceReverse(rbegin, rend) + 1;
    if (word->end - 1 == rend)
        return false;

    word->begin = findSpaceReverse(word->end - 1, rend) + 1;

    return true;
}

void reverseWordsOrder(char *s) {
    memcpy(stringBuffer, s, strlen_(s) + 1);

    WordDescriptor word;

    char *rbegin = stringBuffer + strlen_(stringBuffer) - 1;

    while (getWordReverse(rbegin, stringBuffer - 1, &word)) {
        memcpy(s, word.begin, word.end - word.begin);
        s += word.end - word.begin;
        *s++ = ' ';
        rbegin = word.begin - 1;
    }

    *(s - 1) = '\0';
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
    if (!getWord(s, &prevWord))
        return EMPTY_STRING;

    if (ifAIsThere(prevWord))
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

void wordDescriptorToString(WordDescriptor word, char *destination) {
    char *endString = copy(word.begin, word.end, destination);
    *endString = '\0';
}

bool isWordInBag(WordDescriptor word, BagOfWords bag) {
    for (int i = 0; i < bag.size; i++)
        if (compareWords(word, bag.words[i]) == 0)
            return true;

    return false;
}

bool lastWordInFirstStringInSecondString(char *s1, char *s2, WordDescriptor *word) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    int maxIndex = -1;

    for (int i = 0; i < _bag.size; i++) {
        if (isWordInBag(_bag.words[i], _bag2))
            maxIndex = i;
    }

    if (maxIndex == -1)
        return false;

    *word = _bag.words[maxIndex];

    return true;
}


int compareWordsHardcore(const void *word1, const void *word2) {
    const WordDescriptor *w1 = word1;
    const WordDescriptor *w2 = word2;

    return memcmp(w1->begin, w2->begin, w1->end - w1->begin);
}

bool checkIfRepeatedWordsInString(char *s) {
    getBagOfWords(&_bag, s);

    qsort(_bag.words, _bag.size, sizeof(WordDescriptor), compareWordsHardcore);

    for (int i = 1; i < _bag.size; i++)
        if (compareWords(_bag.words[i - 1], _bag.words[i]) == 0)
            return true;


    return false;
}

int comp_char(const void *ch1, const void *ch2) {
    char arg1 = *(char *) ch1;
    char arg2 = *(char *) ch2;

    return arg2 - arg1;
}

void sortLettersInWord(WordDescriptor word) {
    qsort(word.begin, word.end - word.begin, sizeof(char), comp_char);
}

bool isThereWordsWithSameLetters(char *s) {
    getBagOfWords(&_bag, s);

    for (int i = 0; i < _bag.size; i++)
        sortLettersInWord(_bag.words[i]);

    return checkIfRepeatedWordsInString(s);
}

char *getStringWithoutLastWord(char *s) {
    char *str = (char *) malloc(strlen_(s));
    *str = '\0';

    getBagOfWords(&_bag, s);
    if (_bag.size > 1) {
        WordDescriptor lastWord = _bag.words[_bag.size - 1];

        char *iWrite = str;
        for (int i = 0; i < _bag.size - 1; i++)
            if (!areEqualWords(_bag.words[i], lastWord)) {
                int wordLen = _bag.words[i].end - _bag.words[i].begin;
                memcpy(iWrite, _bag.words[i].begin, wordLen);
                iWrite += wordLen;
                *iWrite++ = ' ';
            }

        *(iWrite - 1) = '\0';
    }

    return str;
}

int firstWordInFirstBagInSecondBagIndex(BagOfWords b1, BagOfWords b2) {
    int maxIndex = -1;

    int i = 0;
    while (i < b1.size && maxIndex == -1) {
        if (isWordInBag(b1.words[i], b2))
            maxIndex = i;

        i++;
    }

    return maxIndex;
}

WordBeforeFirstCommonWordCode getWordBeforeFirstCommonWord(char *s1, char *s2, WordDescriptor *word) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    int firstCommonWordIndex = firstWordInFirstBagInSecondBagIndex(_bag, _bag2);
    if (firstCommonWordIndex > 0) {
        *word = _bag.words[firstCommonWordIndex - 1];
        return WORD_FOUND_OK;
    } else if (firstCommonWordIndex == 0)
        return FIRST_WORD;
    else
        return NO_COMMON_WORD;
}

bool isCharSubset(WordDescriptor set, char *subset) {
    size_t subsetLen = strlen_(subset);

    char *endSet = set.end - subsetLen + 1;
    while (set.begin < endSet) {
        int j = 0;
        while (j < subsetLen && *(set.begin + j) == *(subset + j))
            j++;

        if (j == subsetLen)
            return true;

        set.begin++;
    }

    return false;
}

void deleteWorstContainingTheseSymbols(char *s, char *symbols) {
    getBagOfWords(&_bag, s);

    char str[MAX_STRING_SIZE];
    *str = '\0';

    char *strIndex = str;
    for (int i = 0; i < _bag.size; i++)
        if (!isCharSubset(_bag.words[i], symbols)) {
            strIndex = copy(_bag.words[i].begin, _bag.words[i].end, strIndex);
            *strIndex++ = ' ';
        }

    *(strIndex - 1) = '\0';

    copy(str, strIndex + 1, s);
}

size_t max(size_t a, size_t b) {
    return a > b ? a : b;
}

size_t min(size_t a, size_t b) {
    return a < b ? a : b;
}

void swapBagsOfWords(BagOfWords *b1, BagOfWords *b2) {
    BagOfWords t = *b1;
    *b1 = *b2;
    *b2 = t;
}

void makeEqualWordNumberStrings(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    if (_bag.size > _bag2.size)
        swapBagsOfWords(&_bag, &_bag2);

    if (_bag.size < _bag2.size) {
        char *copyStart;
        if (_bag.size == 0)
            copyStart = s1;
        else {
            *_bag.words[_bag.size - 1].end = ' ';
            copyStart = _bag.words[_bag.size - 1].end + 1;
        }

        copy(_bag2.words[_bag.size].begin, _bag2.words[_bag2.size - 1].end + 1, copyStart);
    }
}
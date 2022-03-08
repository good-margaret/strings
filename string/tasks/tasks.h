//
// Created by 1 on 27.02.2022.
//

#ifndef STR_TASKS_H
#define STR_TASKS_H

#include <stdbool.h>
#include <stdio.h>
#include "../../string/string_.h"

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;


char stringBuffer[MAX_STRING_SIZE + 1];

BagOfWords _bag;
BagOfWords _bag2;


void removeSpaces(char *s);

bool getWord(char *beginSearch, WordDescriptor *word);

void removeAdjacentEqualLetters(char *s);

void removeExtraSpaces(char *s);

void changeWordsSequence(char *beginString);

void changeWordsSequenceFirstLettersThenReverseNumbers(char *beginString);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

void changeDigitsToNSpaces(char *begin);

void replace(char *source, char *w1, char *w2);

void removeSpaces(char *s);

int compareWords(WordDescriptor w1, WordDescriptor w2);

bool areNonDecreasingString(char *beginString);

void getBagOfWords(BagOfWords *bag, char *s);

void reverseWords(char *s);

#endif //STR_TASKS_H

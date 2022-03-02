#include <stdio.h>
#include "string/string_.h"
#include "string/tasks/tasks.h"
#include <assert.h>


#define ASSERT_STRING(expected , got) assertString(expected, got , __FILE__, __FUNCTION__, __LINE__)

void test_removeSpaces_1() {
    char s[] = "1 2 3";
    removeSpaces(s);
    ASSERT_STRING("123", s);
}

void test_removeSpaces_2() {
    char s[] = "123";
    removeSpaces(s);
    ASSERT_STRING("123", s);
}

void test_removeSpaces_3() {
    char s[] = "\n1\t23\t\t";
    removeSpaces(s);
    ASSERT_STRING("123", s);
}

void test_removeSpaces() {
    test_removeSpaces_1();
    test_removeSpaces_2();
    test_removeSpaces_3();
}

void test_removeAdjacentEqualLetters_1() {
    char s[] = "123";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("123", s);
}

void test_removeAdjacentEqualLetters_2() {
    char s[] = "11233";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("123", s);
}

void test_removeAdjacentEqualLetters_3() {
    char s[] = "111222233333";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("123", s);
}

void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters_1();
    test_removeAdjacentEqualLetters_2();
    test_removeAdjacentEqualLetters_3();
}

void test_strcmp_1() {
    char s1[] = "123";
    char s2[] = "123";

    assert(strcmp_(s1, s2) == 0);
}

void test_strcmp_2() {
    char s1[] = "122";
    char s2[] = "123";

    assert(strcmp_(s1, s2) < 0);
}

void test_strcmp_3() {
    char s1[] = "124";
    char s2[] = "123";

    assert(strcmp_(s1, s2) > 0);
}

void test_strcmp_4() {
    char s1[] = "1230";
    char s2[] = "123";

    assert(strcmp_(s1, s2) > 0);
}

void test_strcmp() {
    test_strcmp_1();
    test_strcmp_2();
    test_strcmp_3();
    test_strcmp_4();
}

void test_removeExtraSpaces_1() {
    char s[] = "123";
    removeExtraSpaces(s);
    ASSERT_STRING("123", s);
}

void test_removeExtraSpaces_2() {
    char s[] = "123\t";
    removeExtraSpaces(s);
    ASSERT_STRING("123\t", s);
}

void test_removeExtraSpaces_3() {
    char s[] = "\n1\t2 3\t\t";
    removeExtraSpaces(s);
    ASSERT_STRING("\n123", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_1();
    test_removeExtraSpaces_2();
    test_removeExtraSpaces_3();
}

void test_changeWordsSequence_1() {
    char s[] = "1a2b3c";
    changeWordsSequence(s);
    ASSERT_STRING("321abc", s);
}

void test_changeWordsSequence_2() {
    char s[] = "1a2b3c avra27 om 54321";
    changeWordsSequence(s);
    ASSERT_STRING("321abc 72avra om 12345", s);
}

void test_changeWordsSequence_3() {
    char s[] = "\n1a2b3c \t\naa27 \to\n";
    changeWordsSequence(s);
    ASSERT_STRING("\n321abc \t\n72aa \to\n", s);
}

void test_changeWordsSequence() {
    test_changeWordsSequence_1();
    test_changeWordsSequence_2();
    test_changeWordsSequence_3();
}

void test_changeWordsSequenceFirstLettersThenReverseNumbers_1() {
    char s[] = "1a2b3c";
    changeWordsSequenceFirstLettersThenReverseNumbers(s);
    ASSERT_STRING("abc321", s);
}

void test_changeWordsSequenceFirstLettersThenReverseNumbers_2() {
    char s[] = "1a2b3c avra27 om 54321";
    changeWordsSequenceFirstLettersThenReverseNumbers(s);
    ASSERT_STRING("abc321 avra72 om 12345", s);
}

void test_changeWordsSequenceFirstLettersThenReverseNumbers_3() {
    char s[] = "\n1a2b3c \t\naa27 \to\n";
    changeWordsSequenceFirstLettersThenReverseNumbers(s);
    ASSERT_STRING("\nabc321 \t\naa72 \to\n", s);
}

void test_changeWordsSequenceFirstLettersThenReverseNumbers() {
    test_changeWordsSequenceFirstLettersThenReverseNumbers_1();
    test_changeWordsSequenceFirstLettersThenReverseNumbers_2();
    test_changeWordsSequenceFirstLettersThenReverseNumbers_3();
}

void test_changeDigitsToNSpaces_1() {
    char s[] = "1ma3r2go1";
    changeDigitsToNSpaces(s);
    ASSERT_STRING(" ma   r  go ", s);
}

void test_changeDigitsToNSpaces_2() {
    char s[] = "margo";
    changeDigitsToNSpaces(s);
    ASSERT_STRING("margo", s);
}

void test_changeDigitsToNSpaces_3() {
    char s[] = "123";
    changeDigitsToNSpaces(s);
    ASSERT_STRING("      ", s);
}

void test_changeDigitsToNSpaces() {
    test_changeDigitsToNSpaces_1();
    test_changeDigitsToNSpaces_2();
    test_changeDigitsToNSpaces_3();
}

void test_replace() {
    char s[] = "a a b";
    char w1 = 'a';
    char w2 = 'c';

    replace(s, &w1, &w2);
    ASSERT_STRING("c c b", s);
}

void test() {
    test_strcmp();
    test_removeSpaces();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_changeWordsSequence();
    test_changeWordsSequenceFirstLettersThenReverseNumbers();
    test_changeDigitsToNSpaces();
    test_replace();
}

int main() {
    test();

    printf("Hello, World!\n");

    return 0;
}

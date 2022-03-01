#include <stdio.h>
#include "string/string_.h"
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

void test() {
    test_strcmp();
    test_removeSpaces();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
}

int main() {
    test();

    printf("Hello, World!\n");

    return 0;
}

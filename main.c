#include <stdio.h>
#include "string/string_.h"

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

int main() {
    printf("Hello, World!\n");
    test_removeSpaces();
    return 0;
}

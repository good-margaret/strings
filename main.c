#include <stdio.h>
#include "string/string_.h"
#include "string/tasks/tasks.h"
#include <assert.h>
#include <malloc.h>

#define ASSERT_STRING(expected, got) assertString(expected, got , __FILE__, __FUNCTION__, __LINE__)

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

void test_replace_1() {
    char s[] = "a";
    char w1[] = "a";
    char w2[] = "c";

    replace(s, w1, w2);
    ASSERT_STRING("c", s);
}

void test_replace_2() {
    char *s = createStringFromArray("a");

    char w1[] = "a";
    char w2[] = "cc";

    replace(s, w1, w2);
    ASSERT_STRING("cc", s);

    free(s);
}

void test_replace_3() {
    char *s = createStringFromArray("a a b");
    //char s[] = "a a b";
    char *w1 = "a";
    char *w2 = "c";

    replace(s, w1, w2);
    ASSERT_STRING("c c b", s);

    free(s);
}

void test_replace_4() {
    char *s = createStringFromArray("\tar arr ar tar ");
    //char s[] = "\tar arr ar tar ";
    char w1[] = "ar";
    char w2[] = "r";

    replace(s, w1, w2);
    ASSERT_STRING("\tr arr r tar ", s);

    free(s);
}

void test_replace_5() {
    char *s = createStringFromArray("a aa aaa a a ");

    char w1[] = "a";
    char w2[] = "cc";

    replace(s, w1, w2);
    ASSERT_STRING("cc aa aaa cc cc ", s);

    free(s);
}

void test_replace() {
    test_replace_1();
    test_replace_2();
    test_replace_3();
    test_replace_4();
    test_replace_5();
}

void test_areNonDecreasingString_1() {
    char s[] = "a b";

    if (areNonDecreasingString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_areNonDecreasingString_2() {
    char s[] = "ab b";

    if (areNonDecreasingString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_areNonDecreasingString_3() {
    char s[] = "a a a";

    if (areNonDecreasingString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_areNonDecreasingString_4() {
    char s[] = "a b c";

    if (areNonDecreasingString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_areNonDecreasingString_5() {
    char s[] = "b a";

    if (!areNonDecreasingString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_areNonDecreasingString_6() {
    char s[] = "";

    if (areNonDecreasingString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_areNonDecreasingString_7() {
    char s[] = "aa ab ac";

    if (areNonDecreasingString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_areNonDecreasingString_8() {
    char s[] = "aa ab aa";

    if (!areNonDecreasingString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_areNonDecreasingString() {
    test_areNonDecreasingString_1();
    test_areNonDecreasingString_2();
    test_areNonDecreasingString_3();
    test_areNonDecreasingString_4();
    test_areNonDecreasingString_5();
    test_areNonDecreasingString_6();
    test_areNonDecreasingString_7();
    test_areNonDecreasingString_8();
}

void test_getPalindromeWordsAmount_1() {
    char s[] = "aa";

    if (getPalindromeWordsAmount(s) == 1)
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_getPalindromeWordsAmount_2() {
    char s[] = "ab";

    if (getPalindromeWordsAmount(s) == 0)
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_getPalindromeWordsAmount_3() {
    char s[] = "aca";

    if (getPalindromeWordsAmount(s) == 1)
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_getPalindromeWordsAmount_4() {
    char s[] = "aa,abacaba,wow";

    if (getPalindromeWordsAmount(s) == 3)
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_getPalindromeWordsAmount_5() {
    char s[] = "aa,abac,wow";

    if (getPalindromeWordsAmount(s) == 2)
        fprintf(stderr, "%s - OK\n", __FUNCTION__);
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_getPalindromeWordsAmount() {
    test_getPalindromeWordsAmount_1();
    test_getPalindromeWordsAmount_2();
    test_getPalindromeWordsAmount_3();
    test_getPalindromeWordsAmount_4();
    test_getPalindromeWordsAmount_5();
}

void test_blendStrings_1() {
    char s1[] = "a";
    char s2[] = "b";
    ASSERT_STRING("a b", blendStrings(s1, s2));
}

void test_blendStrings_2() {
    char s1[] = "a aa";
    char s2[] = "b bb";
    ASSERT_STRING("a b aa bb", blendStrings(s1, s2));
}

void test_blendStrings_3() {
    char s1[] = "a aa aaa";
    char s2[] = "";
    ASSERT_STRING("a aa aaa", blendStrings(s1, s2));
}

void test_blendStrings_4() {
    char s1[] = "";
    char s2[] = "b bb";
    ASSERT_STRING("b bb", blendStrings(s1, s2));
}

void test_blendStrings_5() {
    char s1[] = "a aa";
    char s2[] = "b bb bbb bbbb";
    ASSERT_STRING("a b aa bb bbb bbbb", blendStrings(s1, s2));
}

void test_blendStrings() {
    test_blendStrings_1();
    test_blendStrings_2();
    test_blendStrings_3();
    test_blendStrings_4();
    test_blendStrings_5();
}

void test_reverseWordsOrder_1() {
    char s[] = "a";
    reverseWordsOrder(s);
    ASSERT_STRING("a", s);
}

void test_reverseWordsOrder_2() {
    char s[] = " a ";
    reverseWordsOrder(s);
    ASSERT_STRING("a", s);
}

void test_reverseWordsOrder_3() {
    char s[] = "a b ca";
    reverseWordsOrder(s);
    ASSERT_STRING("ca b a", s);
}

void test_reverseWordsOrder() {
    test_reverseWordsOrder_1();
    test_reverseWordsOrder_2();
    test_reverseWordsOrder_3();
}

void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert (getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);

    char s2[] = " ABC";
    assert (getWordBeforeFirstWordWithA(s2, &beginWord, &endWord)
            == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert (getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);

    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING ("BC", got);

    char s4[] = "B Q WE YR OW IUWR ";
    assert (getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) ==
            NOT_FOUND_A_WORD_WITH_A);
}

void test_lastWordInFirstStringInSecondString_1() {
    char s1[] = "a b c";
    char s2[] = "a c b";
    WordDescriptor w;
    if (!lastWordInFirstStringInSecondString(s1, s2, &w)) {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    } else {
        char string[100];
        wordDescriptorToString(w, string);
        ASSERT_STRING ("c", string);
    }
}

void test_lastWordInFirstStringInSecondString_2() {
    char s1[] = "a b c";
    char s2[] = "a n m";
    WordDescriptor w;
    if (!lastWordInFirstStringInSecondString(s1, s2, &w)) {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    } else {
        char string[100];
        wordDescriptorToString(w, string);
        ASSERT_STRING ("a", string);
    }
}

void test_lastWordInFirstStringInSecondString_3() {
    char s1[] = "a b c";
    char s2[] = "b n m";
    WordDescriptor w;
    if (!lastWordInFirstStringInSecondString(s1, s2, &w)) {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    } else {
        char string[100];
        wordDescriptorToString(w, string);
        ASSERT_STRING ("b", string);
    }
}

void test_lastWordInFirstStringInSecondString_4() {
    char s1[] = "aa ab ac";
    char s2[] = "ab an am";
    WordDescriptor w;
    if (!lastWordInFirstStringInSecondString(s1, s2, &w)) {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    } else {
        char string[100];
        wordDescriptorToString(w, string);
        ASSERT_STRING ("ab", string);
    }
}

void test_lastWordInFirstStringInSecondString_5() {
    char s1[] = "a b c";
    char s2[] = "m n h";
    WordDescriptor w;
    if (lastWordInFirstStringInSecondString(s1, s2, &w)) {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    } else
        fprintf(stderr, "%s - OK\n", __FUNCTION__ );
}

void test_lastWordInFirstStringInSecondString() {
    test_lastWordInFirstStringInSecondString_1();
    test_lastWordInFirstStringInSecondString_2();
    test_lastWordInFirstStringInSecondString_3();
    test_lastWordInFirstStringInSecondString_4();
    test_lastWordInFirstStringInSecondString_5();
}

void test_findNonSpaceReverse_1() {
    char s[] = "a b   ";
    assert(*findNonSpaceReverse(s + strlen_(s) - 1, s) == 'b');
}

void test_findNonSpaceReverse_2() {
    char s[] = "a b";
    assert(*findNonSpaceReverse(s + strlen_(s) - 1, s) == 'b');
}

void test_findNonSpaceReverse_3() {
    char s[] = "a";
    assert(*findNonSpaceReverse(s + strlen_(s) - 1, s) == 'a');
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_1();
    test_findNonSpaceReverse_2();
    test_findNonSpaceReverse_3();
}

void test_findSpaceReverse_1() {
    char s[] = "a b   ";
    assert(findSpaceReverse(s + strlen_(s) - 1, s) == s + 5);
}

void test_findSpaceReverse_2() {
    char s[] = "a b";
    assert(findSpaceReverse(s + strlen_(s) - 1, s) == s + 1);
}

void test_findSpaceReverse_3() {
    char s[] = " a";
    assert(findSpaceReverse(s + strlen_(s) - 1, s) == s);
}

void test_findSpaceReverse_4() {
    char s[] = "a";
    assert(findSpaceReverse(s + strlen_(s) - 1, s) == s);
}

void test_findSpaceReverse() {
    test_findSpaceReverse_1();
    test_findSpaceReverse_2();
    test_findSpaceReverse_3();
    test_findSpaceReverse_4();
}

void test_getWordReverse() {
    char s[] = "az";
    char str[100];
    WordDescriptor w;
    getWordReverse(s + strlen_(s) - 1, s, &w);
    wordDescriptorToString(w, str);
    ASSERT_STRING("z", str);
}

void test_checkIfRepeatedWordInString_1() {
    char s[] = "a a";

    if (checkIfRepeatedWordsInString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__ );
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__ , __LINE__);
    }
}

void test_checkIfRepeatedWordInString_2() {
    char s[] = "a b";

    if (!checkIfRepeatedWordsInString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__ );
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_checkIfRepeatedWordInString_3() {
    char s[] = "a b a";

    if (checkIfRepeatedWordsInString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__ );
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_checkIfRepeatedWordInString_4() {
    char s[] = "";

    if (!checkIfRepeatedWordsInString(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__ );
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_checkIfRepeatedWordInString() {
    test_checkIfRepeatedWordInString_1();
    test_checkIfRepeatedWordInString_2();
    test_checkIfRepeatedWordInString_3();
    test_checkIfRepeatedWordInString_4();
}

void test_isThereWordsWithSameLetters_1() {
    char s[] = "a a";

    if (isThereWordsWithSameLetters(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__ );
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_isThereWordsWithSameLetters_2() {
    char s[] = "a";

    if (!isThereWordsWithSameLetters(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__ );
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_isThereWordsWithSameLetters_3() {
    char s[] = "a b";

    if (!isThereWordsWithSameLetters(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__ );
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_isThereWordsWithSameLetters_4() {
    char s[] = "aba ava baa";

    if (isThereWordsWithSameLetters(s))
        fprintf(stderr, "%s - OK\n", __FUNCTION__ );
    else {
        fprintf(stderr, " File %s\n", __FILE__);
        fprintf(stderr, "%s - failed on line %d\n", __FUNCTION__, __LINE__);
    }
}

void test_isThereWordsWithSameLetters() {
    test_isThereWordsWithSameLetters_1();
    test_isThereWordsWithSameLetters_2();
    test_isThereWordsWithSameLetters_3();
    test_isThereWordsWithSameLetters_4();
}

void test_getStringWithoutLastWord_1() {
    char s[] = "a a a";
    char *resStr = getStringWithoutLastWord(s);

    ASSERT_STRING("", resStr);

    free(resStr);
}

void test_getStringWithoutLastWord_2() {
    char s[] = "a b a";
    char *resStr = getStringWithoutLastWord(s);

    ASSERT_STRING("b", resStr);

    free(resStr);
}

void test_getStringWithoutLastWord_3() {
    char s[] = "ab ba a";
    char *resStr = getStringWithoutLastWord(s);

    ASSERT_STRING("ab ba", resStr);

    free(resStr);
}

void test_getStringWithoutLastWord_4() {
    char s[] = "a a aa";
    char *resStr = getStringWithoutLastWord(s);

    ASSERT_STRING("a a", resStr);

    free(resStr);
}

void test_getStringWithoutLastWord_5() {
    char s[] = "ar ra ar";
    char *resStr = getStringWithoutLastWord(s);

    ASSERT_STRING("ra", resStr);

    free(resStr);
}

void test_getStringWithoutLastWord() {
    test_getStringWithoutLastWord_1();
    test_getStringWithoutLastWord_2();
    test_getStringWithoutLastWord_3();
    test_getStringWithoutLastWord_4();
    test_getStringWithoutLastWord_5();
}

void testAll_getWordBeforeLastCommon() {
    WordDescriptor w;

    char s11[] = "c b a";
    char s21[] = "a b c";

    assert (getWordBeforeFirstCommonWord(s11, s21, &w)
            == FIRST_WORD);

    char s12[] = "n k l";
    char s22[] = "a b c";

    assert (getWordBeforeFirstCommonWord(s12, s22, &w) == NO_COMMON_WORD);

    char s13[] = "n k k";
    char s23[] = "a b k";

    assert (getWordBeforeFirstCommonWord(s13, s23, &w) == WORD_FOUND_OK);
    char s[MAX_WORD_SIZE];
    wordDescriptorToString(w, s);

    ASSERT_STRING ("n", s);
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
    test_areNonDecreasingString();
    test_getPalindromeWordsAmount();
    test_blendStrings();
    testAll_getWordBeforeFirstWordWithA();
    test_lastWordInFirstStringInSecondString();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_reverseWordsOrder();
    test_checkIfRepeatedWordInString();
    test_isThereWordsWithSameLetters();
    test_getStringWithoutLastWord();
    testAll_getWordBeforeLastCommon();
}


int main() {
    test();

    //test_isThereWordsWithSameLetters();
    //test_reverseWordsOrder();
    //test_getWordReverse();
    //test_checkIfRepeatedWordInString();
    //char s[] = "aa ab ac";
    //reverseWords(s);

    return 0;
}

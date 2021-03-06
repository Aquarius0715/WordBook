//
// Created by 北野正樹 on 2021/01/21.
//
#include "stdio.h"
#include "Data.h"

#ifndef WORDBOOK_VOL2_UTIL_H
#define WORDBOOK_VOL2_UTIL_H

int getSize(char words[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    int i;
    for (i = 0; i < LENGTH_OF_WORDS; i++) {
        if (words[i][0] == '\0') {
            return i;
        }
    }
    return 0;
}

int getSmallCapitalId(char character) {
    if (character >= 65 && character <= 90) {
        return character + 32;
    } else if (character >= 97 && character <= 122 || character >= 48 && character <= 57) {
        return character;
    }
    return 0;
}

int isCapital(char string) {
    if (string >= 48 && string <= 57 || string >= 97 && string <= 122 || string >= 65 && string <= 90 || string == 32) {
        return 1;
    } else {
        return 0;
    }
}

int stringCopy(const char original[LENGTH_OF_WORDS], char copy[LENGTH_OF_WORDS]) {
    for (int i = 0; i < LENGTH_OF_WORDS; i++) {
        if (original[i] == '\0' && copy[i] == '\0') {
            return 0;
        }
        copy[i] = original[i];
    }
    return 1;
}

int getStringLength(const char string[LENGTH_OF_WORDS]) {
    for (int i = 0; i < LENGTH_OF_WORDS; i++) {
        if (string[i] == '\0') {
            return i;
        }
    }
    return -1;
}

int isEquals(char string1[LENGTH_OF_WORDS], char string2[LENGTH_OF_WORDS]) {
    if (string1[0] == '\0' || string2[0] == '\0') {
        return 0;
    }
    if (getStringLength(string1) != getStringLength(string2)) {
        return 0;
    }
    for (int i = 0; i < LENGTH_OF_WORDS; i++) {
        if (string1[i] == '\0' || string2[i] == '\0') {
            if (string1[i - 1] == string2[i - 1]) {
                return 1;
            } else {
                return 0;
            }
        }
        if (string1[i] != string2[i]) {
            return 0;
        }
    }
    return 1;
}

int isContains(char string[LENGTH_OF_WORDS], char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBook[i][0] == '\0') {
            break;
        }
        if (isEquals(string, wordBook[i])) {
            return 1;
        }
    }
    return 0;
}

int swapString(char string1[LENGTH_OF_WORDS], char string2[LENGTH_OF_WORDS]) {
    if (string1[0] == '\0' || string2[0] == '\0') {
        return 0;
    }
    char memory[LENGTH_OF_WORDS];
    stringCopy(string2, memory);
    stringCopy(string1, string2);
    stringCopy(memory, string1);
    return 1;
}

int shiftString(char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS], int n) {
    for (int i = n + 1; i < NUMBER_OF_WORDS; i++) {
        if (wordBook[i - 1][0] == '\0') {
            return 1;
        }
        for (int ii = 0; ii < LENGTH_OF_WORDS; ii++) {
            wordBook[i - 1][ii] = wordBook[i][ii];
        }
    }
    return 0;
}

void sortString(char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    for (int i = 0; i < NUMBER_OF_WORDS ; i++) {
        if (wordBook[i + 1][0] == '\0') return;
        for (int ii = 0; ii < LENGTH_OF_WORDS ; ii++) {
            if (getSmallCapitalId(wordBook[i][ii]) > getSmallCapitalId(wordBook[i + 1][ii])) {
                swapString(wordBook[i], wordBook[i + 1]);
                i = -1;
                break;
            } else if (getSmallCapitalId(wordBook[i][ii]) == getSmallCapitalId(wordBook[i + 1][ii])) {
                continue;
            } else if (getSmallCapitalId(wordBook[i][ii]) < getSmallCapitalId(wordBook[i + 1][ii])) {
                break;
            }
        }
    }
}

int deleteDuplicate(char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    char str[LENGTH_OF_WORDS];
    char str2[LENGTH_OF_WORDS];
    int count = 0;
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBook[i][0] == '\0') {
            return count;
        }
        for (int ii = 0; ii < LENGTH_OF_WORDS; ii++) {
            str[ii] = wordBook[i][ii];
        }
        for (int I = i + 1; I < NUMBER_OF_WORDS; I++) {
            for (int II = 0; II < LENGTH_OF_WORDS; II++) {
                str2[II] = wordBook[I][II];
            }
            if (isEquals(str, str2)) {
                shiftString(wordBook, I);
                I = i;
                count++;
            }
        }
    }
    return count;
}

int deleteString(char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char string[LENGTH_OF_WORDS]) {
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBook[i][0] == '\0') {
            return 0;
        }
        if (isEquals(wordBook[i], string)) {
            shiftString(wordBook, i);
            return 1;
        }
    }
    return 0;
}

int getWordFromSentence(char sentence[TOTAL_LETTERS], char words[NUMBER_OF_WORDS][LENGTH_OF_WORDS], int n) {
    int insertCount = 0;
    for (int i = 0, ii = 0; i < NUMBER_OF_WORDS; i++) {
        char word[LENGTH_OF_WORDS] = {};
        for (int iii = 0; ; (ii++)) {
            if (getSize(words) >= NUMBER_OF_WORDS - 1) {
                break;
            }
            if (!isCapital(sentence[ii]) && sentence[ii] != ' ' && sentence[ii] != '\0' && sentence[ii] != '\n') {
                continue;
            }
            if (sentence[ii] >= 65 && sentence[ii] <= 90) {
                sentence[ii] = (char) getSmallCapitalId(sentence[ii]);
            }
            word[iii] = sentence[ii]; iii++;
            if (word[0] == '\n' || word[0] == ' ') {
                break;
            }
            if (sentence[ii + 1] == ' ') {
                if (sentence[ii + 1] == '\0') {
                    break;
                }
                stringCopy(word, words[i + n]);
                insertCount++;
                ii += 2;
                break;
            } else if (sentence[ii + 1] == '\0' || sentence[ii + 1] == '\n') {
                stringCopy(word, words[i + n]);
                insertCount++;
                return insertCount;
            }
        }
    }
    return insertCount;
}

int println(char string[LENGTH_OF_WORDS]) {
    printf("%s\n", string);
    return 1;
}

void printFrame(int n) {
    printf("+-");
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("-+\n");
}

#endif //WORDBOOK_VOL2_UTIL_H
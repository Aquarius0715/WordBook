//
// Created by 北野正樹 on 2021/01/22.
//
#include <stdio.h>
#include "Util.h"

#ifndef WORDBOOK_VOL2_SYSTEM_H
#define WORDBOOK_VOL2_SYSTEM_H

#endif //WORDBOOK_VOL2_SYSTEM_H

void printHelp() {
    println("\n----------wordbook----------");
    println("this program is simple wordbook.");
    println("----------command list------");
    println("<help> show this help.");
    println("<create wordbook [wordbook]> create new wordbook.");
    println("<show wordbooks> show index of wordbook.");
    println("<insert into [wordbook] [elements]> insert words to the assigned wordbook.");
    println("<select from [wordbook]> select words from the assigned wordbook.");
    println("<delete from [wordbook]> delete the word from the assigned wordbook.");
    println("<truncate wordbook [wordbook]> truncate words from the assigned wordbook.");
    println("<drop wordbook [wordbook]> drop the assigned wordbook.");
    println("<quit> Quit this program.\n");
}

void quitProgram() {
    //TODO quit logic
    println("quit wordbook program.");
}

int chooseWordBook(char wordBookName[LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    if (!isContains(wordBookName, wordBookIndex)) {
        return -1;
    }
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBookIndex[i][0] == '\0') {
            break;
        }
        if (isEquals(wordBookName, wordBookIndex[i])) {
            return i;
        }
    }
    return -1;
}

void truncateWordBook(char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS], char cmdWords[NUMBER_OF_WORDBOOK][LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    int index = chooseWordBook(cmdWords[2], wordBookIndex);
    if (index == -1) {
        println("failed to truncate the wordbook (because not exist wordbook)");
        return;
    }
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBook[index][i][0] == '\0') {
            break;
        }
        for (int ii = 0; ii < LENGTH_OF_WORDS; ii++) {
            if (wordBook[index][i][ii] == '\0') {
                break;
            }
            wordBook[index][i][ii] = '\0';
        }
    }
    println("cleared wordbook successfully");
}

void dropWordBook(char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char string[LENGTH_OF_WORDS]) {
    int index = chooseWordBook(string, wordBookIndex);
    if (index == -1) {
        println("failed to drop the wordbook (because not exist wordbook)");
        return;
    }
    if (!isContains(string, wordBookIndex)) {
        println("failed to drop the wordbook (because not exist wordbook)");
        return;
    }
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBook[index][i][0] == '\0') {
            break;
        }
        for (int ii = 0; ii < LENGTH_OF_WORDS; ii++) {
            if (wordBook[index][i][ii] == '\0') {
                break;
            }
            wordBook[index][i][ii] = '\0';
        }
    }
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBookIndex[i][0] == '\0') {
            break;
        }
        if (isEquals(string, wordBookIndex[i])) {
            shiftString(wordBookIndex, i);
            println("dropped wordbook successfully");
            return;
        }
    }
}

void addWord(char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS], char cmdWords[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    int index = chooseWordBook(cmdWords[2], wordBookIndex);
    if (index == -1) {
        println("failed to add word to the wordbook (because not exist wordbook)");
        return;
    }
    getWordFromSentence(cmdWords[3], wordBook[index], getSize(wordBook[index]));
    int deleteCount = deleteDuplicate(wordBook[index]);
    sortString(wordBook[index]);
    if (deleteCount == 0) {
        println("added 1 word to the wordbook successfully");
    } else {
        println("failed to add word to the wordbook (because duplicate)");
    }
}

void addMultipleWords(char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS], char cmdWords[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    int index = chooseWordBook(cmdWords[2], wordBookIndex);
    if (index == -1) {
        println("failed to add word to the wordbook (because not exist wordbook)");
        return;
    }
    int i;
    for (i = 0; i < NUMBER_OF_WORDS; i++) {
        if (cmdWords[i + 3][0] == '\0') {
            break;
        }
        getWordFromSentence(cmdWords[i + 3], wordBook[index], getSize(wordBook[index]));
    }
    int deleteCount = deleteDuplicate(wordBook[index]);
    sortString(wordBook[index]);
    if (i - deleteCount == 0) {
        println("added nothing to the wordbook (because duplicate)");
    } else {
        printf("added %d words to the wordbook\n", i - deleteCount);
    }
}

void deleteWord(char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS], char cmdWords[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    int index = chooseWordBook(cmdWords[2], wordBookIndex);
    if (index == -1) {
        println("failed to delete word to the wordbook (because not exist wordbook)");
        return;
    }
    if (deleteString(wordBook[index], cmdWords[4])) {
        printf("the word '%s' deleted successfully\n", cmdWords[4]);
        return;
    } else {
        printf("the word '%s' deleted failed (because not exist word)\n", cmdWords[4]);
        return;
    }
}

void createWordBook(char string[LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    if (isContains(string, wordBookIndex)) {
        println("failed to create a new wordbook (already exist the wordbook)");
        return;
    }
    stringCopy(string, wordBookIndex[getSize(wordBookIndex)]);
    println("create wordbook successfully");
}

void createDefaultWordBook(char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    createWordBook("default", wordBookIndex);
    char cmd_words[NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {"insert", "into", "default", "welcome", "to", "the", "wordbook", "program"};
    addMultipleWords(wordBook, cmd_words, wordBookIndex);
}

void showIndex(char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
        char title[LENGTH_OF_WORDS] = {"wordbook"};
        int max = 0;
        if (getStringLength(title) > max) {
            max = getStringLength(title);
        }
        for (int i = 0; i < NUMBER_OF_WORDS; i++) {
            if (wordBookIndex[i][0] == '\0') {
                break;
            }
            if (getStringLength(wordBookIndex[i]) > max) {
                max = getStringLength(wordBookIndex[i]);
            }
        }

        printFrame(max);
        for (int i = 0; i < max; i++) {
            if (i == 0) {
                printf("| ");
            }
            if (title[i] != '\0') {
                printf("%c", title[i]);
            } else {
                printf(" ");
            }
        }
        printf(" |\n");
        printFrame(max);

        int i;
        for (i = 0; i < NUMBER_OF_WORDS; i++) {
            if (wordBookIndex[i][0] == '\0') {
                printFrame(max);
                printf("%d words in set\n\n", i);
                return;
            }
            for (int ii = 0; ii < max; ii++) {
                if (ii == 0) {
                    printf("| ");
                }
                if (wordBookIndex[i][ii] != '\0' && wordBookIndex[i][ii] != ' ') {
                    printf("%c", wordBookIndex[i][ii]);
                } else {
                    printf(" ");
                }
            }
            printf(" |\n");
        }
    printFrame(max);
    printf("%d words in set\n\n", i);
}

void selectWordBook(char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char cmdWords[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char title[LENGTH_OF_WORDS]) {
    int index = chooseWordBook(cmdWords[2], wordBookIndex);
    if (index == -1) {
        println("failed to select words from the wordbook (because not exist wordbook)");
        return;
    }
    int max = 0;
    if (getStringLength(title) > max) {
        max = getStringLength(title);
    }
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBook[index][i][0] == '\0') {
            break;
        }
        if (getStringLength(wordBook[index][i]) > max) {
            max = getStringLength(wordBook[index][i]);
        }
    }

    printFrame(max);
    for (int i = 0; i < max; i++) {
        if (i == 0) {
            printf("╎ ");
        }
        if (title[i] != '\0') {
            printf("%c", title[i]);
        } else {
            printf(" ");
        }
    }
    printf(" ╎\n");
    printFrame(max);

    int i;

    for (i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBook[index][i][0] == '\0') {
            printFrame(max);
            printf("%d words in set\n\n", i);
            return;
        }
        for (int ii = 0; ii < max; ii++) {
            if (ii == 0) {
                printf("╎ ");
            }
            if (wordBook[index][i][ii] != '\0' && wordBook[index][i][ii] != ' ') {
                printf("%c", wordBook[index][i][ii]);
            } else {
                printf(" ");
            }
        }
        printf(" ╎\n");
    }
    printFrame(max);
    printf("%d words in set\n\n", i);
}
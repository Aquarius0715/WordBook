//
// Created by 北野正樹 on 2021/01/21.
//
#include "System.h"

#ifndef WORDBOOK_VOL2_COMMAND_H
#define WORDBOOK_VOL2_COMMAND_H

#endif //WORDBOOK_VOL2_COMMAND_H

int onCommand(char cmd[], char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    char cmdWords[NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {};
    getWordFromSentence(cmd, cmdWords, 0);
    if (isEquals(cmdWords[0], "wordbook") == 0 || isEquals(cmdWords[0], "wb") == 0) {
        if (getSize(cmdWords) == 1) {
            printHelp();
            return 1;
        }
        if (getSize(cmdWords) == 2) {
            if (isEquals(cmdWords[1], "help") == 0) {
                printHelp();
                return 1;
            }
            if (isEquals(cmdWords[1], "show") == 0) {
                print_word_two_dimensions(wordBook);
                return 1;
            }
            if (isEquals(cmdWords[1], "clear") == 0) {
                clearWordBook(wordBook);
                return 1;
            }
            if (isEquals(cmdWords[1], "quit") == 0) {
                quitProgram();
                return 0;
            }
        }
        if (getSize(cmdWords) == 3) {
            if (isEquals(cmdWords[1], "add") == 0) {
                addWord(wordBook, cmdWords);
                return 1;
            }
            if (isEquals(cmdWords[1], "delete") == 0) {
                deleteWord(wordBook, cmdWords);
                return 1;
            }
        }
        if (getSize(cmdWords) > 3) {
            if (isEquals(cmdWords[1], "add") == 0) {
                addMultipleWords(wordBook, cmdWords);
                return 1;
            }
        }
        println("There is no such command.");
        return 1;
    }
    return 1;
}
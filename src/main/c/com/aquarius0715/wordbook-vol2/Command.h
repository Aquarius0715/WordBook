//
// Created by 北野正樹 on 2021/01/21.
//

#include "System.h"

#ifndef WORDBOOK_VOL2_COMMAND_H
#define WORDBOOK_VOL2_COMMAND_H

#endif //WORDBOOK_VOL2_COMMAND_H

int onCommand(char cmd[], char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    char cmdWords[NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {};
    getWordFromSentence(cmd, cmdWords, 0);

    if (isEquals(cmdWords[0], "quit")) {
        if (getSize(cmdWords) == 1) {
            quitProgram(wordBook, wordBookIndex);
            return 0;
        }
    }

    if (isEquals(cmdWords[0], "help")) {
        if (getSize(cmdWords) == 1) {
            printHelp();
            return 1;
        }
    }

    if (isEquals(cmdWords[0], "show")) {
        if (getSize(cmdWords) == 2) {
            if (isEquals(cmdWords[1], "wordbooks")) {
                showIndex(wordBookIndex);
                return 1;
            }
        }
        println("usage: show wordbooks");
        return 1;
    }

    if (isEquals(cmdWords[0], "create")) {
        if (isEquals(cmdWords[1], "wordbook")) {
            if (getSize(cmdWords) == 3) {
                createWordBook(cmdWords[2], wordBookIndex);
                return 1;
            }
        }
        println("usage: create wordbook [wordbook]");
        return 1;
    }

    if (isEquals(cmdWords[0], "truncate")) {
        if (isEquals(cmdWords[1], "wordbook")) {
            if (getSize(cmdWords) == 3) {
                truncateWordBook(wordBook, cmdWords, wordBookIndex);
                return 1;
            }
        }
        println("usage: truncate wordbook [wordbook]");
        return 1;
    }

    if (isEquals(cmdWords[0], "drop")) {
        if (isEquals(cmdWords[1], "wordbook")) {
            if (getSize(cmdWords) == 3) {
                dropWordBook(wordBook, wordBookIndex, cmdWords[2]);
                return 1;
            }
        }
        println("usage: drop wordbook [wordbook]");
        return 1;
    }

    if (isEquals(cmdWords[0], "insert")) {
        if (isEquals(cmdWords[1], "into")) {
            if (getSize(cmdWords) == 4) {
                insertWord(wordBook, cmdWords, wordBookIndex);
                return 1;
            }
            if (getSize(cmdWords) > 4) {
                insertMultipleWords(wordBook, cmdWords, wordBookIndex);
                return 1;
            }
        }
        println("usage: insert into [wordbook] [element]");
        return 1;
    }

    if (isEquals(cmdWords[0], "select")) {
        if (isEquals(cmdWords[1], "from")) {
            if (getSize(cmdWords) == 3) {
                selectWordBook(wordBook, wordBookIndex, cmdWords, cmdWords[2]);
                return 1;
            }
        }
        println("usage: select from [wordbook]");
        return 1;
    }
    if (isEquals(cmdWords[0], "delete")) {
        if (isEquals(cmdWords[1], "from")) {
            if (isEquals(cmdWords[3], "where")) {
                if (getSize(cmdWords) == 5) {
                    deleteWord(wordBook, cmdWords, wordBookIndex);
                    return 1;
                }
            }
        }
        println("usage: delete from [wordbook] where [element]");
        return 1;
    }
    println("There is no such command.");
    return 1;
}
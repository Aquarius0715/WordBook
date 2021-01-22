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
    println("command label is 'wordbook' or 'wb'.");
    println("----------command list------");
    println("wb show: show words in the wordbook.");
    println("wb add [word]: Add a word to the wordbook.");
    println("wb add [sentence]: Add multiple words to your wordbook.");
    println("wb delete [word]: Deletes the specified word from the wordbook.");
    println("wb clear: Delete all words in the wordbook.");
    println("wb quit: Quit this program.\n");
}

void quitProgram() {
    //TODO quit logic
    println("quit wordbook program.");
}

void clearWordBook(char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBook[i][0] == '\0') {
            break;
        }
        for (int ii = 0; ii < LENGTH_OF_WORDS; ii++) {
            if (wordBook[i][ii] == '\0') {
                break;
            }
            wordBook[i][ii] = '\0';
        }
    }
    println("cleared wordbook successfully");
}

void addWord(char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char cmdWords[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    getWordFromSentence(cmdWords[2], wordBook, getSize(wordBook));
    int deleteCount = deleteDuplicate(wordBook);
    sortString(wordBook);
    if (deleteCount == 0) {
        println("added 1 word to the wordbook");
    } else {
        println("added nothing to the wordbook (because duplicate)");
    }
}

void addMultipleWords(char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char cmdWords[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    int i;
    for (i = 0; i < NUMBER_OF_WORDS; i++) {
        if (cmdWords[i + 2][0] == '\0') {
            break;
        }
        getWordFromSentence(cmdWords[i + 2], wordBook, getSize(wordBook));
    }
    int deleteCount = deleteDuplicate(wordBook);
    sortString(wordBook);
    if (i - deleteCount == 0) {
        println("added nothing to the wordbook (because duplicate)");
    } else {
        printf("added %d words to the wordbook\n", i - deleteCount);
    }
}

void deleteWord(char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char cmd_words[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    if (deleteString(wordBook, cmd_words[2])) {
        printf("the word '%s' deleted successfully\n", cmd_words[2]);
        return;
    } else {
        printf("the word '%s' deleted failed (because not exist word)\n", cmd_words[2]);
        return;
    }
}
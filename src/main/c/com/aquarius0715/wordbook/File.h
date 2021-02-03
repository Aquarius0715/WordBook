//
// Created by 北野正樹 on 2021/01/24.
//

#include "Util.h"

#ifndef WORDBOOK_VOL2_SAVE_H
#define WORDBOOK_VOL2_SAVE_H

void createDefaultWordBook() {
    FILE *fp;
    char filename[LENGTH_OF_WORDS];
    sprintf(filename, "default.txt");
    fp = fopen(filename, "w");
    char words[NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {"welcome", "to", "the", "wordbook", "program"};
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (words[i][0] == '\0') {
            break;
        }
        fprintf(fp, "%s\n", words[i]);
    }
    fclose(fp);
}

void createDefaultIndex() {
    FILE *fp;
    char filename[LENGTH_OF_WORDS];
    sprintf(filename, "WordBookIndex.txt");
    fp = fopen(filename, "w");
    fprintf(fp, "%s\n", "default");
    fclose(fp);
}

void saveIndex(char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    FILE *fp;  /* ファイルポインタの宣言 */
    char filename[LENGTH_OF_WORDS];
    sprintf(filename, "WordBookIndex.txt");
    if ((fp = fopen(filename, "w")) == NULL) {  /* ファイルのオープン */
        println("file open error!!");
        return;
    }
    for (int i = 0; i < NUMBER_OF_WORDS; i++) {
        if (wordBookIndex[i][0] == '\0') {
            break;
        }
        fprintf(fp, "%s\n", wordBookIndex[i]);
    }
    fclose(fp);
}

void saveWordBook(char wordBookIndex[NUMBER_OF_WORDBOOK][LENGTH_OF_WORDS], char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDBOOK][LENGTH_OF_WORDS]) {
    FILE *fp;
    for (int i = 0; i < NUMBER_OF_WORDBOOK; i++) {
        if (wordBookIndex[i][0] == '\0') {
            return;
        }
        char filename[LENGTH_OF_WORDS];
        sprintf(filename, "%s.txt", wordBookIndex[i]);
        if ((fp = fopen(filename, "w")) == NULL) {
            println("file open error!!");
            return;
        }
        for (int ii = 0; ii < NUMBER_OF_WORDS; ii++) {
            if (wordBook[i][ii][0] == '\0') {
                break;
            }
            fprintf(fp, "%s\n", wordBook[i][ii]);
        }
    }
    fclose(fp);
}

void save(char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    saveIndex(wordBookIndex);
    saveWordBook(wordBookIndex, wordBook);
}

int getIndex(char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    FILE *fp;
    char filename[LENGTH_OF_WORDS];
    sprintf(filename, "WordBookIndex.txt");
    if ((fp = fopen(filename, "r")) == NULL) {
        return 0;
    }
    for (int i = 0; fgets(wordBookIndex[i], LENGTH_OF_WORDS, fp) != NULL; i++) {
        wordBookIndex[i][getStringLength(wordBookIndex[i]) - 1] = '\0';
    }
    fclose(fp);
    return 1;
}

int getWordBook(char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS], char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    FILE *fp;
    for (int i = 0; i < NUMBER_OF_WORDBOOK; i++) {
        if (wordBookIndex[i][0] == '\0') {
            return 1;
        }
        char filename[LENGTH_OF_WORDS];
        sprintf(filename, "%s.txt", wordBookIndex[i]);
        if ((fp = fopen(filename, "r")) == NULL) {
            return 0;
        }
        for (int ii = 0; fgets(wordBook[i][ii], LENGTH_OF_WORDS, fp) != NULL; ii++) {
            wordBook[i][ii][getStringLength(wordBook[i][ii]) - 1] = '\0';
        }
    }
    fclose(fp);
    return 1;
}

void checkFile(char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS], char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS]) {
    if (!getIndex(wordBookIndex)) {
        createDefaultIndex();
        createDefaultWordBook();
        getIndex(wordBookIndex);
        getWordBook(wordBook, wordBookIndex);
    } else {
        getIndex(wordBookIndex);
        getWordBook(wordBook, wordBookIndex);
    }
}

#endif //WORDBOOK_VOL2_SAVE_H

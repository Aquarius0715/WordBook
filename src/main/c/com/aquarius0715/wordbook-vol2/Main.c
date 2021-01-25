#include "stdio.h"

#include "Command.h"

char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {};
char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {};

void start() {
    checkFile(wordBookIndex, wordBook);
    println("Type 'help' to see the commands.");
    while (1) {
        char cmdSentence[LENGTH_OF_WORDS] = {};
        printf("WordBook> ");
        fgets(cmdSentence, LENGTH_OF_WORDS, stdin);
        if (cmdSentence[0] == '\n') {
            continue;
        }
        if (onCommand(cmdSentence, wordBook, wordBookIndex)) {
            continue;
        } else {
            return;
        }
    }
}

int main() {
    start();
    return 0;
}

#include "stdio.h"

#include "Command.h"

char wordBook[NUMBER_OF_WORDBOOK][NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {};
char wordBookIndex[NUMBER_OF_WORDS][LENGTH_OF_WORDS];

void start() {
    createDefaultWordBook(wordBook, wordBookIndex);
    println("Type 'help' to see the commands.");
    println("You are using default wordbook.");
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

void test() {
    char test1[LENGTH_OF_WORDS] = {"tashika"};
    char test2[LENGTH_OF_WORDS] = {"sakura"};
    char test3[NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {"apple", "bean", "zoo", "age"};
    printf("%s %s\n", test1, test2);
    swapString(test1, test2);
    printf("%s %s\n", test1, test2);
}

int main() {
    //test();
    start();
    return 0;
}

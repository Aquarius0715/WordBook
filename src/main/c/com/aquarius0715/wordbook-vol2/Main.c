#include <stdio.h>
#include "Command.h"

void alpha() {
    char wordBook[NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {};
    println("Type 'wb to see the commands.'");
    while (1) {
        char cmdWords[NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {};
        char cmdSentence[LENGTH_OF_WORDS] = {};
        printf("WordBook> ");
        fgets(cmdSentence, LENGTH_OF_WORDS, stdin);
        if (cmdSentence[0] == '\n') {
            continue;
        }
        if (onCommand(cmdSentence, wordBook)) {
            continue;
        } else {
            return;
        }
    }
}

void test() {
    char test1[LENGTH_OF_WORDS] = {"unchi"};
    char test2[LENGTH_OF_WORDS] = {"uncahi"};
    char test3[NUMBER_OF_WORDS][LENGTH_OF_WORDS] = {"apple", "bean", "unchi"};
    print_word_two_dimensions(test3);
    printf("\n");
    shiftString(test3, 0);
    print_word_two_dimensions(test3);
}

int main() {
    //test();
    alpha();
    return 0;
}

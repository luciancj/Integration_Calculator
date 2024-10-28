#include "../include/text_utils.h"

/**
 * Function to print each row of text from a textRows structure.
 * The textRows structure contains multiple rows of strings.
 */
void printStringRow(const struct textRows data) {
    for (int i = 0; i < data.numRows; i++) {
        printf("%s\n", data.text[i]);  // Print each row of the text data
    }
}

/**
 * Global variable to store the user's menu choice.
 * We define it as a character array of size 3 to hold 2 characters and a null terminator.
 */
char choice[INPUT_SIZE] = {'\0', '\0', '\0'};

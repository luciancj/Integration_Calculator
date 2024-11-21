#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

#define INPUT_SIZE 3  // Define maximum input size for user input
#define ANSI_COLOR_GREEN "\x1B[32m"
#define ANSI_COLOR_RESET "\x1B[0m"

#include <stdio.h>
#include <string.h>

struct textRows {
    const char **text;
    int numRows;
};

void printStringRow(struct textRows data);

/**
 * Global variable to store the user's menu choice.
 * Defined as a 3-character array to hold a two-character input (e.g., "rf" for Regula False) and a null terminator.
 */
extern char choice[3];

#endif
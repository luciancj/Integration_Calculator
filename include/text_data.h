#ifndef TEXT_DATA_H
#define TEXT_DATA_H
#include <stdio.h>

#define ANSI_COLOR_GREEN "\x1B[32m"
#define ANSI_COLOR_RESET "\x1B[0m"

struct TextData {
    const char **text;
    int numRows;
};

void printStringRow(const struct TextData data);

#endif
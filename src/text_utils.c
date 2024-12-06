#include "../include/text_utils.h"

void printStringRow(const struct textRows data) {
    for (int i = 0; i < data.numRows; i++) {
        printf("%s\n", data.text[i]);
    }
}

char choice[3] = {'\0', '\0', '\0'};


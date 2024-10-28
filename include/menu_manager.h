#ifndef MENU_CHOICE_H
#define MENU_CHOICE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>  // For size_t
#include "../include/text_utils.h"  // Include textRows for displaying banners and messages
#include "../include/menu_text.h"
#include "../include/integration_text.h" // printIntegrationMethod

void userInterface(void);

void interactiveMenu(void);

void parameterMenu(void);

void handleChoice(const char *option);

#endif

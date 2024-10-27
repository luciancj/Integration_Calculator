#ifndef MENU_CHOICE_H
#define MENU_CHOICE_H

#include <stddef.h>  // For size_t
#include "../include/text_data.h"  // Include TextData for displaying banners and messages

// Function to display the welcome menu and prompt the user to choose between interactive and parameter modes.
void welcomeMenu(void);

// Displays the interactive mode menu where the user can select a numerical method interactively.
void handleInteractiveMenu(void);

// Displays the parameter mode menu where the user can select a numerical method with parameters.
void handleParameterMenu(void);

// Processes the user's input and executes the corresponding action based on the selected option.
void handleChoice(const char *option);

// Global variable to store the user's menu choice.
// Defined as a 3-character array to hold a two-character input (e.g., "rf" for Regula Falsi) and a null terminator.
extern char choice[3];

#endif  // MENU_CHOICE_H

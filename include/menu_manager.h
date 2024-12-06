#ifndef MENU_CHOICE_H
#define MENU_CHOICE_H

// Libraries and Headers used for menu_choice.c
#include "../include/user_input.h" // userInputForParameters, userInputForExpression
#include <stdio.h>
#include <stdlib.h>
#include "../include/text_utils.h" // printStringRow
#include "../include/menu_text.h" // welcomeMenu, parameterModeBanner, interactiveModeBanner
#include "../include/integration_text.h" // printIntegrationBanner

/**
  * Displays the welcome menu and prompts the user for input.
  * It provides options for the user to choose between interactive mode and parameter mode.
  * Handles user input validation and navigation to the appropriate menu.
 */
void userInterface(void);

/**
  * Displays the interactive mode menu and prompts the user to choose a numerical method interactively.
  * Accepts the user's choice, validates it, and processes it using the handleChoice() function.
 */
void interactiveMenu(void);

/**
  * Displays the parameter mode menu and prompts the user to choose a numerical method for parameterized execution.
  * Accepts the user's choice, validates it, and processes it using the handleChoice() function.
 */
void parameterMenu(void);

/**
  * Processes the user's choice from the menu and executes the corresponding numerical method.
  * Based on the user's input, the function displays relevant banners and calls functions
  * to collect parameters and expressions needed for computations.
  * @param option A string representing the user's selected option.
 */
void handleChoice(const char *option);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu_manager.h"  // Include custom header for menu functions
#include "../include/menu_text.h"
#include "../include/integration_text.h"

#define INPUT_SIZE 3  // Define maximum input size for user input

// Function to print each row of text from a TextData structure.
// The TextData structure contains multiple rows of strings.
void printStringRow(struct TextData data) {
    for (int i = 0; i < data.numRows; i++) {
        printf("%s\n", data.text[i]);  // Print each row of the text data
    }
}

// Global variable to store the user's menu choice.
// We define it as a character array of size 3 to hold 2 characters and a null terminator.
char choice[INPUT_SIZE] = {'\0', '\0', '\0'};

// Function to handle the user's choice based on the input passed to it.
// It compares the input (option) and calls corresponding functions.
void handleChoice(const char *option) {
    if (strcmp(option, "rf") == 0) {
        printStringRow(printRegulaFalsi);
        printStringRow(valuesMenu);
    } else if (strcmp(option, "rr") == 0) {
        printStringRow(printRightRiemannSum);
        printStringRow(valuesMenu);
    } else if (strcmp(option, "lr") == 0) {
        printStringRow(printLeftRiemannSum);
        printStringRow(valuesMenu);
    } else if (strcmp(option, "mr") == 0) {
        printStringRow(printMidpointRiemannSum);
        printStringRow(valuesMenu);
    } else if (strcmp(option, "tr") == 0) {
        printStringRow(printTrapezoidalRule);
        printStringRow(valuesMenu);
    } else if (strcmp(option, "sm") == 0) {
        printStringRow(printSecantMethod);
        printStringRow(valuesMenu);
    } else if (strcmp(option, "q") == 0) {
        printStringRow(userMenu);
        printStringRow(valuesMenu);

    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

// Function to display the welcome menu and handle the initial user input.
void welcomeMenu() {
    printStringRow(printIntegrationCalculator);  // Print the integration calculator banner

    printStringRow(userMenu);  // Print the user menu
    printf("Enter your choice: ");  // Prompt the user to enter their choice

    // Use fgets to safely capture user input, preventing buffer overflow
    fgets(choice, INPUT_SIZE, stdin);

    // Remove the trailing newline character if present
    size_t len = strlen(choice);
    if (choice[len - 1] == '\n') {
        choice[len - 1] = '\0';  // Replace newline with null terminator
    }

    // Based on the user's choice, either call the interactive or parameter menu
    if (strcmp(choice, "i") == 0) {
        system("clear");  // Clear the screen
        handleInteractiveMenu();  // Call the interactive menu
    } else if (strcmp(choice, "p") == 0) {
        system("clear");  // Clear the screen
        handleParameterMenu();  // Call the parameter menu
    } else {
        printf("Invalid choice. Please try again.\n");  // Show error message for invalid input
    }
}

// Function to handle the interactive mode menu, where users choose a numerical method interactively.
void handleInteractiveMenu() {
    printStringRow(interactiveMode);  // Print the interactive mode banner
    printf("Enter an option in interactive mode: ");  // Prompt user to enter an option

    // Use fgets to safely capture the user input
    fgets(choice, INPUT_SIZE, stdin);

    // Remove the trailing newline character if present
    size_t len = strlen(choice);
    if (choice[len - 1] == '\n') {
        choice[len - 1] = '\0';  // Replace newline with null terminator
    }

    system("clear");  // Clear the screen
    handleChoice(choice);  // Call handleChoice to process the user's input
}

// Function to handle the parameter mode menu, similar to the interactive menu,
// but handles inputs in a different mode.
void handleParameterMenu() {
    printStringRow(parameterMode);  // Print the parameter mode banner
    printf("Enter an option in parameter mode: ");  // Prompt user to enter an option

    // Use fgets to safely capture the user input
    fgets(choice, INPUT_SIZE, stdin);

    // Remove the trailing newline character if present
    size_t len = strlen(choice);
    if (choice[len - 1] == '\n') {
        choice[len - 1] = '\0';  // Replace newline with null terminator
    }

    system("clear");  // Clear the screen
    handleChoice(choice);  // Call handleChoice to process the user's input
}

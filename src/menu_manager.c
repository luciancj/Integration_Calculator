#include "../include/menu_manager.h"

/**
 * Function to handle the user's choice based on the input passed to it.
 * It compares the input (option) and calls corresponding functions.
 */
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
        printStringRow(welcomeMenu);
        printStringRow(valuesMenu);

    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

/**
 * Function to display the welcome menu and handle the initial user input.
 */
void userInterface() {
    printStringRow(printIntegrationBanner);

    printStringRow(welcomeMenu);
    printf("Enter your choice: ");

    fgets(choice, INPUT_SIZE, stdin); // Function to display the welcome menu and handle the initial user input.

    size_t len = strlen(choice); // Remove the trailing newline character if present
    if (choice[len - 1] == '\n') {
        choice[len - 1] = '\0';  // Replace newline with null terminator
    }

    /**
     * Based on the user's choice, either call the interactive or parameter menu
     */
    if (strcmp(choice, "i") == 0) {
        system("clear");
        interactiveMenu();  // Call the interactive menu
    } else if (strcmp(choice, "p") == 0) {
        system("clear");
        parameterMenu();  // Call the parameter menu
    } else {
        printf("Invalid choice. Please try again.\n");  // Show error message for invalid input
    }
}

// TODO Try to optimize the code since interactiveMenu() and parameterMenu() share most parts of the code
/**
 * Function to handle the interactive mode menu, where users choose a numerical method interactively.
 */
void interactiveMenu() {
    printStringRow(interactiveModeBanner);
    printf("Enter an option in interactive mode: ");

    fgets(choice, INPUT_SIZE, stdin);

    size_t len = strlen(choice);
    if (choice[len - 1] == '\n') {
        choice[len - 1] = '\0';
    }

    system("clear");
    handleChoice(choice);  // Call handleChoice to process the user's input
}

/**
 * Function to handle the parameter mode menu, similar to the interactive menu, but handles inputs in a different mode.
 */
void parameterMenu() {
    printStringRow(parameterModeBanner);
    printf("Enter an option in parameter mode: ");

    fgets(choice, INPUT_SIZE, stdin);

    size_t len = strlen(choice);
    if (choice[len - 1] == '\n') {
        choice[len - 1] = '\0';
    }

    system("clear");
    handleChoice(choice);
}

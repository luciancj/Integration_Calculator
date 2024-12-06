#include "../include/menu_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Optimize handleChoice(), printStringRow() is repetitive, grouping all the commands for printing the banners could be a solution

void handleChoice(const char *option) {
    if (option == NULL) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    if (strcmp(option, "rf") == 0) {
        printStringRow(bannerRegulaFalsi);
        userInputForParameters();
        userInputForExpression();
    } else if (strcmp(option, "rr") == 0) {
        printStringRow(bannerRightRiemannSum);
        userInputForParameters();
        userInputForExpression();
    } else if (strcmp(option, "lr") == 0) {
        printStringRow(bannerLeftRiemannSum);
        userInputForParameters();
        userInputForExpression();
    } else if (strcmp(option, "mr") == 0) {
        printStringRow(bannerMidpointRiemannSum);
        userInputForParameters();
        userInputForExpression();
    } else if (strcmp(option, "tr") == 0) {
        printStringRow(bannerTrapezoidalRule);
        userInputForParameters();
        userInputForExpression();
    } else if (strcmp(option, "sm") == 0) {
        printStringRow(bannerSecantMethod);
        userInputForParameters();
        userInputForExpression();
    } else if (strcmp(option, "q") == 0) {
        printStringRow(welcomeMenu);
        userInputForExpression();
        userInputForExpression();
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

void userInterface() {
    printStringRow(printIntegrationBanner);
    printStringRow(welcomeMenu);

    printf("Enter your choice: ");
    fgets(choice, INPUT_SIZE, stdin);

    size_t len = strlen(choice);
    if (choice[len - 1] == '\n') {
        choice[len - 1] = '\0';
    }

    if (strcmp(choice, "i") == 0) {
        system("clear");
        interactiveMenu();
    } else if (strcmp(choice, "p") == 0) {
        system("clear");
        parameterMenu();
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

// TODO: Optimize shared logic between interactiveMenu() and parameterMenu()

void interactiveMenu() {
    fflush(stdin);
    printStringRow(interactiveModeBanner);
    printf("Enter an option in interactive mode: ");

    fgets(choice, INPUT_SIZE, stdin);

    size_t len = strlen(choice);
    if (choice[len - 1] == '\n') {
        choice[len - 1] = '\0';
    }

    system("clear");
    handleChoice(choice);
}

// TODO: Include askFileNameBanner() function
void parameterMenu() {
    fflush(stdin);
    printStringRow(parameterModeBanner);
    printf("Enter an option in parameter mode: ");
    fgets(choice, INPUT_SIZE, stdin);
    printf("\n");
    printStringRow(askFileNameBanner);

    size_t len = strlen(choice);
    if (choice[len - 1] == '\n') {
        choice[len - 1] = '\0';
    }

    // After askFileNameBanner: Read from "input.csv" and write to "output.txt"
    char fileName[256] = "../input.csv";
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return;
    }

    char line[256];
    printf("Contents of the CSV file:\n");
    while (fgets(line, sizeof(line), file)) {
        char function[128];
        double a, b;

        // Assuming the CSV file has columns: function, a, b
        if (sscanf(line, "%127[^,],%lf,%lf", function, &a, &b) == 3) {
            printf("Function: %s, a: %lf, b: %lf\n", function, a, b);
        } else {
            printf("Error: Incorrectly formatted line in CSV: %s\n", line);
        }
    }
    fclose(file);

    // Create an output file "output.txt" and write success message
    FILE *outputFile = fopen("../output.txt", "w");
    if (outputFile != NULL) {
        fprintf(outputFile, "File successfully read\n");
        fclose(outputFile);
    } else {
        printf("Error: Could not create output.txt\n");
    }

    handleChoice(choice);
}

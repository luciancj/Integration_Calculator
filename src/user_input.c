#include "../include/user_input.h"

// Declare the external variables
double inputA, inputB, inputTol;
int inputN;

// Function to get user input for interval bounds, tolerance, and number of sub-intervals from the menu manager
void userInputForParameters() {
    char input[256];
    char *endptr;

    printf("\nEnter the necessary inputs for the operation:\n");

    // Get starting point of the interval (a)
    printf("Enter the starting point of the interval (a): ");
    fgets(input, sizeof(input), stdin);
    inputA = strtod(input, &endptr);
    if (endptr == input || *endptr != '\n') {
        printf("Error: Invalid input for interval start. Please enter a valid number.\n");
        exit(EXIT_FAILURE);
    }

    // Get ending point of the interval (b)
    printf("Enter the ending point of the interval (b): ");
    fgets(input, sizeof(input), stdin);
    inputB = strtod(input, &endptr);
    if (endptr == input || *endptr != '\n') {
        printf("Error: Invalid input for interval end. Please enter a valid number.\n");
        exit(EXIT_FAILURE);
    }

    // Get tolerance level
    printf("Enter the tolerance level (e.g., 0.0001): ");
    fgets(input, sizeof(input), stdin);
    inputTol = strtod(input, &endptr);
    if (endptr == input || *endptr != '\n') {
        printf("Error: Invalid input for tolerance. Please enter a valid number.\n");
        exit(EXIT_FAILURE);
    }

    // Get number of sub-intervals (n)
    printf("Enter the number of sub-intervals for Riemann sums (n): ");
    fgets(input, sizeof(input), stdin);
    const long n = strtol(input, &endptr, 10);
    if (endptr == input || *endptr != '\n' || n < INT_MIN || n > INT_MAX) {
        printf("Error: Invalid input for number of sub-intervals. Please enter a valid integer.\n");
        exit(EXIT_FAILURE);
    }
    inputN = (int)n;  // Safe to cast after range check
}

// Function to get the user input, parse the function, and evaluate it for a given x
void userInputForExpression() {
    // Step 1: Clear the buffer from any remaining characters
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    // Step 2: Get the function from the user
    char input[256];
    char *endptr;
    printf("Enter a function to evaluate (use 'x' as the variable, e.g., 'sin(x) + 2*x'): ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    // Check if the input is empty
    if (len == 0) {
        printf("Error: No input provided. Please enter a valid function.\n");
        return; // Early return, no further processing
    }

    // Step 3: Parse the function into a parse tree
    char *expr = input;  // Point to the input string
    Node* root = parseExpression(&expr);

    if (root == NULL) {
        printf("Error parsing the function. Please check your input.\n");
        return; // Early return, no further processing
    }

    // Step 4: Get the value of 'x' from the user
    printf("Enter the value of x to evaluate the function: ");
    fgets(input, sizeof(input), stdin);
    double x = strtod(input, &endptr);
    if (endptr == input || *endptr != '\n') {
        printf("Error: Invalid input for x. Please enter a valid number.\n");
        freeNode(root);
        return; // Early return, no further processing
    }

    // Step 5: Evaluate the parsed function
    double result = evaluate(root, x);
    printf("The result of the function at x = %lf is: %lf\n", x, result);

    // Step 6: Clean up memory
    freeNode(root);  // Ensure all allocated memory is freed
}

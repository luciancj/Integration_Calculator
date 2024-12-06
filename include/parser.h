#ifndef PARSER_H
#define PARSER_H

#define NUMBER 1
#define VARIABLE 2
#define OPERATOR 3
#define FUNCTION 4

// Necessary libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Define the Node structure
typedef struct Node {
    int type; // Node type: NUMBER, VARIABLE, OPERATOR, FUNCTION, etc.
    union {
        double number;        // For number nodes
        char variable;        // For variable nodes (e.g., 'x')
        char operator;        // For operator nodes (e.g., '+', '*')
        char function[16];    // For function nodes (e.g., "sin", "log")
    } data;
    struct Node *left;        // Left child
    struct Node *right;       // Right child
} Node;

/**
 * Creates a new node representing a numeric value.
 * Allocates memory for the node and initializes it with the given number.
 * @param number The numeric value to store in the node.
 * @return A pointer to the newly created number node.
 */
Node* newNumberNode(double number);

/**
 * Creates a new node representing a variable.
 * Allocates memory for the node and initializes it with the given variable.
 * @param variable The variable name (e.g., 'x').
 * @return A pointer to the newly created variable node.
 */
Node* newVariableNode(char variable);

/**
 * Creates a new node representing an operator.
 * Allocates memory for the node, assigns the operator, and sets left and right children.
 * @param operator The operator symbol (e.g., '+', '*').
 * @param left A pointer to the left operand node.
 * @param right A pointer to the right operand node.
 * @return A pointer to the newly created operator node.
 */
Node* newOperatorNode(char operator, Node* left, Node* right);

/**
 * Creates a new node representing a function.
 * Allocates memory for the node, assigns the function name, and sets the child node.
 * @param function The function name (e.g., "sin", "cos").
 * @param child A pointer to the child node (the argument of the function).
 * @return A pointer to the newly created function node.
 */
Node* newFunctionNode(const char* function, Node* child);

/**
 * Evaluates the expression represented by the parse tree rooted at the given node.
 * Recursively evaluates the parse tree based on the node type.
 * @param node The root of the parse tree to evaluate.
 * @param x The value of the variable (used if the expression contains a variable).
 * @return The result of the evaluated expression.
 */
double evaluate(const Node* node, double x);

/**
 * Parses an expression, which can include addition and subtraction operations.
 * @param expr A pointer to the expression string (to be updated as it is parsed).
 * @return A pointer to the newly created node representing the expression.
 */
Node* parseExpression(char** expr);

/**
 * Skips over whitespace characters in the expression string.
 * Advances the pointer until a non-whitespace character is found.
 * @param expr A pointer to the expression string (to be updated as it is parsed).
 */
void skipWhitespace(char** expr);

/**
 * Frees the memory allocated for the parse tree rooted at the given node.
 * Recursively frees left and right children before freeing the node itself.
 * @param node The root of the parse tree to free.
 */
void freeNode(Node* node);

/**
 * Parses a numeric value from the expression and creates a corresponding number node.
 * Advances the pointer in the expression to the end of the parsed number.
 * @param expr A pointer to the expression string (to be updated as it is parsed).
 * @return A pointer to the newly created number node.
 */
Node* parseNumber(char** expr);

/**
 * Parses a variable from the expression and creates a corresponding variable node.
 * Currently, supports only the variable 'x'.
 * @param expr A pointer to the expression string (to be updated as it is parsed).
 * @return A pointer to the newly created variable node.
 */
Node* parseVariable(char** expr);

/**
 * Parses a function from the expression and creates a corresponding function node.
 * Advances the pointer to parse the function argument within parentheses.
 * @param expr A pointer to the expression string (to be updated as it is parsed).
 * @return A pointer to the newly created function node.
 */
Node* parseFunction(char** expr);

/**
 * Parses an expression within parentheses and creates a corresponding node.
 * Advances the pointer to the end of the parentheses.
 * @param expr A pointer to the expression string (to be updated as it is parsed).
 * @return A pointer to the node representing the expression within parentheses.
 */
Node* parseParentheses(char** expr);

/**
 * Parses a factor from the expression, which could be a number, variable, function, or sub-expression.
 * @param expr A pointer to the expression string (to be updated as it is parsed).
 * @return A pointer to the newly created node representing the factor.
 */
Node* parseFactor(char** expr);

/**
 * Parses an exponentiation operation from the expression.
 * Supports right-associative exponentiation with the '^' operator.
 * @param expr A pointer to the expression string (to be updated as it is parsed).
 * @return A pointer to the newly created node representing the exponentiation.
 */
Node* parseExponent(char** expr);

/**
 * Parses a term from the expression, which can include multiplication and division operations.
 * @param expr A pointer to the expression string (to be updated as it is parsed).
 * @return A pointer to the newly created node representing the term.
 */
Node* parseTerm(char** expr);

#endif // PARSER_H

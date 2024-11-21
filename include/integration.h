/*
#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Original code with expression parsing and evaluation
#include "../include/parser.h" // Assume the original code is in "evaluating_expression.h"

// Function Prototypes for Integration Methods
double regulaFalsi(Node* root, double a, double b, double tol);
double rightRiemannSum(Node* root, double a, double b, int n);
double leftRiemannSum(Node* root, double a, double b, int n);
double midpointRiemannSum(Node* root, double a, double b, int n);
double trapezoidalRule(Node* root, double a, double b, int n);
double secantMethod(Node* root, double x0, double x1, double tol);

// Function to evaluate a Node for a specific x value (originally from expression parser)
extern double evaluate(Node *node, double x);
extern Node* parseExpression(char** expr);

#endif // INTEGRATION_H
*/

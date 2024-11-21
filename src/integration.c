/*
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

// Regula Falsi Method
double regulaFalsi(Node* root, double a, double b, double tol) {
    double fa = evaluate(root, a);
    double fb = evaluate(root, b);
    if (fa * fb >= 0) {
        printf("Error: f(a) and f(b) must have opposite signs.\n");
        return NAN;
    }

    double c;
    while (fabs(b - a) > tol) {
        c = (a * fb - b * fa) / (fb - fa);
        double fc = evaluate(root, c);

        if (fabs(fc) < tol) {
            return c;
        } else if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
    return c;
}

// Right Riemann Sum
double rightRiemannSum(Node* root, double a, double b, int n) {
    double deltaX = (b - a) / n;
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double x = a + i * deltaX;
        sum += evaluate(root, x);
    }
    return sum * deltaX;
}

// Left Riemann Sum
double leftRiemannSum(Node* root, double a, double b, int n) {
    double deltaX = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + i * deltaX;
        sum += evaluate(root, x);
    }
    return sum * deltaX;
}

// Midpoint Riemann Sum
double midpointRiemannSum(Node* root, double a, double b, int n) {
    double deltaX = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * deltaX;
        sum += evaluate(root, x);
    }
    return sum * deltaX;
}

// Trapezoidal Rule
double trapezoidalRule(Node* root, double a, double b, int n) {
    double deltaX = (b - a) / n;
    double sum = (evaluate(root, a) + evaluate(root, b)) / 2.0;
    for (int i = 1; i < n; i++) {
        double x = a + i * deltaX;
        sum += evaluate(root, x);
    }
    return sum * deltaX;
}

// Secant Method
double secantMethod(Node* root, double x0, double x1, double tol) {
    double f0 = evaluate(root, x0);
    double f1 = evaluate(root, x1);
    while (fabs(x1 - x0) > tol) {
        if (fabs(f1 - f0) < 1e-12) {
            printf("Error: Division by nearly zero in secant method.\n");
            return NAN;
        }
        double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = evaluate(root, x1);
    }
    return x1;
}
*/

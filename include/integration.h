#ifndef INTEGRATION_H
#define INTEGRATION_H


#include "../include/parser.h"
#include <math.h>
#include <stdio.h>

/**
 * Implements the Regula Falsi (False Position) method to find a root of the equation represented by the parse tree.
 * @param root The root of the parse tree representing the function.
 * @param a The starting point of the interval.
 * @param b The ending point of the interval.
 * @param tol The tolerance level for root estimation.
 * @return The estimated root within the given tolerance.
 */
double regulaFalsi(const Node* root, double a, double b, double tol);

/**
 * Calculates the Right Riemann Sum for the function represented by the parse tree.
 * @param root The root of the parse tree representing the function.
 * @param a The starting point of the interval.
 * @param b The ending point of the interval.
 * @param n The number of subintervals.
 * @return The approximate integral of the function over the interval [a, b].
 */
double rightRiemannSum(const Node* root, double a, double b, int n);

/**
 * Calculates the Left Riemann Sum for the function represented by the parse tree.
 * @param root The root of the parse tree representing the function.
 * @param a The starting point of the interval.
 * @param b The ending point of the interval.
 * @param n The number of subintervals.
 * @return The approximate integral of the function over the interval [a, b].
 */
double leftRiemannSum(const Node* root, double a, double b, int n);

/**
 * Calculates the Midpoint Riemann Sum for the function represented by the parse tree.
 * @param root The root of the parse tree representing the function.
 * @param a The starting point of the interval.
 * @param b The ending point of the interval.
 * @param n The number of subintervals.
 * @return The approximate integral of the function over the interval [a, b].
 */
double midpointRiemannSum(const Node* root, double a, double b, int n);

/**
 * Calculates the Trapezoidal Rule for the function represented by the parse tree.
 * @param root The root of the parse tree representing the function.
 * @param a The starting point of the interval.
 * @param b The ending point of the interval.
 * @param n The number of subintervals.
 * @return The approximate integral of the function over the interval [a, b].
 */
double trapezoidalRule(const Node* root, double a, double b, int n);

/**
 * Implements the Secant Method to find a root of the equation represented by the parse tree.
 * @param root The root of the parse tree representing the function.
 * @param a The first initial guess.
 * @param b The second initial guess.
 * @param tol The tolerance level for root estimation.
 * @return The estimated root within the given tolerance.
 */
double secantMethod(const Node* root, double a, double b, double tol);

#endif

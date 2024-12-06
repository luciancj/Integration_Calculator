#include "../include/integration.h"

double regulaFalsi(const Node* root, double a, double b, double tol) {
    double fa = evaluate(root, a);
    double fb = evaluate(root, b);

    if (fa * fb >= 0) {
        fprintf(stderr, "Error: f(a) and f(b) must have opposite signs.\n");
        return NAN;
    }

    double c = 0;

    while (fabs(b - a) > tol) {
        c = (a * fb - b * fa) / (fb - fa);
        double fc = evaluate(root, c);

        if (fabs(fc) < tol) {
            return c;
        }
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    return c;
}

double rightRiemannSum(const Node* root, double a, double b, int n) {
    double deltaX = (b - a) / n;
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double x = a + i * deltaX;
        sum += evaluate(root, x);
    }
    return sum * deltaX;
}

double leftRiemannSum(const Node* root, double a, double b, int n) {
    double deltaX = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + i * deltaX;
        sum += evaluate(root, x);
    }
    return sum * deltaX;
}

double midpointRiemannSum(const Node* root, double a, double b, int n) {
    double deltaX = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * deltaX;
        sum += evaluate(root, x);
    }
    return sum * deltaX;
}

double trapezoidalRule(const Node* root, double a, double b, int n) {
    double deltaX = (b - a) / n;
    double sum = (evaluate(root, a) + evaluate(root, b)) / 2.0;
    for (int i = 1; i < n; i++) {
        double x = a + i * deltaX;
        sum += evaluate(root, x);
    }
    return sum * deltaX;
}

double secantMethod(const Node* root, double a, double b, double tol) {
    double f0 = evaluate(root, a);
    double f1 = evaluate(root, b);
    while (fabs(b - a) > tol) {
        if (fabs(f1 - f0) < 1e-12) {
            fprintf(stderr, "Error: Division by nearly zero in secant method.\n");
            return NAN;
        }
        double x2 = b - f1 * (b - a) / (f1 - f0);
        a = b;
        f0 = f1;
        b = x2;
        f1 = evaluate(root, b);
    }
    return b;
}

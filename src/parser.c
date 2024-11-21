/*
#include "../include/parser.h"

// Function Prototypes
Node* newNumberNode(double number);
Node* newVariableNode(char variable);
Node* newOperatorNode(char operator, Node* left, Node* right);
Node* newFunctionNode(char* function, Node* child);
double evaluate(Node *node, double x);
Node* parseExpression(char** expr);
Node* parseFactor(char** expr);
Node* parseTerm(char** expr);
Node* parseExponent(char** expr);
Node* parseFunction(char** expr);
void skipWhitespace(char** expr);

// Function to create a new node for a number
Node* newNumberNode(double number) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation error for number node.\n");
        exit(1);
    }
    node->type = NUMBER;
    node->data.number = number;
    node->left = node->right = NULL;
    return node;
}

// Function to create a new node for a variable
Node* newVariableNode(char variable) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation error for variable node.\n");
        exit(1);
    }
    node->type = VARIABLE;
    node->data.variable = variable;
    node->left = node->right = NULL;
    return node;
}

// Function to create a new node for an operator
Node* newOperatorNode(char operator, Node* left, Node* right) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation error for operator node.\n");
        exit(1);
    }
    node->type = OPERATOR;
    node->data.operator = operator;
    node->left = left;
    node->right = right;
    return node;
}

// Function to create a new node for a function like sin, cos, etc.
Node* newFunctionNode(char* function, Node* child) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation error for function node.\n");
        exit(1);
    }
    node->type = FUNCTION;
    strcpy(node->data.function, function);
    node->left = child;
    node->right = NULL;
    return node;
}

// Function to skip whitespace
void skipWhitespace(char** expr) {
    while (**expr == ' ' || **expr == '\t') {
        (*expr)++;
    }
}

// Recursive function to evaluate the expression tree
double evaluate(Node *node, double x) {
    if (node == NULL) {
        printf("Error: Null node encountered during evaluation.\n");
        exit(1);
    }
    if (node->type == NUMBER) {
        return node->data.number;
    }
    if (node->type == VARIABLE) {
        return x; // Substitute x with the given value
    }
    if (node->type == OPERATOR) {
        double leftVal = evaluate(node->left, x);
        double rightVal = evaluate(node->right, x);
        switch (node->data.operator) {
            case '+': return leftVal + rightVal;
            case '-': return leftVal - rightVal;
            case '*': return leftVal * rightVal;
            case '/': return rightVal != 0 ? leftVal / rightVal : 0;
            case '^': return pow(leftVal, rightVal); // For exponents
        }
    }
    if (node->type == FUNCTION) {
        double childVal = evaluate(node->left, x);
        if (strcmp(node->data.function, "sin") == 0) return sin(childVal);
        if (strcmp(node->data.function, "cos") == 0) return cos(childVal);
        if (strcmp(node->data.function, "tan") == 0) return tan(childVal);
        if (strcmp(node->data.function, "log") == 0) return childVal > 0 ? log(childVal) : 0;
    }
    return 0; // Error case
}

// Function to parse a number (handles 'e' as Euler's Number)
Node* parseNumber(char** expr) {
    skipWhitespace(expr);
    if (**expr == 'e') {
        (*expr)++; // Move past 'e'
        return newNumberNode(M_E); // Euler's number
    } else {
        char* end;
        double number = strtod(*expr, &end);
        *expr = end; // Move the pointer to the end of the number
        return newNumberNode(number);
    }
}

// Function to parse a variable (assumes only 'x' as variable)
Node* parseVariable(char** expr) {
    skipWhitespace(expr);
    (*expr)++; // Move past 'x'
    return newVariableNode('x');
}

// Function to parse a function like sin, cos, etc.
Node* parseFunction(char** expr) {
    skipWhitespace(expr);
    char func[10];
    int i = 0;

    // Extract the function name (e.g., "sin", "cos")
    while (isalpha(**expr)) {
        func[i++] = *(*expr)++;
    }
    func[i] = '\0'; // Null-terminate function name

    if (**expr != '(') {
        printf("Error: Missing '(' after function name '%s'.\n", func);
        exit(1);
    }

    (*expr)++; // Skip the opening '('
    skipWhitespace(expr);

    Node* child = parseExpression(expr);

    if (**expr != ')') {
        printf("Error: Missing ')' after function argument for '%s'.\n", func);
        exit(1);
    }

    (*expr)++; // Skip the closing ')'
    return newFunctionNode(func, child);
}

// Function to parse parentheses (handles nested expressions)
Node* parseParentheses(char** expr) {
    skipWhitespace(expr);
    if (**expr != '(') {
        printf("Error: Expected '(' at the beginning of parentheses.\n");
        exit(1);
    }
    (*expr)++; // Skip '('
    skipWhitespace(expr);
    Node* node = parseExpression(expr);
    if (**expr != ')') {
        printf("Error: Missing ')' at the end of parentheses.\n");
        exit(1);
    }
    (*expr)++; // Skip ')'
    return node;
}

// Function to parse factors (numbers, variables, functions, or nested expressions)
Node* parseFactor(char** expr) {
    skipWhitespace(expr);
    if (isdigit(**expr) || **expr == 'e') {
        return parseNumber(expr);
    } else if (**expr == 'x') {
        return parseVariable(expr);
    } else if (isalpha(**expr)) {
        return parseFunction(expr);
    } else if (**expr == '(') {
        return parseParentheses(expr);
    } else if (**expr == '-') {
        (*expr)++; // Skip '-'
        return newOperatorNode('*', newNumberNode(-1), parseFactor(expr));
    }
    printf("Error: Unexpected character '%c' in expression.\n", **expr);
    exit(1);
}

// Function to parse exponents (handles '^' operator with right associativity)
Node* parseExponent(char** expr) {
    skipWhitespace(expr);
    Node* left = parseFactor(expr);
    while (1) {
        skipWhitespace(expr);
        if (**expr == '^') {
            char op = *(*expr)++;
            Node* right = parseExponent(expr); // Recursive call for right-associativity
            left = newOperatorNode(op, left, right);
        } else {
            break;
        }
    }
    return left;
}

// Function to parse terms (factors combined by '*' or '/')
Node* parseTerm(char** expr) {
    skipWhitespace(expr);
    Node* left = parseExponent(expr);
    while (1) {
        skipWhitespace(expr);
        if (**expr == '*' || **expr == '/') {
            char op = *(*expr)++;
            Node* right = parseExponent(expr);
            left = newOperatorNode(op, left, right);
        } else {
            break;
        }
    }
    return left;
}

// Function to parse expressions (terms combined by '+' or '-')
Node* parseExpression(char** expr) {
    skipWhitespace(expr);
    Node* left = parseTerm(expr);
    while (1) {
        skipWhitespace(expr);
        if (**expr == '+' || **expr == '-') {
            char op = *(*expr)++;
            Node* right = parseTerm(expr);
            left = newOperatorNode(op, left, right);
        } else {
            break;
        }
    }
    return left;
}
*/

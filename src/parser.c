#include "../include/parser.h"

void freeNode(Node* node) {
    if (node == NULL) {
        return;
    }

    freeNode(node->left);
    freeNode(node->right);
    free(node);
}

Node* newNumberNode(double number) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Memory allocation error for number node.\n");
        exit(EXIT_FAILURE);
    }
    node->type = NUMBER;
    node->data.number = number;
    node->left = node->right = NULL;
    return node;
}

Node* newVariableNode(char variable) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Memory allocation error for variable node.\n");
        exit(EXIT_FAILURE);
    }
    node->type = VARIABLE;
    node->data.variable = variable;
    node->left = node->right = NULL;
    return node;
}

Node* newOperatorNode(char operator, Node* left, Node* right) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Memory allocation error for operator node.\n");
        exit(EXIT_FAILURE);
    }
    node->type = OPERATOR;
    node->data.operator = operator;
    node->left = left;
    node->right = right;
    return node;
}

Node* newFunctionNode(const char* function, Node* child) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Memory allocation error for function node.\n");
        exit(EXIT_FAILURE);
    }
    node->type = FUNCTION;
    strncpy(node->data.function, function, sizeof(node->data.function) - 1);
    node->data.function[sizeof(node->data.function) - 1] = '\0';
    node->left = child;
    node->right = NULL;
    return node;
}

void skipWhitespace(char** expr) {
    while (**expr == ' ' || **expr == '\t') {
        (*expr)++;
    }
}

double evaluate(const Node *node, double x) {
    if (node == NULL) {
        fprintf(stderr, "Error: Null node encountered during evaluation.\n");
        exit(EXIT_FAILURE);
    }

    switch (node->type) {
        case NUMBER:
            return node->data.number;
        case VARIABLE:
            return x;
        case OPERATOR: {
            double leftVal = evaluate(node->left, x);
            double rightVal = evaluate(node->right, x);
            switch (node->data.operator) {
                case '+': return leftVal + rightVal;
                case '-': return leftVal - rightVal;
                case '*': return leftVal * rightVal;
                case '/':
                    if (rightVal != 0)
                        return leftVal / rightVal;
                    else {
                        fprintf(stderr, "Error: Division by zero.\n");
                        exit(EXIT_FAILURE);
                    }
                case '^': return pow(leftVal, rightVal);
                default:
                    fprintf(stderr, "Error: Unknown operator '%c'.\n", node->data.operator);
                    exit(EXIT_FAILURE);
            }
        }
        case FUNCTION: {
            double childVal = evaluate(node->left, x);
            if (strcmp(node->data.function, "sin") == 0) return sin(childVal);
            if (strcmp(node->data.function, "cos") == 0) return cos(childVal);
            if (strcmp(node->data.function, "tan") == 0) return tan(childVal);
            if (strcmp(node->data.function, "log") == 0) {
                if (childVal > 0)
                    return log(childVal);
                else {
                    fprintf(stderr, "Error: Logarithm of a non-positive number.\n");
                    exit(EXIT_FAILURE);
                }
            }
            fprintf(stderr, "Error: Unknown function '%s'.\n", node->data.function);
            exit(EXIT_FAILURE);
        }
        default:
            fprintf(stderr, "Error: Unknown node type '%d'.\n", node->type);
            exit(EXIT_FAILURE);
    }
}

Node* parseNumber(char** expr) {
    skipWhitespace(expr);
    if (**expr == 'e') {
        (*expr)++;
        return newNumberNode(M_E);
    }
    char* end;
    double number = strtod(*expr, &end);
    if (*expr == end) {
        fprintf(stderr, "Error: Invalid number format.\n");
        exit(EXIT_FAILURE);
    }
    *expr = end;
    return newNumberNode(number);
}

Node* parseVariable(char** expr) {
    skipWhitespace(expr);
    if (**expr == 'x') {
        (*expr)++;
        return newVariableNode('x');
    }
    fprintf(stderr, "Error: Unknown variable.\n");
    exit(EXIT_FAILURE);
}

Node* parseFunction(char** expr) {
    skipWhitespace(expr);
    char func[16] = {0};
    int i = 0;

    while (isalpha(**expr) && i < sizeof(func) - 1) {
        func[i++] = *(*expr)++;
    }
    func[i] = '\0';

    if (**expr != '(') {
        fprintf(stderr, "Error: Missing '(' after function name '%s'.\n", func);
        exit(EXIT_FAILURE);
    }

    (*expr)++;
    skipWhitespace(expr);

    Node* child = parseExpression(expr);

    if (**expr != ')') {
        fprintf(stderr, "Error: Missing ')' after function argument for '%s'.\n", func);
        exit(EXIT_FAILURE);
    }
    (*expr)++;
    return newFunctionNode(func, child);
}

Node* parseParentheses(char** expr) {
    skipWhitespace(expr);
    if (**expr != '(') {
        fprintf(stderr, "Error: Expected '(' at the beginning of parentheses.\n");
        exit(EXIT_FAILURE);
    }
    (*expr)++;
    Node* node = parseExpression(expr);
    if (**expr != ')') {
        fprintf(stderr, "Error: Missing ')' at the end of parentheses.\n");
        exit(EXIT_FAILURE);
    }
    (*expr)++;
    return node;
}

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
        (*expr)++;
        return newOperatorNode('*', newNumberNode(-1), parseFactor(expr));
    }
    fprintf(stderr, "Error: Unexpected character '%c' in expression.\n", **expr);
    exit(EXIT_FAILURE);
}

Node* parseExponent(char** expr) {
    Node* left = parseFactor(expr);
    while (**expr == '^') {
        char op = *(*expr)++;
        Node* right = parseExponent(expr);
        left = newOperatorNode(op, left, right);
    }
    return left;
}

Node* parseTerm(char** expr) {
    Node* left = parseExponent(expr);
    while (**expr == '*' || **expr == '/') {
        char op = *(*expr)++;
        Node* right = parseExponent(expr);
        left = newOperatorNode(op, left, right);
    }
    return left;
}

Node* parseExpression(char** expr) {
    Node* left = parseTerm(expr);
    while (**expr == '+' || **expr == '-') {
        char op = *(*expr)++;
        Node* right = parseTerm(expr);
        left = newOperatorNode(op, left, right);
    }
    return left;
}
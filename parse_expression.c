#include <stdio.h>
#include <stdlib.h>

typedef enum { NODE_BINARY_OP, NODE_NUMBER, NODE_IDENTIFIER } NodeType;

typedef struct Node {
    NodeType type;
    union {
        struct { struct Node *left; char op; struct Node *right; } binary;
        int number;
        char *identifier;
    };
} Node;

// توابع پیش‌نیاز
Node *parse_expression();
Node *parse_term();
Node *parse_factor();
void print_ast(Node *node);

Node *parse_expression() {
    Node *left = parse_term();
    while (current_token == '+' || current_token == '-') {
        char op = current_token;
        next_token(); // حرکت به توکن بعدی
        Node *right = parse_term();
        Node *node = malloc(sizeof(Node));
        node->type = NODE_BINARY_OP;
        node->binary.left = left;
        node->binary.op = op;
        node->binary.right = right;
        left = node;
    }
    return left;
}

Node *parse_term() {
    Node *left = parse_factor();
    while (current_token == '*' || current_token == '/') {
        char op = current_token;
        next_token();
        Node *right = parse_factor();
        Node *node = malloc(sizeof(Node));
        node->type = NODE_BINARY_OP;
        node->binary.left = left;
        node->binary.op = op;
        node->binary.right = right;
        left = node;
    }
    return left;
}

Node *parse_factor() {
    if (current_token == '(') {
        next_token();
        Node *node = parse_expression();
        expect(')'); // چک کردن بسته شدن پرانتز
        return node;
    } else if (is_number(current_token)) {
        Node *node = malloc(sizeof(Node));
        node->type = NODE_NUMBER;
        node->number = atoi(current_token);
        next_token();
        return node;
    }
    return NULL; // خطا
}
Node *parse_expression() {
    Node *left = parse_term();
    
    // بررسی اگر متغیری مقداردهی شده باشد (x = ...)
    if (current_token == '=') {
        if (left->type != NODE_IDENTIFIER) {
            printf("Error: Left side of assignment must be a variable!\n");
            exit(1);
        }
        next_token();
        Node *right = parse_expression();
        
        Node *node = malloc(sizeof(Node));
        node->type = NODE_ASSIGNMENT;
        node->assignment.var_name = left->identifier;
        node->assignment.value = right;
        return node;
    }

    while (current_token == '+' || current_token == '-') {
        char op = current_token;
        next_token();
        Node *right = parse_term();
        Node *node = malloc(sizeof(Node));
        node->type = NODE_BINARY_OP;
        node->binary.left = left;
        node->binary.op = op;
        node->binary.right = right;
        left = node;
    }
    return left;
}
Node *parse_statement() {
    if (current_token == TOKEN_IF) {
        next_token(); // رد کردن `if`
        Node *condition = parse_expression();
        expect('{');
        Node *body = parse_block();
        expect('}');

        Node *node = malloc(sizeof(Node));
        node->type = NODE_IF;
        node->if_stmt.condition = condition;
        node->if_stmt.body = body;
        return node;
    } 
    else if (current_token == TOKEN_WHILE) {
        next_token(); // رد کردن `while`
        Node *condition = parse_expression();
        expect('{');
        Node *body = parse_block();
        expect('}');

        Node *node = malloc(sizeof(Node));
        node->type = NODE_WHILE;
        node->while_stmt.condition = condition;
        node->while_stmt.body = body;
        return node;
    }
    return parse_expression();
}
void parse_function() {
    expect(TOKEN_FUNC);
    char name[32];
    expect_identifier(name);

    Function *func = &functions[function_count++];
    strcpy(func->name, name);

    expect('(');
    func->param_count = 0;
    while (current_token == TOKEN_IDENTIFIER) {
        strcpy(func->params[func->param_count++], token_value);
        next_token();
        if (current_token == ',') next_token();
    }
    expect(')');

    expect('{');
    func->body = parse_block();
    expect('}');
}
void parse_return() {
    expect(TOKEN_RETURN);
    Node *value = NULL;
    if (current_token != ';') {
        value = parse_expression();
    }
    expect(';');
    return new_return_node(value);
}
typedef struct {
    NodeType type;
    union {
        if (match(TOKEN_FLOAT)) {
    return create_literal_node(TOKEN_FLOAT, token.value);
}
if (match(TOKEN_STRING)) {
    return create_literal_node(TOKEN_STRING, token.value);
}
if (match(TOKEN_BOOL)) {
    return create_literal_node(TOKEN_BOOL, token.value);
}
#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_IDENTIFIER,  // نام متغیرها و توابع
    TOKEN_NUMBER,      // اعداد (123, 3.14)
    TOKEN_STRING,      // رشته‌ها ("Hello, CJDK!")
    TOKEN_OPERATOR,    // عملگرها (+, -, *, /)
    TOKEN_KEYWORD,     // کلمات کلیدی (if, else, while, print)
    TOKEN_EOF          // پایان ورودی
} TokenType;

typedef struct {
    TokenType type;
    char value[256]; // مقدار توکن (مثلاً "print", "42", "+")
} Token;

Token get_next_token(const char **input);

#endif
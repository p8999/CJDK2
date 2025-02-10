#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

// لیست کلمات کلیدی
const char *keywords[] = {"if", "else", "while", "print", "return", NULL};

// بررسی اینکه آیا یک رشته کلمه کلیدی است؟
int is_keyword(const char *str) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(str, keywords[i]) == 0) return 1;
    }
    return 0;
}

// دریافت توکن بعدی
Token get_next_token(const char **input) {
    while (**input == ' ' || **input == '\n') (*input)++; // رد کردن فاصله‌ها

    Token token;
    token.value[0] = '\0';

    if (**input == '\0') { // پایان ورودی
        token.type = TOKEN_EOF;
        return token;
    }

    if (isalpha(**input)) { // شناسایی متغیرها و کلمات کلیدی
        int i = 0;
        while (isalnum(**input)) {
            token.value[i++] = **input;
            (*input)++;
        }
        token.value[i] = '\0';

        token.type = is_keyword(token.value) ? TOKEN_KEYWORD : TOKEN_IDENTIFIER;
        return token;
    }

    if (isdigit(**input)) { // شناسایی اعداد
        int i = 0;
        while (isdigit(**input)) {
            token.value[i++] = **input;
            (*input)++;
        }
        token.value[i] = '\0';

        token.type = TOKEN_NUMBER;
        return token;
    }

    if (**input == '"') { // شناسایی رشته‌ها
        (*input)++;
        int i = 0;
        while (**input != '"' && **input != '\0') {
            token.value[i++] = **input;
            (*input)++;
        }
        if (**input == '"') (*input)++;
        token.value[i] = '\0';

        token.type = TOKEN_STRING;
        return token;
    }

    // سایر کاراکترها (عملگرها)
    token.type = TOKEN_OPERATOR;
    token.value[0
    func check(x) {
    if (x < 0) { return "منفی"; }
    return "مثبت";
}

print(check(-5)); // خروجی: "منفی"
print(check(5));  // خروجی: "مثبت"
if (is_number(current_char)) {
    return make_token(TOKEN_FLOAT, read_float());
} 
else if (current_char == '"') {
    return make_token(TOKEN_STRING, read_string());
} 
else if (match_keyword("true") || match_keyword("false")) {
    return make_token(TOKEN_BOOL, read_boolean());
}
if (match_keyword("import")) {
    return make_token(TOKEN_IMPORT, NULL);
}
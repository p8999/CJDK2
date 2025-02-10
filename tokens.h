typedef enum {
    TOKEN_INT,
    TOKEN_FLOAT,   // عدد اعشاری
    TOKEN_STRING,  // رشته متنی
    TOKEN_BOOL,    // مقدار `true` یا `false`
    // ...
} TokenType;
typedef enum {
    TOKEN_IMPORT, // دستور import
    TOKEN_IDENTIFIER,
    // ...
} TokenType;
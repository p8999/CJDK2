typedef enum {
    NODE_BINARY_OP,
    NODE_NUMBER,
    NODE_IDENTIFIER
} NodeType;

typedef struct Node {
    NodeType type;
    union {
        struct { struct Node *left; char op; struct Node *right; } binary;
        int number;
        char *identifier;
    };
} Node;
typedef struct Node {
    enum { 
        NODE_NUMBER, NODE_IDENTIFIER, NODE_BINARY_OP, NODE_ASSIGNMENT,
        NODE_IF, NODE_WHILE
    } type;
    
    union {
        int number;
        char identifier[32];

        struct {
            char op;
            struct Node *left;
            struct Node *right;
        } binary;

        struct {
            char var_name[32];
            struct Node *value;
        } assignment;

        struct {
            struct Node *condition;
            struct Node *body;
        } if_stmt;

        struct {
            struct Node *condition;
            struct Node *body;
        } while_stmt;
    };
} Node;
typedef struct ReturnNode {
    struct Node *value; // مقدار بازگشتی
} ReturnNode;
typedef struct FieldList {
    char* name;
    char* type;
    struct FieldList* next;
} FieldList;

typedef struct StructNode {
    NodeType type;
    char* name;
    FieldList* fields;
} StructNode;
typedef struct MethodList {
    char* name;
    char* returnType;
    struct ParamList* params;
    struct MethodList* next;
} MethodList;

typedef struct ClassNode {
    NodeType type;
    char* name;
    FieldList* fields;
    MethodList* methods;
} ClassNode;
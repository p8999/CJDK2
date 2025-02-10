typedef struct {
    NodeType type;
    union {
        int int_value;
        float float_value;
        char* string_value;
        bool bool_value;
    };
} LiteralNode;
typedef struct {
    NodeType type;
    char* module_name;
Node* parse_statement() {
    if (match(TOKEN_IF)) {
        return parse_if_statement();
    } else if (match(TOKEN_WHILE)) {
        return parse_while_statement();
    } else if (match(TOKEN_RETURN)) {
        return parse_return_statement();
    }
    if (match(TOKEN_IMPORT)) {
    Token module_name = expect(TOKEN_IDENTIFIER, "Expected module name after 'import'");
    return create_import_node(module_name.value);
}
if (match(TOKEN_STRUCT)) {
    return parse_struct();
}
Node* parse_struct() {
    Token name = expect(TOKEN_IDENTIFIER, "Expected struct name");
    expect(TOKEN_LBRACE, "Expected '{' after struct name");

    StructNode* struct_node = malloc(sizeof(StructNode));
    struct_node->type = NODE_STRUCT;
    struct_node->name = strdup(name.value);
    struct_node->fields = NULL;

    while (!match(TOKEN_RBRACE)) {
        Token field_name = expect(TOKEN_IDENTIFIER, "Expected field name");
        expect(TOKEN_COLON, "Expected ':' after field name");
        Token field_type = expect(TOKEN_IDENTIFIER, "Expected field type");

        add_field_to_struct(struct_node, field_name.value, field_type.value);
    }

    return (Node*)struct_node;
}
Node* parseStructOrClass(Parser* parser) {
    if (match(parser, TOKEN_STRUCT) || match(parser, TOKEN_CLASS)) {
        bool isClass = parser->previous.type == TOKEN_CLASS;
        char* name = consume(parser, TOKEN_IDENTIFIER, "Expected name for struct/class").lexeme;

        consume(parser, TOKEN_LBRACE, "Expected '{' after struct/class name");

        FieldList* fields = NULL;
        MethodList* methods = NULL;

        while (!check(parser, TOKEN_RBRACE) && !isAtEnd(parser)) {
            char* type = consume(parser, TOKEN_IDENTIFIER, "Expected type").lexeme;
            char* fieldName = consume(parser, TOKEN_IDENTIFIER, "Expected field name").lexeme;
            consume(parser, TOKEN_SEMICOLON, "Expected ';' after field");

            FieldList* newField = malloc(sizeof(FieldList));
            newField->name = fieldName;
            newField->type = type;
            newField->next = fields;
            fields = newField;
        }

        consume(parser, TOKEN_RBRACE, "Expected '}' after struct/class body");

        if (isClass) {
            ClassNode* classNode = malloc(sizeof(ClassNode));
            classNode->type = NODE_CLASS;
            classNode->name = name;
            classNode->fields = fields;
            classNode->methods = methods;
            return (Node*)classNode;
        } else {
            StructNode* structNode = malloc(sizeof(StructNode));
            structNode->type = NODE_STRUCT;
            structNode->name = name;
            structNode->fields = fields;
            return (Node*)structNode;
        }
    }
    return NULL;
}
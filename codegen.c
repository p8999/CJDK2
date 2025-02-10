void generate_code_for_literal(LiteralNode* node) {
    switch (node->type) {
        case TOKEN_INT: printf("push_int %d\n", node->int_value); break;
        case TOKEN_FLOAT: printf("push_float %f\n", node->float_value); break;
        case TOKEN_STRING: printf("push_string \"%s\"\n", node->string_value); break;
        case TOKEN_BOOL: printf("push_bool %d\n", node->bool_value); break;
    }
}
void generateStruct(StructNode* structNode) {
    printf("Generating struct: %s\n", structNode->name);
    printf("struct %s {\n", structNode->name);
    
    FieldList* field = structNode->fields;
    while (field != NULL) {
        printf("    %s %s;\n", field->type, field->name);
        field = field->next;
    }

    printf("};\n");
}
void generateClass(ClassNode* classNode) {
    printf("Generating class: %s\n", classNode->name);
    
    printf("typedef struct %s {\n", classNode->name);
    
    FieldList* field = classNode->fields;
    while (field != NULL) {
        printf("    %s %s;\n", field->type, field->name);
        field = field->next;
    }

    printf("} %s;\n", classNode->name);

    // تولید متدهای کلاس
    MethodList* method = classNode->methods;
    while (method != NULL) {
        printf("%s %s_%s(", method->returnType, classNode->name, method->name);

        ParamList* param = method->params;
        while (param != NULL) {
            printf("%s %s", param->type, param->name);
            param = param->next;
            if (param != NULL) printf(", ");
        }

        printf(");\n");
        method = method->next;
    }
}
void generateNode(Node* node) {
    switch (node->type) {
        case NODE_STRUCT:
            generateStruct((StructNode*)node);
            break;
        case NODE_CLASS:
            generateClass((ClassNode*)node);
            break;
        default:
            printf("Unsupported node type.\n");
    }
}
Value eval_literal(LiteralNode* node) {
    switch (node->type) {
        case TOKEN_INT: return make_value_int(node->int_value);
        case TOKEN_FLOAT: return make_value_float(node->float_value);
        case TOKEN_STRING: return make_value_string(node->string_value);
        case TOKEN_BOOL: return make_value_bool(node->bool_value);
    }
}
void eval_import(ImportNode* node) {
    char filename[256];
    snprintf(filename, sizeof(filename), "%s.cjdk", node->module_name);

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Module '%s' not found!\n", node->module_name);
        return;
    }

    char* code = read_file(file);
    fclose(file);
    
    execute_code(code); // اجرای کد ماژول
}
if (node->type == NODE_IMPORT) {
    eval_import((ImportNode*)node);
}
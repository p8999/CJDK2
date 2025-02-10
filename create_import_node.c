ImportNode* create_import_node(char* module_name) {
    ImportNode* node = malloc(sizeof(ImportNode));
    node->type = NODE_IMPORT;
    node->module_name = strdup(module_name);
    return (Node*)node;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int value;
} Variable;

#define MAX_VARS 100
Variable symbol_table[MAX_VARS];
int var_count = 0;

// ذخیره متغیر در جدول
void set_variable(char *name, int value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            symbol_table[i].value = value;
            return;
        }
    }
    strcpy(symbol_table[var_count].name, name);
    symbol_table[var_count].value = value;
    var_count++;
}

// گرفتن مقدار متغیر از جدول
int get_variable(char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].value;
        }
    }
    printf("Error: Undefined variable %s\n", name);
    exit(1);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_code(const char *code) {
    printf("Executing CJDK Code:\n%s\n", code);
    // در اینجا کدهای مربوط به تجزیه و اجرا را اضافه می‌کنیم
}

int main() {
    char input[256];
    printf("CJDK Interpreter v1.0\n");
    while (1) {
        printf(">>> ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "exit\n") == 0) break;
        run_code(input);
    }
    return 0;
}
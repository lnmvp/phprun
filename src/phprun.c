#include <stdio.h>
#include "lexer.h"

int main() {
    const char *code = "<?php\n$a = 5 + 3;\necho $a;";
    init_lexer(code);

    Token token;
    do {
        token = get_next_token();
        printf("Token: %d, Value: %s\n", token.type, token.value);
    } while (token.type != TOKEN_EOF);

    return 0;
}

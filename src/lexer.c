#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

const char *src;
size_t pos = 0;

void init_lexer(const char *source) {
    src = source;
    pos = 0;
}

// 跳过空格
void skip_whitespace() {
    while (isspace(src[pos])) pos++;
}

// 读取下一个 Token
Token get_next_token() {
    Token token;
    token.value[0] = '\0';

    skip_whitespace();

    if (src[pos] == '\0') {
        token.type = TOKEN_EOF;
        return token;
    }

    if (strncmp(&src[pos], "<?php", 5) == 0) {
        token.type = TOKEN_OPEN_TAG;
        strcpy(token.value, "<?php");
        pos += 5;
        return token;
    }

    if (isalpha(src[pos])) {
        if (strncmp(&src[pos], "echo", 4) == 0) {
            token.type = TOKEN_ECHO;
            strcpy(token.value, "echo");
            pos += 4;
            return token;
        }
    }

    if (src[pos] == '$') {
        token.type = TOKEN_VARIABLE;
        int i = 0;
        token.value[i++] = src[pos++];
        while (isalnum(src[pos]) || src[pos] == '_') {
            token.value[i++] = src[pos++];
        }
        token.value[i] = '\0';
        return token;
    }

    if (isdigit(src[pos])) {
        token.type = TOKEN_NUMBER;
        int i = 0;
        while (isdigit(src[pos])) {
            token.value[i++] = src[pos++];
        }
        token.value[i] = '\0';
        return token;
    }

    switch (src[pos]) {
        case '=': token.type = TOKEN_EQUAL; token.value[0] = '='; pos++; break;
        case '+': token.type = TOKEN_PLUS; token.value[0] = '+'; pos++; break;
        case ';': token.type = TOKEN_SEMICOLON; token.value[0] = ';'; pos++; break;
        default:
            printf("Unexpected character: %c\n", src[pos]);
            exit(1);
    }
    token.value[1] = '\0';
    return token;
}

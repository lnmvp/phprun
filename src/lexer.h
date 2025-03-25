#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_OPEN_TAG,  // <?php
    TOKEN_VARIABLE,  // $a
    TOKEN_EQUAL,     // =
    TOKEN_NUMBER,    // 5, 3
    TOKEN_PLUS,      // +
    TOKEN_SEMICOLON, // ;
    TOKEN_ECHO,      // echo
    TOKEN_EOF        // 结束
} TokenType;

typedef struct {
    TokenType type;
    char value[256];  // Token 的值
} Token;

void init_lexer(const char *source);
Token get_next_token();

#endif

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef enum {
    NODE_NUMBER,
    NODE_VARIABLE,
    NODE_ASSIGN,
    NODE_ADD,
    NODE_ECHO
} NodeType;

typedef struct Node {
    NodeType type;
    struct Node *left;
    struct Node *right;
    char value[256];  // 变量名 或 数值
} Node;

Node *parse();
void free_ast(Node *node);

#endif

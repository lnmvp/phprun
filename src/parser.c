#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "parser.h"

Token current_token;

// 创建新的节点
Node *new_node(NodeType type, const char *value, Node *left, Node *right) {
    Node *node = malloc(sizeof(Node));
    node->type = type;
    node->left = left;
    node->right = right;
    if (value) {
        strcpy(node->value, value);
    } else {
        node->value[0] = '\0';
    }
    return node;
}

// 获取下一个 Token，并确保不会越界
void advance() {
    if (current_token.type != TOKEN_EOF) {
        current_token = get_next_token();
    }
}

// 解析因子（数字或变量）
Node *parse_factor() {
    if (current_token.type == TOKEN_NUMBER) {
        Node *node = new_node(NODE_NUMBER, current_token.value, NULL, NULL);
        advance();
        return node;
    } else if (current_token.type == TOKEN_VARIABLE) {
        Node *node = new_node(NODE_VARIABLE, current_token.value, NULL, NULL);
        advance();
        return node;
    }
    printf("Syntax Error: Expected number or variable, got `%s`\n", current_token.value);
    exit(1);
}

// 解析表达式（支持 `+` 运算）
Node *parse_expr() {
    Node *left = parse_factor();
    while (current_token.type == TOKEN_PLUS) {
        advance();
        Node *right = parse_factor();
        left = new_node(NODE_ADD, "+", left, right);
    }
    return left;
}

// 解析赋值语句
Node *parse_statement() {
    if (current_token.type == TOKEN_VARIABLE) {
        Node *var_node = parse_factor(); // 变量
        if (current_token.type == TOKEN_EQUAL) {
            advance();
            Node *expr_node = parse_expr();
            if (current_token.type == TOKEN_SEMICOLON) {
                advance();
                return new_node(NODE_ASSIGN, "=", var_node, expr_node);
            }
            printf("Syntax Error: Expected `;` after assignment\n");
            exit(1);
        }
        printf("Syntax Error: Expected `=` after variable `%s`\n", var_node->value);
        exit(1);
    } else if (current_token.type == TOKEN_ECHO) {
        advance();
        Node *expr_node = parse_expr();
        if (current_token.type == TOKEN_SEMICOLON) {
            advance();
            return new_node(NODE_ECHO, "echo", expr_node, NULL);
        }
        printf("Syntax Error: Expected `;` after `echo`\n");
        exit(1);
    }
    printf("Syntax Error: Unexpected token `%s`\n", current_token.value);
    exit(1);
}

// 解析整个 PHP 文件
Node *parse() {
    advance(); // 获取第一个 Token

    // 处理 <?php 开头
    if (current_token.type == TOKEN_OPEN_TAG) {
        advance();
    }

    // 解析多个语句
    Node *root = NULL;
    Node *last = NULL;
    
    while (current_token.type != TOKEN_EOF) {
        Node *stmt = parse_statement();

        if (!root) {
            root = stmt;
        } else {
            last->right = stmt;
        }
        last = stmt;
    }

    // 确保结束时 Token 是 EOF
    if (current_token.type != TOKEN_EOF) {
        printf("Syntax Error: Expected end of file, but got `%s`\n", current_token.value);
        exit(1);
    }

    return root;
}

// 释放 AST
void free_ast(Node *node) {
    if (!node) return;
    free_ast(node->left);
    free_ast(node->right);
    free(node);
}

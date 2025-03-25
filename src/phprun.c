#include <stdio.h>
#include "lexer.h"
#include "parser.h"

// 递归打印 AST
void print_ast(Node *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("  ");
    
    switch (node->type) {
        case NODE_NUMBER:
            printf("Number(%s)\n", node->value);
            break;
        case NODE_VARIABLE:
            printf("Variable(%s)\n", node->value);
            break;
        case NODE_ASSIGN:
            printf("Assign:\n");
            print_ast(node->left, depth + 1);
            print_ast(node->right, depth + 1);
            break;
        case NODE_ADD:
            printf("Add:\n");
            print_ast(node->left, depth + 1);
            print_ast(node->right, depth + 1);
            break;
        case NODE_ECHO:
            printf("Echo:\n");
            print_ast(node->left, depth + 1);
            break;
        default:
            printf("UNKNOW(%s)\n", node->value);
    }
}

int main() {
    const char *code = "<?php\n$a = 5 + 3;\necho $a;";  // 示例 PHP 代码
    init_lexer(code);  // 初始化词法分析器

    Node *ast = parse();

    // 打印 AST
    printf("AST:\n");
    print_ast(ast, 0);

    // 释放 AST 内存
    free_ast(ast);

    return 0;
}

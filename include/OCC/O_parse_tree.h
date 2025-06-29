#pragma once
#include "O_symbol_table.h"
#include "O_token_types.h"

typedef struct ParseTreeNode {
    char* value;                         // Value of that node
    TokenType type;                      // Type of node
    struct ParseTreeNode** children;     // Array of child nodes
    int childCount;                      // Number of children
    SymbolTable* scope;
} ParseTreeNode;

ParseTreeNode* createParseTreeNode(Token*, SymbolTable*);

void addChild(ParseTreeNode*, ParseTreeNode*);

void freeParseTree(ParseTreeNode*);
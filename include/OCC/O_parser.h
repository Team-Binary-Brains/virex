/**
 * @file O_parser.h
 * @brief MISSING DOCUMENTATION.
 *
 * @author Omkar Jagtap
 * @date January 2025
 */

#pragma once
#include "O_parse_tree.h"
#include "O_symbol_table.h"
#include "O_token_types.h"

ParseTreeNode* parser(Token*);

Token* match(Token**, TokenType);

ParseTreeNode* parseDeclaration(Token**, SymbolTable*, int flag);

ParseTreeNode* parseAssignment(Token**, SymbolTable*, int flag);

ParseTreeNode* parsePrimaryExpr(Token** currentToken, SymbolTable* symTable);

ParseTreeNode* parseMultiplicativeExpr(Token** currentToken, SymbolTable* symTable);

ParseTreeNode* parseAdditiveExpr(Token** currentToken, SymbolTable* symTable);

ParseTreeNode* parseExpression(Token** currentToken, SymbolTable* symTable);

ParseTreeNode* parseExitStatement(Token**, SymbolTable*);

ParseTreeNode* parsePrintStatement(Token**, SymbolTable*);

ParseTreeNode* parseScanStatement(Token**, SymbolTable*);

ParseTreeNode* parseIfStatement(Token**, SymbolTable*);

ParseTreeNode* parseBlock(Token**, SymbolTable*);

ParseTreeNode* parseStatement(Token**, SymbolTable*);

ParseTreeNode* parseWhileStatement(Token**, SymbolTable*);

ParseTreeNode* parseForStatement(Token**, SymbolTable*);

ParseTreeNode* parseAssignmentExpr(Token**, SymbolTable*);
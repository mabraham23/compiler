#ifndef PARSER_H
#define PARSER_H

#include "Scanner.h"
#include "Symbol.h"
#include "Token.h"
#include "node.h"

class Parser {
private:
    ScannerClass* scanner;
    SymbolTableClass* table;

    TokenClass Match(TokenType expected);

    ProgramNode* Program();
    BlockNode* Block();
    StatementGroupNode* StatementGroup();
    StatementNode* Statement();
    // Statements
    DeclarationStatementNode* DeclarationStatement();
    DeclarationAssignmentStatementNode* DeclarationAssignmentStatement();
    AssignmentStatementNode* AssignmentStatement();
    IfStatementNode* IfStatement();
    WhileStatementNode* WhileStatement();
    ForStatementNode* ForStatement();
    CoutStatementNode* CoutStatement();

    ExpressionNode* Expression();
    ExpressionNode* Relational();
    ExpressionNode* PlusMinus();
    ExpressionNode* TimesDivide();
    ExpressionNode* Factor();

    IdentifierNode* Identifier();
    IntegerNode* Integer();
public:
    Parser(ScannerClass* scanner, SymbolTableClass* table);
    ~Parser();

    StartNode* Start();
};


#endif // PARSER_H
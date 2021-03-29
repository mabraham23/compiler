#include <iostream>
#include "Parser.h"

Parser::Parser(ScannerClass* scanner, SymbolTableClass* table)
    : scanner(scanner), table(table) {}

Parser::~Parser() {
    delete this->scanner;
    delete this->table;
}

TokenClass Parser::Match(TokenType expected) {
    TokenClass t = this->scanner->GetNextToken();
    if (t.GetTokenType() != expected) {
        std::cerr << "Parser Error Match" << std::endl;
        std::cerr << "Token Expected: " <<
            TokenClass::GetTokenTypeName(expected) <<
            ", token type received: " << t.GetTokenTypeName() << ": " << t << std::endl;
        exit(1);
    }

    return t;
}

StartNode* Parser::Start() {
    ProgramNode* pn = this->Program();
    this->Match(ENDFILE_TOKEN);
    return new StartNode(pn);
}

ProgramNode* Parser::Program() {
    this->Match(VOID_TOKEN);
    this->Match(MAIN_TOKEN);
    this->Match(LPAREN_TOKEN);
    this->Match(RPAREN_TOKEN);
    BlockNode* bn = this->Block();
    return new ProgramNode(bn);
}

BlockNode* Parser::Block() {
    this->Match(LCURLY_TOKEN);
    StatementGroupNode* sgn = this->StatementGroup();
    this->Match(RCURLY_TOKEN);
    return new BlockNode(sgn);
}

StatementGroupNode* Parser::StatementGroup() {
    StatementGroupNode* sgn = new StatementGroupNode();
    StatementNode* sn;
    do {
        sn = this->Statement();
        if (sn != NULL) {
            sgn->AddStatement(sn);
        }
    } while (sn != NULL);
    return sgn;
}

// Statements

StatementNode* Parser::Statement() {
    TokenType t = this->scanner->PeekNextToken().GetTokenType();
    switch (t) {
    case INT_TOKEN:
        return this->DeclarationStatement();
    case IDENTIFIER_TOKEN:
        return this->AssignmentStatement();
    case IF_TOKEN:
        return this->IfStatement();
    case WHILE_TOKEN:
        return this->WhileStatement();
    case FOR_TOKEN:
        return this->ForStatement();
    case COUT_TOKEN:
        return this->CoutStatement();
    default:
        return NULL;
    }
    
    return NULL;
}



DeclarationStatementNode* Parser::DeclarationStatement() {
    this->Match(INT_TOKEN);
    IdentifierNode* in = this->Identifier();
    // Optional assignment at same time
    TokenClass t = this->scanner->PeekNextToken();
    TokenType tt = t.GetTokenType();
    switch (tt) {
    case SEMICOLON_TOKEN:
        this->Match(tt);
        return new DeclarationStatementNode(in);
    case ASSIGNMENT_TOKEN:
    {
        this->Match(tt);
        ExpressionNode* en = this->Expression();
        this->Match(SEMICOLON_TOKEN);
        return new DeclarationAssignmentStatementNode(in, en);
    }
    default:
        std::cerr << "Error: invalid declaration: " << t << std::endl;
        break;
    }
    return NULL;
}

AssignmentStatementNode* Parser::AssignmentStatement() {
    IdentifierNode* in = this->Identifier();
    this->Match(ASSIGNMENT_TOKEN);
    ExpressionNode* en = this->Expression();
    this->Match(SEMICOLON_TOKEN);
    return new AssignmentStatementNode(in, en);
}

IfStatementNode* Parser::IfStatement() {
    this->Match(IF_TOKEN);
    this->Match(LPAREN_TOKEN);
    ExpressionNode* en = this->Expression();
    this->Match(RPAREN_TOKEN);
    BlockNode* bn = this->Block();
    return new IfStatementNode(en, bn);
}

WhileStatementNode* Parser::WhileStatement() {
    this->Match(WHILE_TOKEN);
    this->Match(LPAREN_TOKEN);
    ExpressionNode* en = this->Expression();
    this->Match(RPAREN_TOKEN);
    BlockNode* bn = this->Block();
    return new WhileStatementNode(en, bn);
}

ForStatementNode* Parser::ForStatement() {
    this->Match(FOR_TOKEN);
    this->Match(LPAREN_TOKEN);
    StatementNode* initializer = this->Statement();
    ExpressionNode* comparison = this->Expression();
    this->Match(SEMICOLON_TOKEN);
    IdentifierNode* in = this->Identifier();
    this->Match(ASSIGNMENT_TOKEN);
    ExpressionNode* en = this->Expression();
    AssignmentStatementNode* incrementer = new AssignmentStatementNode(in, en);
    this->Match(RPAREN_TOKEN);
    BlockNode* bn = this->Block();
    return new ForStatementNode(initializer, comparison, incrementer, bn);
}

CoutStatementNode* Parser::CoutStatement() {
    this->Match(COUT_TOKEN);
    this->Match(INSERTION_TOKEN);
    ExpressionNode* en = this->Expression();
    this->Match(SEMICOLON_TOKEN);
    return new CoutStatementNode(en);
}

// Expressions

ExpressionNode* Parser::Expression() {
    return this->Relational();
}

ExpressionNode* Parser::Relational() {
    ExpressionNode* en = this->PlusMinus();

    TokenType t = this->scanner->PeekNextToken().GetTokenType();
    switch (t) {
    case LESS_TOKEN:
        this->Match(t);
        en = new LessNode(en, this->PlusMinus());
        break;
    case LESS_EQUAL_TOKEN:
        this->Match(t);
        en = new LessEqualNode(en, this->PlusMinus());
        break;
    case GREATER_TOKEN:
        this->Match(t);
        en = new GreaterNode(en, this->PlusMinus());
        break;
    case GREATER_EQUAL_TOKEN:
        this->Match(t);
        en = new GreaterEqualNode(en, this->PlusMinus());
        break;
    case EQUAL_TOKEN:
        this->Match(t);
        en = new EqualNode(en, this->PlusMinus());
        break;
    case NOTEQUAL_TOKEN:
        this->Match(t);
        en = new NotEqualNode(en, this->PlusMinus());
        break;
    case BITWISE_AND_TOKEN:
        this->Match(t);
        en = new BitwiseAndNode(en, this->PlusMinus());
        break;
    case BITWISE_OR_TOKEN:
        this->Match(t);
        en = new BitwiseOrNode(en, this->PlusMinus());
        break;
    case AND_TOKEN:
        this->Match(t);
        en = new AndNode(en, this->PlusMinus());
        break;
    case OR_TOKEN:
        this->Match(t);
        en = new OrNode(en, this->PlusMinus());
        break;
    default:
        return en;
    }
    return en;
}

ExpressionNode* Parser::PlusMinus() {
    ExpressionNode* en = this->TimesDivide();

    for (;;) {
        TokenType t = this->scanner->PeekNextToken().GetTokenType();
        switch (t) {
        case PLUS_TOKEN:
            this->Match(t);
            en = new PlusNode(en, this->TimesDivide());
            break;
        case MINUS_TOKEN:
            this->Match(t);
            en = new MinusNode(en, this->TimesDivide());
            break;
        default:
            return en;
        }
    }
}

ExpressionNode* Parser::TimesDivide() {
    ExpressionNode* en = this->Factor();

    for (;;) {
        TokenType t = this->scanner->PeekNextToken().GetTokenType();
        switch (t) {
        case TIMES_TOKEN:
            this->Match(t);
            en = new TimesNode(en, this->Factor());
            break;
        case DIVIDE_TOKEN:
            this->Match(t);
            en = new DivideNode(en, this->Factor());
            break;
        default:
            return en;
        }
    }
}

ExpressionNode* Parser::Factor() {
    ExpressionNode* en;
    TokenType t = this->scanner->PeekNextToken().GetTokenType();
    switch (t) {
    case IDENTIFIER_TOKEN:
        en = this->Identifier();
        break;
    case INTEGER_TOKEN:
        en = this->Integer();
        break;
    case LPAREN_TOKEN:
        this->Match(LPAREN_TOKEN);
        en = this->Expression();
        this->Match(RPAREN_TOKEN);
        break;
    default:
        std::cerr << "Factor expected " << TokenClass::GetTokenTypeName(t) << std::endl;
        exit(EXIT_FAILURE);
    }
    return en;
}

IdentifierNode* Parser::Identifier() {
    TokenClass t = this->Match(IDENTIFIER_TOKEN);
    return new IdentifierNode(t.GetLexeme(), this->table);
}

IntegerNode* Parser::Integer() {
    TokenClass t = this->Match(INTEGER_TOKEN);
    int i = atoi(t.GetLexeme().c_str());
    return new IntegerNode(i);
}
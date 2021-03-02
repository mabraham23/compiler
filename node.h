#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string> 
#include "Symbol.h"


class Node;
class StartNode;
class ProgramNode;
class StatementNode;
class BlockNode;
class StatementGroupNode;
class DeclarationStatementNode;
class DeclarationAssignmentStatementNode;
class AssignmentStatementNode;
class IfStatementNode;
class WhileStatementNode;
class ForStatementNode;
class CoutStatementNode;

class ExpressionNode;
class IntegerNode;
class IdentifierNode;

class BinaryOperatorNode;
class PlusNode;
class MinusNode;
class TimesNode;
class DividesNode;

class LessEqualNode;
class GreaterNode;
class GreaterEqualNode;
class EqualNode;
class NotEqualNode;

class BitwiseAndNode;
class BitwiseOrNode;
class AndNode;
class OrNode;

class Node
{
public:
    virtual ~Node();
    virtual void Interpret() = 0;
};

class StartNode: public Node
{
private:
    ProgramNode *mProgramNode;
public:
    StartNode(ProgramNode *ProgramNode);
    ~StartNode();

    void Interpret();
};

class ProgramNode: public Node
{
private:
    BlockNode *mBlockNode;
public:
    ProgramNode(BlockNode *BlockNode);
    ~ProgramNode();

    void Interpret();
};

class StatementNode: public Node {
private:
public:
};

class BlockNode: public StatementNode 
{
private:
    StatementGroupNode *mStatementGroupNode; 
public:
    BlockNode(StatementGroupNode *StatementGroupNode);
    ~BlockNode();

    void Interpret();
};

class StatementGroupNode: public Node 
{
private:
    std::vector<StatementNode *> mStatementNodes;
public:
    StatementGroupNode();
    ~StatementGroupNode();

    void Interpret();
    void AddStatement(StatementNode *StatementNode);
};

class DeclarationStatementNode: public StatementNode 
{
protected:
    IdentifierNode *mIdentifierNode;
public:
    DeclarationStatementNode(IdentifierNode *IdentifierNode);
    ~DeclarationStatementNode();

    void Interpret();
};

class DeclarationAssignmentStatementNode: public DeclarationStatementNode 
{
private:
    ExpressionNode* mExpressionNode;
public:
    DeclarationAssignmentStatementNode(IdentifierNode* IdentifierNode, ExpressionNode *ExpressionNode);
    ~DeclarationAssignmentStatementNode();

    void Interpret();
};

class AssignmentStatementNode: public StatementNode
{
private:
    IdentifierNode *mIdentifierNode;
    ExpressionNode *mExpressionNode;
public:
    AssignmentStatementNode(IdentifierNode* IdentifierNode, ExpressionNode *ExpressionNode);
    ~AssignmentStatementNode();

    void Interpret();
};

class IfStatementNode : public StatementNode
{
private:
    ExpressionNode *mExpressionNode;
    BlockNode *mBlockNode;
public:
    IfStatementNode(ExpressionNode *ExpressionNode, BlockNode *BlockNode);
    ~IfStatementNode();

    void Interpret();
};

class WhileStatementNode : public StatementNode
{
private:
    ExpressionNode *mExpressionNode;
    BlockNode *mBlockNode;
public:
    WhileStatementNode(ExpressionNode *ExpressionNode, BlockNode *BlockNode);
    ~WhileStatementNode();

    void Interpret();
};

class ForStatementNode : public StatementNode
{
private:
    StatementNode *mInitializer;
    ExpressionNode *mComparison;
    StatementNode *mIncrementer;
    BlockNode *mBlockNode;
public:
    ForStatementNode(
        StatementNode *mInitializer,
        ExpressionNode *mComparison,
        StatementNode *Incrementer,
        BlockNode *mBlockNode
    );
    ~ForStatementNode();

    void Interpret();
};


class CoutStatementNode : public StatementNode
{
private:
    ExpressionNode *mExpressionNode;
public:
    CoutStatementNode(ExpressionNode *ExpressionNode);
    ~CoutStatementNode();

    void Interpret();
};

class ExpressionNode {
public:
    virtual ~ExpressionNode();
    virtual int Evaluate() = 0;
};

class IntegerNode: public ExpressionNode
{
private:
    int mValue;
public:
    IntegerNode(int i);
    int Evaluate();
};

class IdentifierNode: public ExpressionNode {
private:
    std::string mLabel;
    SymbolTableClass *mTable;
public:
    IdentifierNode(std::string label, SymbolTableClass *symTable);
    ~IdentifierNode();

    void DeclareVariable();
    void SetValue(int v);
    int GetIndex();
    int Evaluate();
};

class BinaryOperatorNode: public ExpressionNode 
{
protected:
    ExpressionNode *mLeft;
    ExpressionNode *mRight;
public:
    BinaryOperatorNode(ExpressionNode *left, ExpressionNode *right );
    ~BinaryOperatorNode();
};

class PlusNode: public BinaryOperatorNode
{
private:
public:
    PlusNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
};

class MinusNode: public BinaryOperatorNode
{
private:
public:
    MinusNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
};

class TimesNode: public BinaryOperatorNode
{
private:
public:
    TimesNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
};

class DivideNode: public BinaryOperatorNode
{
private:
public:
    DivideNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
};

class LessNode: public BinaryOperatorNode
{
private:
public:
    LessNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
};

class LessEqualNode: public BinaryOperatorNode
{
private:
public:
    LessEqualNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
};

class GreaterNode: public BinaryOperatorNode
{
private:
public:
    GreaterNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
};

class GreaterEqualNode: public BinaryOperatorNode
{
private:
public:
    GreaterEqualNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
};

class EqualNode: public BinaryOperatorNode
{
private:
public:
    EqualNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
};

class NotEqualNode: public BinaryOperatorNode
{
private:
public:
    NotEqualNode(ExpressionNode *left, ExpressionNode *right);
    int Evaluate();
};

class BitwiseAndNode : public BinaryOperatorNode {
private:

public:
    BitwiseAndNode(ExpressionNode* left, ExpressionNode* right);
    int Evaluate();
};
class BitwiseOrNode : public BinaryOperatorNode {
private:

public:
    BitwiseOrNode(ExpressionNode* left, ExpressionNode* right);
    int Evaluate();
};
class AndNode : public BinaryOperatorNode {
private:

public:
    AndNode(ExpressionNode* left, ExpressionNode* right);
    int Evaluate();
};
class OrNode : public BinaryOperatorNode {
private:

public:
    OrNode(ExpressionNode* left, ExpressionNode* right);
    int Evaluate();
};

#endif // NODE_H
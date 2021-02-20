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

class Node
{
public:
    virtual ~Node();
};

class StartNode: public Node
{
private:
    ProgramNode *mProgramNode;
public:
    StartNode(ProgramNode *ProgramNode);
    ~StartNode();
};

class ProgramNode: public Node
{
private:
    BlockNode *mBlockNode;
public:
    ProgramNode(BlockNode *BlockNode);
    ~ProgramNode();
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
};

class StatementGroupNode: public Node 
{
private:
    std::vector<StatementNode *> mStatementNodes;
public:
    StatementGroupNode();
    ~StatementGroupNode();

    void AddStatement(StatementNode *StatementNode);
};

class DeclarationStatementNode: public StatementNode 
{
protected:
    IdentifierNode *mIdentifierNode;
public:
    DeclarationStatementNode(IdentifierNode *IdentifierNode);
    ~DeclarationStatementNode();
};

class DeclarationAssignmentStatementNode: public DeclarationStatementNode 
{
private:
    ExpressionNode* mExpressionNode;
public:
    DeclarationAssignmentStatementNode(IdentifierNode* IdentifierNode, ExpressionNode *ExpressionNode);
    ~DeclarationAssignmentStatementNode();
};

class AssignmentStatementNode: public StatementNode
{
private:
    IdentifierNode *mIdentifierNode;
    ExpressionNode *mExpressionNode;
public:
    AssignmentStatementNode(IdentifierNode* IdentifierNode, ExpressionNode *ExpressionNode);
    ~AssignmentStatementNode();
};

class IfStatementNode : public StatementNode
{
private:
    ExpressionNode *mExpressionNode;
    BlockNode *mBlockNode;
public:
    IfStatementNode(ExpressionNode *ExpressionNode, BlockNode *BlockNode);
    ~IfStatementNode();
};

class WhileStatementNode : public StatementNode
{
private:
    ExpressionNode *mExpressionNode;
    BlockNode *mBlockNode;
public:
    WhileStatementNode(ExpressionNode *ExpressionNode, BlockNode *BlockNode);
    ~WhileStatementNode();
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
};


class CoutStatementNode : public StatementNode
{
private:
    ExpressionNode *mExpressionNode;
public:
    CoutStatementNode(ExpressionNode *ExpressionNode);
    ~CoutStatementNode();
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

#endif // NODE_H
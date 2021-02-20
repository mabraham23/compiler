#include <iostream>
#include "node.h"

Node::~Node(){}

StartNode::StartNode(ProgramNode *ProgramNode)
    : mProgramNode(ProgramNode) {}

StartNode::~StartNode(){
    delete this->mProgramNode;
};

ProgramNode::ProgramNode(BlockNode *BlockNode)
    : mBlockNode(BlockNode) {}

ProgramNode::~ProgramNode(){
    delete this->mBlockNode;
};

BlockNode::BlockNode(StatementGroupNode *StatementGroupNode)
    : mStatementGroupNode(StatementGroupNode) {}

BlockNode::~BlockNode(){
    delete this->mStatementGroupNode;
};

StatementGroupNode::StatementGroupNode()
    : mStatementNodes(std::vector<StatementNode*>{}) {}

StatementGroupNode::~StatementGroupNode(){
    for ( auto n : this->mStatementNodes ) {
        delete n;
    }
};

void StatementGroupNode::AddStatement(StatementNode *StatementNode){
    this->mStatementNodes.push_back(StatementNode);
};

DeclarationStatementNode::DeclarationStatementNode(IdentifierNode *IdentifierNode)
    : mIdentifierNode(IdentifierNode) {}

DeclarationStatementNode::~DeclarationStatementNode() {
    delete this->mIdentifierNode;
};

DeclarationAssignmentStatementNode::DeclarationAssignmentStatementNode(IdentifierNode* IdentifierNode, ExpressionNode* ExpressionNode)
    : DeclarationStatementNode(IdentifierNode), mExpressionNode(ExpressionNode) {}
DeclarationAssignmentStatementNode::~DeclarationAssignmentStatementNode() {
    delete this->mExpressionNode;
};

AssignmentStatementNode::AssignmentStatementNode(IdentifierNode* IdentifierNode, ExpressionNode* ExpressionNode)
    : mIdentifierNode(IdentifierNode), mExpressionNode(ExpressionNode) {}
AssignmentStatementNode::~AssignmentStatementNode() {
    delete this->mIdentifierNode;
    delete this->mExpressionNode;
};

IfStatementNode::IfStatementNode(ExpressionNode* ExpressionNode, BlockNode* BlockNode)
    : mExpressionNode(ExpressionNode), mBlockNode(BlockNode) {}
IfStatementNode::~IfStatementNode() {
    delete this->mExpressionNode;
    delete this->mBlockNode;
};

WhileStatementNode::WhileStatementNode(ExpressionNode* ExpressionNode, BlockNode* BlockNode)
    : mExpressionNode(ExpressionNode), mBlockNode(BlockNode) {}
WhileStatementNode::~WhileStatementNode() {
    delete this->mExpressionNode;
    delete this->mBlockNode;
}

ForStatementNode::ForStatementNode(
    StatementNode* initializer,
    ExpressionNode* comparison,
    StatementNode* incrementer,
    BlockNode* bn)
    : mInitializer(initializer),
      mComparison(comparison),
      mIncrementer(incrementer),
      mBlockNode(bn) {}
ForStatementNode::~ForStatementNode() {
    delete this->mInitializer;
    delete this->mComparison;
    delete this->mIncrementer;
    delete this->mBlockNode;
}

CoutStatementNode::CoutStatementNode( ExpressionNode *ExpressionNode )
    : mExpressionNode( ExpressionNode ){}
CoutStatementNode::~CoutStatementNode() {
    delete this->mExpressionNode;
}

ExpressionNode::~ExpressionNode() {}

IntegerNode::IntegerNode(int i)
    : mValue(i){}

int IntegerNode::Evaluate(){
    return this->mValue;
}

IdentifierNode::IdentifierNode( std::string label, SymbolTableClass *symTable )
    : mLabel(label), mTable(symTable){}

IdentifierNode::~IdentifierNode(){
    delete this->mTable;
}

void IdentifierNode::DeclareVariable(){
    this->mTable->AddEntry(this->mLabel);
}

void IdentifierNode::SetValue(int v){
    this->mTable->SetValue(this->mLabel, v);
}

int IdentifierNode::GetIndex(){
    return this->mTable->GetIndex(this->mLabel);
}

BinaryOperatorNode::BinaryOperatorNode(ExpressionNode *left, ExpressionNode *right )
    : mLeft(left), mRight(right){}

BinaryOperatorNode::~BinaryOperatorNode(){
    delete this->mLeft;
    delete this->mRight;
}

// Mathematical Operators

PlusNode::PlusNode(ExpressionNode *left, ExpressionNode *right)
    : BinaryOperatorNode(left, right) {}

int PlusNode::Evaluate(){
    return this->mLeft->Evaluate() + this->mRight->Evaluate();
}

MinusNode::MinusNode(ExpressionNode *left, ExpressionNode *right)
    : BinaryOperatorNode(left, right) {}

int MinusNode::Evaluate(){
    return this->mLeft->Evaluate() - this->mRight->Evaluate();
}

TimesNode::TimesNode(ExpressionNode *left, ExpressionNode *right)
    : BinaryOperatorNode(left, right) {}

int TimesNode::Evaluate(){
    return this->mLeft->Evaluate() * this->mRight->Evaluate();
}

DivideNode::DivideNode(ExpressionNode *left, ExpressionNode *right)
    : BinaryOperatorNode(left, right) {}

int DivideNode::Evaluate(){
    return this->mLeft->Evaluate() / this->mRight->Evaluate();
}

LessNode::LessNode(ExpressionNode *left, ExpressionNode *right)
    : BinaryOperatorNode(left, right) {}

int LessNode::Evaluate(){
    return this->mLeft->Evaluate() < this->mRight->Evaluate();
}

LessEqualNode::LessEqualNode(ExpressionNode *left, ExpressionNode *right)
    : BinaryOperatorNode(left, right) {}

int LessEqualNode::Evaluate(){
    return this->mLeft->Evaluate() <= this->mRight->Evaluate();
}

GreaterNode::GreaterNode(ExpressionNode *left, ExpressionNode *right)
    : BinaryOperatorNode(left, right) {}

int GreaterNode::Evaluate(){
    return this->mLeft->Evaluate() > this->mRight->Evaluate();
}

GreaterEqualNode::GreaterEqualNode(ExpressionNode *left, ExpressionNode *right)
    : BinaryOperatorNode(left, right) {}

int GreaterEqualNode::Evaluate(){
    return this->mLeft->Evaluate() >= this->mRight->Evaluate();
}

EqualNode::EqualNode(ExpressionNode *left, ExpressionNode *right)
    : BinaryOperatorNode(left, right) {}

int EqualNode::Evaluate(){
    return this->mLeft->Evaluate() == this->mRight->Evaluate();
}

NotEqualNode::NotEqualNode(ExpressionNode *left, ExpressionNode *right)
    : BinaryOperatorNode(left, right) {}

int NotEqualNode::Evaluate(){
    return this->mLeft->Evaluate() != this->mRight->Evaluate();
}
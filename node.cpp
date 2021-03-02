#include <iostream>
#include "node.h"

Node::~Node(){}

StartNode::StartNode(ProgramNode *ProgramNode)
    : mProgramNode(ProgramNode) {}

StartNode::~StartNode(){
    delete this->mProgramNode;
};

void StartNode::Interpret(){
    this->mProgramNode->Interpret();
};


ProgramNode::ProgramNode(BlockNode *BlockNode)
    : mBlockNode(BlockNode) {}

ProgramNode::~ProgramNode(){
    delete this->mBlockNode;
};

void ProgramNode::Interpret(){
    this->mBlockNode->Interpret();
};

BlockNode::BlockNode(StatementGroupNode *StatementGroupNode)
    : mStatementGroupNode(StatementGroupNode) {}

BlockNode::~BlockNode(){
    delete this->mStatementGroupNode;
};

void BlockNode::Interpret(){
    this->mStatementGroupNode->Interpret();
};

StatementGroupNode::StatementGroupNode()
    : mStatementNodes(std::vector<StatementNode*>{}) {}

StatementGroupNode::~StatementGroupNode(){
    for ( auto n : this->mStatementNodes ) {
        delete n;
    }
};

void StatementGroupNode::Interpret(){
    for ( auto n : this->mStatementNodes ) {
        n->Interpret();
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

void DeclarationStatementNode::Interpret() {
    this->mIdentifierNode->DeclareVariable();
};

DeclarationAssignmentStatementNode::DeclarationAssignmentStatementNode(IdentifierNode* IdentifierNode, ExpressionNode* ExpressionNode)
    : DeclarationStatementNode(IdentifierNode), mExpressionNode(ExpressionNode) {}

DeclarationAssignmentStatementNode::~DeclarationAssignmentStatementNode() {
    delete this->mExpressionNode;
};

void DeclarationAssignmentStatementNode::Interpret() {
    this->mIdentifierNode->DeclareVariable();
    int val = this->mExpressionNode->Evaluate();
    this->mIdentifierNode->SetValue(val);
};

AssignmentStatementNode::AssignmentStatementNode(IdentifierNode* IdentifierNode, ExpressionNode* ExpressionNode)
    : mIdentifierNode(IdentifierNode), mExpressionNode(ExpressionNode) {}

AssignmentStatementNode::~AssignmentStatementNode() {
    delete this->mIdentifierNode;
    delete this->mExpressionNode;
};

void AssignmentStatementNode::Interpret() {
    int val = this->mExpressionNode->Evaluate();
    this->mIdentifierNode->SetValue(val);
};

IfStatementNode::IfStatementNode(ExpressionNode* ExpressionNode, BlockNode* BlockNode)
    : mExpressionNode(ExpressionNode), mBlockNode(BlockNode) {}

IfStatementNode::~IfStatementNode() {
    delete this->mExpressionNode;
    delete this->mBlockNode;
};

void IfStatementNode::Interpret() {
    if ( this->mExpressionNode->Evaluate()) {
        this->mBlockNode->Interpret();
    }
};

WhileStatementNode::WhileStatementNode(ExpressionNode* ExpressionNode, BlockNode* BlockNode)
    : mExpressionNode(ExpressionNode), mBlockNode(BlockNode) {}

WhileStatementNode::~WhileStatementNode() {
    delete this->mExpressionNode;
    delete this->mBlockNode;
}

void WhileStatementNode::Interpret() {
    while( this->mExpressionNode->Evaluate()) {
        this->mBlockNode->Interpret();
    }
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

void ForStatementNode::Interpret() {
    this->mInitializer->Interpret();
    while ( this->mComparison->Evaluate()) {
        this->mBlockNode->Interpret();
        this->mIncrementer->Interpret();
    }
}

CoutStatementNode::CoutStatementNode( ExpressionNode *ExpressionNode )
    : mExpressionNode( ExpressionNode ){}
CoutStatementNode::~CoutStatementNode() {
    delete this->mExpressionNode;
}

void CoutStatementNode::Interpret() {
    int val = this->mExpressionNode->Evaluate();
    std::cout << val << std::endl;
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

int IdentifierNode::Evaluate(){
    return this->mTable->GetValue(this->mLabel);
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

BitwiseAndNode::BitwiseAndNode(ExpressionNode* left, ExpressionNode* right)
    : BinaryOperatorNode(left, right) {}

int BitwiseAndNode::Evaluate() {
    return this->mLeft->Evaluate() & this->mRight->Evaluate();
}

BitwiseOrNode::BitwiseOrNode(ExpressionNode* left, ExpressionNode* right)
    : BinaryOperatorNode(left, right) {}

int BitwiseOrNode::Evaluate() {
    return this->mLeft->Evaluate() | this->mRight->Evaluate();
}

AndNode::AndNode(ExpressionNode* left, ExpressionNode* right)
    : BinaryOperatorNode(left, right) {}

int AndNode::Evaluate() {
    return this->mLeft->Evaluate() && this->mRight->Evaluate();
}

OrNode::OrNode(ExpressionNode* left, ExpressionNode* right)
    : BinaryOperatorNode(left, right) {}

int OrNode::Evaluate() {
    return this->mLeft->Evaluate() || this->mRight->Evaluate();
}
#include "Scanner.h"
#include "StateMachine.h"
#include "Token.h"

ScannerClass::ScannerClass(const string &inputFileName)
{
    mLineNumber = 1;
    mFin.open(inputFileName.c_str(), ios::binary);
    if (!mFin.is_open())
    {
        cout << "failed to open " << inputFileName << '\n';
    }
}
ScannerClass::~ScannerClass() { mFin.close(); }

int ScannerClass::GetLineNumber()
{
    return mLineNumber;
}

TokenClass ScannerClass::GetNextToken()
{
    StateMachineClass stateMachine;
    MachineState currentState;
    TokenType type;
    string lexeme;
    char c;
    do
    {
        c = mFin.get();
        if (c == '\n')
        {
            mLineNumber += 1;
        }
        lexeme += c;
        currentState = stateMachine.UpdateState(c, type);
        if (currentState == START_STATE)
        {
            lexeme = "";
        }
    } while (currentState != CANTMOVE_STATE);
    if (!lexeme.empty())
    {
        lexeme.erase(lexeme.size() - 1);
    }
    TokenClass token(type, lexeme);
    lexeme = "";
    mFin.unget();
    if (c == '\n')
        mLineNumber -= 1;
    token.CheckReserved();
    return token;
}

TokenClass ScannerClass::PeekNextToken() {
    std::streampos pos = this->mFin.tellg();
    int line = this->mLineNumber;
    TokenClass t = this->GetNextToken();
    if (!this->mFin) {
        this->mFin.clear();
    }
    this->mFin.seekg(pos);
    this->mLineNumber = line;
    return t;
}
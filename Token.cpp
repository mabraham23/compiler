#include "Token.h"

TokenClass::TokenClass()
{
    mType = BAD_TOKEN;
};

TokenClass::TokenClass(TokenType type, const string &lexeme)
{
    mType = type;
    mLexeme = lexeme;
};

// The CheckReserved method should change the TokenType from IDENTIFIER_TOKEN,
// if mLexeme matches one of the reserved words.  For example, if mLexeme
// is “void” then reset mType to VOID_TOKEN.
void TokenClass::CheckReserved()
{
    if (mLexeme == "void")
    {
        mType = VOID_TOKEN;
    }
    else if (mLexeme == "main")
    {
        mType = MAIN_TOKEN;
    }
    else if (mLexeme == "int")
    {
        mType = INT_TOKEN;
    }
    else if (mLexeme == "cout")
    {
        mType = COUT_TOKEN;
    }
    else if (mLexeme == "while")
    {
        mType = WHILE_TOKEN;
    }
    else if (mLexeme == "for")
    {
        mType = FOR_TOKEN;
    }
    else if (mLexeme == "if")
    {
        mType = IF_TOKEN;
    }
}

ostream &operator<<(ostream &out, const TokenClass &tc)
{
    out.setf(ios::left);
    out << "Type: " << setw(15) << tc.GetTokenTypeName() << "Lexeme: " << setw(15) << tc.GetLexeme();
    return out;
}

// Complete Token.cpp by providing implementations for the TokenClass constructors
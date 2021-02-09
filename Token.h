#ifndef TOKEN
#define TOKEN
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// TokenType[VOID_TOKEN] = 0
enum TokenType
{
    // Reserved Words:
    VOID_TOKEN,
    MAIN_TOKEN,
    INT_TOKEN,
    COUT_TOKEN,
    // Relational Operators:
    LESS_TOKEN,
    LESSEQUAL_TOKEN,
    GREATER_TOKEN,
    GREATEREQUAL_TOKEN,
    EQUAL_TOKEN,
    NOTEQUAL_TOKEN,
    // Other Operators:
    INSERTION_TOKEN,
    ASSIGNMENT_TOKEN,
    PLUS_TOKEN,
    MINUS_TOKEN,
    TIMES_TOKEN,
    DIVIDE_TOKEN,
    // Other Characters:
    SEMICOLON_TOKEN,
    LPAREN_TOKEN,
    RPAREN_TOKEN,
    LCURLY_TOKEN,
    RCURLY_TOKEN,
    // Other Token Types:
    IDENTIFIER_TOKEN,
    INTEGER_TOKEN,
    BAD_TOKEN,
    ENDFILE_TOKEN
};

// IMPORTANT: The list above and the list below MUST be kept in sync.
// Then you can access the name given the enum using: gTokenTypeNames[mType].
const string gTokenTypeNames[] = {
    "VOID",
    "MAIN",
    "INT",
    "COUT",
    "LESS",
    "LESSEQUAL",
    "GREATER",
    "GREATEREQUAL",
    "EQUAL",
    "NOTEQUAL",
    "INSERTION",
    "ASSIGNMENT",
    "PLUS",
    "MINUS",
    "TIMES",
    "DIVIDE",
    "SEMICOLON",
    "LPAREN",
    "RPAREN",
    "LCURLY",
    "RCURLY",
    "IDENTIFIER",
    "INTEGER",
    "BAD",
    "ENDFILE"};

class TokenClass
{
private:
    TokenType mType;
    string mLexeme;

public:
    TokenClass();
    TokenClass(TokenType type, const string &lexeme);
    TokenType GetTokenType() const { return mType; }
    const string &GetTokenTypeName() const
    {
        return gTokenTypeNames[mType];
    }
    string GetLexeme() const { return mLexeme; }
    void CheckReserved();
    static const string &GetTokenTypeName(TokenType type)
    {
        return gTokenTypeNames[type];
    }
};

inline bool isInteger(const string &s);
ostream &operator<<(ostream &out, const TokenClass &tc);

#endif // TOKEN
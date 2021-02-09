#ifndef STATE_MACHINE
#define STATE_MACHINE
#include "Token.h"

enum MachineState
{
    START_STATE,
    IDENTIFIER_STATE,
    LETTER_STATE,
    DIGIT_STATE,
    WHITESPACE_STATE,
    BLOCKCOMMENT_MIDDLE_STATE,
    BLOCKCOMMENT_NOTDONE_STATE,
    SLASHCOMMENT_STATE,
    PLUS_STATE,
    MINUS_STATE,
    TIMES_STATE,
    DIVIDE_STATE,
    LESS_STATE,
    GREATER_STATE,
    EQUAL_STATE,
    INTEGER_STATE,
    SEMICOLON_STATE,
    LPAREN_STATE,
    RPAREN_STATE,
    LCURLY_STATE,
    RCURLY_STATE,
    INSERTION_STATE,
    EOF_STATE,
    CANTMOVE_STATE,
    LAST_STATE
};

enum CharacterType
{
    LETTER_CHAR,
    DIGIT_CHAR,
    WHITESPACE_CHAR,
    PLUS_CHAR,
    MINUS_CHAR,
    TIMES_CHAR,
    DIVIDE_CHAR,
    LESS_CHAR,
    GREATER_CHAR,
    EQUAL_CHAR,
    SEMICOLON_CHAR,
    LPAREN_CHAR,
    RPAREN_CHAR,
    LCURLY_CHAR,
    RCURLY_CHAR,
    INSERTION_CHAR,
    NEWLINE_CHAR,
    EOF_CHAR,
    BAD_CHAR,
    LAST_CHAR
};

class StateMachineClass
{
public:
    StateMachineClass();
    MachineState UpdateState(char currentCharacter, TokenType &correspondingTokenType);

private:
    MachineState mCurrentState;

    // The matrix of legal moves:
    MachineState mLegalMoves[LAST_STATE][LAST_CHAR];

    // Which end-machine-states correspond to which token types.
    // (non end states correspond to the BAD_TOKEN token type)
    TokenType mCorrespondingTokenTypes[LAST_STATE];
};

#endif // STATE_MACHINE
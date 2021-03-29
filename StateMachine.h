#ifndef STATE_MACHINE
#define STATE_MACHINE
#include "Token.h"

enum MachineState
{
    START_STATE,
    ASSIGNMENT_STATE,
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
    LESS_EQUAL_STATE,
    GREATER_STATE,
    GREATER_EQUAL_STATE,
    NOT_EQUAL_STATE,
    BITWISE_AND_STATE,
    BITWISE_OR_STATE,
    NOT_STATE,
    AND_STATE,
    OR_STATE,
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
    NOT_CHAR,
    AND_CHAR,
    OR_CHAR,
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
    MachineState mLegalMoves[LAST_STATE][LAST_CHAR];
    TokenType mCorrespondingTokenTypes[LAST_STATE];
};

#endif // STATE_MACHINE
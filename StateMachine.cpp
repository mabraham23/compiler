#include "StateMachine.h"

StateMachineClass::StateMachineClass()
{
    mCurrentState = START_STATE;
    for (int i = 0; i < LAST_STATE; i++)
    {
        for (int j = 0; j < LAST_CHAR; j++)
        {
            mLegalMoves[i][j] = CANTMOVE_STATE;
        }
    }
    mLegalMoves[START_STATE][DIGIT_CHAR] = INTEGER_STATE;
    mLegalMoves[INTEGER_STATE][DIGIT_CHAR] = INTEGER_STATE;
    mLegalMoves[START_STATE][PLUS_CHAR] = PLUS_STATE;
    mLegalMoves[START_STATE][MINUS_CHAR] = MINUS_STATE;
    mLegalMoves[START_STATE][SEMICOLON_CHAR] = SEMICOLON_STATE;
    mLegalMoves[START_STATE][LESS_CHAR] = LESS_STATE;
    mLegalMoves[LESS_STATE][LESS_CHAR] = INSERTION_STATE;
    mLegalMoves[START_STATE][LPAREN_CHAR] = LPAREN_STATE;
    mLegalMoves[START_STATE][RPAREN_CHAR] = RPAREN_STATE;
    mLegalMoves[START_STATE][LCURLY_CHAR] = LCURLY_STATE;
    mLegalMoves[START_STATE][RCURLY_CHAR] = RCURLY_STATE;
    mLegalMoves[START_STATE][LETTER_CHAR] = LETTER_STATE;
    mLegalMoves[LETTER_STATE][LETTER_CHAR] = LETTER_STATE;
    mLegalMoves[LETTER_STATE][DIGIT_CHAR] = IDENTIFIER_STATE;
    mLegalMoves[START_STATE][DIGIT_CHAR] = DIGIT_STATE;
    mLegalMoves[DIGIT_STATE][DIGIT_CHAR] = DIGIT_STATE;
    mLegalMoves[START_STATE][EQUAL_CHAR] = ASSIGNMENT_STATE;
    mLegalMoves[ASSIGNMENT_STATE][EQUAL_CHAR] = EQUAL_STATE;
    mLegalMoves[START_STATE][EOF_CHAR] = EOF_STATE;
    mLegalMoves[START_STATE][WHITESPACE_CHAR] = START_STATE;
    mLegalMoves[START_STATE][TIMES_CHAR] = TIMES_STATE;
    mLegalMoves[START_STATE][DIVIDE_CHAR] = DIVIDE_STATE;
    mLegalMoves[DIVIDE_STATE][DIVIDE_CHAR] = SLASHCOMMENT_STATE;
    for (int j = 0; j < LAST_CHAR; j++)
    {
        mLegalMoves[SLASHCOMMENT_STATE][j] = SLASHCOMMENT_STATE;
    }
    mLegalMoves[SLASHCOMMENT_STATE][NEWLINE_CHAR] = START_STATE;
    mLegalMoves[SLASHCOMMENT_STATE][EOF_CHAR] = EOF_STATE;

    mLegalMoves[DIVIDE_STATE][TIMES_CHAR] = BLOCKCOMMENT_MIDDLE_STATE;
    for (int j = 0; j < LAST_CHAR; j++)
    {
        mLegalMoves[BLOCKCOMMENT_MIDDLE_STATE][j] = BLOCKCOMMENT_MIDDLE_STATE;
    }
    mLegalMoves[BLOCKCOMMENT_MIDDLE_STATE][TIMES_CHAR] = BLOCKCOMMENT_NOTDONE_STATE;
    mLegalMoves[BLOCKCOMMENT_NOTDONE_STATE][TIMES_CHAR] = BLOCKCOMMENT_NOTDONE_STATE;
    for (int j = 0; j < LAST_CHAR; j++)
    {
        mLegalMoves[BLOCKCOMMENT_NOTDONE_STATE][j] = BLOCKCOMMENT_MIDDLE_STATE;
    }
    mLegalMoves[BLOCKCOMMENT_NOTDONE_STATE][DIVIDE_CHAR] = START_STATE;


    mLegalMoves[START_STATE][NEWLINE_CHAR] = START_STATE;

    mLegalMoves[START_STATE][LESS_CHAR] = LESS_STATE;
    mLegalMoves[LESS_STATE][EQUAL_CHAR] = LESS_EQUAL_STATE;
    mLegalMoves[START_STATE][GREATER_CHAR] = GREATER_STATE;
    mLegalMoves[GREATER_STATE][EQUAL_CHAR] = GREATER_EQUAL_STATE;
    mLegalMoves[START_STATE][NOT_CHAR] = NOT_STATE;
    mLegalMoves[NOT_STATE][EQUAL_CHAR] = NOT_EQUAL_STATE;
    mLegalMoves[IDENTIFIER_STATE][DIGIT_CHAR] = IDENTIFIER_STATE;
    mLegalMoves[IDENTIFIER_STATE][LETTER_CHAR] = IDENTIFIER_STATE;

    mLegalMoves[START_STATE][AND_CHAR] = BITWISE_AND_STATE;
    mLegalMoves[BITWISE_AND_STATE][AND_CHAR] = AND_STATE;

    mLegalMoves[START_STATE][OR_CHAR] = BITWISE_OR_STATE;
    mLegalMoves[BITWISE_OR_STATE][OR_CHAR] = OR_STATE;

    mLegalMoves[START_STATE][NOT_CHAR] = NOT_STATE;

    // First, initialize all states to correspond to the BAD token type.
    // Then, reset the end states to correspond to the correct token types.
    for (int i = 0; i < LAST_STATE; i++)
    {
        mCorrespondingTokenTypes[i] = BAD_TOKEN;
    }
    mCorrespondingTokenTypes[IDENTIFIER_STATE] = IDENTIFIER_TOKEN;
    mCorrespondingTokenTypes[INTEGER_STATE] = INTEGER_TOKEN;
    mCorrespondingTokenTypes[PLUS_STATE] = PLUS_TOKEN;
    mCorrespondingTokenTypes[MINUS_STATE] = MINUS_TOKEN;
    mCorrespondingTokenTypes[DIVIDE_STATE] = DIVIDE_TOKEN;
    mCorrespondingTokenTypes[TIMES_STATE] = TIMES_TOKEN;
    mCorrespondingTokenTypes[SEMICOLON_STATE] = SEMICOLON_TOKEN;
    mCorrespondingTokenTypes[LESS_STATE] = LESS_TOKEN;
    mCorrespondingTokenTypes[GREATER_STATE] = GREATER_TOKEN;
    mCorrespondingTokenTypes[GREATER_EQUAL_STATE] = GREATER_EQUAL_TOKEN;
    mCorrespondingTokenTypes[LESS_EQUAL_STATE] = LESS_EQUAL_TOKEN;
    mCorrespondingTokenTypes[INSERTION_STATE] = INSERTION_TOKEN;
    mCorrespondingTokenTypes[LPAREN_STATE] = LPAREN_TOKEN;
    mCorrespondingTokenTypes[RPAREN_STATE] = RPAREN_TOKEN;
    mCorrespondingTokenTypes[LCURLY_STATE] = LCURLY_TOKEN;
    mCorrespondingTokenTypes[RCURLY_STATE] = RCURLY_TOKEN;
    mCorrespondingTokenTypes[LETTER_STATE] = IDENTIFIER_TOKEN;
    mCorrespondingTokenTypes[DIGIT_STATE] = INTEGER_TOKEN;
    mCorrespondingTokenTypes[ASSIGNMENT_STATE] = ASSIGNMENT_TOKEN;
    mCorrespondingTokenTypes[EQUAL_STATE] = EQUAL_TOKEN;
    mCorrespondingTokenTypes[NOT_EQUAL_STATE] = NOTEQUAL_TOKEN;
    mCorrespondingTokenTypes[NOT_STATE] = NOT_TOKEN;
    mCorrespondingTokenTypes[AND_STATE] = AND_TOKEN;
    mCorrespondingTokenTypes[OR_STATE] = OR_TOKEN;
    mCorrespondingTokenTypes[BITWISE_OR_STATE] = BITWISE_OR_TOKEN;
    mCorrespondingTokenTypes[BITWISE_AND_STATE] = BITWISE_AND_TOKEN;
    mCorrespondingTokenTypes[EOF_STATE] = ENDFILE_TOKEN;
}

MachineState StateMachineClass::UpdateState(char currentCharacter, TokenType &correspondingTokenType)
{
    // convert the input character into an input character type
    CharacterType charType = BAD_CHAR;

    if (isdigit(currentCharacter))
        charType = DIGIT_CHAR;
    if (isalpha(currentCharacter))
        charType = LETTER_CHAR;
    if (isspace(currentCharacter))
        charType = WHITESPACE_CHAR;
    if (currentCharacter == '\n')
        charType = NEWLINE_CHAR;
    if (currentCharacter == '+')
        charType = PLUS_CHAR;
    if (currentCharacter == '-')
        charType = MINUS_CHAR;
    if (currentCharacter == '*')
        charType = TIMES_CHAR;
    if (currentCharacter == '/')
        charType = DIVIDE_CHAR;
    if (currentCharacter == '<')
        charType = LESS_CHAR;
    if (currentCharacter == '=')
        charType = EQUAL_CHAR;
    if (currentCharacter == '>')
        charType = GREATER_CHAR;
    if (currentCharacter == ';')
        charType = SEMICOLON_CHAR;
    if (currentCharacter == '(')
        charType = LPAREN_CHAR;
    if (currentCharacter == ')')
        charType = RPAREN_CHAR;
    if (currentCharacter == '{')
        charType = LCURLY_CHAR;
    if (currentCharacter == '}')
        charType = RCURLY_CHAR;
    if (currentCharacter == '&')
        charType = AND_CHAR;
    if (currentCharacter == '|')
        charType = OR_CHAR;
    if (currentCharacter == '!')
        charType = NOT_CHAR;
    if (currentCharacter == EOF)
        charType = EOF_CHAR;

    correspondingTokenType = mCorrespondingTokenTypes[mCurrentState];
    mCurrentState = mLegalMoves[mCurrentState][charType];
    return mCurrentState;
}
#ifndef SCANNER
#define SCANNER
#include <fstream>
#include "Token.h"

using namespace std;

class ScannerClass
{
private:
    ifstream mFin;
    int mLineNumber;

public:
    ScannerClass(const string &in_file);
    ~ScannerClass();
    TokenClass GetNextToken();
    TokenClass PeekNextToken();
    int GetLineNumber();
};

#endif // SCANNER
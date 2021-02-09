#include "Token.h"
#include "Scanner.h"
#include <iostream>

int main()
{
    ScannerClass scanner("test.txt");
    TokenClass t;
    do
    {
        t = scanner.GetNextToken();
        std::cout << scanner.GetLineNumber() << " " << t << std::endl;
        if (t.GetTokenTypeName() == "BAD")
        {
            std::cout << "Read invalid chacter on line: " << scanner.GetLineNumber() << std::endl;
            return -1;
        }
    } while (t.GetTokenTypeName() != "ENDFILE");
    return 0;
}
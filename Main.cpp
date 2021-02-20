#include "Token.h"
#include "Scanner.h"
#include "node.h"
#include <iostream>

void testNodes() {
    StartNode* start = new StartNode(new ProgramNode(new BlockNode(new StatementGroupNode())));
    std::cout << "deleting start" << std::endl;
    delete start;

    PlusNode* plus = new PlusNode(new IntegerNode(40), new IntegerNode(50));
    std::cout << plus->Evaluate() << std::endl;
    std::cout << "deleting plusNode" << std::endl;
    delete plus;

    LessEqualNode* lte = new LessEqualNode(new IntegerNode(40), new IntegerNode(50));
    std::cout << lte->Evaluate() << std::endl;
    std::cout << "deleting lessEqualNode" << std::endl;
    delete lte;
}

int main()
{
    // ScannerClass scanner("test.txt");
    // TokenClass t;
    // do
    // {
    //     t = scanner.GetNextToken();
    //     std::cout << scanner.GetLineNumber() << " " << t << std::endl;
    //     if (t.GetTokenTypeName() == "BAD")
    //     {
    //         std::cout << "Read invalid chacter on line: " << scanner.GetLineNumber() << std::endl;
    //         return -1;
    //     }
    // } while (t.GetTokenTypeName() != "ENDFILE");
    testNodes();

    return 0;
}
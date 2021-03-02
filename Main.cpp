#include "Token.h"
#include "Scanner.h"
#include "node.h"
#include "Parser.h"
#include "log.h"
#include <iostream>

// void testNodes() {
//     StartNode* start = new StartNode(new ProgramNode(new BlockNode(new StatementGroupNode())));
//     std::cout << "deleting start" << std::endl;
//     delete start;

//     PlusNode* plus = new PlusNode(new IntegerNode(40), new IntegerNode(50));
//     std::cout << plus->Evaluate() << std::endl;
//     std::cout << "deleting plusNode" << std::endl;
//     delete plus;

//     LessEqualNode* lte = new LessEqualNode(new IntegerNode(60), new IntegerNode(50));
//     std::cout << lte->Evaluate() << std::endl;
//     std::cout << "deleting lessEqualNode" << std::endl;
//     delete lte;
// }

// int main()
// {
//     // ScannerClass scanner("test.txt");
//     // TokenClass t;
//     // do
//     // {
//     //     t = scanner.GetNextToken();
//     //     std::cout << scanner.GetLineNumber() << " " << t << std::endl;
//     //     if (t.GetTokenTypeName() == "BAD")
//     //     {
//     //         std::cout << "Read invalid chacter on line: " << scanner.GetLineNumber() << std::endl;
//     //         return -1;
//     //     }
//     // } while (t.GetTokenTypeName() != "ENDFILE");
//     testNodes();

//     return 0;
// }


void interpret(std::string fileName) {
    ScannerClass* scanner = new ScannerClass(fileName);
    SymbolTableClass* table = new SymbolTableClass();
    Parser* parser = new Parser(scanner, table);
    parser->Start()->Interpret();
}

int main(int argc, char const* argv[]) {
    LOG("LOGGING");
    if (argc < 2) {
        std::cout << "No input files provided" << std::endl;
    } else {
        for (int i = 1; i < argc; i++) {
            // printTokens(argv[i]);
            interpret(argv[1]);
        }
    }
    // testNodes();
    // testTokens();
    // machine();
}
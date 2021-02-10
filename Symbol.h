#ifndef SYMBOL
#define SYMBOL
#include <vector>

class SymbolTableClass
{
private:
    struct Variable {
        std::string mLabel;
        int mValue;
    }
    std::vector<Variable> vars;
public:
    bool Exists(const std::string & s); 
        // returns true if <s> is already in the symbol table.
    void AddEntry(const std::string & s); 
        // adds <s> to the symbol table, 
        // or quits if it was already there
    int GetValue(const std::string & s); 
        // returns the current value of variable <s>, when
        // interpreting. Meaningless for Coding and Executing.
        // Prints a message and quits if variable s does not exist.
    void SetValue(const std::string & s, int v); 
        // sets variable <s> to the given value, when interpreting.
        // Meaningless for Coding and Executing.
        // Prints a message and quits if variable s does not exist.
    int GetIndex(const std::string & s); 
        // returns the index of where variable <s> is.
        // returns -1 if variable <s> is not there.
    int GetCount(); 
        // returns the current number of variables in the symbol
        // table. 
}

#endif // SYMBOL
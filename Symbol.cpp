#include "Symbol.h"

SymbolTableClass::SymbolTableClass()
    : sybmolTable(std::vector<Variable>{}) {}

SymbolTableClass::~SymbolTableClass() {}

// returns true if <s> is already in the symbol table.
bool SymbolTableClass::Exists(const std::string &s){
    for ( int i=0; i<sybmolTable.size(); i++) {
        if ( sybmolTable[i].mLabel == s) {
            return false;
        }
    };
    return true;
};

// adds <s> to the symbol table, 
// or quits if it was already there
void SymbolTableClass::AddEntry(const std::string & s){
    Variable var;
    var.mLabel = s;
    if ( Exists(s) == false ) {
        sybmolTable.push_back(var);
    }
    exit(-1);
};

// returns the current value of variable <s>, when
// interpreting. Meaningless for Coding and Executing.
// Prints a message and quits if variable s does not exist.
int SymbolTableClass::GetValue(const std::string & s){
    if ( Exists(s) == false ) {
        std::cout << "No Variable found for string " << s << std::endl;
        exit(-1);
    }
    int i = GetIndex(s);
    return sybmolTable[i].mValue;
    // what to do if there is no value associated with the variable?
}; 

// sets variable <s> to the given value, when interpreting.
// Meaningless for Coding and Executing.
// Prints a message and quits if variable s does not exist.
void SymbolTableClass::SetValue(const std::string & s, int v){
    if ( Exists(s) == false ) {
        std::cout << "No Variable found for string " << s << std::endl;
        exit(-1);
    }
    int i = GetIndex(s);
    sybmolTable[i].mValue = v;
}; 

// returns the index of where variable <s> is.
// returns -1 if variable <s> is not there.
int SymbolTableClass::GetIndex(const std::string & s){
    for ( int i=0; i<sybmolTable.size(); i++) {
        if ( sybmolTable[i].mLabel == s ) {
            return i;
        }
    }
    return -1;
}; 

// returns the current number of variables in the symbol
// table. 
int SymbolTableClass::GetCount(){
    return sybmolTable.size();
};



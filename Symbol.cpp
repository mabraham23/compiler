#include "Symbol.h"

SymbolTableClass::SymbolTableClass()
    : sybmolTable(std::vector<Variable>{}) {}

SymbolTableClass::~SymbolTableClass() {}


bool SymbolTableClass::Exists(const std::string& s) {
    for (auto v : this->sybmolTable) {
        if (v.mLabel == s) {
            return true;
        }
    }
    return false;
}


void SymbolTableClass::AddEntry(const std::string& s) {
    if (!this->Exists(s)) {
        this->sybmolTable.push_back(Variable{ s,0 });
    }
}

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


void SymbolTableClass::SetValue(const std::string& s, int v) {
    int idx = this->GetIndex(s);
    if (idx != -1) {
        this->sybmolTable[idx].mValue = v;
    } else {
        std::cout << "Variable does not exist: " << s << std::endl;
    }
}

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



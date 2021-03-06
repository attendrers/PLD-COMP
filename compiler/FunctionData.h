// Say to the compiler to only compile this class once
#pragma once

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// A class that regroups important data for each function
class FunctionData
{
public:
    unordered_map<string, int> offsets;
    unordered_map<string, int> types;
    vector<string> vars;
    int lastVarPosition;

public:

    FunctionData() : lastVarPosition(0){};

    void addToOffset(string var, int offset){
        offsets[var]=offset;
    }

    void addToTypes(string var,int type){
        types[var] = type;
    }

    void addToVars(string var){
        vars.push_back(var);
    }

    void decrementLastVarPosition(int value){
        lastVarPosition-= value;
    }

    const unordered_map<string, int> & getOffsets(){
        return offsets;
    };

    int getLastVarPosition() {
        return lastVarPosition;
    }

    const unordered_map<string, int> & getTypes(){
        return types;
    };

    const vector<string> & getVars(){
        return vars;
    };
};
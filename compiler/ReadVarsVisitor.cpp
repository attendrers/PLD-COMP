#include "ReadVarsVisitor.h"

antlrcpp::Any ReadVarsVisitor::visitProg(ifccParser::ProgContext *ctx){
    for(auto & line : ctx->line()){
        visit(line);
    }

    int length  = vars.size();
    int current = lastVarPosition;
    for(string & var : vars){
        offsets[var] = current;
        current+= types[var];
    }

    for ( auto it : vars)
    {
        if(!(find(used_vars.begin(), used_vars.end(), it) != used_vars.end()))
        {
            not_used.push_back(it);
        }
    }

    if (not_used.size() != 0)
    {
        cout << "#Warning : (" << not_used.size() << ") not used" << endl;
    }

    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_intconst(ifccParser::Declaration_intconstContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();

    if(!(types[varName]==0)){
        throw out_of_range("Variable ("+varName+") already declared 1");
    }
    vars.push_back(varName);

    int type=(ctx->TYPE()->getText()=="int")?4:1;
    types[varName] = type;
    lastVarPosition -= type;

    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_charconst(ifccParser::Declaration_charconstContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();

    if(!(types[varName]==0)){
        throw out_of_range("Variable ("+varName+") already declared");
    }

    vars.push_back(varName);
    int type=(ctx->TYPE()->getText()=="int")?4:1;
    types[varName] = type;
    lastVarPosition -= type;

    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx) {
    string leftVar = ctx->ALPHANUMERIC().at(0)->getText();
    string rightVar= ctx->ALPHANUMERIC().at(1)->getText();
    
    if(types[rightVar]==0){
        throw out_of_range("Undeclared variable: ("+rightVar+") at variable declaration of: ("+leftVar+")");
    }
    used_vars.push_back(rightVar);
    vars.push_back(leftVar);

    int type=(ctx->TYPE()->getText()=="int")?4:1;
    types[leftVar] = type;
    lastVarPosition -= type;

    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();
    vars.push_back(varName);
    int type=(ctx->TYPE()->getText()=="int")?4:1;
    types[varName] = type;
    lastVarPosition -= type;
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitReturn_variable(ifccParser::Return_variableContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();

    if(types[varName]==0){
        throw out_of_range("Undeclared variable: ("+varName+") at final return");
    }

    used_vars.push_back(varName);

    return 0;
    
};

antlrcpp::Any ReadVarsVisitor::visitVariable(ifccParser::VariableContext *ctx){
    string varName = ctx->ALPHANUMERIC()->getText();
    used_vars.push_back(varName);
}

unordered_map <string,int> ReadVarsVisitor::getOffsets(){
    return offsets;
};

int ReadVarsVisitor::getLastVarPosition(){
    return lastVarPosition;
}

unordered_map <string,int> ReadVarsVisitor::getTypes(){
    return types;
};


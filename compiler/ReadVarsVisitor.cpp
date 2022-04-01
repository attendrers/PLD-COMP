#include "ReadVarsVisitor.h"

#include <algorithm>

antlrcpp::Any ReadVarsVisitor::visitProg(ifccParser::ProgContext *ctx){
    for(auto & line : ctx->line()){
        visit(line);
    }

    int length  = vars.size();
    for(int i=0; i<length ; i++){
        offsets[vars[i]] = -(length -i)*4;
    }
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_const(ifccParser::Declaration_constContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();
    vars.push_back(varName);
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx) {
    string leftVar = ctx->ALPHANUMERIC().at(0)->getText();
    string rightVar= ctx->ALPHANUMERIC().at(1)->getText();

    vector<string>::iterator it = find(vars.begin(),vars.end(),leftVar);
    if(it==vars.end()){
        throw out_of_range("Undeclared variable: ("+rightVar+") at variable declaration of: ("+leftVar+")");
    }

    vars.push_back(leftVar);
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();
    vars.push_back(varName);
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitReturn_variable(ifccParser::Return_variableContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();

     vector<string>::iterator it = find(vars.begin(),vars.end(),varName);
    if(it==vars.end()){
        throw out_of_range("Undeclared variable: ("+varName+") at final return");
    }
    return 0;
    
};

unordered_map <string,int> ReadVarsVisitor::getOffsets(){
    return offsets;
};


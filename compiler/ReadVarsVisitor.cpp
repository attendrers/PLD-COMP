#include "ReadVarsVisitor.h"

antlrcpp::Any ReadVarsVisitor::visitProg(ifccParser::ProgContext *ctx){
    for(auto & line : ctx->line()){
        visit(line);
    }

    int length  = vars.size();
    for(int i=0; i<length ; i++){
        offsets[vars[i]] = -(length -i)*types[vars[i]];
    }
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_intconst(ifccParser::Declaration_intconstContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();
    vars.push_back(varName);

    int type=(ctx->TYPE()->getText()=="int")?4:1;
    types[varName] = type;
    cout<<"types "<<types[varName]<<endl;
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_charconst(ifccParser::Declaration_charconstContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();
    vars.push_back(varName);
    int type=(ctx->TYPE()->getText()=="int")?4:1;
    types[varName] = type;
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx) {
    string leftVar = ctx->ALPHANUMERIC().at(0)->getText();
    string rightVar= ctx->ALPHANUMERIC().at(1)->getText();
    
    if(types[rightVar]==0){
        throw out_of_range("Undeclared variable: ("+rightVar+") at variable declaration of: ("+leftVar+")");
    }
    vars.push_back(leftVar);

    int type=(ctx->TYPE()->getText()=="int")?4:1;
    types[leftVar] = type;
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();
    vars.push_back(varName);
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitReturn_variable(ifccParser::Return_variableContext *ctx) {
    string varName = ctx->ALPHANUMERIC()->getText();

    if(types[varName]==0){
        throw out_of_range("Undeclared variable: ("+varName+") at final return");
    }
    return 0;
    
};

unordered_map <string,int> ReadVarsVisitor::getOffsets(){
    return offsets;
};


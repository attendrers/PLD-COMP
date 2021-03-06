#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "FunctionData.h"
#include <map>

using namespace std;


class ReadVarsVisitor : public ifccBaseVisitor
{
protected:
    // unordered_map<string, int> offsets;
    // unordered_map<string, int> types;
    // vector<string> vars;
    vector<FunctionData*> functionDatas;
    vector<string> used_vars;
    vector<string> not_used;
    // int lastVarPosition;
    int currentIndex;

public:
    ReadVarsVisitor() : ifccBaseVisitor(), currentIndex(0){};

    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;

    virtual antlrcpp::Any visitFunc(ifccParser::FuncContext *ctx) override;

    virtual antlrcpp::Any visitDeclaration_intconst(ifccParser::Declaration_intconstContext *ctx) override;

    virtual antlrcpp::Any visitDeclaration_charconst(ifccParser::Declaration_charconstContext *ctx) override;

    virtual antlrcpp::Any visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx) override;

    virtual antlrcpp::Any visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx) override;

    virtual antlrcpp::Any visitReturn_variable(ifccParser::Return_variableContext *ctx) override;

    virtual antlrcpp::Any visitDeclaration_function_call(ifccParser::Declaration_function_callContext *ctx) override;

    // Affectations

    virtual antlrcpp::Any visitAffectation_intconst(ifccParser::Affectation_intconstContext *ctx) override;

    virtual antlrcpp::Any visitAffectation_charconst(ifccParser::Affectation_charconstContext *ctx) override;

    virtual antlrcpp::Any visitAffectation_variable(ifccParser::Affectation_variableContext *ctx) override;

    virtual antlrcpp::Any visitAffectation_expr(ifccParser::Affectation_exprContext *ctx) override;

    virtual antlrcpp::Any visitAffectation_function_call(ifccParser::Affectation_function_callContext *ctx) override;

    
    virtual antlrcpp::Any visitVariable(ifccParser::VariableContext *ctx) override;

    virtual antlrcpp::Any visitReturn_expr(ifccParser::Return_exprContext *ctx) override {
        return 0;
    }

    vector<FunctionData*> getFunctionDatas(){
        return functionDatas;
    }     

    // unordered_map<string, int> getOffsets();

    // int getLastVarPosition();

    // unordered_map<string, int> getTypes();
};
#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <map>

using namespace std;

class ReadVarsVisitor : public ifccBaseVisitor
{
    protected:
        unordered_map <string,int> offsets;
        unordered_map <string,int> types;
        vector<string> vars;
        vector<string> used_vars;
        vector<string> not_used;
        int lastVarPosition;

    public:
        ReadVarsVisitor(): ifccBaseVisitor(),lastVarPosition(0){};

        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;

        virtual antlrcpp::Any visitDeclaration_intconst(ifccParser::Declaration_intconstContext *ctx) override ;

        virtual antlrcpp::Any visitDeclaration_charconst(ifccParser::Declaration_charconstContext *ctx) override ;

        virtual antlrcpp::Any visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx) override ;

        virtual antlrcpp::Any visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx) override ;

        virtual antlrcpp::Any visitReturn_variable(ifccParser::Return_variableContext *ctx) override ;

        virtual antlrcpp::Any visitVariable(ifccParser::VariableContext *ctx) override;

        unordered_map <string,int> getOffsets();

        int getLastVarPosition();

        unordered_map <string,int> getTypes();

};
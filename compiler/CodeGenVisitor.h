#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include <map>

using namespace std;

class CodeGenVisitor : public ifccBaseVisitor
{

    protected:
        unordered_map <string,int> offsets;
        int i;


    public:
        CodeGenVisitor(unordered_map <string,int> & offsets): ifccBaseVisitor(),offsets(offsets),i(0){};

        CodeGenVisitor(): ifccBaseVisitor(),i(0){};

        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;

        // Declarations
        virtual antlrcpp::Any visitDeclaration_intconst(ifccParser::Declaration_intconstContext *ctx) override ;
        
        virtual antlrcpp::Any visitDeclaration_charconst(ifccParser::Declaration_charconstContext *ctx) override ;

        virtual antlrcpp::Any visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx) override ;

        virtual antlrcpp::Any visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx) override ;


        // Return
        virtual antlrcpp::Any visitReturn(ifccParser::ReturnContext *ctx) override ;

        virtual antlrcpp::Any visitReturn_intconst(ifccParser::Return_intconstContext *ctx) override ;
        
        virtual antlrcpp::Any visitReturn_charconst(ifccParser::Return_charconstContext *ctx) override ;

        virtual antlrcpp::Any visitReturn_variable(ifccParser::Return_variableContext *ctx) override ;

        virtual antlrcpp::Any visitReturn_expr(ifccParser::Return_exprContext *ctx) override ;

        // Expressions
        // virtual antlrcpp::Any visitPlus(ifccParser::PlusContext *ctx) override ;

};

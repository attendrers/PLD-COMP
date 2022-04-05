#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "FunctionData.h"
#include <map>

using namespace std;

class CodeGenVisitor : public ifccBaseVisitor
{

    protected:
        // unordered_map <string,int> offsets;
        // unordered_map <string,int> types;
        // int i;
        // int lastVarPosition;
        vector<FunctionData*> functionDatas;
        int currentIndex;


    public:
        // CodeGenVisitor(unordered_map <string,int> & offsets, unordered_map <string,int> types, int lastVarPosition): ifccBaseVisitor(),offsets(offsets),types(types),i(0),lastVarPosition(lastVarPosition){};

        CodeGenVisitor(vector<FunctionData*> functionDatas): ifccBaseVisitor(),functionDatas(functionDatas),currentIndex(0){}; 

        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;

        virtual antlrcpp::Any visitFunc(ifccParser::FuncContext *ctx) override;

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
        
        virtual antlrcpp::Any visitPar(ifccParser::ParContext *context) override;

        virtual antlrcpp::Any visitPrExpr(ifccParser::PrExprContext *ctx) override ;

        virtual antlrcpp::Any visitOp_infsup(ifccParser::Op_infsupContext *ctx) override ;

        virtual antlrcpp::Any visitOp_equalornot(ifccParser::Op_equalornotContext *ctx) override ;

        virtual antlrcpp::Any visitOp_not(ifccParser::Op_notContext *ctx) override ;

        virtual antlrcpp::Any visitOp_opposite(ifccParser::Op_oppositeContext *ctx) override ;

        virtual antlrcpp::Any visitOp_muldiv(ifccParser::Op_muldivContext *ctx) override ;

        virtual antlrcpp::Any visitOp_plusmoins(ifccParser::Op_plusmoinsContext *ctx) override ;

        virtual antlrcpp::Any visitOp_bit(ifccParser::Op_bitContext *ctx) override ;

        virtual antlrcpp::Any visitInt(ifccParser::IntContext *ctx) override ;


        // primaryexpr
        virtual antlrcpp::Any visitChar(ifccParser::CharContext *ctx) override ;

        virtual antlrcpp::Any visitVariable(ifccParser::VariableContext *ctx) override ;

        // functions

        virtual antlrcpp::Any visitFunction_call(ifccParser::Function_callContext *ctx) override;

        virtual antlrcpp::Any visitLine_function_call(ifccParser::Line_function_callContext *ctx) override;

        virtual antlrcpp::Any visitDeclaration_function_call(ifccParser::Declaration_function_callContext *ctx) override;

};
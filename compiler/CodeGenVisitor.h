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
        int blocIndex;
        bool fin;


    public:
        // CodeGenVisitor(unordered_map <string,int> & offsets, unordered_map <string,int> types, int lastVarPosition): ifccBaseVisitor(),offsets(offsets),types(types),i(0),lastVarPosition(lastVarPosition){};

        CodeGenVisitor(vector<FunctionData*> functionDatas): ifccBaseVisitor(),functionDatas(functionDatas),fin(false),currentIndex(0),blocIndex(0){}; 

        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;

        virtual antlrcpp::Any visitFunc(ifccParser::FuncContext *ctx) override;

        virtual antlrcpp::Any visitBloc(ifccParser::BlocContext *ctx) override;

        // Declarations
        virtual antlrcpp::Any visitDeclaration_intconst(ifccParser::Declaration_intconstContext *ctx) override ;
        
        virtual antlrcpp::Any visitDeclaration_charconst(ifccParser::Declaration_charconstContext *ctx) override ;

        virtual antlrcpp::Any visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx) override ;

        virtual antlrcpp::Any visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx) override ;


        // Affectations

        virtual antlrcpp::Any visitAffectation_intconst(ifccParser::Affectation_intconstContext *ctx) override;

        virtual antlrcpp::Any visitAffectation_charconst(ifccParser::Affectation_charconstContext *ctx) override;

        virtual antlrcpp::Any visitAffectation_variable(ifccParser::Affectation_variableContext *ctx) override;

        virtual antlrcpp::Any visitAffectation_expr(ifccParser::Affectation_exprContext *ctx) override;

        virtual antlrcpp::Any visitAffectation_function_call(ifccParser::Affectation_function_callContext *ctx) override;

        // Conditions
        virtual antlrcpp::Any visitComp_infsup(ifccParser::Comp_infsupContext *ctx) override ;

        virtual antlrcpp::Any visitComp_equalornot(ifccParser::Comp_equalornotContext *ctx) override ;

        virtual antlrcpp::Any visitComp2_infsup(ifccParser::Comp2_infsupContext *ctx) override ;

        virtual antlrcpp::Any visitComp2_equalornot(ifccParser::Comp2_equalornotContext *ctx) override ;

        // Statements
        virtual antlrcpp::Any visitStatement_if(ifccParser::Statement_ifContext *ctx) override ;

        virtual antlrcpp::Any visitStatement_while(ifccParser::Statement_whileContext *ctx) override ;

        // Return
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

        // primaryexpr
        virtual antlrcpp::Any visitChar(ifccParser::CharContext *ctx) override ;

        virtual antlrcpp::Any visitVariable(ifccParser::VariableContext *ctx) override ;

        virtual antlrcpp::Any visitInt(ifccParser::IntContext *context) override;

        // functions

        virtual antlrcpp::Any visitFunction_call(ifccParser::Function_callContext *ctx) override;

        virtual antlrcpp::Any visitDeclaration_function_call(ifccParser::Declaration_function_callContext *ctx) override;

        virtual antlrcpp::Any visitF_int(ifccParser::F_intContext *ctx) override;

        virtual antlrcpp::Any visitF_char(ifccParser::F_charContext *ctx) override;

        virtual antlrcpp::Any visitF_variable(ifccParser::F_variableContext *ctx) override;

};

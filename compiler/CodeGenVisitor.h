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

class ExprVisitor : public ifccBaseVisitor {
	protected:
        int i;
        string assemblerText;
        unordered_map <string,int> offsets;
	public:
		ExprVisitor(unordered_map <string,int> & offsets):offsets(offsets);

		virtual antlrcpp::Any CodeGenVisitor::visitPar(ifccParser::ParContext *context);

		virtual antlrcpp::Any CodeGenVisitor::visitMinus(ifccParser::MinusContext *context);

		virtual antlrcpp::Any CodeGenVisitor::visitMuldiv(ifccParser::MuldivContext *context);

		virtual antlrcpp::Any CodeGenVisitor::visitCONST(ifccParser::CONSTContext *context);

		virtual antlrcpp::Any CodeGenVisitor::visitPlus(ifccParser::PlusContext *context);

		virtual antlrcpp::Any CodeGenVisitor::visitOp_or(ifccParser::Op_orContext *context) override;

		virtual antlrcpp::Any CodeGenVisitor::visitOp_and(ifccParser::Op_andContext *context) override;

		virtual antlrcpp::Any CodeGenVisitor::visitOp_xor(ifccParser::Op_xorContext *context) override;

		virtual antlrcpp::Any CodeGenVisitor::visitOp_equal(ifccParser::Op_equalContext *context) override;

		virtual antlrcpp::Any CodeGenVisitor::visitOp_not_equal(ifccParser::Op_not_equalContext *context) override;

		virtual antlrcpp::Any CodeGenVisitor::visitOp_sup(ifccParser::Op_supContext *context) override;

		virtual antlrcpp::Any CodeGenVisitor::visitOp_inf(ifccParser::Op_infContext *context) override;

		virtual antlrcpp::Any CodeGenVisitor::visitALPHANUMERIC(ifccParser::ALPHANUMERICContext *context);

		virtual antlrcpp::Any CodeGenVisitor::visitOp_opposite(ifccParser::Op_oppositeContext *context) override;

		virtual antlrcpp::Any CodeGenVisitor::visitOp_not(ifccParser::Op_notContext *context) override;

		antlrcpp::Any CodeGenVisitor::visitAxiom(ifccParser::AxiomContext *context);

		antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *context);

		antlrcpp::Any CodeGenVisitor::visitLine(ifccParser::LineContext *context);

};

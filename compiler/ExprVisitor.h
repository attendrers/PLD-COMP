#pragma once
#include "generated/ifccBaseVisitor.h"
#include "CodeGenVisitor.h"

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

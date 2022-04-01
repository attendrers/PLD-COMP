
// Generated from ifcc.g4 by ANTLR 4.9.2

#pragma once
#include "generated/ifccBaseVisitor.h"
#include <string>
#include "CodeGenVisitor.h"
#include "ExprVisitor.h"
using namespace std;

/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ExprVisitor : public ifccBaseVisitor {
	public:

	  /**
	   * Visit parse trees produced by ifccParser.
	   */

	    ExprVisitor(unordered_map <string,int> & offsets):offsets(offsets){
	        ifccBaseVisitor();
	        i=-1;
	    }

	    antlrcpp::Any CodeGenVisitor::visitPar(ifccParser::ParContext *context){
	        return visit(context->expr())   ;
	    };

	    antlrcpp::Any CodeGenVisitor::visitMinus(ifccParser::MinusContext *context){
	        string tmp0 = (string) visit(context->expr(0));
	        string tmp1 = (string) visit(context->expr(1));
	        assemblerText+="        movl    "+tmp0+", %edx\n";
	        assemblerText+="        movl    "+tmp1+", %eax\n";
	        assemblerText+="        subl	%edx, %eax\n";
	        // i++;
	        // return string("#tmp"+to_string(i));
	        return string("%eax");
	    };

	    antlrcpp::Any CodeGenVisitor::visitMuldiv(ifccParser::MuldivContext *context) {
	        string tmp0 = (string) visit(context->expr(0));
	        string tmp1 = (string) visit(context->expr(1));
	        char op = context->OP()->getText()[0];
	        if(op=='*'){
	            assemblerText+="        movl    "+tmp0+", %edx\n";
	            assemblerText+="        movl    "+tmp1+", %eax\n";
	            assemblerText+="        imul	%edx, %eax\n";
	        }
	        else{
	            assemblerText+="        movl    "+tmp0+", %eax\n";
	            assemblerText+="        cltd\n";
	            // %edx is used by the cltd command so we're gonna use %ebx instead it's a 32bits register just like %eax and %edx
	            assemblerText+="        movl    "+tmp1+", %ebx\n";
	            assemblerText+="        idivl	%ebx \n";
	        }
	        // i++;
	        // return string("#tmp"+to_string(i));
	        return string("%eax");
	    }

	    antlrcpp::Any CodeGenVisitor::visitCONST(ifccParser::CONSTContext *context) {
	        // i++;
	        // return string("#tmp"+to_string(i));
	        return string("$"+context->CONST()->getText());
	    }

	    antlrcpp::Any CodeGenVisitor::visitPlus(ifccParser::PlusContext *context){
	        string tmp0 = (string) visit(context->expr(0));
	        string tmp1 = (string) visit(context->expr(1));
	        assemblerText+="        movl    "+tmp0+", %edx\n";
	        assemblerText+="        movl    "+tmp1+", %eax\n";
	        assemblerText+="        addl	%edx, %eax\n";
	        // i++;
	        // return string("#tmp"+to_string(i));
	        return string("%eax");
	    }

	    antlrcpp::Any CodeGenVisitor::visitOp_or(ifccParser::Op_orContext *context) override {
	     string tmp0 = (string) visit(context->expr(0));
	        string tmp1 = (string) visit(context->expr(1));
	        assemblerText+="        movl    "+tmp0+", %edx\n";
	        assemblerText+="        movl    "+tmp1+", %eax\n";
	        assemblerText+="        orl	%edx, %eax\n";
	        // i++;
	        // return string("#tmp"+to_string(i));
	        return string("%eax");
	    }

	    antlrcpp::Any CodeGenVisitor::visitOp_and(ifccParser::Op_andContext *context) override {
	         string tmp0 = (string) visit(context->expr(0));
	        string tmp1 = (string) visit(context->expr(1));
	        assemblerText+="        movl    "+tmp0+", %edx\n";
	        assemblerText+="        movl    "+tmp1+", %eax\n";
	        assemblerText+="        andl	%edx, %eax\n";
	        // i++;
	        // return string("#tmp"+to_string(i));
	        return string("%eax");
	    }

	    antlrcpp::Any CodeGenVisitor::visitOp_xor(ifccParser::Op_xorContext *context) override {
	        string tmp0 = (string) visit(context->expr(0));
	        string tmp1 = (string) visit(context->expr(1));
	        assemblerText+="        movl    "+tmp0+", %edx\n";
	        assemblerText+="        movl    "+tmp1+", %eax\n";
	        assemblerText+="        xorl	%edx, %eax\n";
	        // i++;
	        // return string("#tmp"+to_string(i));
	        return string("%eax");
	    }

	    antlrcpp::Any CodeGenVisitor::visitOp_equal(ifccParser::Op_equalContext *context) override {
	        string tmp0 = (string) visit(context->expr(0));
	        string tmp1 = (string) visit(context->expr(1));
	        assemblerText+="        movl    "+tmp0+", %edx\n";
	        assemblerText+="        movl    "+tmp1+", %eax\n";
		    assemblerText+="        cmpl	%edx, %eax\n";
		    assemblerText+="        sete	%al\n";
		    assemblerText+="        movzbl	%al, %eax\n";
	        return string("%eax");
	    }

	    antlrcpp::Any CodeGenVisitor::visitOp_not_equal(ifccParser::Op_not_equalContext *context) override {
	        string tmp0 = (string) visit(context->expr(0));
	        string tmp1 = (string) visit(context->expr(1));
	        assemblerText+="        movl    "+tmp0+", %edx\n";
	        assemblerText+="        movl    "+tmp1+", %eax\n";
		    assemblerText+="        cmpl	%edx, %eax\n";
		    assemblerText+="        setne	%al\n";
		    assemblerText+="        movzbl	%al, %eax\n";
	        return string("%eax");
	    }

	    antlrcpp::Any CodeGenVisitor::visitOp_sup(ifccParser::Op_supContext *context) override {
	        string tmp0 = (string) visit(context->expr(0));
	        string tmp1 = (string) visit(context->expr(1));
	        assemblerText+="        movl    "+tmp0+", %edx\n";
	        assemblerText+="        movl    "+tmp1+", %eax\n";
		    assemblerText+="        cmpl	%edx, %eax\n";
		    assemblerText+="        setg	%al\n";
		    assemblerText+="        movzbl	%al, %eax\n";
	        return string("%eax");
	    }

	    antlrcpp::Any CodeGenVisitor::visitOp_inf(ifccParser::Op_infContext *context) override {
	        string tmp0 = (string) visit(context->expr(0));
	        string tmp1 = (string) visit(context->expr(1));
	        assemblerText+="        movl    "+tmp0+", %edx\n";
	        assemblerText+="        movl    "+tmp1+", %eax\n";
		    assemblerText+="        cmpl	%edx, %eax\n";
		    assemblerText+="        setl	%al\n";
		    assemblerText+="        movzbl	%al, %eax\n";
	        return string("%eax");
	    }

	    antlrcpp::Any CodeGenVisitor::visitALPHANUMERIC(ifccParser::ALPHANUMERICContext *context){
	        return string(to_string(offsets[context->ALPHANUMERIC()->getText()])+"(%rbp)");
	    }

	    antlrcpp::Any CodeGenVisitor::visitOp_opposite(ifccParser::Op_oppositeContext *context) override {
	        string tmp0 = (string) visit(context->expr());
	        assemblerText+="        movl    "+tmp0+", %eax\n";
		    assemblerText+="        negl	%eax\n";
	        return string("%eax");
	    }

	    antlrcpp::Any CodeGenVisitor::visitOp_not(ifccParser::Op_notContext *context) override {
	        string tmp0 = (string) visit(context->expr());
	        assemblerText+="        cmpl	$0, "+tmp0+"\n";
		    assemblerText+="        sete	%al\n";
		    assemblerText+="        movzbl	%al, %eax\n";
	        return string("%eax");
	    }


	    antlrcpp::Any CodeGenVisitor::visitAxiom(ifccParser::AxiomContext *context){
	        return nullptr;
	    };

	    antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *context){
	        return nullptr;
	    };

	    antlrcpp::Any CodeGenVisitor::visitLine(ifccParser::LineContext *context){
	        return nullptr;
	    };

	    string getAssemblerText(){
	        return assemblerText;
	    }

}


// Generated from ifcc.g4 by ANTLR 4.9.2

#pragma once


#include "generated/ifccBaseVisitor.h"
#include <string>
using namespace std;

/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ExprVisitor : public ifccBaseVisitor {
    protected:
        int i;
        string assemblerText;
        unordered_map <string,int> offsets;
    
public:

  /**
   * Visit parse trees produced by ifccParser.
   */

    ExprVisitor(unordered_map <string,int> & offsets):offsets(offsets){
        ifccBaseVisitor();
        i=-1;
    }

    virtual antlrcpp::Any visitPar(ifccParser::ParContext *context){
        return visit(context->expr())   ;
    };

    virtual antlrcpp::Any visitMinus(ifccParser::MinusContext *context){
        string tmp0 = (string) visit(context->expr(0));
        string tmp1 = (string) visit(context->expr(1));
        assemblerText+="        movl    "+tmp0+", %edx\n";
        assemblerText+="        movl    "+tmp1+", %eax\n";
        assemblerText+="        subl	%edx, %eax\n";
        // i++;
        // return string("#tmp"+to_string(i));
        return string("%eax");
    };

    virtual antlrcpp::Any visitMuldiv(ifccParser::MuldivContext *context) {
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

    virtual antlrcpp::Any visitCONST(ifccParser::CONSTContext *context) {
        // i++;
        // return string("#tmp"+to_string(i));
        return string("$"+context->CONST()->getText());
    }

    virtual antlrcpp::Any visitPlus(ifccParser::PlusContext *context){
        string tmp0 = (string) visit(context->expr(0));
        string tmp1 = (string) visit(context->expr(1));
        assemblerText+="        movl    "+tmp0+", %edx\n";
        assemblerText+="        movl    "+tmp1+", %eax\n";
        assemblerText+="        addl	%edx, %eax\n";
        // i++;
        // return string("#tmp"+to_string(i));
        return string("%eax");
    }

    virtual antlrcpp::Any visitOp_or(ifccParser::Op_orContext *context) override {
     string tmp0 = (string) visit(context->expr(0));
        string tmp1 = (string) visit(context->expr(1));
        assemblerText+="        movl    "+tmp0+", %edx\n";
        assemblerText+="        movl    "+tmp1+", %eax\n";
        assemblerText+="        orl	%edx, %eax\n";
        // i++;
        // return string("#tmp"+to_string(i));
        return string("%eax");
    }

    virtual antlrcpp::Any visitOp_and(ifccParser::Op_andContext *context) override {
         string tmp0 = (string) visit(context->expr(0));
        string tmp1 = (string) visit(context->expr(1));
        assemblerText+="        movl    "+tmp0+", %edx\n";
        assemblerText+="        movl    "+tmp1+", %eax\n";
        assemblerText+="        andl	%edx, %eax\n";
        // i++;
        // return string("#tmp"+to_string(i));
        return string("%eax");
    }

    virtual antlrcpp::Any visitOp_xor(ifccParser::Op_xorContext *context) override {
        string tmp0 = (string) visit(context->expr(0));
        string tmp1 = (string) visit(context->expr(1));
        assemblerText+="        movl    "+tmp0+", %edx\n";
        assemblerText+="        movl    "+tmp1+", %eax\n";
        assemblerText+="        xorl	%edx, %eax\n";
        // i++;
        // return string("#tmp"+to_string(i));
        return string("%eax");
    }



    virtual antlrcpp::Any visitALPHANUMERIC(ifccParser::ALPHANUMERICContext *context){
        return string(to_string(offsets[context->ALPHANUMERIC()->getText()])+"(%rbp)");
    }



    antlrcpp::Any visitAxiom(ifccParser::AxiomContext *context){
        return nullptr;
    };

    antlrcpp::Any visitProg(ifccParser::ProgContext *context){
        return nullptr;
    };

    antlrcpp::Any visitLine(ifccParser::LineContext *context){
        return nullptr;
    };

    string getAssemblerText(){
        return assemblerText;
    }


};


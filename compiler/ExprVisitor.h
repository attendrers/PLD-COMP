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

    virtual antlrcpp::Any visitDiv(ifccParser::DivContext *context){
        return (int) visit(context->expr(0))/(int) visit(context->expr(1));
    };

    virtual antlrcpp::Any visitMinus(ifccParser::MinusContext *context){
        return (int) visit(context->expr(0))-(int) visit(context->expr(1));
    };

    virtual antlrcpp::Any visitMult(ifccParser::MultContext *context) {
        return (int) visit(context->expr(0))*(int) visit(context->expr(1));
    }

    virtual antlrcpp::Any visitCONST(ifccParser::CONSTContext *context) {
        // i++;
        // return string("#tmp"+to_string(i));
        return string("$"+context->CONST()->getText());
    }

    virtual antlrcpp::Any visitPlus(ifccParser::PlusContext *context){
        string tmp0 = (string) visit(context->expr(0));
        string tmp1 = (string) visit(context->expr(1));
        assemblerText+="movl    "+tmp0+", %edx\n";
        assemblerText+="movl    "+tmp1+", %eax\n";
        assemblerText+="addl	%edx, %eax\n";
        i++;
        return string("#tmp"+to_string(i));
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


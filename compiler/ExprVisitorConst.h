// Generated from ifcc.g4 by ANTLR 4.9.2

#pragma once


#include "generated/ifccBaseVisitor.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ExprVisitor : public ifccBaseVisitor {
public:

  /**
   * Visit parse trees produced by ifccParser.
   */

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
        return stoi(context->CONST()->getText());
    }

    virtual antlrcpp::Any visitPlus(ifccParser::PlusContext *context){
        return (int) visit(context->expr(0))+(int) visit(context->expr(1));
    }

    virtual antlrcpp::Any visitALPHANUMERIC(ifccParser::ALPHANUMERICContext *context){
        return nullptr;
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


};


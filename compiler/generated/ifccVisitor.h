
// Generated from ifcc.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ifccVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ifccParser.
   */
    virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitLine(ifccParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitPar(ifccParser::ParContext *context) = 0;

    virtual antlrcpp::Any visitDiv(ifccParser::DivContext *context) = 0;

    virtual antlrcpp::Any visitMinus(ifccParser::MinusContext *context) = 0;

    virtual antlrcpp::Any visitMult(ifccParser::MultContext *context) = 0;

    virtual antlrcpp::Any visitCONST(ifccParser::CONSTContext *context) = 0;

    virtual antlrcpp::Any visitPlus(ifccParser::PlusContext *context) = 0;


};


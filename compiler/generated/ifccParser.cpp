
// Generated from ifcc.g4 by ANTLR 4.9.2


#include "ifccVisitor.h"

#include "ifccParser.h"


using namespace antlrcpp;
using namespace antlr4;

ifccParser::ifccParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ifccParser::~ifccParser() {
  delete _interpreter;
}

std::string ifccParser::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ifccParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- AxiomContext ------------------------------------------------------------------

ifccParser::AxiomContext::AxiomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ProgContext* ifccParser::AxiomContext::prog() {
  return getRuleContext<ifccParser::ProgContext>(0);
}


size_t ifccParser::AxiomContext::getRuleIndex() const {
  return ifccParser::RuleAxiom;
}


antlrcpp::Any ifccParser::AxiomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAxiom(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AxiomContext* ifccParser::axiom() {
  AxiomContext *_localctx = _tracker.createInstance<AxiomContext>(_ctx, getState());
  enterRule(_localctx, 0, ifccParser::RuleAxiom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    prog();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgContext ------------------------------------------------------------------

ifccParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ifccParser::LineContext *> ifccParser::ProgContext::line() {
  return getRuleContexts<ifccParser::LineContext>();
}

ifccParser::LineContext* ifccParser::ProgContext::line(size_t i) {
  return getRuleContext<ifccParser::LineContext>(i);
}


size_t ifccParser::ProgContext::getRuleIndex() const {
  return ifccParser::RuleProg;
}


antlrcpp::Any ifccParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgContext* ifccParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 2, ifccParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(10);
    match(ifccParser::T__0);
    setState(11);
    match(ifccParser::T__1);
    setState(12);
    match(ifccParser::T__2);
    setState(13);
    match(ifccParser::T__3);
    setState(14);
    match(ifccParser::T__4);
    setState(18);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ifccParser::T__0

    || _la == ifccParser::RETURN) {
      setState(15);
      line();
      setState(20);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(21);
    match(ifccParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

ifccParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ifccParser::LineContext::ALPHANUMERIC() {
  return getTokens(ifccParser::ALPHANUMERIC);
}

tree::TerminalNode* ifccParser::LineContext::ALPHANUMERIC(size_t i) {
  return getToken(ifccParser::ALPHANUMERIC, i);
}

tree::TerminalNode* ifccParser::LineContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::ExprContext* ifccParser::LineContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

tree::TerminalNode* ifccParser::LineContext::RETURN() {
  return getToken(ifccParser::RETURN, 0);
}


size_t ifccParser::LineContext::getRuleIndex() const {
  return ifccParser::RuleLine;
}


antlrcpp::Any ifccParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::LineContext* ifccParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleLine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(42);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(23);
      match(ifccParser::T__0);
      setState(24);
      match(ifccParser::ALPHANUMERIC);
      setState(25);
      match(ifccParser::T__6);
      setState(26);
      match(ifccParser::CONST);
      setState(27);
      match(ifccParser::T__7);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(28);
      match(ifccParser::T__0);
      setState(29);
      match(ifccParser::ALPHANUMERIC);
      setState(30);
      match(ifccParser::T__6);
      setState(31);
      match(ifccParser::ALPHANUMERIC);
      setState(32);
      match(ifccParser::T__7);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(33);
      match(ifccParser::T__0);
      setState(34);
      match(ifccParser::ALPHANUMERIC);
      setState(35);
      match(ifccParser::T__6);
      setState(36);
      expr(0);
      setState(37);
      match(ifccParser::T__7);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(39);
      match(ifccParser::RETURN);
      setState(40);
      match(ifccParser::CONST);
      setState(41);
      match(ifccParser::T__7);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ifccParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::ExprContext::getRuleIndex() const {
  return ifccParser::RuleExpr;
}

void ifccParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParContext ------------------------------------------------------------------

ifccParser::ExprContext* ifccParser::ParContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::ParContext::ParContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::ParContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitPar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DivContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::DivContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::DivContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::DivContext::DivContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::DivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ALPHANUMERICContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ALPHANUMERICContext::ALPHANUMERIC() {
  return getToken(ifccParser::ALPHANUMERIC, 0);
}

ifccParser::ALPHANUMERICContext::ALPHANUMERICContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::ALPHANUMERICContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitALPHANUMERIC(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinusContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::MinusContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::MinusContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::MinusContext::MinusContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::MinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::MultContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::MultContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::MultContext::MultContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::MultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CONSTContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::CONSTContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::CONSTContext::CONSTContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::CONSTContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitCONST(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::PlusContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::PlusContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

ifccParser::PlusContext::PlusContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::PlusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitPlus(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExprContext* ifccParser::expr() {
   return expr(0);
}

ifccParser::ExprContext* ifccParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ifccParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ifccParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, ifccParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(51);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::CONST: {
        _localctx = _tracker.createInstance<CONSTContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(45);
        match(ifccParser::CONST);
        break;
      }

      case ifccParser::ALPHANUMERIC: {
        _localctx = _tracker.createInstance<ALPHANUMERICContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(46);
        match(ifccParser::ALPHANUMERIC);
        break;
      }

      case ifccParser::T__2: {
        _localctx = _tracker.createInstance<ParContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(47);
        match(ifccParser::T__2);
        setState(48);
        expr(0);
        setState(49);
        match(ifccParser::T__3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(67);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(65);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(53);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(54);
          match(ifccParser::T__8);
          setState(55);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(56);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(57);
          match(ifccParser::T__9);
          setState(58);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<DivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(59);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(60);
          match(ifccParser::T__10);
          setState(61);
          expr(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<MinusContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(62);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(63);
          match(ifccParser::T__11);
          setState(64);
          expr(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(69);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ifccParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ifccParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ifccParser::_decisionToDFA;
atn::PredictionContextCache ifccParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ifccParser::_atn;
std::vector<uint16_t> ifccParser::_serializedATN;

std::vector<std::string> ifccParser::_ruleNames = {
  "axiom", "prog", "line", "expr"
};

std::vector<std::string> ifccParser::_literalNames = {
  "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "'='", "';'", "'*'", 
  "'+'", "'/'", "'-'", "'return'"
};

std::vector<std::string> ifccParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "RETURN", "CONST", 
  "COMMENT", "DIRECTIVE", "ALPHANUMERIC", "WS"
};

dfa::Vocabulary ifccParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ifccParser::_tokenNames;

ifccParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x14, 0x49, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x13, 0xa, 
       0x3, 0xc, 0x3, 0xe, 0x3, 0x16, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
       0x2d, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x36, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x44, 0xa, 0x5, 0xc, 
       0x5, 0xe, 0x5, 0x47, 0xb, 0x5, 0x3, 0x5, 0x2, 0x3, 0x8, 0x6, 0x2, 
       0x4, 0x6, 0x8, 0x2, 0x2, 0x2, 0x4e, 0x2, 0xa, 0x3, 0x2, 0x2, 0x2, 
       0x4, 0xc, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x8, 
       0x35, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb, 0x5, 0x4, 0x3, 0x2, 0xb, 0x3, 
       0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x7, 0x3, 0x2, 0x2, 0xd, 0xe, 0x7, 
       0x4, 0x2, 0x2, 0xe, 0xf, 0x7, 0x5, 0x2, 0x2, 0xf, 0x10, 0x7, 0x6, 
       0x2, 0x2, 0x10, 0x14, 0x7, 0x7, 0x2, 0x2, 0x11, 0x13, 0x5, 0x6, 0x4, 
       0x2, 0x12, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x16, 0x3, 0x2, 0x2, 0x2, 
       0x14, 0x12, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x3, 0x2, 0x2, 0x2, 0x15, 
       0x17, 0x3, 0x2, 0x2, 0x2, 0x16, 0x14, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 
       0x7, 0x8, 0x2, 0x2, 0x18, 0x5, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x7, 
       0x3, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0x13, 0x2, 0x2, 0x1b, 0x1c, 0x7, 
       0x9, 0x2, 0x2, 0x1c, 0x1d, 0x7, 0x10, 0x2, 0x2, 0x1d, 0x2d, 0x7, 
       0xa, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x3, 0x2, 0x2, 0x1f, 0x20, 0x7, 0x13, 
       0x2, 0x2, 0x20, 0x21, 0x7, 0x9, 0x2, 0x2, 0x21, 0x22, 0x7, 0x13, 
       0x2, 0x2, 0x22, 0x2d, 0x7, 0xa, 0x2, 0x2, 0x23, 0x24, 0x7, 0x3, 0x2, 
       0x2, 0x24, 0x25, 0x7, 0x13, 0x2, 0x2, 0x25, 0x26, 0x7, 0x9, 0x2, 
       0x2, 0x26, 0x27, 0x5, 0x8, 0x5, 0x2, 0x27, 0x28, 0x7, 0xa, 0x2, 0x2, 
       0x28, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x7, 0xf, 0x2, 0x2, 0x2a, 
       0x2b, 0x7, 0x10, 0x2, 0x2, 0x2b, 0x2d, 0x7, 0xa, 0x2, 0x2, 0x2c, 
       0x19, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0x2c, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x7, 0x3, 
       0x2, 0x2, 0x2, 0x2e, 0x2f, 0x8, 0x5, 0x1, 0x2, 0x2f, 0x36, 0x7, 0x10, 
       0x2, 0x2, 0x30, 0x36, 0x7, 0x13, 0x2, 0x2, 0x31, 0x32, 0x7, 0x5, 
       0x2, 0x2, 0x32, 0x33, 0x5, 0x8, 0x5, 0x2, 0x33, 0x34, 0x7, 0x6, 0x2, 
       0x2, 0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x2e, 0x3, 0x2, 0x2, 0x2, 
       0x35, 0x30, 0x3, 0x2, 0x2, 0x2, 0x35, 0x31, 0x3, 0x2, 0x2, 0x2, 0x36, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0xc, 0x9, 0x2, 0x2, 0x38, 0x39, 
       0x7, 0xb, 0x2, 0x2, 0x39, 0x44, 0x5, 0x8, 0x5, 0xa, 0x3a, 0x3b, 0xc, 
       0x8, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0xc, 0x2, 0x2, 0x3c, 0x44, 0x5, 0x8, 
       0x5, 0x9, 0x3d, 0x3e, 0xc, 0x7, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0xd, 0x2, 
       0x2, 0x3f, 0x44, 0x5, 0x8, 0x5, 0x8, 0x40, 0x41, 0xc, 0x6, 0x2, 0x2, 
       0x41, 0x42, 0x7, 0xe, 0x2, 0x2, 0x42, 0x44, 0x5, 0x8, 0x5, 0x7, 0x43, 
       0x37, 0x3, 0x2, 0x2, 0x2, 0x43, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x43, 0x3d, 
       0x3, 0x2, 0x2, 0x2, 0x43, 0x40, 0x3, 0x2, 0x2, 0x2, 0x44, 0x47, 0x3, 
       0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 
       0x2, 0x2, 0x46, 0x9, 0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 
       0x2, 0x7, 0x14, 0x2c, 0x35, 0x43, 0x45, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ifccParser::Initializer ifccParser::_init;

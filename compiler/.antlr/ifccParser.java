// Generated from /home/ubuntu/studies/PLD_Comp/pld-comp/compiler/ifcc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ifccParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, RETURN=14, CONST=15, COMMENT=16, 
		DIRECTIVE=17, WS=18, ALPHANUMERIC=19, OP=20;
	public static final int
		RULE_axiom = 0, RULE_prog = 1, RULE_line = 2, RULE_expr = 3;
	private static String[] makeRuleNames() {
		return new String[] {
			"axiom", "prog", "line", "expr"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'int'", "'main'", "'('", "')'", "'{'", "'}'", "'='", "';'", "'+'", 
			"'-'", "'|'", "'&'", "'^'", "'return'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, "RETURN", "CONST", "COMMENT", "DIRECTIVE", "WS", "ALPHANUMERIC", 
			"OP"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "ifcc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public ifccParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class AxiomContext extends ParserRuleContext {
		public ProgContext prog() {
			return getRuleContext(ProgContext.class,0);
		}
		public AxiomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_axiom; }
	}

	public final AxiomContext axiom() throws RecognitionException {
		AxiomContext _localctx = new AxiomContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_axiom);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(8);
			prog();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProgContext extends ParserRuleContext {
		public List<LineContext> line() {
			return getRuleContexts(LineContext.class);
		}
		public LineContext line(int i) {
			return getRuleContext(LineContext.class,i);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_prog);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(10);
			match(T__0);
			setState(11);
			match(T__1);
			setState(12);
			match(T__2);
			setState(13);
			match(T__3);
			setState(14);
			match(T__4);
			setState(18);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0 || _la==RETURN) {
				{
				{
				setState(15);
				line();
				}
				}
				setState(20);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(21);
			match(T__5);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LineContext extends ParserRuleContext {
		public List<TerminalNode> ALPHANUMERIC() { return getTokens(ifccParser.ALPHANUMERIC); }
		public TerminalNode ALPHANUMERIC(int i) {
			return getToken(ifccParser.ALPHANUMERIC, i);
		}
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RETURN() { return getToken(ifccParser.RETURN, 0); }
		public LineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_line; }
	}

	public final LineContext line() throws RecognitionException {
		LineContext _localctx = new LineContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_line);
		try {
			setState(46);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(23);
				match(T__0);
				setState(24);
				match(ALPHANUMERIC);
				setState(25);
				match(T__6);
				setState(26);
				match(CONST);
				setState(27);
				match(T__7);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(28);
				match(T__0);
				setState(29);
				match(ALPHANUMERIC);
				setState(30);
				match(T__6);
				setState(31);
				match(ALPHANUMERIC);
				setState(32);
				match(T__7);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(33);
				match(T__0);
				setState(34);
				match(ALPHANUMERIC);
				setState(35);
				match(T__6);
				setState(36);
				expr(0);
				setState(37);
				match(T__7);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(39);
				match(RETURN);
				setState(43);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
				case 1:
					{
					setState(40);
					match(CONST);
					}
					break;
				case 2:
					{
					setState(41);
					match(ALPHANUMERIC);
					}
					break;
				case 3:
					{
					setState(42);
					expr(0);
					}
					break;
				}
				setState(45);
				match(T__7);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ParContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ParContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ALPHANUMERICContext extends ExprContext {
		public TerminalNode ALPHANUMERIC() { return getToken(ifccParser.ALPHANUMERIC, 0); }
		public ALPHANUMERICContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class MinusContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public MinusContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class Op_orContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Op_orContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class CONSTContext extends ExprContext {
		public TerminalNode CONST() { return getToken(ifccParser.CONST, 0); }
		public CONSTContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class Op_andContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Op_andContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class Op_xorContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Op_xorContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class MuldivContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode OP() { return getToken(ifccParser.OP, 0); }
		public MuldivContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class PlusContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public PlusContext(ExprContext ctx) { copyFrom(ctx); }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 6;
		enterRecursionRule(_localctx, 6, RULE_expr, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(55);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CONST:
				{
				_localctx = new CONSTContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(49);
				match(CONST);
				}
				break;
			case ALPHANUMERIC:
				{
				_localctx = new ALPHANUMERICContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(50);
				match(ALPHANUMERIC);
				}
				break;
			case T__2:
				{
				_localctx = new ParContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(51);
				match(T__2);
				setState(52);
				expr(0);
				setState(53);
				match(T__3);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(77);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(75);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
					case 1:
						{
						_localctx = new MuldivContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(57);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(58);
						match(OP);
						setState(59);
						expr(10);
						}
						break;
					case 2:
						{
						_localctx = new PlusContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(60);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(61);
						match(T__8);
						setState(62);
						expr(9);
						}
						break;
					case 3:
						{
						_localctx = new MinusContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(63);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(64);
						match(T__9);
						setState(65);
						expr(8);
						}
						break;
					case 4:
						{
						_localctx = new Op_orContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(66);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(67);
						match(T__10);
						setState(68);
						expr(7);
						}
						break;
					case 5:
						{
						_localctx = new Op_andContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(69);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(70);
						match(T__11);
						setState(71);
						expr(6);
						}
						break;
					case 6:
						{
						_localctx = new Op_xorContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(72);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(73);
						match(T__12);
						setState(74);
						expr(5);
						}
						break;
					}
					} 
				}
				setState(79);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 3:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 9);
		case 1:
			return precpred(_ctx, 8);
		case 2:
			return precpred(_ctx, 7);
		case 3:
			return precpred(_ctx, 6);
		case 4:
			return precpred(_ctx, 5);
		case 5:
			return precpred(_ctx, 4);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\26S\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\7\3\23\n\3\f\3\16\3"+
		"\26\13\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4.\n\4\3\4\5\4\61\n\4\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\5\5:\n\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\3\5\3\5\7\5N\n\5\f\5\16\5Q\13\5\3\5\2\3\b\6\2\4\6\b\2\2\2"+
		"\\\2\n\3\2\2\2\4\f\3\2\2\2\6\60\3\2\2\2\b9\3\2\2\2\n\13\5\4\3\2\13\3\3"+
		"\2\2\2\f\r\7\3\2\2\r\16\7\4\2\2\16\17\7\5\2\2\17\20\7\6\2\2\20\24\7\7"+
		"\2\2\21\23\5\6\4\2\22\21\3\2\2\2\23\26\3\2\2\2\24\22\3\2\2\2\24\25\3\2"+
		"\2\2\25\27\3\2\2\2\26\24\3\2\2\2\27\30\7\b\2\2\30\5\3\2\2\2\31\32\7\3"+
		"\2\2\32\33\7\25\2\2\33\34\7\t\2\2\34\35\7\21\2\2\35\61\7\n\2\2\36\37\7"+
		"\3\2\2\37 \7\25\2\2 !\7\t\2\2!\"\7\25\2\2\"\61\7\n\2\2#$\7\3\2\2$%\7\25"+
		"\2\2%&\7\t\2\2&\'\5\b\5\2\'(\7\n\2\2(\61\3\2\2\2)-\7\20\2\2*.\7\21\2\2"+
		"+.\7\25\2\2,.\5\b\5\2-*\3\2\2\2-+\3\2\2\2-,\3\2\2\2./\3\2\2\2/\61\7\n"+
		"\2\2\60\31\3\2\2\2\60\36\3\2\2\2\60#\3\2\2\2\60)\3\2\2\2\61\7\3\2\2\2"+
		"\62\63\b\5\1\2\63:\7\21\2\2\64:\7\25\2\2\65\66\7\5\2\2\66\67\5\b\5\2\67"+
		"8\7\6\2\28:\3\2\2\29\62\3\2\2\29\64\3\2\2\29\65\3\2\2\2:O\3\2\2\2;<\f"+
		"\13\2\2<=\7\26\2\2=N\5\b\5\f>?\f\n\2\2?@\7\13\2\2@N\5\b\5\13AB\f\t\2\2"+
		"BC\7\f\2\2CN\5\b\5\nDE\f\b\2\2EF\7\r\2\2FN\5\b\5\tGH\f\7\2\2HI\7\16\2"+
		"\2IN\5\b\5\bJK\f\6\2\2KL\7\17\2\2LN\5\b\5\7M;\3\2\2\2M>\3\2\2\2MA\3\2"+
		"\2\2MD\3\2\2\2MG\3\2\2\2MJ\3\2\2\2NQ\3\2\2\2OM\3\2\2\2OP\3\2\2\2P\t\3"+
		"\2\2\2QO\3\2\2\2\b\24-\609MO";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
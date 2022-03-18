// Generated from /home/ubuntu/studies/PLD_Comp/pld-comp/compiler/ifcc.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ifccLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, RETURN=13, CONST=14, COMMENT=15, DIRECTIVE=16, 
		ALPHANUMERIC=17, WS=18;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "T__10", "T__11", "RETURN", "CONST", "COMMENT", "DIRECTIVE", 
			"ALPHANUMERIC", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'int'", "'main'", "'('", "')'", "'{'", "'}'", "'='", "';'", "'*'", 
			"'+'", "'/'", "'-'", "'return'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, "RETURN", "CONST", "COMMENT", "DIRECTIVE", "ALPHANUMERIC", "WS"
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


	public ifccLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "ifcc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\24t\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6"+
		"\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3"+
		"\16\3\16\3\16\3\16\3\16\3\17\6\17M\n\17\r\17\16\17N\3\20\3\20\3\20\3\20"+
		"\7\20U\n\20\f\20\16\20X\13\20\3\20\3\20\3\20\3\20\3\20\3\21\3\21\7\21"+
		"a\n\21\f\21\16\21d\13\21\3\21\3\21\3\21\3\21\3\22\3\22\7\22l\n\22\f\22"+
		"\16\22o\13\22\3\23\3\23\3\23\3\23\4Vb\2\24\3\3\5\4\7\5\t\6\13\7\r\b\17"+
		"\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\3\2\6\3\2"+
		"\62;\4\2C\\c|\5\2\62;C\\c|\5\2\13\f\17\17\"\"\2w\2\3\3\2\2\2\2\5\3\2\2"+
		"\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21"+
		"\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2"+
		"\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\3\'\3"+
		"\2\2\2\5+\3\2\2\2\7\60\3\2\2\2\t\62\3\2\2\2\13\64\3\2\2\2\r\66\3\2\2\2"+
		"\178\3\2\2\2\21:\3\2\2\2\23<\3\2\2\2\25>\3\2\2\2\27@\3\2\2\2\31B\3\2\2"+
		"\2\33D\3\2\2\2\35L\3\2\2\2\37P\3\2\2\2!^\3\2\2\2#i\3\2\2\2%p\3\2\2\2\'"+
		"(\7k\2\2()\7p\2\2)*\7v\2\2*\4\3\2\2\2+,\7o\2\2,-\7c\2\2-.\7k\2\2./\7p"+
		"\2\2/\6\3\2\2\2\60\61\7*\2\2\61\b\3\2\2\2\62\63\7+\2\2\63\n\3\2\2\2\64"+
		"\65\7}\2\2\65\f\3\2\2\2\66\67\7\177\2\2\67\16\3\2\2\289\7?\2\29\20\3\2"+
		"\2\2:;\7=\2\2;\22\3\2\2\2<=\7,\2\2=\24\3\2\2\2>?\7-\2\2?\26\3\2\2\2@A"+
		"\7\61\2\2A\30\3\2\2\2BC\7/\2\2C\32\3\2\2\2DE\7t\2\2EF\7g\2\2FG\7v\2\2"+
		"GH\7w\2\2HI\7t\2\2IJ\7p\2\2J\34\3\2\2\2KM\t\2\2\2LK\3\2\2\2MN\3\2\2\2"+
		"NL\3\2\2\2NO\3\2\2\2O\36\3\2\2\2PQ\7\61\2\2QR\7,\2\2RV\3\2\2\2SU\13\2"+
		"\2\2TS\3\2\2\2UX\3\2\2\2VW\3\2\2\2VT\3\2\2\2WY\3\2\2\2XV\3\2\2\2YZ\7,"+
		"\2\2Z[\7\61\2\2[\\\3\2\2\2\\]\b\20\2\2] \3\2\2\2^b\7%\2\2_a\13\2\2\2`"+
		"_\3\2\2\2ad\3\2\2\2bc\3\2\2\2b`\3\2\2\2ce\3\2\2\2db\3\2\2\2ef\7\f\2\2"+
		"fg\3\2\2\2gh\b\21\2\2h\"\3\2\2\2im\t\3\2\2jl\t\4\2\2kj\3\2\2\2lo\3\2\2"+
		"\2mk\3\2\2\2mn\3\2\2\2n$\3\2\2\2om\3\2\2\2pq\t\5\2\2qr\3\2\2\2rs\b\23"+
		"\3\2s&\3\2\2\2\7\2NVbm\4\b\2\2\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
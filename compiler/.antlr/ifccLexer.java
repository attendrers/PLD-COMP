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
		T__9=10, RETURN=11, CONST=12, COMMENT=13, DIRECTIVE=14, WS=15, ALPHANUMERIC=16, 
		OP=17;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "RETURN", "CONST", "COMMENT", "DIRECTIVE", "WS", "ALPHANUMERIC", 
			"OP"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'int'", "'main'", "'('", "')'", "'{'", "'}'", "'='", "';'", "'+'", 
			"'-'", "'return'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, "RETURN", 
			"CONST", "COMMENT", "DIRECTIVE", "WS", "ALPHANUMERIC", "OP"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\23p\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3"+
		"\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\r\6\rG"+
		"\n\r\r\r\16\rH\3\16\3\16\3\16\3\16\7\16O\n\16\f\16\16\16R\13\16\3\16\3"+
		"\16\3\16\3\16\3\16\3\17\3\17\7\17[\n\17\f\17\16\17^\13\17\3\17\3\17\3"+
		"\17\3\17\3\20\3\20\3\20\3\20\3\21\3\21\7\21j\n\21\f\21\16\21m\13\21\3"+
		"\22\3\22\4P\\\2\23\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r"+
		"\31\16\33\17\35\20\37\21!\22#\23\3\2\7\3\2\62;\5\2\13\f\17\17\"\"\4\2"+
		"C\\c|\5\2\62;C\\c|\4\2,,\61\61\2s\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2"+
		"\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3"+
		"\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2"+
		"\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\3%\3\2\2\2\5)\3\2\2\2\7.\3\2\2\2"+
		"\t\60\3\2\2\2\13\62\3\2\2\2\r\64\3\2\2\2\17\66\3\2\2\2\218\3\2\2\2\23"+
		":\3\2\2\2\25<\3\2\2\2\27>\3\2\2\2\31F\3\2\2\2\33J\3\2\2\2\35X\3\2\2\2"+
		"\37c\3\2\2\2!g\3\2\2\2#n\3\2\2\2%&\7k\2\2&\'\7p\2\2\'(\7v\2\2(\4\3\2\2"+
		"\2)*\7o\2\2*+\7c\2\2+,\7k\2\2,-\7p\2\2-\6\3\2\2\2./\7*\2\2/\b\3\2\2\2"+
		"\60\61\7+\2\2\61\n\3\2\2\2\62\63\7}\2\2\63\f\3\2\2\2\64\65\7\177\2\2\65"+
		"\16\3\2\2\2\66\67\7?\2\2\67\20\3\2\2\289\7=\2\29\22\3\2\2\2:;\7-\2\2;"+
		"\24\3\2\2\2<=\7/\2\2=\26\3\2\2\2>?\7t\2\2?@\7g\2\2@A\7v\2\2AB\7w\2\2B"+
		"C\7t\2\2CD\7p\2\2D\30\3\2\2\2EG\t\2\2\2FE\3\2\2\2GH\3\2\2\2HF\3\2\2\2"+
		"HI\3\2\2\2I\32\3\2\2\2JK\7\61\2\2KL\7,\2\2LP\3\2\2\2MO\13\2\2\2NM\3\2"+
		"\2\2OR\3\2\2\2PQ\3\2\2\2PN\3\2\2\2QS\3\2\2\2RP\3\2\2\2ST\7,\2\2TU\7\61"+
		"\2\2UV\3\2\2\2VW\b\16\2\2W\34\3\2\2\2X\\\7%\2\2Y[\13\2\2\2ZY\3\2\2\2["+
		"^\3\2\2\2\\]\3\2\2\2\\Z\3\2\2\2]_\3\2\2\2^\\\3\2\2\2_`\7\f\2\2`a\3\2\2"+
		"\2ab\b\17\2\2b\36\3\2\2\2cd\t\3\2\2de\3\2\2\2ef\b\20\3\2f \3\2\2\2gk\t"+
		"\4\2\2hj\t\5\2\2ih\3\2\2\2jm\3\2\2\2ki\3\2\2\2kl\3\2\2\2l\"\3\2\2\2mk"+
		"\3\2\2\2no\t\6\2\2o$\3\2\2\2\7\2HP\\k\4\b\2\2\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
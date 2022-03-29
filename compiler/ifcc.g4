grammar ifcc;

axiom : prog ;

prog : 'int' 'main' '(' ')' '{' line* '}' ;

line: TYPE ALPHANUMERIC '=' INT_CONST ';'
| TYPE ALPHANUMERIC '=' CHAR_CONST ';'
| TYPE ALPHANUMERIC '=' ALPHANUMERIC ';'
| TYPE ALPHANUMERIC '=' expr ';'
| RETURN (INT_CONST|ALPHANUMERIC|expr) ';' ;

expr: expr OP expr # muldiv
| expr '+' expr # plus
| expr '-' expr # minus
| INT_CONST # INT_CONST
| ALPHANUMERIC # ALPHANUMERIC
| '(' expr ')'  # par ;


RETURN : 'return' ;
INT_CONST : [-]?[0-9]+ ;
CHAR_CONST : '\'' . '\'';
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
ALPHANUMERIC: [a-zA-Z] [a-zA-Z0-9]*;
OP : ('*'|'/');
TYPE : 'int' | 'char';

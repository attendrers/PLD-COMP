grammar ifcc;

axiom : prog ;

prog : 'int' 'main' '(' ')' '{' line* '}' ;

line: TYPE ALPHANUMERIC '=' CONST ';'
| TYPE ALPHANUMERIC '=' ALPHANUMERIC ';'
| TYPE ALPHANUMERIC '=' expr ';'
| RETURN (CONST|ALPHANUMERIC|expr) ';' ;

expr: expr OP expr # muldiv
| expr '+' expr # plus
| expr '-' expr # minus
| CONST # CONST
| ALPHANUMERIC # ALPHANUMERIC
| '(' expr ')'  # par ;


RETURN : 'return' ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
ALPHANUMERIC: [a-zA-Z] [a-zA-Z0-9]*;
OP : ('*'|'/');
TYPE : 'int' | 'char';

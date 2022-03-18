grammar ifcc;

axiom : prog ;

prog : 'int' 'main' '(' ')' '{' line* '}' ;

line: 'int' ALPHANUMERIC '=' CONST ';'
| 'int' ALPHANUMERIC '=' ALPHANUMERIC ';'
| RETURN CONST ';' ;

expr: expr '*' expr # mult
| expr '+' expr # plus
| expr '/' expr # div
| expr '-' expr # minus
| CONST # CONST
| '(' expr ')'  # par ;


RETURN : 'return' ;
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
ALPHANUMERIC: [a-zA-Z] [a-zA-Z0-9]*;
WS    : [ \t\r\n] -> channel(HIDDEN);

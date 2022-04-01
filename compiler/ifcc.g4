grammar ifcc;

axiom : prog ;

prog : TYPE 'main' '(' ')' '{' line* '}' ;

line: TYPE ALPHANUMERIC '=' CONST ';' # declaration_const
| TYPE ALPHANUMERIC '=' ALPHANUMERIC ';' # declaration_variable
| TYPE ALPHANUMERIC '=' expr ';' # declaration_expr
| return_global # return ;

return_global: RETURN CONST ';' # return_const
| RETURN ALPHANUMERIC ';'  # return_variable
| RETURN expr ';' # return_expr ;


expr: 
  '!' expr # op_not
| '-' expr # op_opposite
| expr OP expr # muldiv
| expr '+' expr # plus
| expr '-' expr # minus
| expr '|' expr # op_or
| expr '&' expr # op_and
| expr '^' expr # op_xor
| expr '==' expr # op_equal
| expr '!=' expr # op_not_equal
| expr '<' expr # op_inf
| expr '>' expr # op_sup

| CONST # CONST
| ALPHANUMERIC # ALPHANUMERIC
| '(' expr ')'  # par ;


RETURN : 'return' ;
TYPE: 'int';
CONST : [0-9]+ ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
ALPHANUMERIC: [a-zA-Z] [a-zA-Z0-9]*;
OP : ('*'|'/');

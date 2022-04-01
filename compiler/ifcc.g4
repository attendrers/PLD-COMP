grammar ifcc;

axiom : prog ;

prog : TYPE 'main' '(' ')' '{' line* '}' ;

line
    : TYPE ALPHANUMERIC '=' CONST ';'                 # declaration_const
    | TYPE ALPHANUMERIC '=' ALPHANUMERIC ';'          # declaration_variable
    | TYPE ALPHANUMERIC '=' expr ';'                  # declaration_expr
    | return_global                                   # return ;

return_global
    : RETURN CONST ';'                                # return_const
    | RETURN ALPHANUMERIC ';'                         # return_variable
    | RETURN expr ';'                                 # return_expr ;

primaryexpr
    : INT_CONST                                       #int
    | CHAR_CONST                                      #char
    | ALPHANUMERIC                                    #variable
    ;

expr
    : '(' expr ')'                                    # par
    | primaryexpr                                     # prExpr
    | '!' expr                                        # op_not
    | '-' expr                                        # op_opposite
    | left=expr op=('*'|'/') right=expr               # op_muldiv
    | left=expr op=('+'|'-') right=expr               # op_plusmoins
    | left=expr op=('<'|'>'|'<='|'>=') right=expr     # op_infsup
    | left=expr op=('=='|'!=') right=expr             # op_equalornot
    | left=expr op=('&'|'^'|'|') right=expr           # op_bit
    ;

RETURN : 'return' ;
INT_CONST : [-]?[0-9]+ ;
CHAR_CONST : '\'' . '\'';
COMMENT : '/*' .*? '*/' -> skip ;
INLINECOMMENT : '//' ~[\r\n]* [\r\n] -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
ALPHANUMERIC: [_a-zA-Z] [_a-zA-Z0-9]*;







grammar ifcc;

axiom : prog ;

prog : TYPE 'main' '(' ')' '{' line* '}' ;

line
    : TYPE ALPHANUMERIC '=' INT_CONST ';'             # declaration_intconst
    | TYPE ALPHANUMERIC '=' CHAR_CONST ';'            # declaration_charconst
    | TYPE ALPHANUMERIC '=' ALPHANUMERIC ';'          # declaration_variable
    | TYPE ALPHANUMERIC '=' expr ';'                  # declaration_expr
    | return_global                                   # return ;

return_global
    : RETURN INT_CONST ';'                            # return_intconst
    | RETURN CHAR_CONST ';'                           # return_charconst
    | RETURN ALPHANUMERIC ';'                         # return_variable
    | RETURN expr ';'                                 # return_expr
    ;

bloc
    : '{' line* '}'                                   # bloc
    ;

condition
    : left=expr op=('<'|'>'|'<='|'>=') right=expr     # comp_infsup
    | left=expr op=('=='|'!=') right=expr             # comp_equalornot
    ;

ifStatement
    : left='if' '(' condition ')' bloc                # if_noelse
    | left='if' '(' condition ')' bloc
      right='else' bloc                               # if_else
    ;

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
TYPE: ('int' | 'char') ;
COMMENT : '/*' .*? '*/' -> skip ;
INLINECOMMENT : '//' ~[\r\n]* [\r\n] -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
ALPHANUMERIC: [_a-zA-Z] [_a-zA-Z0-9]*;







grammar ifcc;

axiom : prog ;


prog : (func*);

func: (TYPE|'void') funcName=ALPHANUMERIC '(' ')' '{' line* '}';

bloc : '{' line* '}';

line:
    decl                                              # declaration
    | affect                                          # affectation
    | func_call ';'                                   # line_function_call
    | ifstatement                                     # caseif
    | return_global                                   # return 
    ;

decl: TYPE ALPHANUMERIC '=' INT_CONST ';'             # declaration_intconst
    | TYPE ALPHANUMERIC '=' CHAR_CONST ';'            # declaration_charconst
    | TYPE ALPHANUMERIC '=' ALPHANUMERIC ';'          # declaration_variable
    | TYPE ALPHANUMERIC '=' expr ';'                  # declaration_expr
    | TYPE ALPHANUMERIC '=' func_call ';'             # declaration_function_call 
    ;

affect: ALPHANUMERIC '=' INT_CONST ';'                # affectation_intconst
    | ALPHANUMERIC '=' CHAR_CONST ';'                 # affectation_charconst
    | ALPHANUMERIC '=' ALPHANUMERIC ';'               # affectation_variable
    | ALPHANUMERIC '=' expr ';'                       # affectation_expr
    | ALPHANUMERIC '=' func_call ';'                  # affectation_function_call 
    ;

func_call: 
funcName=ALPHANUMERIC '(' (primaryexpr ','?)* ')'     # function_call ; 

return_global
    : RETURN INT_CONST ';'                                  # return_intconst
    | RETURN CHAR_CONST ';'                                 # return_charconst
    | RETURN ALPHANUMERIC ';'                               # return_variable
    | RETURN expr ';'                                       # return_expr
    ;

condition
    : left=expr op=('<'|'>'|'<='|'>=') right=expr           # comp_infsup
    | left=expr op=('=='|'!=') right=expr                   # comp_equalornot
    ;

ifstatement
    : IF '(' cond=condition ')' blocif=bloc (ELSE blocelse=bloc)? ;  # statement_if

primaryexpr
    : INT_CONST                                            #int
    | CHAR_CONST                                           #char
    | ALPHANUMERIC                                         #variable
    ;

expr
    : '(' expr ')'                                         # par
    | primaryexpr                                          # prExpr
    | '!' expr                                             # op_not
    | '-' expr                                             # op_opposite
    | left=expr op=('*'|'/') right=expr                    # op_muldiv
    | left=expr op=('+'|'-') right=expr                    # op_plusmoins
    | left=expr op=('<'|'>'|'<='|'>=') right=expr          # op_infsup
    | left=expr op=('=='|'!=') right=expr                  # op_equalornot
    | left=expr op=('&'|'^'|'|') right=expr                # op_bit
    ;

IF : 'if';
ELSE : 'else';
RETURN : 'return' ;
INT_CONST : [-]?[0-9]+ ;
CHAR_CONST : '\'' . '\'';
TYPE: ('int' | 'char') ;
COMMENT : '/*' .*? '*/' -> skip ;
INLINECOMMENT : '//' ~[\r\n]* [\r\n] -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
ALPHANUMERIC: [_a-zA-Z] [_a-zA-Z0-9]*;

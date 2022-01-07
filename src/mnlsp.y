%define parse.error verbose

%{
#include<stdio.h>

#include<iostream>
#include<string>

#include"mnlsp.hpp"

#define DEBUG true

#define ERR_SYN "syntax error"

extern "C"
{
    void yyerror(const char* msg);
    extern int yylex();
};
%}

%code requires
{
#include"mnlsp.hpp"
}

%type program
%type stmts  // _
%type stmt
%type exps
%type exp

%type print_stmt

%type def_stmt
%type variable

%type num_op
%type plus
%type minus
%type multiply
%type divide
%type modulus
%type greater
%type smaller
%type equal

%type logical_op
%type and_op
%type or_op
%type not_op

%type fun_exp
%type fun_ids
%type idsn
%type fun_body
%type fun_call
%type paramsn
%type param
%type last_exp
%type fun_name

%type if_exp
%type test_exp
%type than_exp
%type else_exp

%token NUMBER
%token ID
%token BOOL_VAL

%token LP
%token RP

%token PRINT_NUM_ID
%token PRINT_BOOL_ID

%token PLUS_ID
%token MINUS_ID
%token MULTIPLY_ID
%token DIVIDE_ID
%token MODULUS_ID
%token GREATER_ID
%token SMALLER_ID
%token EQUAL_ID

%token AND_ID
%token OR_ID
%token NOT_ID

%token DEFINE_ID

%token FUN_ID

%token IF_ID

%%
program
    : stmts {}
    ;
stmts
    : stmt stmts {}
    | stmt {}
    ;
stmt
    : exp {}
    | def_stmt {}
    | print_stmt {}
    ;
exps
    : exp exps {}
    | exp {}
    ;
exp
    : BOOL_VAL {}
    | NUMBER {}
    | variable {}
    | num_op {}
    | logical_op {}
    | fun_exp {}
    | fun_call {}
    | if_exp {}
    ;

print_stmt
    : LP PRINT_NUM_ID exp RP {}
    | LP PRINT_BOOL_ID exp RP {}
    ;

def_stmt
    : LP DEFINE_ID variable exp RP {}
    ;
variable
    : ID {}
    ;

num_op
    : plus {}
    | minus {}
    | multiply {}
    | divide {}
    | modulus {}
    | greater {}
    | smaller {}
    | equal {}
    ;
plus
    : LP PLUS_ID exp exps RP {}
    ;
minus
    : LP MINUS_ID exp exp RP {}
    ;
multiply
    : LP MULTIPLY_ID exp exps RP {}
    ;
divide
    : LP DIVIDE_ID exp exp RP {}
    ;
modulus
    : LP MODULUS_ID exp exp RP {}
    ;
greater
    : LP GREATER_ID exp exp RP {}
    ;
smaller
    : LP SMALLER_ID exp exp RP {}
    ;
equal
    : LP EQUAL_ID exp exps RP {}
    ;

logical_op
    : and_op {}
    | or_op {}
    | not_op {}
    ;
and_op
    : LP AND_ID exp exps RP {}
    ;
or_op
    : LP OR_ID exp exps RP {}
    ;
not_op
    : LP NOT_ID exp exp RP {}
    ;

fun_exp
    : LP FUN_ID fun_ids fun_body RP {}
    ;
fun_ids
    : LP idsn RP {}
    | LP RP {}
    ;
idsn
    : ID idsn {}
    |
    ;
fun_body
    : def_stmt exp {}
    | exp {}
    ;
fun_call
    : LP fun_exp paramsn RP {}
    | LP fun_name paramsn RP {}
    ;
paramsn
    : param paramsn {}
    |
    ;
param
    : exp {}
    ;
last_exp
    : exp {}
    ;
fun_name
    : ID {}
    ;

if_exp
    : LP IF_ID test_exp than_exp else_exp RP {}
    ;
test_exp
    : exp {}
    ;
than_exp
    : exp {}
    ;
else_exp
    : exp {}
    ;

%%
void yyerror(const char* msg)
{
    #if DEBUG
        fprintf(stderr, "%s\n", msg);
    #endif
    exit(0);

    return;
}

int main()
{
    /* yyparse(); */

    return 0;
}

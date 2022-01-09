%define parse.error verbose

%{
#include<stdio.h>
#include"mnlsp.hpp"

#define DEBUG true

// #define ERR_SYN "syntax error"

extern "C"
{
    void yyerror(const char* msg);
    extern int yylex();
};

mnlsp::RTE* brte;
%}

%code requires
{
#include"mnlsp.hpp"
}

%type<t> program
%type<t> stmts
%type<t> stmt
%type<t> exps
%type<t> exp

%type<t> print_stmt

%type<t> def_stmt
%type<t> variable

%type<t> num_op
%type<t> plus
%type<t> minus
%type<t> multiply
%type<t> divide
%type<t> modulus
%type<t> greater
%type<t> smaller
%type<t> equal

%type<t> logical_op
%type<t> and_op
%type<t> or_op
%type<t> not_op

%type<t> fun_exp
%type<t> fun_ids
%type<t> idsn
%type<t> fun_body

%type<t> fun_call
%type<t> paramsn
%type<t> param
/* %type<t> last_exp */
%type<t> fun_name

%type<t> if_exp
%type<t> test_exp
%type<t> than_exp
%type<t> else_exp

%token<t> NUMBER
%token<t> ID
%token<t> BOOL_VAL

%token<t> LP
%token<t> RP

%token<t> PRINT_NUM_ID
%token<t> PRINT_BOOL_ID

%token<t> PLUS_ID
%token<t> MINUS_ID
%token<t> MULTIPLY_ID
%token<t> DIVIDE_ID
%token<t> MODULUS_ID
%token<t> GREATER_ID
%token<t> SMALLER_ID
%token<t> EQUAL_ID

%token<t> AND_ID
%token<t> OR_ID
%token<t> NOT_ID

%token<t> DEFINE_ID

%token<t> FUN_ID

%token<t> IF_ID

%%
program
    : stmts {
        $$.r = mnlsp::RTE::get_base_rte();
        $$.r->add_params(*$1.v);
        brte = $$.r;
        // printf(">>>\n");
    }
    ;
stmts
    : stmt stmts {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($1.n);
        mnlsp::utl::v_concat($$.v, $2.v);
    }
    | stmt {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($1.n);
    }
    ;
stmt
    : exp        {$$.n = $1.n;}
    | print_stmt {$$.n = new mnlsp::ExpNode(mnlsp::Data($1.r));}
    | def_stmt   {$$.n = new mnlsp::ExpNode(mnlsp::Data($1.r));}
    ;
exps
    : exp exps {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($1.n);
        mnlsp::utl::v_concat($$.v, $2.v);
    }
    | exp {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($1.n);
    }
    ;
exp
    : BOOL_VAL   {$$.n = new mnlsp::ExpNode(*$1.d);}
    | NUMBER     {$$.n = new mnlsp::ExpNode(*$1.d);}
    | variable   {$$.n = $1.n;}
    | num_op     {$$.n = new mnlsp::ExpNode(mnlsp::Data($1.r));}
    | logical_op {$$.n = new mnlsp::ExpNode(mnlsp::Data($1.r));}
    | fun_exp    {$$.n = new mnlsp::ExpNode(mnlsp::Data($1.r));}
    | fun_call   {$$.n = new mnlsp::ExpNode(mnlsp::Data($1.r));}
    | if_exp     {$$.n = new mnlsp::ExpNode(mnlsp::Data($1.r));}
    ;

print_stmt
    : LP PRINT_NUM_ID exp RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n);
        $$.r = mnlsp::RTE::get_var_fun_rte("_print-num", *$$.v);
    }
    | LP PRINT_BOOL_ID exp RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n);
        $$.r = mnlsp::RTE::get_var_fun_rte("_print-bool", *$$.v);
    }
    ;

def_stmt
    : LP DEFINE_ID variable exp RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n); $$.v->push_back($4.n);
        $$.r = mnlsp::RTE::get_var_fun_rte("_define", *$$.v);
    }
    ;
variable
    : ID {
        $$.n = (mnlsp::ExpNode*)(new mnlsp::VarNode());
        ((mnlsp::VarNode*)$$.n)->vid = *$1.s;
    }
    ;

num_op
    : plus     {$$.r = $1.r;}
    | minus    {$$.r = $1.r;}
    | multiply {$$.r = $1.r;}
    | divide   {$$.r = $1.r;}
    | modulus  {$$.r = $1.r;}
    | greater  {$$.r = $1.r;}
    | smaller  {$$.r = $1.r;}
    | equal    {$$.r = $1.r;}
    ;
plus
    : LP PLUS_ID exp exps RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n);
        mnlsp::utl::v_concat($$.v, $4.v);
        $$.r = mnlsp::RTE::get_var_fun_rte("_plus", *$$.v);
    }
    ;
minus
    : LP MINUS_ID exp exp RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n); $$.v->push_back($4.n);
        $$.r = mnlsp::RTE::get_var_fun_rte("_minus", *$$.v);
    }
    ;
multiply
    : LP MULTIPLY_ID exp exps RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n);
        mnlsp::utl::v_concat($$.v, $4.v);
        $$.r = mnlsp::RTE::get_var_fun_rte("_multiply", *$$.v);
    }
    ;
divide
    : LP DIVIDE_ID exp exp RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n); $$.v->push_back($4.n);
        $$.r = mnlsp::RTE::get_var_fun_rte("_divide", *$$.v);
    }
    ;
modulus
    : LP MODULUS_ID exp exp RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n); $$.v->push_back($4.n);
        $$.r = mnlsp::RTE::get_var_fun_rte("_modulus", *$$.v);
    }
    ;
greater
    : LP GREATER_ID exp exp RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n); $$.v->push_back($4.n);
        $$.r = mnlsp::RTE::get_var_fun_rte("_greater", *$$.v);
    }
    ;
smaller
    : LP SMALLER_ID exp exp RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n); $$.v->push_back($4.n);
        $$.r = mnlsp::RTE::get_var_fun_rte("_smaller", *$$.v);
    }
    ;
equal
    : LP EQUAL_ID exp exps RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n);
        mnlsp::utl::v_concat($$.v, $4.v);
        $$.r = mnlsp::RTE::get_var_fun_rte("_equal", *$$.v);
    }
    ;

logical_op
    : and_op {$$.r = $1.r;}
    | or_op  {$$.r = $1.r;}
    | not_op {$$.r = $1.r;}
    ;
and_op
    : LP AND_ID exp exps RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n);
        mnlsp::utl::v_concat($$.v, $4.v);
        $$.r = mnlsp::RTE::get_var_fun_rte("_and", *$$.v);
    }
    ;
or_op
    : LP OR_ID exp exps RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n);
        mnlsp::utl::v_concat($$.v, $4.v);
        $$.r = mnlsp::RTE::get_var_fun_rte("_or", *$$.v);
    }
    ;
not_op
    : LP NOT_ID exp RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n);
        $$.r = mnlsp::RTE::get_var_fun_rte("_not", *$$.v);
    }
    ;

fun_exp
    : LP FUN_ID fun_ids fun_body RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n);
        mnlsp::utl::v_concat($$.v, $4.v);
        $$.r = mnlsp::RTE::get_var_fun_rte("_fun", *$$.v);
    }
    ;
fun_ids
    : LP idsn RP {
        $$.n = (mnlsp::ExpNode*)(new mnlsp::VarNode());
        ((mnlsp::VarNode*)$$.n)->vid = "_p" + *$2.s;
    }
    ;
idsn
    : ID idsn {*$$.s = "_" + *$1.s + *$2.s;}
    |         {$$.s = new std::string();}
    ;
fun_body
    : def_stmt exp {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($1.n); $$.v->push_back($2.n);
    }
    | exp {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($1.n);
    }
    ;

fun_call
    : LP fun_exp paramsn RP {
        // $$.r = new mnlsp::RTE();
        // $$.r->set_fun(new mnlsp::ExpNode());
        // $$.r->add_params(*$3.v, true);
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back(new mnlsp::ExpNode(mnlsp::Data($2.r)));
        mnlsp::utl::v_concat($$.v, $3.v);
        $$.r = mnlsp::RTE::get_var_fun_rte("_fun_call", *$$.v);
    }
    | LP fun_name paramsn RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back(new mnlsp::ExpNode(*$2.s, 0));
        mnlsp::utl::v_concat($$.v, $3.v);
        $$.r = mnlsp::RTE::get_var_fun_rte("_fun_call", *$$.v);
    }
    ;
paramsn
    : param paramsn {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($1.n);
        mnlsp::utl::v_concat($$.v, $2.v);
    }
    | {$$.v = mnlsp::utl::v_new();}
    ;
param
    : exp {$$.n = $1.n;}
    ;
/* last_exp
    : exp {}
    ; */
fun_name
    : ID {$$.s = $1.s;}
    ;

if_exp
    : LP IF_ID test_exp than_exp else_exp RP {
        $$.v = mnlsp::utl::v_new();
        $$.v->push_back($3.n); $$.v->push_back($4.n); $$.v->push_back($5.n);
        $$.r = mnlsp::RTE::get_var_fun_rte("_if", *$$.v);
    }
    ;
test_exp
    : exp {$$.n = $1.n;}
    ;
than_exp
    : exp {$$.n = $1.n;}
    ;
else_exp
    : exp {$$.n = $1.n;}
    ;

%%
void yyerror(const char* msg)
{
    #if DEBUG
        fprintf(stderr, "%s\n", msg);
    #else
        fprintf(stderr, "%s\n", msg);
    #endif
    exit(0);

    return;
}

int main()
{
    mnlsp::RTES* prtes = mnlsp::mnlsp_init();

    try
    {
        yyparse();
        prtes->eval(brte);
        /* printf(">>>\n"); */
    }
    catch(mnlsp::ErrPkt ep)
    {
        yyerror(ep.msg.c_str());
    }

    return 0;
}

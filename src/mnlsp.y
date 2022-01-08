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
%type<t> last_exp
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
    }
    ;
stmts
    : stmt stmts {$$.v->push_back($1.n); $$.v->insert($$.v->end(), $2.v->begin(), $2.v->end());}
    | stmt       {$$.v = new std::vector<mnlsp::ExpNode*>(); $$.v->push_back($1.n);}
    ;
stmt
    : exp        {$$.n = $1.n;}
    | print_stmt {$$.n = new mnlsp::ExpNode(mnlsp::Data($1.r));}
    | def_stmt   {}
    ;
exps
    : exp exps {$$.v->push_back($1.n); $$.v->insert($$.v->end(), $2.v->begin(), $2.v->end());}
    | exp      {$$.v = new std::vector<mnlsp::ExpNode*>(); $$.v->push_back($1.n);}
    ;
exp
    : BOOL_VAL   {$$.n = new mnlsp::ExpNode(*$1.d);}
    | NUMBER     {$$.n = new mnlsp::ExpNode(*$1.d);}
    | variable   {}
    | num_op     {$$.n = new mnlsp::ExpNode(mnlsp::Data($1.r));}
    | logical_op {}
    | fun_exp    {}
    | fun_call   {}
    | if_exp     {}
    ;

print_stmt
    : LP PRINT_NUM_ID exp RP {
        $$.v = new std::vector<mnlsp::ExpNode*>(); 
        $$.v->push_back($3.n);

        $$.r = new mnlsp::RTE();
        $$.r->set_fun(new mnlsp::ExpNode("_print-num", 0));
        $$.r->add_params(*$$.v);
    }
    | LP PRINT_BOOL_ID exp RP {}
    ;

def_stmt
    : LP DEFINE_ID variable exp RP {}
    ;
variable
    : ID {}
    ;

num_op
    : plus {$$.r = $1.r;}
    | minus {}
    | multiply {}
    | divide {}
    | modulus {}
    | greater {}
    | smaller {}
    | equal {}
    ;
plus
    : LP PLUS_ID exp exps RP {
        $$.v = new std::vector<mnlsp::ExpNode*>();
        $$.v->push_back($3.n);
        $$.v->insert($$.v->end(), $4.v->begin(), $4.v->end());

        $$.r = new mnlsp::RTE();
        $$.r->set_fun(new mnlsp::ExpNode("_plus", 0));
        $$.r->add_params(*$$.v);
    }
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
    : ID {$$.n = new mnlsp::ExpNode(*$1.s, 0);}
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

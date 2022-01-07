%{
#include"mnlsp.tab.h"

extern "C"
{
    int yylex();
};
%}

eol             \n

separator       [\t\n\r ]
letter          [a-z]
digit           [0-9]

lp              "("
rp              ")"

print_num_id    "print-num"
print_bool_id   "print-bool"

plus_id         "+"
minus_id        "-"
multiply_id     "*"
divide_id       "/"
modulus_id      "mod"
greater_id      ">"
smaller_id      "<"
equal_id        "="

and_id          "and"
or_id           "or"
not_id          "not"

define_id       "define"

fun_id          "fun"|"lambda"

if_id           "if"

number          0|[1-9]{digit}*|-[1-9]{digit}*
id              {letter}({letter}|{digit}|"-")*
bool_val        "#t"|"#f"

%%
{eol}           {}
{separator}     {}

{lp}            {return LP;}
{rp}            {return RP;}

{print_num_id}  {return PRINT_NUM_ID;}
{print_bool_id} {return PRINT_BOOL_ID;}

{plus_id}       {return PLUS_ID;}
{minus_id}      {return MINUS_ID;}
{multiply_id}   {return MULTIPLY_ID;}
{divide_id}     {return DIVIDE_ID;}
{modulus_id}    {return MODULUS_ID;}
{greater_id}    {return GREATER_ID;}
{smaller_id}    {return SMALLER_ID;}
{equal_id}      {return EQUAL_ID;}

{and_id}        {return AND_ID;}
{or_id}         {return OR_ID;}
{not_id}        {return NOT_ID;}

{define_id}     {return DEFINE_ID;}

{fun_id}        {return FUN_ID;}

{if_id}         {return IF_ID;}

{number}        {return NUMBER;}
{id}            {return ID;}
{bool_val}      {return BOOL_VAL;}

.               {}

%%

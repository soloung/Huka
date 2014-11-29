#include "common.h"
#include "operator.h"

char operator[] = {
    '+' ,
    '-' ,
    '*' ,
    '/' ,
    '&' ,
    '|' ,
    '^' ,
    //'<<',
    //'>>',
    '(' ,
    ')' ,
    '!' ,
};

operator_st operatorArray[OPERATOR_NUM] =
{
    {'+',1},
    {'-',1},
    {'*',2},
    {'/',2}
};

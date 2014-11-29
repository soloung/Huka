/*********************************************************
    This file is transfer the infix expression
    into postfix expression

    notice:it now only deals simple infix to postfix
********************************************************/
#include"common.h"
#include"operator.h"


extern operator_st operatorArray[];

static int judgeTokenType(char token);

void infix2postfix()
{
    char ch;
    int i = 0;//log the statement position
    int j = 0;//log the result position
    int k = 0;//log the operatorStack position
    int z = 0;
    int y = 0;
    int type;
    char* statement = "a+2*3-2;";//test infix statements
    char result[100] = {0};    //store postfix result
    operator_st operatorStack[10] = {0}; //assume that the operator is less than 10
    operator_st temp_operator;

    for(k = 0; k < 10; k++)
    {
        operatorStack[z].operator_type = 0;
        operatorStack[z].priority_level = 0;
    }
    k = 0;

    while( statement[i]!=';')
    {
        //
        ch = statement[i];
        printf("ch = %c i = %d\n",ch,i);
        type = judgeTokenType(ch);
        if(type == DIGIT_TYPE)
        {
            result[j] = ch;
            j++;
        }
        else if(type == OPERATOR_TYPE)
        {
            temp_operator.operator_type = ch;
            if((ch == '+') || (ch == '-'))
            {
                temp_operator.priority_level = 1;

            }
            else
            {
                temp_operator.priority_level = 2;
            }

            for(z = 0; z < 9; z++)
            {
                if(temp_operator.priority_level > operatorStack[0].priority_level)
                {
                    //push the operator into the stack
                    for(y = 9; y>0; y--)
                    {
                        operatorStack[y].operator_type = operatorStack[y-1].operator_type;
                        operatorStack[y].priority_level = operatorStack[y-1].priority_level;
                    }
                    operatorStack[0].operator_type = temp_operator.operator_type;
                    operatorStack[0].priority_level = temp_operator.priority_level;
                    break;
                }
                else
                {
                    result[j] = operatorStack[0].operator_type;
                    j++;
                    for(y = 0; y < 9; y++)
                    {
                        operatorStack[y].operator_type = operatorStack[y+1].operator_type;
                        operatorStack[y].priority_level = operatorStack[y+1].priority_level;
                    }
                }

            }
        }

        i++;

    }
    z = 0;
    while(operatorStack[z].operator_type!=0)
    {
        result[j] = operatorStack[z].operator_type;
        //printf("the operator in stack is %c ",operatorStack[z].operator_type);
        z++;
        j++;
    }
    printf("deal ok\n");
    printf("the result is : %s\n",result);
}

int judgeTokenType(char token)
{
    int i;
    int rtv_type = DIGIT_TYPE;
    for(i = 0; i < 4; i++)
    {
        if(token == operatorArray[i].operator_type)
        {
            rtv_type = OPERATOR_TYPE;
        }
    }
    return rtv_type;
}



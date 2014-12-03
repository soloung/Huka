/******************************

    E -> E + T;
    E -> E - T;
    E -> T;
    T -> T * F;
    T -> T / F
    T - > F;
    F - > I;
    ********************************
    Eliminate left recursion
    E -> TE'
    E' -> +TE'|-TE'|null
    T- > FT'
    T' -> *FT'|/FT'|null
    F -> I



****************************/

#include"common.h"
#include<stdio.h>
#define PLUS  ('+')
#define MINUS ('-')
#define MULTI ('*')
#define CHU   ('/')
#define SEMI  (';')

char predict;
char testS[] = "x+I*I;";
int i = 0;

int exprime();
int exexprime();
int Term();
int TeTerm();
int match(char ch);
int Factor();
void advance();
char getPredict();
void parse()
{
    printf("\n--------------parse------------\n");
    do
    {
       // printf("i = %d\n",i);
        exprime();
        advance();
        //printf("called advance in while\n");
    }while((!match(SEMI))&&(i<=6));
    printf("\ni = %d\n",i);
    printf("parse ok\n");

}
int match(char ch)
{
    int rtv;
    if(testS[i] == ch)
    {
        rtv = 1;
    }
    else
    {
        rtv = 0;
    }
    return rtv;

}
void advance()
{
    //predict = testS[i];
    i++;
    //printf("i = %d\n",i);
}
char getPredict()
{
    //predict = testS[i+1];
    return testS[i+1];
}
int exprime()
{
    //advance();
    int rtv;
    rtv = Term();
    if(getPredict() == '+')
    {
        advance();
        exexprime();
    }
    else if(getPredict() == '-')
    {
        advance();
        exexprime();
    }
}
int exexprime()
{
    if(match(PLUS))//+TE'
    {
        printf("+");
        advance();
        Term();
        if(getPredict() == ';')
            return 1;
        advance();
        exexprime();
    }
    else if(match(MINUS))//-TE'
    {
        Term();
        if(getPredict() == '1')
            return 1;
        advance();
        exexprime();
    }
    else
    {
        ;
    }
}
/*******************
 T -> FT'
*******************/
int Term()
{
    int rtv = 0;
    rtv = Factor();
    if(getPredict() == '*')
    {
        advance();
        TeTerm();
    }
    else if(getPredict() == '/')
    {
        advance();
        TeTerm();
    }
    else if(getPredict() == ';')
    {
        printf("stop here, i  = %d\n",i);
        while(1);
    }
    return 0;
}
/*********************
    T' -> *FT'|/FT'|null
***********************/
int TeTerm()
{
    int rtv = 0;
    if(match(MULTI))//*FT'
    {
        printf("*");
        advance();
        rtv = Factor();
        if(getPredict() == ';')
        {
            return 1;
        }
        advance();
        TeTerm();
    }
    else if(match(CHU))
    {
        rtv = Factor();
        if(rtv == 1)
            return 1;
        advance();
        TeTerm();
    }
    else
    {
        ;
    }

}

int Factor()
{
    if(match('I'))
    {
        printf("I");
        return 1;
    }
    else
    {
        printf("error");
        return 0;
    }
}



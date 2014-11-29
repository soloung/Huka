#ifndef OPERATOR_H_
#define OPERATOR_H_
#include "common.h"

#define OPERATOR_NUM 4

#define ILLEGAL_TYPE  0
#define OPERATOR_TYPE 1
#define DIGIT_TYPE    2

typedef struct{
    char operator_type;
    int  priority_level;
}operator_st;

void infix2postfix();

#endif // OPERATOR_H_

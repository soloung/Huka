#include<stdio.h>
#include"Token.h"
#include"common.h"

void Token(char* statements)
{
	char ch;
	int i = 0;//log the position of statements
    int j = 0;//log the position of token[];
	int k = 0;
	char token[10][10] = {0};
    char HeadFlag = FALSE;
    char EndFlag = FALSE;

	do
    {
        ch = statements[i];

        if(ch !=' ')
        {
            printf("%c ",ch);
            if(HeadFlag == FALSE)
            {
                HeadFlag = TRUE;

            }
            token[j][k] = ch;
            k++;
        }
        else
        {
            if(HeadFlag == TRUE)
            {
                j++;
                k = 0;
                HeadFlag = FALSE;
            }
        }

        i++;



    }while(ch!=0);

#ifdef DEBUG
    for(i = 0; i < j+1; i++)
    {
        printf("%s ",token[i]);
    }
#endif

}

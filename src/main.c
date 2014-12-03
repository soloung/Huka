#include <stdio.h>
#include <stdlib.h>
#include"Token.h"
#include"operator.h"
#include"common.h"

int main()
{
	char statements[100] = {0};
	//scanf("%[a-zA-Z1-9 ]",statements);
	//printf("%s\n",statements);
    //Token(statements);
    infix2postfix();
    parse();


    return 0;
}

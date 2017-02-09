#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

int main(int argc, char const *argv[])
{
	int type;
	char s[MAXOP];
	double op2;

	while((type=getop(s))!=EOF){
		switch(type){
			case NUMBER:{
				push(atof(s));
				break;
			}
			case '+':{
				push(pop()+pop());
				break;
			}
			case '-':{
				op2=pop();
				push(pop()-op2);
				break;
			}
			case '*':{
				push(pop()*pop());
				break;
			}
			case '/':{
				if(op2=pop()!=0)
					push(pop() / op2);
				else
					printf("ERR: division by zero!\n");
				break;
			}
			case 's':{
				push(sin(pop()));
				break;
			}
			case 'e':{
				push(exp(pop()));
				break;
			}
			case 'p':{
				op2=pop();
				push(pow(pop(),op2));
				break;
			}
			case '%':{
				if((op2=pop())!=0)
					push( (int)(pop()) % (int)(op2));
				else
					printf("ERR: division by zero!\n");
				break;
			}
			case '\n':{
				//printf("%g\n",pop());
				break;
			}
			case '=':{
				printf("%g\n",pop());
				break;
			}
			case '?':{
				printf("%g\n",gettop());
				break;
			}
			case '!':{
				topx2();
				break;
			}
			case '$':{
				swap();
				break;
			}
			case '_':{
				clear();
				break;
			}
			case '#':{
				showstack();
				break;
			}
			default:{
				printf("ERR: wrong input!\n");
				break;
			}
		}
	}

	return 0;
}
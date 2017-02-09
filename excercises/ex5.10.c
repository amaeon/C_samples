#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMBER '0'

int getop(char *s);
double pop();
void push(double f);

int main(int argc, char *argv[])
{
	int c;
	double op2;
	while(--argc>0){
		++argv;
		switch(getop(*argv)){
			case NUMBER: {push(atof(*argv)); break;}
			case '+': {push(pop()+pop()); break;}
			case '-': {op2=pop(); push(pop()-op2); break;}
			case '*': case 'x': {push(pop()*pop()); break;}
			case '/': {if((op2=pop())!=0.0) push(pop()/op2); else {fprintf(stderr,"main: div by 0!\n"); push(op2);} break;}
			case '%': {break;}
			case '=': {printf("=%lf\n",pop()); break;}
		}
	}

	return 0;
}

int getop(char *s)
{
	if(isdigit(*s) || *s=='.' || (*s=='-'&&isdigit(*(s+1))) )
		return NUMBER;
	else return *s;
}

#define MAXSTACK 100
double stk[MAXSTACK];
int sp=0;

void push(double f)
{
	if (sp<MAXSTACK)
		stk[sp++]=f;
	else
		fprintf(stderr,"stack is full, can't push!\n");
}

double pop()
{
	if(sp>0)
		return stk[--sp];
	else{
		fprintf(stderr,"stack is empty!\n");
		return 0.0;
	}
}
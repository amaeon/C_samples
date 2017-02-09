#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXOP 100

void push(double f);
double pop(void);

int getop(char s[]);

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
			case '%':{
				if((op2=pop())!=0)
					push( (int)(pop()) % (int)(op2));
				else
					printf("ERR: division by zero!\n");
				break;
			}
			case '\n':{
				printf("%g\n",pop());
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

#define MAXSTACK 100

int sp = 0;
double stk[MAXSTACK];

void push(double f)
{
	if(sp<MAXSTACK)
		stk[sp++]=f;
	else
		printf("ERR: Stack full, can't push!\n");
}

double pop(void)
{
	if(sp>0)
		return stk[--sp];
	else{
		printf("ERR: Stack empty!\n");
		return 0.0;
	}
}

int getop(char s[])
{
	static int ct=0;
	int i,c;
	i=0;

	if(ct==0){
		c=getchar();
	}
	else{
		c=ct;
		ct=0;
	}

	while((s[0]=c)==' ' || c=='\t' )
		c=getchar();						// ignore space, last taken symbol goes to s[0]
	s[1]='\0';									// terminate line (will work if there's all)
	if(!isdigit(c) && c!='.')			// not number: maybe sign such as + or * which will be returned
			return c;

	if(isdigit(c))
		while( isdigit(s[++i]=c=getchar()));	// collecting whole part
	if(c=='.')
		while( isdigit(s[++i]=c=getchar()));	// collecting fract part
	s[i]='\0';
	if(c!=EOF)
		ct=c;
	return NUMBER;
}


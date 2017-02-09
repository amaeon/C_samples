#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NUMBER '0'
#define MAXOP 100
#define MAXLINE 1000

void push(double f);
double pop(void);
void pstack(void);

int getline();
int getop(char s[]);

char line[MAXLINE];
int pos=0;			// position of processing

int main(int argc, char const *argv[])
{
	int type;
	int len;
	char s[MAXOP];
	double op2;

	while((len=getline())>0){
		while(pos<len-1)
		switch(type=getop(s)){
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
			case '/': case '\\':{
				if((op2=pop())!=0)
					push(pop() / op2);
				else{
					push(op2);
					printf("ERR: division by zero!\n");
				}
				break;
			}
			case '%':{
				if((op2=pop())!=0)
					push( (int)(pop()) % (int)(op2));
				else
					printf("ERR: division by zero!\n");
				break;
			}
			case '=':{
				printf("%g\n",pop());
				break;
			}
			case '\n':{
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

int getline()
{
	int i,c;

	for(i=0; i<MAXLINE-1 && (c=getchar())!='\n' && c!=EOF; i++)
		line[i]=c;
	if(c=='\n')
		line[i++]=c;
	line[i]='\0';
	pos=0;
	return i;
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

void pstack(void)
{
	int i;
	for(i=sp-1; i>=0; i--)
		printf("%g ",stk[i]);
	printf("\n");
}

int getop(char s[])
{
	int i=0;
	while(line[pos]==' ' || line[pos]=='\t')
		pos++;									// ignore space
	if(!isdigit(line[pos]) && line[pos]!='.'){	// not number -> return (operation?) symbol
		int t=pos;
		while(line[pos]!=' ' && line[pos]!='\t' && line[pos]!='\n')
			pos++;
		return line[t];
	}

	while(isdigit(line[pos]) && i<MAXOP-1)
		s[i++]=line[pos++];
	if(line[pos]=='.' && i<MAXOP-1){
		s[i++]=line[pos++];
		while(isdigit(line[pos]) && i<MAXOP-1)
			s[i++]=line[pos++];
	}
	s[i]='\0';
	return NUMBER;
}

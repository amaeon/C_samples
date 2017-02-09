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
			}
			case '%':{
				if((op2=pop())!=0)
					push( (int)(pop()) % (int)(op2));
				else
					printf("ERR: division by zero!\n");
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


int getch(void);
void ungetch(int c);

int getop(char s[])
{
	int i,c;
	i=0;

	while((s[0]=c=getch())==' ' || c=='\t' );	// ignore space, last taken symbol goes to s[0]
	s[1]='\0';									// terminate line (will work if there's all)
	if(!isdigit(c) && c!='.' && c!='-')			// not number: maybe sign such as + or * which will be returned
			return c;

	if (c=='-')						// processing negative number
		if(isdigit( c=getch() ))	// BUT doesn't work if enter pressed after '-'
			ungetch(c);
		else return c;

	if(isdigit(c) || c=='-')
		while( isdigit(s[++i]=c=getch()));	// collecting whole part
	if(c=='.')
		while( isdigit(s[++i]=c=getch()));	// collecting fract part
	s[i]='\0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp=0;

int getch()
{
	return (bufp>0)? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp<BUFSIZE)
		buf[bufp++]=c;
	else
		printf("ungetch: too many characters!\n");
}
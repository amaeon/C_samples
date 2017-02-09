#include <stdio.h>

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
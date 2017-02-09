#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 1000

int buf[BUFSIZE];
int bufp=0;

int getch(void);
void ungetch(int c);
void ungets(char s[]);

int main(int argc, char const *argv[])
{
	int c;
	char s[] = "Let there be\nLIGHT!\n";
	while((c=getch())!='~'){
		if(c=='#')
			ungets(s);
		else
			putchar(c);
	}
	return 0;
}

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

void ungets(char s[])
{
	int i=strlen(s);
	while(i>=0)
		ungetch(s[i--]);
}
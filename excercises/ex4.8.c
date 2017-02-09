#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

int main(int argc, char const *argv[])
{
	int c;
	while((c=getch())!='~'){
		if(c=='#'){
			ungetch('~');
			putchar(getch());
		}
		else
			putchar(c);
	}
	return 0;
}

int buf=0;

int getch()
{
	int t;
	if(buf==0)
		return getchar();
	else{
		t=buf;
		buf=0;
		return t;
	}
}

void ungetch(int c)
{
	if(buf==0)
		buf=c;
	else
		printf("ungetch: too many characters!");
}

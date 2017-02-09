#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

FILE *f;

int main(int argc, char const *argv[])
{
	f = fopen("in.txt","r");
	int c;
	while(c!=EOF && (c=getch())!='~'){
		ungetch(c);
		putchar(getch());
	}
	fclose(f);
	return 0;
}

int buf=0;

int getch()
{
	int t;
	if(buf==0)
		return getc(f);
	else{
		t=buf;
		buf=0;
		return t;
	}
}

void ungetch(int c)
{
	if(c==EOF){
		printf("\nungetch: can't ungetch EOF\n");
		return;
	}
	if(buf==0)
		buf=c;
	else
		printf("\nungetch: too many characters!\n");
}

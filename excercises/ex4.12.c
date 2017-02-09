#include <stdio.h>
#include <string.h>

#define MAXLINE 100

void itoa(int n, char s[]);
void alt_itoa(int n, char s[]);		// alternative version i've done first -- with strcat()

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	int a;
	scanf("%d",&a);
	itoa(a,line);
	printf("%s\n",line);
	return 0;
}

void itoa(int n, char s[])
{
	static int i=0;
	if(n<0){
		s[i++]='-';
		n=-n;
	}
	if(n/10>0)
		itoa(n/10,s);
	s[i++]=n%10 + '0';
	s[i]='\0';
}

void alt_itoa(int n, char s[])
{
	char st[] = "*";
	if(n<0){
		strcat(s,"-");
		n=-n;
	}
	if(n/10>0)
		itoa(n/10,s);
	st[0]=n%10 + '0';
	strcat(s,st);
}

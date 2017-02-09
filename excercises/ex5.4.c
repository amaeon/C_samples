#include <stdio.h>

#define MAXLINE 1000

int getline(char *s, int lim);
int strend(char *s, char *t);

int main(int argc, char const *argv[])
{
	char s1[MAXLINE];
	char s2[MAXLINE];
	getline(s1,MAXLINE);
	getline(s2,MAXLINE);
	
	printf("%s\n",strend(s1,s2)?"YES":"NO");

	return 0;
}

int getline(char *s, int lim)	// special version -- without \n
{
	int i,c;

	for(i=0; i<lim-1 && (c=getchar())!='\n' && c!=EOF; i++)
		s[i]=c;
/*	if(c=='\n')	
		s[i++]=c;*/
	s[i]='\0';
	return i;
}

int strend(char *s, char *t)
{
	char *k=t;
	while(*s!='\0'){
		if(*s==*k)
			k++;
		else
			k=t;
		if(*k=='\0')
			return 1;
		s++;
	}
	return 0;
}
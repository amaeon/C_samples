#include <stdio.h>

#define MAXLINE 1000

int getline(char *s, int lim);
char *strncpy(char *s, char *t, int n);
char *strncat(char *s, char *t, int n);
int strncmp(char *s, char *t, int n);


int main(int argc, char const *argv[])
{
	char s1[MAXLINE];
	char s2[MAXLINE];
	int n;

	getline(s1,MAXLINE);
	getline(s2,MAXLINE);
	scanf("%d",&n);

	int r=strncmp(s1,s2,n);
	if(r!=0)
		printf("\"%s\" is first\n",r<0?s1:s2);
	else
		printf("Lines are equal\n");

	return 0;
}

int getline(char *s, int lim)
{
	int i,c;

	for(i=0; i<lim-1 && (c=getchar())!='\n' && c!=EOF; i++)
		s[i]=c;
	/*if(c=='\n')
		s[i++]=c;*/
	s[i]='\0';
	return i;
}

char *strncpy(char *s, char *t, int n)
{
	char *r=s;
	while(n-- >0 && (*s++=*t++)!='\0');
	*s='\0';
	return r;
}

char *strncat(char *s, char *t, int n)
{
	char *r=s;
	for(;*s!='\0';s++);
	while(n-->0 && (*s++=*t++)!='\0');
	*s='\n';
	return r;
}

int strncmp(char *s, char *t, int n)
{
	for(;n>0 && *s==*t && *s!='\0' && *t!='\0'; n--,s++,t++);
	return (n>0)? *s-*t : *--s-*--t;	// if n ends we should compare previous symbols
}
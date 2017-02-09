#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int getline(char *s, int lim);
int atoi(char *s);
char *itoa(int n, char *s);
char *reverse(char *s);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	char line2[MAXLINE];
	int len,n;
	len=getline(line,MAXLINE);
	printf("%d: %s\n",len,line);
	printf("%d\n",n=atoi(line));
	reverse(line);
	printf("%s\n",line);
	reverse(line);
	printf("%s\n",line);
	printf("%s\n",itoa(n,line2));
	return 0;
}

int getline(char *s, int lim)
{
	int c;
	char *p;
	for(p=s; lim-1>0 && (c=getchar())!='\n' && c!=EOF; s++)
		*s=c;
	if(c=='\n')
		*s++=c;
	*s='\0';
	return s-p+1;
}

int atoi(char *s)
{
	int n,sign;
	while(isspace(*s))
		s++;
	sign=(*s=='-')?-1:1;
	if(*s=='-' || *s=='+')
		s++;
	for(n=0; isdigit(*s); s++)
		n = n*10 + (*s - '0');
	return n*sign;
}

char *itoa(int n, char *s)
{
	char *r=s;
	int sign;
	if((sign=n)<0)
		n=-n;
	for(;n>0; n/=10)
		*s++ = '0' + n%10;
	if(sign<0)
		*s++='-';
	*s='\0';
	reverse(r);
	return r;
}

char *reverse(char *s)
{
	char *r,*t,c;
	r=t=s;
	while(*t!='\0')
		t++;
	t--;
	while(s<t){
		c=*s;
		*s++=*t;
		*t--=c;
	}
	return r;
}
#include <stdio.h>
#include <ctype.h>

int getch();
void ungetch(int c);
int buf=0;				// buffer for getch/ungetch

int getint(int *pn);

int main(int argc, char const *argv[])
{
	int a,s,res;
	s=0;
	while((res=getint(&a))>=0)
		if(res>0){
			s+=a;
			printf("+%d = %d\n",a,s);
		}
	return 0;
}

int getint(int *pn)
{
	int c,sign;

	while(isspace(c=getch()));		// ignore spaces
	if(!isdigit(c) && c!='-' && c!='+' && c!=EOF){
		ungetch(c);
		return 0;
	}
	sign=(c=='-')?-1:1;
	if(c=='-'||c=='+')				// ungetch sigh and then return 0
		if(!isdigit(c=getch())){
			ungetch(sign>0?'+':'-');
			return 0;
		}
	for(*pn=0; isdigit(c); c=getch())
		*pn = *pn*10 + (c-'0');
	*pn *= sign;
	if(c!=EOF)
		ungetch(c);
	return c;
}

int getch()
{
	if(buf==0)
		return getchar();
	else{
		int t=buf;
		buf=0;
		return t;
	}
}

void ungetch(int c)
{
	if(buf==0)
		buf=c;
	else
		printf("\nCan't ungetch: buffer is full!\n");
}
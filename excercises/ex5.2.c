#include <stdio.h>

int getch();
void ungetch(int c);
int buf=0;

int getfloat(float *pf);

int main(int argc, char const *argv[])
{
	float a,s;
	int res;
	s=0.0;
	while ((res=getfloat(&a))>=0)
		if(res>0){
			s+=a;
			printf("+%.3f =%.3f\n",a,s);
		}

	return 0;
}

int getfloat(float *pf)
{
	int c, sign;
	float power;
	*pf=0.0;

	while(isspace(c=getch()));	// ignore spaces

	if(!isdigit(c) && c!='.' && c!='-' && c!= '+' && c!=EOF){
		ungetch(c);
		return 0;
	}
	sign=(c=='-')?-1:1;
	if(c=='-'||c=='+')
		c=getch();
	for(*pf=0.0; isdigit(c); c=getch())
		*pf = *pf*10.0 + (c-'0');
	if(c=='.')
		c=getch();
	for(power=1.0; isdigit(c); c=getch(),power*=10.0)
		*pf = *pf*10.0 + (c-'0');
	*pf*= sign/power;
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
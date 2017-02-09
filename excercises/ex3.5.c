#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
	int a,b;
	char line[MAXLINE];
	scanf("%d %d",&a,&b);
	itob(a,line,b);
	printf("%s\n",line);
	return 0;
}

void reverse(char s[])
{
	int i,j,c;
	for(i=0,j=strlen(s)-1; i<j; i++,j--){
		c=s[i];
		s[i]=s[j];
		s[j]=c;
	}
}

void itob(int n, char s[], int b)
{
	int i,d,sign;
	unsigned int un;
	un = abs(n);
	sign = (n>0)?1:-1;
	i=0;
	do{
		d=un%b;
		if(d<10)
			s[i++]=d+'0';
		else if(d<36)
			s[i++]=d-10+'A';
		else
			s[i++]='#';
	}while((un /= b)>0);
	if(sign<0)
		s[i++]='-';
	s[i]='\0';
	reverse(s);
}
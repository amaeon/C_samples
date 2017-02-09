#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]);
void itoa(int n, char s[], int m);

int main(int argc, char const *argv[])
{
	int a,b;
	char line[MAXLINE];
	scanf("%d %d",&a,&b);
	itoa(a,line,b);
	printf("%s\n",line);
	return 0;
}

void reverse(char s[])
{
	int c,i,j;
	for(i=0,j=strlen(s)-1; i<j; i++,j--){
		c=s[i];
		s[i]=s[j];
		s[j]=c;
	}
}

void itoa(int n, char s[], int m)
{
	int i,sign;
	unsigned int un;
	un = abs(n);
	sign=(n>0)?1:-1;
	i=0;
	do{
		s[i++]= un%10 + '0';
	}while((un/=10)>0);
	if(sign<0)
		s[i++]='-';
	s[i]='\0';
	int r;
	for(r=m-strlen(s); r>0; r--)
		s[i++]=' ';
	s[i]='\0';
	reverse(s);
}
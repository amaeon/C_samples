#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
	int a;
	char line[MAXLINE];
	scanf("%d",&a);
	itoa(a,line);
	printf("%s\n",line);

	return 0;
}

void itoa(int n, char s[])
{
	int i, sign;
	unsigned int un;
	un = abs(n);

 	sign=(n>0)?1:-1;
	i=0;
	do{
		s[i++]= un%10+'0';
	}while((un /= 10)>0);
	if (sign<0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
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
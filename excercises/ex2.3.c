#include <stdio.h>
#include <ctype.h>
#define MAXLEN 12

int getline(char s[], int lim);
int htoi(char s[]);

int main(int argc, char const *argv[])
{
	int c;
	char s[MAXLEN];

	getline(s,MAXLEN);

	printf("%d\n",htoi(s));
	return 0;
}

int getline(char s[], int lim)
{
	int i=0;
	int c;
	while(i<lim-1 && (c=getchar())!='\n' && c!=EOF)
		s[i++]=c;
	if(c=='\n')
		s[i++]='\n';
	s[i]='\0';
	return i;
}

int htoi(char s[])
{
	int n=0;
	int correct = 1;
	int i=0;
	while(isspace(s[i])) // ignoring empty space
		++i;
	int sign = (s[i]=='-')?-1:1;
	if (s[i]=='+' || s[i]=='-')		// ignore sign
		++i;
	if(s[i]=='0' && (s[i+1]=='x' || s[i+1]=='X')) // ignore 0x or 0X 
		i+=2;
	while(s[i]!='\n' && s[i]!='\0'){
		int d;
		switch(s[i]){
			case 'A': case 'a': {d=10; break;}
			case 'B': case 'b': {d=11; break;}
			case 'C': case 'c': {d=12; break;}
			case 'D': case 'd': {d=13; break;}
			case 'E': case 'e': {d=14; break;}
			case 'F': case 'f': {d=15; break;}
			default: {
				if(isdigit(s[i]))
					d=(s[i]-'0');
				else
					d=correct=0;
			}
		}
		n = n*16 + d;
		++i;
	}
	if(!correct)
		printf("Incorrect input! Result is not unsafe!\n");
	return sign*n;
}
#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[], int a, int b);
int getline(char s[], int lim);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	getline(line,MAXLINE);
	reverse(line,0,strlen(line)-1);
	printf("%s\n",line);
	return 0;
}

void reverse(char s[], int a, int b){
	int t = s[a];
	s[a]=s[b];
	s[b]=t;
	if(a<b)
		reverse(s,a+1,b-1);
}

int getline(char s[], int lim)
{
	int c,i;
	for(i=0; i<lim-1 && (c=getchar())!='\n' && c!=EOF; i++)
		s[i]=c;
	s[i]='\0';
	return i;
}
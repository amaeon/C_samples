#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char from[], char to[]);

int main()
{
	int len;
	char line[MAXLINE];
	char enil[MAXLINE];

	while( (len=getline(line,MAXLINE))>0 ){
		reverse(line,enil);
		printf("%s",enil);		
	}
	return 0;
}

int getline(char line[], int maxline)
{
	int i,c;
	for(i=0; i<maxline-1 && (c=getchar())!='\n' && c!=EOF && c!='`'; ++i){
		line[i]=c;
	}
	if(c=='\n'){
		line[i]=c;
		++i;
	}
	if(c=='`')
		return -1;
	line[i]='\0';
	return i;
}

void reverse(char from[], char to[])
{
	int i=0;
	while(from[i]!='\0')
		++i;
	--i;
	int j=0;
	while(i>=0){
		if(from[i]!='\n'){
			to[j]=from[i];
			++j;
		}
		--i;
	}
	to[j]='\n';
	++j;
	to[j]='\0';
}
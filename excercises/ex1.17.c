#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char from[], char to[]);

int main()
{
	int len;
	char line[MAXLINE];

	while( (len=getline(line,MAXLINE))>0 )
		if(len>80)
			printf("%s",line);
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

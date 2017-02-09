#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
int clear(char line[]);

int main()
{
	int len;
	char line[MAXLINE];

	while( (len=getline(line,MAXLINE))>0 ){
		len=clear(line);
		if (len>1)
			printf("%s",line);
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

int clear(char line[])
{
	int i=0;
	while (line[i]!='\0')
		++i;
	i=i-2; //back before \n appears
	while (line[i]=='\t' || line[i]==' ')
		--i;
	++i;
	line[i]='\n';
	++i;
	line[i]='\0';
	return i;
}
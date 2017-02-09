#include <stdio.h>

#define MAXLINE 1000

int getline(char *s, int lim);
void strcat(char *s, char *t);

int main(int argc, char const *argv[])
{
	char prefix[MAXLINE];
	char suffix[MAXLINE];
	*prefix='\0';
	strcat(prefix,"Hello, ");
	printf("What's your name?\n");
	getline(suffix,MAXLINE);
	strcat(prefix,suffix);
	printf("%s\n",prefix);

	return 0;
}

int getline(char *s, int lim)
{
	int i,c;

	for(i=0; i<lim-1 && (c=getchar())!='\n' && c!=EOF; i++)
		s[i]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}

void strcat(char *s, char *t)
{
	while(*s!='\0')
		s++;
	while((*s++=*t++)!='\0');
}
#include <stdio.h>
#define MAXLEN 1000

int getline(FILE *f, char s[], int lim);

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin=fopen("in.txt","r");
	myout=fopen("out.txt","w");

	int c;
	char line[MAXLEN];
	char maxline[MAXLEN];
	int len;
	int max=0;

	while((len=getline(myin,line,MAXLEN))>0)
		printf("%s\n",line);

	fclose(myin);
	fclose(myout);
	return 0;
}

int getline(FILE *f, char s[], int lim)
{
	int i,c;
	for(i=0; (i<lim-1) == ((c=fgetc(f))!='\n') == (c!=EOF) ==1; ++i)
		s[i]=c;
	if(c=='\n')
		s[i++]='\n';
	s[i]='\0';
	return i;
}

#include <stdio.h>
#define MAXLEN 1000
#define TOSCREEN 80

int getline(FILE *f, char s[], int lim);

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin=fopen("in.txt","r");
	myout=fopen("out.txt","w");

	int c;
	char line[MAXLEN];
	int len;

	while((len=getline(myin,line,MAXLEN))>0)
		if(len>TOSCREEN)
			printf("%s",line); 

	fclose(myin);
	fclose(myout);
	return 0;
}

int getline(FILE *f, char s[], int lim)
{
	int i=0;
	int c;
	while(i<lim-1 && (c=fgetc(f))!='\n' && c!=EOF)
		s[i++]=c;
	if(c=='\n')
		s[i++]='\n';
	s[i]='\0';
	return i;
}

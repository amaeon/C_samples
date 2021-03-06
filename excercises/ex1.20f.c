#include <stdio.h>
#define MAXLEN 1000
#define TABPOS 4

int getline(FILE *f, char s[], int lim);
void detab(char from[], char to[]);

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin=fopen("in.txt","r");
	myout=fopen("out.txt","w");

	int c;
	char line[MAXLEN];
	char newline[MAXLEN];
	int len;

	while((len=getline(myin,line,MAXLEN))>0){
		detab(line,newline);
		fprintf(myout,"%s",newline);
	}

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

void detab(char from[], char to[])
{
	int i,j,k;
	for(i=0,j=0; from[i]!='\0'; ++i)
		if (from[i]=='\t'){
			for(k=TABPOS-i%TABPOS; k>0; --k,j++)
				to[j]=' ';
		}
		else{
			to[j]=from[i];
			++j;
		}
	to[j]='\0';
}
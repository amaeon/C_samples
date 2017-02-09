#include <stdio.h>
#define MAXLEN 12

int getline(FILE *f, char s[], int lim);
void copy(char from[], char to[]);

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin=fopen("ex1.16f.c","r");
	myout=fopen("out.txt","w");

	int c;
	char line[MAXLEN];
	char maxline[MAXLEN];
	int len;
	int slen=0;
	int max=0;

	while((len=getline(myin,line,MAXLEN))>0){
		slen+=len;
		if(len<MAXLEN-1 || (len==MAXLEN-1)&&(line[MAXLEN-2]=='\n')){
			if(slen>max)
				max=slen;
			slen=0;
		}
		/*if(len>max)
			max=len;*/
	}

	if(max>0)
		printf("length=%d\n",max);

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

void copy(char from[], char to[])
{
	int i=0;
	while((to[i]=from[i])!='\0')
		i++;
}
/*There is the longest line in file: to test program for finding a longest line if it is last line in file*/
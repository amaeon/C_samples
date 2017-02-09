#include <stdio.h>
#define MAXLEN 1000
#define ENOUGH 60

int getline(FILE *f, char s[], int lim);
int divide(FILE *f, char s[], int lim);

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin=fopen("in.txt","r");
	myout=fopen("out.txt","w");

	char line[MAXLEN];
	char newline[MAXLEN];
	int len;

	while((len=getline(myin,line,MAXLEN))>0){
		entab(line,newline);
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

int divide(FILE *f, char s[], int lim)
{
	int i,j,k;
	int p1,p2;
	p1=p2=0;
	while(s[i]!='\n' && s[i]!='\0'){
		++i;
		++k;
		if(k==lim){
			p1=p2;
			p2=i+1;			
		}
	}
}
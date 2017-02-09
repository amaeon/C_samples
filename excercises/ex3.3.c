#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1200

int getline(FILE *f, char s[], int lim);
void expand(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin=fopen("in.txt","r");
	myout=fopen("out.txt","w");

	char line[MAXLINE];
	char newline[MAXLINE];
	while(getline(myin,line,MAXLINE)>0){
		expand(line,newline);
		fprintf(myout,"%s",newline);
	}

	fclose(myin);
	fclose(myout);
	return 0;
}

int getline(FILE *f, char s[], int lim)
{
	int i,c;
	for(i=0; i<lim-1 && (c=fgetc(f))!='\n' && c!=EOF; i++)
		s[i]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}

void expand(char s1[], char s2[])
{
	int c1, c2;
	int i,j,k;
	s2[0]=s1[0];
	for(i=j=1; s1[i]!='\0'; i++){
		if(s1[i]=='-'){
			if(isdigit(s1[i-1])&&isdigit(s1[i+1]) || isalpha(s1[i-1])&&isalpha(s1[i+1])){
				c1=s1[i-1];
				c2=s1[i+1];
				for(k=c1+1; k<c2; k++)
					s2[j++]=k;
			}
			else s2[j++]=s1[i];
		}
		else s2[j++]=s1[i];
	}
	s2[j]='\0';
}
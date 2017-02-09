#include <stdio.h>
#define MAXLINE 1000

int getline(FILE *f, char s[], int lim);
void escape(char s1[], char s2[]);
void unescape(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin=fopen("in.txt","r");
	myout=fopen("out.txt","w");

	char line[MAXLINE];
	char newline[MAXLINE];
	char newest[MAXLINE];

	while(getline(myin,line,MAXLINE)>0){
		escape(line,newline);
		fprintf(myout,"%s\n",newline);
		unescape(newline,newest);
		fprintf(myout,"%s",newest);
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

void escape(char s1[], char s2[])
{
	int i,j;
	for(i=j=0; s1[i]!='\0'; i++){
		switch(s1[i]){
			case '\a': {s2[j++]='\\'; s2[j++]='a'; break;}
			case '\b': {s2[j++]='\\'; s2[j++]='b'; break;}
			case '\f': {s2[j++]='\\'; s2[j++]='f'; break;}
			case '\n': {s2[j++]='\\'; s2[j++]='n'; break;}
			case '\r': {s2[j++]='\\'; s2[j++]='r'; break;}
			case '\t': {s2[j++]='\\'; s2[j++]='t'; break;}
			case '\v': {s2[j++]='\\'; s2[j++]='v'; break;}
			case '\\': {s2[j++]='\\'; s2[j++]='\\'; break;}
			case '\?': {s2[j++]='\\'; s2[j++]='?'; break;}
			case '\'': {s2[j++]='\\'; s2[j++]='\''; break;}
			case '\"': {s2[j++]='\\'; s2[j++]='\"'; break;} 
			default: {s2[j++]=s1[i]; }
		}
	}
	s2[j]='\0';
}

void unescape(char s1[], char s2[])
{
	int i,j;
	for(i=j=0; s1[i]!=0; i++){
		if(s1[i]=='\\'){
			switch(s1[++i]){
				case 'a': {s2[j++]='\a'; break;}
				case 'b': {s2[j++]='\b'; break;}
				case 'f': {s2[j++]='\f'; break;}
				case 'n': {s2[j++]='\n'; break;}
				case 'r': {s2[j++]='\r'; break;}
				case 't': {s2[j++]='\t'; break;}
				case 'v': {s2[j++]='\v'; break;}
				case '\\': {s2[j++]='\\'; break;}
				case '?': {s2[j++]='\?'; break;}
				case '\'': {s2[j++]='\''; break;}
				case '\"': {s2[j++]='\"'; break;}
				default: {s2[j++]='\\';}
			}
		}
		else
			s2[j++]=s1[i];
	}
	s2[j]='\0';
}
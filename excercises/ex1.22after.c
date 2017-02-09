#include <stdio.h>

#define MAXLINE 100000
#define WRAPPOS 40

int getline(FILE *f, char *s, int lim);
int wrapline(char *to, char *from, int pos, int nl);

int main(int argc, char const *argv[])
{
	FILE *f1, *f2;
	f1=fopen("in.txt","r");
	f2=fopen("out.txt","w");

	char s1[MAXLINE];
	char s2[MAXLINE];
	int len, lastpos;
	lastpos=0;

	len=0;
	while(len>=0){
		len=getline(f1,s1,MAXLINE);
		while(lastpos>=0){
			lastpos=wrapline(s2,s1,lastpos,WRAPPOS-1);
			fprintf(f2,"%s\n",s2);
		}
		lastpos = 0;
	}

	fclose(f1);
	fclose(f2);
	return 0;
}

int getline(FILE *f, char *s, int lim)	// without \n
{
	int c,i;
	char *t = s;

	while(--lim>0 && (c=getc(f))!='\n' && c!=EOF)
		*s++=c;
	*s='\0';
	if (c==EOF) return -1;
	return s-t;
}

int wrapline(char *to, char *from, int pos, int nl)
{
	int i,j,spos;
	while (from[pos]==' ' || from[pos]=='\t')
		pos++;
	spos=pos;
	while(from[pos]!='\0' && nl-->0)
		pos++;
	if(from[pos]=='\0'){
		do{
			--pos;
		}while(from[pos]==' ' || from[pos]=='\t');
		for(i=spos,j=0; i<=pos; i++,j++ )
			to[j]=from[i];
		to[j]='\0';
		return -1;
	}
	else if(from[pos]==' ' || from[pos]=='\t'){
		pos--;
		while((from[pos]==' ' || from[pos]=='\t')&&pos>spos)
			pos--;
		for(i=spos,j=0; i<=pos; i++,j++ )
			to[j]=from[i];
		to[j]='\0';
		return pos+1;
	}
	else{
		pos--;
		for(i=pos; i>spos && from[i]!=' ' && from[i]!='\t'; i--);
		while(from[i]==' ' || from[i]=='\t')
			i--;
		if(i!=spos)
			pos=i;
		for(i=spos,j=0; i<=pos; i++,j++ )
			to[j]=from[i];
		to[j]='\0';
		return pos+1;
	}
}
#include <stdio.h>
#define MAXLEN 120

int getline(char s[], int lim);
void squeeze1(char s[], int c);
void squeeze(char s1[], char s2[]);
int any(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
	char s1[MAXLEN];
	char s2[MAXLEN];
	int c;

	getline(s1,MAXLEN);
	getline(s2,MAXLEN);

	/*squeeze(s1,s2);
	printf("%s",s1);*/
	printf("%d\n",any(s1,s2));

	return 0;
}

int getline(char s[], int lim)
{
	int i=0;
	int c;
	while(i<lim-1 && (c=getchar())!='\n' && c!=EOF)
		s[i++]=c;
	if(c=='\n')
		s[i++]='\n';
	s[i]='\0';
	return i;
}

void squeeze1(char s[], int c)
{
	int i,j;
	for(i=j=0; s[i]!='\0'; i++)
		if(s[i]!=c)
			s[j++]=s[i];
	s[j]='\0';
}

void squeeze(char s1[], char s2[])
{
	int i,j,k;
	for(i=j=0; s1[i]!='\0'; i++){
		k=-1;
		while(s1[i]!=s2[++k] && s2[k]!='\n');
		if(s2[k]=='\n')
			s1[j++]=s1[i];
	}
	s1[j]='\0';
}

int any(char s1[], char s2[])
{
	int i,k;
	for(i=0; s1[i]!='\0'; i++){
		for(k=0; s1[i]!=s2[k] && s2[k]!='\n'; k++);
		if (s2[k]!='\n')
			return i;
	}
	return -1;
}
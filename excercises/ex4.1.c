#include <stdio.h>
// #include <string.h>

#define MAXLINE 1000

int getline(char s[], int lim);
int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);

int main(int argc, char const *argv[])
{
	char s1[MAXLINE];
	char s2[MAXLINE];
	if(getline(s1,MAXLINE)>0 && getline(s2,MAXLINE)>0){
		printf("%d\n",strrindex(s1,s2));
		// printf("%s\n%s",s1,s2);
	}
	return 0;
}

int getline(char s[], int lim)
{
	int i,c;
	for(i=0; --lim>0 && (c=getchar())!='\n' && c!=EOF; i++)
		s[i]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}

int strindex(char s[], char t[]) // stops before \n not \0
{
	int i,j,k;
	for(i=0; s[i]!='\0'; i++){
		for(j=i,k=0; t[k]!='\n' && s[j]==t[k]; j++,k++);
			if(k>0 && t[k]=='\n')
				return i;
	}
	return -1;
}

int strrindex(char s[], char t[]) // also stops before \n not \0
{
	int i,j,k;
	int klast;
	i=klast=0;
	while(s[i]!='\0')
		i++;
	while(t[klast+1]!='\n')
		klast++;
	while(i>=0){
		for(j=i,k=klast; k>=0 && j>=0 && s[j]==t[k]; j--,k--);
		if(k<0)
			return i-klast;
		else
			i--;
	}
	return -1;
}
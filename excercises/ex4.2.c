#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000
#define DIVISOR '.'

int getline(char s[], int lim);
double atof(char s[]);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	if(getline(line, MAXLINE)>0)
		printf("%E\n",atof(line));
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

double atof(char s[])
{
	double val, power;
	int i,sign;
	for(i=0; isspace(s[i]); i++); // ignoring empty space
	sign = (s[i]=='-')?-1:1;
	if(s[i]=='+'||s[i]=='-')	// ignore sign if any
		i++;
	for(val=0.0; isdigit(s[i]); i++)
		val = val*10.0 + (s[i]-'0');
	if(s[i]==DIVISOR)			// ignore divisor
		i++;
	for(power=1.0; isdigit(s[i]); i++){
		val = val*10.0 + (s[i]-'0');
		power*=10.0;
	}
	if(tolower(s[i])=='e'){
		int e,esign;
		i++;						// ignore e or E
		esign=(s[i]=='-')?-1:1;
		if(s[i]=='+'||s[i]=='-')	// ignore esign if any
			i++;
		for(e=0; isdigit(s[i]); i++)
			e= e*10 + (s[i]-'0');
		while(e>0){
			power = (esign>0)? power/10.0 : power*10.0;
			e--;
		}		
	}
	return sign*val/power;
}
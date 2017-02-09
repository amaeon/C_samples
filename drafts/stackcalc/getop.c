#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
	int i,c;
	i=0;

	while((s[0]=c=getch())==' ' || c=='\t' );	// ignore space, last taken symbol goes to s[0]
	s[1]='\0';									// terminate line (will work if there's all)
	if(!isdigit(c) && c!='.' && c!='-')			// not number: maybe sign such as + or * which will be returned
			return c;

	if (c=='-')						// processing negative number
		if(isdigit( c=getch() ))	// BUT doesn't work if enter pressed after '-'
			ungetch(c);
		else return '-';

	if(isdigit(c) || c=='-')
		while( isdigit(s[++i]=c=getch()));	// collecting whole part
	if(c=='.')
		while( isdigit(s[++i]=c=getch()));	// collecting fract part
	s[i]='\0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;
}
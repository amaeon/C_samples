#include <stdio.h>
/* This program counts spaces, tabs and EOL symbols */


int main()
{
	FILE *myin, *myout;
	myin = fopen("in.txt","r");
	myout = fopen("out.txt","w");

	int ns,nt,nl;
	ns=nt=nl=0;

	int c;
	while((c=fgetc(myin))!=EOF){
		switch(c){
			case ' ': {++ns; break;}
			case '\t': {++nt; break;}
			case '\n': {++nl; break;}
		}
	}
	printf("%d spaces\n",ns);
	printf("%d tabs\n",nt);
	printf("%d EOLs\n",nl);

	fclose(myin);
	fclose(myout); 
	return 0;
}
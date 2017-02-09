#include <stdio.h>
#define NSYM 256
#define FIRSTSYM 32
#define MAXHYST 78

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin = fopen("ex1.14f.c","r");
	myout = fopen("out.txt","w");

	int c;
	int qsym[NSYM];
	int i,j;
	for(i=0; i<NSYM; i++)
		qsym[i]=0;

	while((c=fgetc(myin))!=EOF)
		++qsym[c];

	for(i=FIRSTSYM; i<NSYM; i++){
		printf("%c ",i);
		for(j=0; j<qsym[i] && j<MAXHYST; j++)
			putchar('\xB1');
		printf("%d\n",qsym[i]);
	}


	fclose(myin);
	fclose(myout);
	return 0;
}
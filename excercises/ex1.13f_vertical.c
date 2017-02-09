#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXLEN 30+1

/* Makes vertical hystogram of words' lengths in input file */

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin = fopen("ex1.13f_vertical.c","r");
	myout = fopen("out.txt","w");

	int c;
	int nc=0;
	int state=OUT;
	int len[MAXLEN]={0};

	while((c=fgetc(myin))!=EOF){
		if (state==IN){
			if(c!=' ' && c!= '\t' && c!='\n')
				++nc;
			else{
				if(nc<MAXLEN)
					++len[nc];
				else
					++len[0];
				nc=0;
				state=OUT;
			}
		}
		else if(c!=' ' && c!='\t' && c!='\n'){
			++nc;
			state=IN;
		}
	}

	int i,j;
	int maxl=0;
	for(i=1; i<MAXLEN; i++)
		if(len[i]>maxl)
			maxl=len[i];

	for(j=maxl; j>0; j--){
		printf("\n%3d",j);
		for(i=1; i<MAXLEN; i++)
			putchar((len[i]>=j)?'\xB1':' ');
	}
	printf("\n   ");
	for(i=1; i<MAXLEN; i++)
		printf("%d",i%10);
	printf("\n   ");
	for(i=1,j=0; i<MAXLEN; i++)
		(i%10==0)?printf("%d",++j):printf(" ");
	printf("\n");
	if (len[0]>0)
		printf("There were %d words with length more than %d symbols!\n",len[0],MAXLEN-1);

	fclose(myin);
	fclose(myout);
	return 0;
}
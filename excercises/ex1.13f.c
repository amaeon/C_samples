#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 20+1 // for array indexes from 0 to MAXLEN

/* Makes hystogram of words' lengths in input file */

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin = fopen("in.txt","r");
	myout = fopen("out.txt","w");

	int c;
	int nc=0;
	int state=OUT;
	int len[MAXLEN] = {0};

	while((c=fgetc(myin))!=EOF){
		if(state==IN){
			if(c!=' ' && c!='\t' && c!='\n')
				++nc;
			else{
				if (nc<=MAXLEN)
					++len[nc];
				else
					++len[0];
				state=OUT;
				nc=0;
			}
		}
		else if(c!=' ' && c!='\t' && c!='\n'){
			++nc;
			state=IN;
		}
	}

	int i,j;
	printf("  ");
	for(i=1; i<MAXLEN; i++)
		printf("%d",i%10);
	putchar('\n');
	for(i=1; i<MAXLEN; i++){
		printf("%2d",i);
		for(j=0; j<len[i]; j++)
			putchar('\xB1');
		putchar('\n');
	}
	if(len[0]!=0)
		printf("There were %d words with length more than %d\n",len[0],MAXLEN-1);

	fclose(myin);
	fclose(myout);
	return 0;
}
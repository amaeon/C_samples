#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int c;
	int state; // in or out of word
	long nw;
	
	nw=0;
	state=OUT;
	while((c=getchar())!='`'){
		if (c!=' ' && c!='\t' && c!='\n'){
			if (state==OUT){
				++nw;
				state=IN;
			}
			//putchar(c);
		}
		else{
			state=OUT;
			//printf(" -word #%ld\n",nw);
		}
	}
	printf("\nTotal words: %ld\n",nw);

	return 0;
}
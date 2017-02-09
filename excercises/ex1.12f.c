#include <stdio.h>

/* Transofms input: writes every word in separate line */

#define IN 1
#define OUT 0

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin = fopen("in.txt","r");
	myout = fopen("out","w");

	int c;
	int state = OUT;
	while((c=fgetc(myin))!=EOF){
		if(c==' ' || c=='\t' || c=='\n'){
			if (state==IN){
				putchar('\n');
				state=OUT;
			}
		}
		else{
			putchar(c);
			state=IN;
		}
	}

	fclose(myin);
	fclose(myout);
	return 0;
}
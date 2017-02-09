#include <stdio.h>

/* Changes tabs, backspcs, \ into \t, \b and \\ */

int main(int argc, char const *argv[])
{
	FILE *myin, *myout;
	myin = fopen("in.txt","r");
	myout = fopen("out.txt","w");

	int c;
	while((c=fgetc(myin))!=EOF){
		switch (c){
			case '\t': {printf("\\t"); break;}
			case '\b': {printf("\\b"); break;}
			case '\\': {printf("\\\\"); break;}
			default: putchar(c);
		}
	}

	fclose(myin);
	fclose(myout);
	return 0;
}
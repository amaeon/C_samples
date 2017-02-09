#include <stdio.h>
/* Changes lines of one ore more spaces into one space 
22.08.2016 -- not finished (boring)*/


int main()
{
	FILE *myin, *myout;
	myin = fopen("in.txt","r");
	myout = fopen("out.txt","w");

	int c;
	int empty=1;
	int space=0;
	while((c=fgetc(myin))!=EOF){
		if (!empty || c=='\n')
			putchar(c);
		else{
			if (c!=' '){
				if (space) putchar(' ');
				putchar(c);
				space=empty=0;
			}
			else
				++space;
			
		}
		if (c=='\n')
			empty=1;
	}


	fclose(myin);
	fclose(myout);
	return 0;
}
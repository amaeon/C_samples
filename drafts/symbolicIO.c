#include <stdio.h>

int main()
{
	int c;
	long count;
	count=0;
	while((c=getchar())!=EOF){
		if (c=='\n'){
			++count;
			printf("\\n %ld",count);
		} 
		else
			putchar(c);
	}
	printf("\n\n\n%ld",count);
	return 0;
}
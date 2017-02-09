#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("%s: ",*argv);
	argc--;
	for(;argc>0;argc--)
		printf( (argc>1)?"%s ":"%s\n", *++argv  );
	getchar();
	return 0;
}
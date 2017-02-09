#include <stdio.h>

int main(int argc, char const *argv[])
{
	register unsigned int a=0;
	while(a<0xFFFFFFFF)
		a++;
	printf("%u\n",a);
	return 0;
}
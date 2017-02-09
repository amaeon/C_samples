#include <stdio.h>

void bin(unsigned int x);
int bitcount(unsigned int x);

int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d",&a);
	bin(a);
	printf("%d\n",bitcount(a));
	return 0;
}

void bin(unsigned int x)
{
	int i;
	for(i=15; i>=0; i-- )
		printf("%1d", (x>>i)&01);
	printf("\n");
}

int bitcount(unsigned int x)
{
	int i;
	for(i=0; x>0; x&=(x-1))
		++i;
	return i;
}
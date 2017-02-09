#include <stdio.h>

#define POS 1
#define WID 3

void bin(unsigned int x, int n);
unsigned int getbits(unsigned int x, int p, int n);
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
unsigned int invert(unsigned int x, int p, int n);
unsigned int rightrot(unsigned int x, int n);

int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d",&a);
	printf("%d\n",b=rightrot(a,WID));
	bin(a,8*sizeof(a));
	bin(b,8*sizeof(b));
	return 0;
}

void bin(unsigned int x, int n)
{
	int i;
	for(i=n-1; i>=0; --i)
		printf("%1d",(x>>i)&1);
	printf("\n");
}

unsigned int getbits(unsigned int x, int p, int n)
{
	return (x >> p) & ~(~0 << n);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	return (x & ~(~(~0 << n) << p)) | ((y & ~(~0 << n)) << p);
}

unsigned int invert(unsigned int x, int p, int n)
{
	return (~(~0 << n) << p) ^ x;
}

unsigned int rightrot(unsigned int x, int n)
{
	return ((~(~0 << n) & x) << 8*sizeof(x)-n) | (x >> n);
}
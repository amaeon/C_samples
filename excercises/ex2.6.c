#include <stdio.h>

#define POS 2
#define WID 3

void bin(unsigned int x, int n);
unsigned int getbits(unsigned int x, int p, int n);
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main(int argc, char const *argv[])
{
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%d\n",c=setbits(a,POS,WID,b));
	bin(a,8);
	bin(b,8);
	bin(c,8);
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
#include <stdio.h>

void foo(int k);

int main(void)
{	
	foo(0);
	return 0;
}

void foo(int k)
{
	static int a=0;
	if (k<10)
		foo(k+1);
	a+=1;
	printf("%d\n",a);
}
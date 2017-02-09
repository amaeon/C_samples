#include <stdio.h>
#include <limits.h>

int main()
{
	printf("EOF: %d\n",EOF);
	int a,b;
	a=111;
	b=-1;
	printf("a!=EOF: %d\n",a!=EOF);
	printf("b!=EOF: %d\n",b!=EOF);
}
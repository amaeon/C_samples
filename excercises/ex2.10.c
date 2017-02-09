#include <stdio.h>

int lower(int c); 

int main(int argc, char const *argv[])
{
	int c;
	c=getchar();
	printf("%c\n",lower(c));
	return 0;
}

int lower(int c)
{
	return (c>='A' && c<='Z')?(c+'a'-'A'):c;
}
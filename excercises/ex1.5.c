#include <stdio.h>

#define UPPER 300
#define LOWER -100
#define STEP 20

int main()
{
	float fahr, celsium;
	printf("CELS\tFAHR\n==================\n");
	for(celsium=UPPER; celsium>=LOWER; celsium-=STEP)
		printf("%3.0f\t%6.1f\n",celsium,fahr=celsium*(9.0/5.0)+32);

	return 0;
}
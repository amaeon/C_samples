#include <stdio.h>

int main()
{
	float fahr, cels;
	int upper, lower, step;

	lower = 0;
	upper = 300;
	step = 20;

	cels = lower;

	printf("CELSIUM\tFAHREN\n====================\n");
	while (cels<=upper){
		fahr = cels*(9.0/5.0)+32.0;
		printf("%3.0f\t%6.1f\n",cels,fahr);
		cels += step;
	}
	return 0;
}
#include <stdio.h>

int main()
{
	float fahr, cels;
	int upper, lower, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	while (fahr<=upper){
		cels = (fahr-32.0)*(5.0/9.0);
		printf("%3.0f\t%6.1f\n",fahr,cels);
		fahr += step;
	}
	return 0;
}
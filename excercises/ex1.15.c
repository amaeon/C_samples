#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float tconv_ctof(float c);
float tconv_ftoc(float f);

int main()
{
	printf("Table: Celsium to Fahrenheit\n");
	printf("CELS\tFAHR\n");
	float i;
	for(i=LOWER; i<=UPPER; i+=STEP)
		printf("%3.0f\t%3.1f\n",i,tconv_ctof(i));

	printf("\nTable: Fahrenheit to Celsium\n");
	printf("FAHR\tCELS\n");
	for(i=LOWER; i<=UPPER; i+=STEP)
		printf("%3.0f\t%3.1f\n",i,tconv_ftoc(i));
	return 0;
}

float tconv_ctof(float c)
{
	return (9.0/5.0)*c+32.0;
}

float tconv_ftoc(float f)
{
	return (f-32.0)*(5.0/9.0);
}
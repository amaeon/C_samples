#include <stdio.h>

#define swap(t, x, y) {t tmp=x; x=y; y=tmp;}

int main(int argc, char const *argv[])
{
	double a,b;
	printf("a=");
	scanf("%lf",&a);
	printf("b=");
	scanf("%lf",&b);
	
	swap(double,a,b);
	printf("Nooo! ;D\na=%lf\nb=%lf\n",a,b);
	return 0;
}
#include <stdio.h>
#include <limits.h>
#include <float.h>

#define FACT 1.0000001

int main()
{
	printf("INTEGER TYPES\n");
	printf("Taken from limits.h:\n");
	printf("signed char\t%ld...%ld\n",SCHAR_MIN,SCHAR_MAX);
	printf("unsigned char\t%ld...%ld\n",0,UCHAR_MAX);
	printf("signed short\t%ld...%ld\n",SHRT_MIN,SHRT_MAX);
	printf("unsigned short\t%ld...%ld\n",0,USHRT_MAX);
	printf("signed int\t%ld...%lu\n",INT_MIN,INT_MAX);
	printf("unsigned int\t%lu...%lu\n",0,UINT_MAX);
	printf("signed long\t%ld...%lu\n",LONG_MIN,LONG_MAX);
	printf("unsigned long\t%lu...%lu\n",0,ULONG_MAX);

	printf("\nCalculated directly:\n");

	signed char c;
	for(c=0;c>=0;c++);
	printf("signed char\t%ld...",c);
	printf("%ld\n",--c);

	unsigned char uc;
	for(uc=1;uc!=0;uc++);
	printf("unsigned char\t%ld...%ld\n",0,--uc);

	signed short sh;
	for(sh=0;sh>=0;sh++);
	printf("signed short\t%ld...",sh);
	printf("%ld\n",--sh);

	unsigned short ush;
	for(ush=1;ush!=0;ush++);
	printf("unsigned short\t%ld...%ld\n",0,--ush);

	{
		register signed int i;
		for(i=0; i>=0; i++);
		printf("signed int\t%d...",i);
		printf("%d\n",--i);
	}
	{
		register unsigned int ui;
		for(ui=1; ui!=0; ui++);
		printf("unsigned int\t%lu...%lu\n",0,--ui);
	}
	{
		register signed long l;
		for(l=0; l>=0; l++);
		printf("signed long\t%ld...",l);
		printf("%lu\n",--l);
	}
	{
		register unsigned long ul;
		for(ul=1; ul!=0; ul++);
		printf("unsigned long\t%lu...%lu\n",0,--ul);
	}

	printf("\nREAL TYPES\nCalculated directly:\n");
	{
		register float f1,f2;
		f1=1.0;
		f2=f1*FACT;
		while(_finite(f2)){
			f1=f2;
			f2*=FACT;
		}
		printf("float\t-%E...%E\n",f1,f1);
	}
	{
		register double d1,d2;
		d1=1.0;
		d2=d1*FACT;
		while(_finite(d2)){
			d1=d2;
			d2*=FACT;
		}
		printf("double\t-%E...%E\n",d1,d1);
	}

	printf("\nFrom float.h:\n");
	printf("float max: %E\n",FLT_MAX);
	printf("double max: %E\n",DBL_MAX);

	printf("\nDone!\n");
	return 0;
}
#include <stdio.h>
#include "calc.h"

#define MAXSTACK 100

int sp = 0;
double stk[MAXSTACK];

void push(double f)
{
	if(sp<MAXSTACK)
		stk[sp++]=f;
	else
		printf("ERR: Stack full, can't push!\n");
}

double pop(void)
{
	if(sp>0)
		return stk[--sp];
	else{
		printf("ERR: Stack empty!\n");
		return 0.0;
	}
}

double gettop(void)
{
	if(sp>0)
		return stk[sp-1];
	else{
		printf("ERR: Stack empty\n");
		return 0.0;
	}
}

void topx2(void)
{
	if(sp>0){
		stk[sp] = gettop();
		sp++;
	}
	else
		printf("ERR: Stack empty!\n");
}

void swap(void)
{
	if(sp>1){
		double t;
		t=stk[sp-1];
		stk[sp-1]=stk[sp-2];
		stk[sp-2]=t;
	}
	else
		printf("ERR: Less than two elements in stack!\n");
}

void clear(void)
{
	sp=0;
	printf("Stack clear!\n");
}

void showstack(void)
{
	int i;
	for(i=0; i<sp; i++)
		printf("%g ",stk[i]);
	printf("\n");
}
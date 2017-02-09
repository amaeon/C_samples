#include <stdio.h>

#define ASIZE 5

int A[ASIZE];

void qsort(int *A, int *I, int l, int r);
void qsortm(int *A, int l, int r);
void print();

int main(int argc, char const *argv[])
{
	int I[ASIZE];
	int i;
	srand(13);
	for(i=0; i<ASIZE; i++){
		//A[i]=rand()%ASIZE;
		scanf("%c",&A[i]);
		I[i]=i;
	}
	print();

	
	printf("UNSORTED:\n");
	for(i=0; i<ASIZE; i++)
		printf("%d ",A[i]);
	printf("\n");

	qsort(A,I,0,ASIZE-1);

	printf("SORTED:\n");
	for(i=0; i<ASIZE; i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}

void qsort(int *A, int *I, int l, int r)
{
	if(l>=r)
		return;
	int i,j,m;
	i=l;
	j=r;
	m=(l+r)/2;
	while(i<j){
		while(A[i]<A[m])
			i++;
		while(A[j]>A[m])
			j--;
		if(A[i]!=A[j] || (A[i]==A[j] && I[j]<I[i])){
			int t=A[i];
			A[i]=A[j];
			A[j]=t;
			t=I[i];
			I[i]=I[j];
			I[j]=t;
			if(m==i)
				m=j;
			else if(m==j)
				m=i;
			print();
		}
	}
	qsort(A,I,l,m-1);
	qsort(A,I,m+1,r);
}

void qsortm(int *A, int l, int r)
{
	if(l>=r)
		return;
	int i,j,m;

}

void print()
{
	int i;
	for(i=0; i<ASIZE; i++)
		printf("%c ",A[i]);
	printf("\n");
}
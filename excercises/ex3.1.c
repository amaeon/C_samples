#include <stdio.h>

#define SIZE 1200

int isprime(int n);
int binsearch(int x, int a[], int size);

int main(int argc, char const *argv[])
{
	// making array of prime numbers (sorted by ascending)
	int pr[SIZE];
	int i,j;
	pr[0]=2;
	for(i=1; i<SIZE; i++){
		for(j=pr[i-1]+1; !isprime(j); j++);
		pr[i]=j;
	}
	/*for(i=0; i<SIZE; i++)
		printf("%d ",pr[i]);*/
	int val;
	scanf("%d",&val);
	printf("%d\n",binsearch(val,pr,SIZE));

	return 0;
}

int isprime(int n)
{
	int i;
	for(i=n/2+1; i>1; i--)
		if(n%i==0){
			//printf("%d*n=%d",i,n);
			return 0;
		} 
	return 1;
}

int binsearch(int x, int a[], int size)
{
	int low, high, mid;
	low=0;
	high=size-1;
	mid = (low+high)/2;
	while(low<=high && x!=a[mid]){
		mid = (low+high)/2;
		if (x<a[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	if(x=a[mid])
		return mid;
	return -1;
}
#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 20

int main()
{
	int c,i,j;
	int state=OUT;
	int nsym=0;
	int lens[MAXLEN];
	for(i=0; i<MAXLEN; i++)
		lens[i]=0;

	while ((c=getchar())!='`'){
		if (state==IN)
			if (c!=' ' && c!='\n' && c!='\t')
				nsym++;
			else{
				state=OUT;
				if (nsym<MAXLEN)
					lens[nsym]++;
				else
					printf("\n\nMAXLENGTH OVERFLOW");
				nsym=0;
			}
		else if(c!=' ' && c!='\n' && c!='\t'){
			state=IN;
			nsym++;
		}
	}

	int max=-1;
	for(i=0; i<MAXLEN; i++)
		if (lens[i]>max)
			max=lens[i];

	for(j=max; j>0; j--){
		for(i=0; i<MAXLEN; i++)
			if (lens[i]>=j)
				printf("#");
			else
				printf(" ");
		printf("\n");
	}
	for(i=0; i<MAXLEN; i++)
		printf("%d",i%10);

	return 0;
}
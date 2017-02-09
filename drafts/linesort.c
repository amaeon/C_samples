#include <stdio.h>
#include <string.h>

#define MAXNLINES 5000

char *lptr[MAXNLINES];

int readlines(char *lptr[], int nl);
void writelines(char *lptr[], int nl);
void qsort(char *lptr[], int left, int right);
void myqsort(char *lptr[], int left, int right);

int main(int argc, char const *argv[])
{
	int nlines;
	if((nlines=readlines(lptr,MAXNLINES))>=0){
		qsort(lptr,0,nlines-1);
		writelines(lptr,nlines);
		return 0;
	}
	else{
		printf("ERR: input too big to sort!\n");
		return 0;
	}
	return 0;
}

void swap(char *lptr[], int i, int j);

void qsort(char *lptr[], int left, int right)
{
	int i, last;
	if(left>=right)
		return;
	swap(lptr,left,(left+right)/2);
	last=left;
	for(i=left+1; i<=right; i++)
		if(strcmp(lptr[i],lptr[left])<0)
			swap(lptr,++last,i);
	swap(lptr,left,last);
	qsort(lptr,left,last-1);
	qsort(lptr,last+1,right);
}

void myqsort(char *lptr[], int left, int right)
{
	if(left>=right)
		return;
	int i,j,m;
	i=left;
	j=right;
	m=(left+right)/2;

	while(i<j){
		while( strcmp(lptr[i],lptr[m])<0 )
			i++;
		while( strcmp(lptr[j],lptr[m])>0 )
			j--;
		swap(lptr,i,j);
		if(m==i)
			m=j;
		else if(m==j)
			m=i;
	}
	qsort(lptr,left,m-1);
	qsort(lptr,m+1,right);
}

void swap(char *lptr[], int i, int j)
{
	char *p;
	p=lptr[i];
	lptr[i]=lptr[j];
	lptr[j]=p;
}

#define MAXLEN 1000

int getline(char *s, int lim);
char *alloc(int n);
void afree(char *p);

int readlines(char *lptr[], int nl)
{
	int nlines, len;
	char line[MAXLEN];
	char *p;

	nlines=0;

	while((len=getline(line,MAXLEN))>0){
		if(nlines>=nl || (p=alloc(len))==NULL)
			return -1;
		else{
			line[len-1]='\0';	// remove \n symbol
			strcpy(p,line);
			lptr[nlines++]=p;
		}
	}
	return nlines;
}

void writelines(char *lptr[], int nl)
{
	int i;
	for(i=0; i<nl; i++)
		printf("%s\n",lptr[i]);
}

int getline(char *s, int lim)
{
	int c;
	char *t=s;
	while(lim-->0 && (c=getchar())!='\n' && c!=EOF)
		*s++ = c;
	if(c=='\n')
		*s++ = c;
	*s='\0';
	return s-t;
}

#define ALLOCSIZE 90000

char allocbuf[ALLOCSIZE];
char *allocp = allocbuf;

char *alloc(int n)
{
	if(ALLOCSIZE-(allocp-allocbuf)>=n){
		allocp+=n;
		return allocp-n;
	}
	else{
		fprintf(stderr,"alloc: not enough space in buffer!");
		return 0;
	}
}

void afree(char *p)
{
	if(p>=allocbuf && p<allocbuf+ALLOCSIZE)
		allocp=p;
}
#include <stdio.h>

#define DAYS_IY 365

const char ytab[2][13] =
{
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int day, int *pm, int *pd);
char *month_name(int n);

int main(int argc, char const *argv[])
{
	int y,m,d,doy;
	printf("Year: ");
	scanf("%d",&y);
	printf("Month: ");
	scanf("%d",&m);
	printf("Day: ");
	scanf("%d",&d);

	printf("\nDay of year: %d\n",day_of_year(y,m,d));
	printf("===================\n\n");

	printf("Year: ");
	scanf("%d",&y);
	printf("Day of year: ");
	scanf("%d",&doy);
	month_day(y,doy,&m,&d);
	printf("\n%d of %s\n",d,month_name(m));
	return 0;
}

int day_of_year(int year, int month, int day)
{
	if(year<0){
		fprintf(stderr,"day_of_year: Incorrect year!\n");
		return -1;
	}
	if(month >12 || month<1){
		fprintf(stderr,"day_of_year: Incorrect month!\n");
		return -1;
	}

	int res=0;
	int i;
	int leap = (year%4==0 && year%100!=0) || (year%400==0);
	if( day > *(*(ytab+leap)+month) ){
		fprintf(stderr,"day_of_year: Incorrect day!\n");
		return -1;
	}
	while(--month>0)
		day+= *(*(ytab+leap)+month);
	return day;
}

void month_day(int year, int day, int *pm, int *pd)
{
	if(year<0){
		fprintf(stderr,"month_day: Incorrect year!\n");
		*pm=*pd=-1;
		return;
	}

	int leap = (year%4==0 && year%100!=0) || (year%400==0);
	if(day> DAYS_IY+leap || day<1){
		fprintf(stderr,"month_day: Incorrect days in year!\n");
	}
	for(*pm=1; day> *(*(ytab+leap)+*pm); (*pm)++)
		day-= *(*(ytab+leap)+*pm);
	*pd=day;
}

char *month_name(int n)
{
	static char *months[] = {
		"Incorrect month", "January", "February",
		"March", "April", "May", "June", "July",
		"August", "September", "October",
		"November", "December"
	};

	return (n>12 || n<1)?months[0]:months[n];
}
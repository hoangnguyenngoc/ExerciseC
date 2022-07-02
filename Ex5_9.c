/*Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of
indexing*/

#include<stdio.h>
#include<strings.h>
static char daytab[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year,int month,int day);
void month_day(int year,int yearday, int *month, int *day);

int main(void)
{
    int yearday,month,day,year;
    //int c;
   // c = 121;
   // while(1){
    	    //fflush(stdin);
	    printf("\nday_of_year: set day of year from month & day");
	    printf("\n -------- type y/m/d ---");
	    printf("\n Year:");   scanf("%d",&year);
	    printf("\n Month:");  scanf("%d",&month);
	    printf("\n Day:");  scanf("%d",&day);
	    yearday = day_of_year(year,month,day);
	    printf("\n ----->> %d day from the start year", yearday);
	    //fflush(stdin);
	    //printf("\n continue y/n:"); 
	    //scanf("%d",&c);
	   // printf("\n"); 
	    //if(c == 110) break;
    //}
    //c = 121;
    //while(1){
    	    //fflush(stdin);
	    printf("\n \n \nmonth_day: set month,day from day of year");
	    printf("\n -------- type year,day from the start year  ---");
	    printf("\n Year:");  scanf("%d",&year);
	    printf("\n Yearday:"); scanf("%d",&yearday);
	    month_day(year,yearday, &month, &day);
	    printf("\n ----->Month: %d, Day: %d\n", month, day);
	    //fflush(stdin);
	   //printf("\n continue y/n:");  scanf("%d",&c);
    //}
	
    return 0;
}

/* day_of_year: set day of year from month & day */

int day_of_year(int year,int month,int day)
{
    int i,leap;

    leap = ( year % 4 == 0 && year % 100 != 0 || year % 400 == 0 );

    if(year < 1 || month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
        return -1;
    
    for(i = 1;i < month;i++)
        day += daytab[leap][i];

    return day;
}

/* month_day: set month,day from day of year */

void month_day(int year,int yearday, int *month, int *day)
{
    int i,leap;

    leap = year % 4 == 0 && year%100 != 0 || year%400 == 0;

    if(year < 1 || yearday < 1 || yearday > (leap? 366 : 365))
    {
        *month = -1;
        *day = -1;
        return;
    }

    for(i = 1 ;yearday > daytab[leap][i];i++)
        yearday -= daytab[leap][i];

    *month = i;
    *day = yearday;
}

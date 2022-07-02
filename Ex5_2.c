#include<stdio.h>
#include<ctype.h>
#define BUFSIZE 100
#define SIZE 1000
int bufp = 0;
char buf[BUFSIZE];

int getch(void)
{
	return (bufp > 0)? buf[--bufp] : getchar();
}
int ungetch(int c)
{
	if( bufp >= BUFSIZE )
		printf("ungetch: too many charaters\n");
	else 
		buf[bufp++] = c;
}
int getfloat(float *pn)
{
	int c, sign;
	float deno;
	while(isspace(c = getch()))
	;
	if(!isdigit(c) && c != EOF && c!= '+' && c != '-')
	{
		ungetch(c);
		return -1;
	}
	
	sign = (c == '-') ? -1 : 1;
	
	if( c == '+' || c == '-')
        c = getch();

	
        for(*pn = 0; isdigit(c);c=getch())
        {
        	*pn = 10 * *pn + (c-'0');
        	
        	
        }
        if( c == '.'){
        c = getch();}
        
        for(deno = 1.0 ; isdigit(c) ; c=getch())
        {
        	*pn = 10 * *pn + (c-'0');
        	deno*= 10.0;
        }
        *pn *= sign / deno;
        
        if( c != EOF)
        ungetch(c);
    
    	return c;
}
int main(void)
{
	int n = 0;
	float array[SIZE];
	int m = getfloat(&array[n]);
	
	while(n < SIZE  && m!= EOF && m != -1 )
	{
		printf("n = %d, getfloat %f\n ", n, array[n]);
		n++;
		m = getfloat(&array[n]);
	}
	return 0;
}



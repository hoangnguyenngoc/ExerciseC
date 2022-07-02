#include <stdio.h>
/* count lines in input */
main()
{
int c, nl, b ,t;

nl = 0;
t = 0 ,b = 0;
while ((c = getchar()) != EOF)
{
	if (c == '\n')
		++nl;
	else if ( c == '\t')
		++t;
	else if ( c == ' ')
		++b;
		

	
}
	printf("Number blank: %d\n", b);
	printf("Number newline: %d\n", nl);
	printf("Number tab:%d\n", t);
}

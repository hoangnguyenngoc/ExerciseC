#include<stdio.h>
#define HAVENL 1
#define	NONL 0
int main()
{
	int c;
	int state = NONL;
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t')
		{
			state = HAVENL;
		}
		else 
		{
			if (state == HAVENL)
			{
				putchar('\n');
				putchar(c);
				state = NONL;
			}
			else putchar(c);
		}
	}
	return 0;
}


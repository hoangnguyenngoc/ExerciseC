#include <stdio.h>
main()
{
int c;

while ((c = getchar()) != EOF)
{
	if (c == ' ')
	{
		putchar('\\');
		putchar('b');
	}
	else if ( c == '\t')
	{
		putchar('\\');
		putchar('t');
	}
	else if ( c == '\\')
		putchar('\\');
	else putchar(c);
}
}

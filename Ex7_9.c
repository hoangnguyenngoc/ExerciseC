/*Exercise 7-9. Functions like isupper can be implemented to save space or to save time. Explore both possibilities. */

#include <stdio.h>
#include <stdlib.h>
int xisupper(int);
int main(void) {
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            continue;

        if (xisupper(c) == 1)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}

int xisupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

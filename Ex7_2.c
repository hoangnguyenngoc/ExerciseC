/* Exercise 7-2. Write a program that will print arbitrary input in a sensible way. As a minimum, it should print non-graphic characters in octal or hexadecimal according to local custom, and break long text lines.*/

#include<stdio.h>
#include<ctype.h>
#define MAXL 50
#define OCTLEN 6
int incpos(int pos, int n);
int main(){
	int c, pos;
	pos = 0;
	while((c = getchar()) != EOF){
		if(iscntrl(c) || c == ' '){
			pos = incpos(pos,OCTLEN);
			printf("\\%03o",c);
			if(c == '\n'){
				pos = 0;
			}
			putchar('\n');	
		} 
		else {
			pos = incpos(pos,1);
			putchar(c);
		}
	}
	return 0;
}
int incpos(int pos, int n){
	if(pos +n < MAXL)
		return pos+n;
	else {
		putchar('\n');
		return n;
	}
}


/*Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument.*/
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXOP 100
#define MAXV 100
#define BUFSIZE 100
int getop(char []);
void unget(char []);
void push(float);
float pop(void);
int getch(void);
void ungetch(int);

int main(int argc, char *argv[]){
	char s[MAXOP];
	float op;
	while(-- argc > 0)
	{
		unget(" ");
		unget(*++argv);
	}
	switch(getop(s)){
		case '0':
		    push(atof(s));
		    break;
		case '+':
                    push(pop() + pop());
                    break;
           	 case '*':
                    push(pop() * pop());
                    break;
         	   case '-':
                    op = pop();
                    push(pop() - op);
                    break;
           	 case '/':
                    op = pop();
                    if(op != 0.0)
                        push(pop()/op);
                        else 
                        	printf("error");
                        break;
                  default:
                  	printf("unknown command %s \n",s);
                  	argc = 1;
                  	break;
	}
	printf("\t %8g\n",pop());
    	return 0;
}

int getop(char s[]){
	int i,c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(s[++i] = c = getch())
		;
	s[i] = '\0';
	
	if(c != EOF)
		ungetch(c);
	return '0';
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0)? buf[--bufp] : getchar();
}
void ungetch(int c){
	if( bufp >= BUFSIZE)
	;
	else buf[bufp++] = c;
}
void unget(char s[]){
	int len = strlen(s);
	while(len > 0)
		ungetch(s[--len]); 
}

int stp = 0;
float val[MAXV];

void push(float v)
{
	if(stp < MAXV)
		val[stp++] = v;
	else
		printf("err: full stack");
}
float pop(void){
	if(stp > 0)
		return val[--stp];
	else {
		printf("Errr");
		return 0.0;
	}
}

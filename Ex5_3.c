/*#Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.*/
#include<stdio.h>
#define MAXL 100

int xgetline(char line[], int limit);
int xstrcat(char *, char*);

int main(){
	char s[MAXL],t[MAXL];
	printf("String t: ");
	xgetline(t,MAXL);
	printf("String s: ");
	xgetline(s,MAXL);
	xstrcat(s,t);
	printf("\n --> %s\n",s);
	//for (int i = 0; i < MAXL ; i++ ){
	//putchar(s[i]);
	//}
	return 0;
}

int xgetline(char line[], int limit){
	int c;
	int n;
	for(n = 0; n < limit && ( c = getchar()) != '\n' && c != EOF ; ++n ){
		line[n] = c;
	}
	
	if(line[n] == '\n'){
		line[n] = '\0';
	}
	return n;
}

int xstrcat(char *s, char *t){
	while(*s != '\0'){
	s++;
	}
	//s--;
	
	while(*t != '\0'){
	*s = *t;
	s++;
	t++;
	}
	*(s++) = '\0';
	return 0;
	
}

/*#Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.*/

#include<stdio.h>
#define MAXL 100
int xgetline(char line[],int limit);
int xstrend(char *,char *);
int main(){
	char s[MAXL],t[MAXL];
	printf("String s: ");
	xgetline(s,MAXL);
	printf("String t: ");
	xgetline(t,MAXL);
	if (xstrend(s,t) == 1) 
		printf("String t occurs at the end of string s \n");
	return 0;
}
int xgetline(char line[], int limit){
	int n;
	char c;
	for(n = 0; n < limit && (c = getchar()) != EOF && c != '\n' ; n++){
	line [n] = c;}
	if(line[n] == '\n'){
		line[n]='\0';
	}
	return n;
}
int xstrend(char *s, char *t){
	int n,m;
	char c;
	for (n = 0; *s != EOF && *s != '\0'; n++){
		s++;
	}
	for (m = 0; *t != EOF && *t != '\0'; m++){
		t++;
	}
	if( n < m ) return 0;
	for (; m != 0; m-- ){
		if( *s != *t) return 0;
		s--;
		t--;
	}
	return 1;
}


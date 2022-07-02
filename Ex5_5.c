/* Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.*/

/// sua lai sau thanh n> , ncat, ncmp , not ,cat,cmp 
#include<stdio.h>
#include<stdlib.h>

#define MAXL 100
int xstrcat(char * , char *) ;
int xstrcmp(char * , char *);
int lenL(char *);
int xgetline(char line[], int limit);
int xstrcpy(char *, char * , int n);

int main()
{
	char s[MAXL], t[MAXL];
	int option = -1;
	printf("String s: ");
	xgetline(s,MAXL);
	printf("String t: ");
	xgetline(t,MAXL);
	printf("Op 1 Strcpy , Op 2 Strcat , Op 3 Strcmp \n  Option: ");
	scanf("%d",&option);
	switch(option){
		case 1:{
			char *d;
    			if ((d = (char *) malloc(sizeof(char) * (lenL(s) +1))) == NULL) {
            			printf("unable to allocate memory \n");
 
        		}
        		int ncy = 0;
        		printf("n = ");
        		scanf("%d",&ncy);
        		xstrcpy(s,d,ncy);
			printf("\n Str d copy Str s: %s \n",d);
			free(d);
			break;
		}
		case 2:{
			xstrcat(s,t);
			printf("\n --> %s\n",s);
			break;
		}
		case 3:{
			if (xstrcmp(s,t) == 0 ) 
			printf("String s == string t \n");
			else if (xstrcmp(s,t) > 0 ) 
			printf("String s > string t \n");
			else 
			printf("String s < string t \n");
			break;
		}
	}
	return 0;
}
int xstrcpy(char *ori, char *copy , int n){
	int i;
	for(i = 0; *ori != '\0' && i < n; i++){
		*copy = *ori;
		copy++;
		ori++;	
	}
	*copy = '\0';
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

int lenL(char *len){
	char *x;
	x = len;
	while(*x != '\0'){
		x++;
	}
	return (x-len+1);
}

int xstrcmp(char *s, char *t){
	for(; *s == *t; s++,t++){
        	if( *s == '\0' && *t == '\0')
            	return 0;
          }
    	return *s - *t;
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


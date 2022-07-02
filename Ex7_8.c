/* Exercise 7-8. Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELEN 50
#define LINEPERPAGE 10

void printpage(FILE*,FILE*);
int main(int argc, char *argv[]){
	FILE *f;
	int linecoun = 0;
	if(argc == 1){
		fprintf(stderr,"No file given");
	}
	else {
		while(--argc){
			if((f = fopen(*++argv,"r")) == NULL){
				fprintf(stderr,"Can open %s",*argv);
				return 1;
			}
		 	else {
			fprintf(stdout,"FILE: %s \n", *argv);
			printpage(f,stdout);
			fclose(f);
			}
		
		}
	
	}
	return 0;
}
void printpage(FILE *fi,FILE *fo){
	int c;
	int line = 0;
	int page = 1;
	while ((c = getc(fi)) != EOF){
	putc(c,fo);
	if(c == '\n'){
		line ++;
		if(line == LINEPERPAGE){
			fprintf(stdout, "PAGE %d END.\n",page);
		}
	}
	} 

}

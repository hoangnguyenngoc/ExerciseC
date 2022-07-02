/* Exercise 7-6. Write a program to compare two files, printing the first line where they differ.*/

#include<stdio.h>
void filecmp(FILE *fp1, FILE *fp2);
int main(int argc, char *argv[]){
	FILE *fp1, *fp2;
	
	if(argc == 1){
		printf("Not enough two files");
		return 1;
	}
	else {
		while(-- argc > 0){
		
			if((fp1 = fopen(argv[1],"r")) == NULL){
				printf("cant open");
				return 1;
			}
			
			if((fp2 = fopen(argv[2],"r")) == NULL){
				printf("cant open");
				return 1;
			}
		}
		filecmp(fp1,fp2);
		fclose(fp1);
		fclose(fp2);
	}
}
void filecmp(FILE *fp1, FILE *fp2){
	int f1, f2;
	while(1){
		if((f1 = getc(fp1)) == EOF)
		break;
		if((f2 = getc(fp2)) == EOF)
		break;
	
	
		if(f1 != f2){
			putchar(f1);
			putchar(f2);
			break;
		}
	}
}




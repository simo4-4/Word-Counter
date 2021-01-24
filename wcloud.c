#include <stdio.h>
#include "wordlist.h" //might not be a good idea to include c file
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{


FILE *fp = NULL; //file pointer
char line[1000]; //current line in file
char *delim = " \t\n,:;'\".?!#$-><(){}[]|\\/*&^%@!~+=_"; // These are our word delimiters.
char* currentword = "hello";
int outofmem = 0;
int* outofm = &outofmem;
int exitcode = 0;

//if program invoked without arguments, it exits with error code 1
if(argc == 1){
	printf("Usage: wcloud article [article]...\n");
	return 1;
}

struct WordNode *head = (struct WordNode*) malloc(sizeof(struct WordNode));
head->next = NULL;
head->count = 0;
head->word = "kgsfks";



for(int i=1; i<argc; i++){

	fp=fopen(argv[i],"r");
	

	//displays error messesage, skips to next iteration, and alters the exitcode if a file can't be opened
	if(fp == NULL){
		printf("Error! unable to open %s", argv[i]);
		exitcode = 2;
		continue;	
	}
	
	while(fgets(line,1000,fp) != NULL){
//		printf("head in wcloud START: %s \n", head->word);
//			printf("LINE before strtok: %s", line);
			currentword = strtok(line,delim);
			addWord(currentword, head, outofm);
//			printf("currentword in wcloud: %s for line: %s\n", currentword,line);
			while(currentword != NULL){
				currentword = strtok(NULL,delim);
				if(currentword != NULL){
				addWord(currentword, head, outofm);
//				printf("currentword in wcloud: %s for line: %s\n", currentword,line);	
				}
			}
	
//			printWordList(head);
//			printf("head in wcloud END: %s \n", head->word);
	}


}


printWordList(head);
freeNodes(head);

if(outofmem == 3)
exitcode = 3;


return exitcode;



}











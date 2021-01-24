#include "wordlist.h" //includes header file in my directory, declares WordNode
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct WordNode *addWord1(char* word, struct WordNode *wordListHead, int* outofmemory){


	printf("wordListHead in addWord: %s \n", wordListHead->word);

	//for first word to be added to the list
	if(wordListHead->count ==0){
		wordListHead->word = (char*) malloc(sizeof(char*));
		strcpy(wordListHead->word,word);
		wordListHead->count = 1;
		wordListHead->next = NULL;
		return wordListHead;
	}



	struct WordNode *newNode = (struct WordNode*) malloc(sizeof(struct WordNode));
	

	if (newNode == NULL || word == NULL){
		printf("Error not enough memory \n");
		*outofmemory = 1;
		return NULL;
	}
	
	
	//traverse down till temp->next points to NULL
	struct WordNode *temp = wordListHead;
	while(temp->next != NULL){
		
//		printf("addWord: %s \n", temp->word);


		if(temp->word == NULL || word == NULL){
//			printf("temp->word or word is NULL");
		}

//		printf("strcmp (temp->word, word): (%s,%s)\n",temp->word, word);
		if(strcasecmp(temp->word, word) == 0){ //or strcmpi()
			printf("EQUAL \n");
			temp->count = temp->count + 1;
			return temp;//not sure if I should return current node
		}

		temp = temp->next;
	}

	if(strcasecmp(temp->word, word) == 0){ //or strcmpi()
//                        printf("EQUAL \n");
                        temp->count = temp->count + 1;
                        return temp;//not sure if I should return current node
                }


	temp->next = newNode;
	
	newNode->word = (char*) malloc(sizeof(char*));
        strcpy(newNode->word,word);
	newNode->next = NULL;
	newNode->count = 1;\

	return newNode;
}


struct WordNode *addWord(char* word, struct WordNode *wordListHead, int* outofmemory){

	//for the first node
	if(wordListHead->count == 0){
                wordListHead->word = (char*) malloc(sizeof(char*));
                strcpy(wordListHead->word,word);
                wordListHead->count = 1;
                wordListHead->next = NULL;
                return wordListHead;
        }



        struct WordNode *newNode = (struct WordNode*) malloc(sizeof(struct WordNode));
	
	//if malloc doesn't work or if there's no more memory
	if (newNode == NULL){
                printf("Error not enough memory \n");
                *outofmemory = 1;
                return NULL;
        }


	//locate the node before the point of insertion
	struct WordNode *temp = wordListHead;
	while(temp->next != NULL && strcasecmp(temp->next->word,word) < 0 ){
		temp = temp->next;
	}



	if(temp->next == NULL){
                newNode->word = (char*) malloc(sizeof(char*));
                strcpy(newNode->word,word);
                temp->next = newNode;
		newNode->count = 1;
		newNode->next = NULL;
		return newNode;
	}


	else if(strcasecmp(temp->next->word,word) == 0 || strcasecmp(temp->word, word) == 0){

		if(strcasecmp(temp->next->word,word) == 0)
		temp->next->count++;

		if(strcasecmp(temp->word,word) == 0)
                temp->count++;

		return temp;
	}


	else{ //inserts node after temp and before temp->next...

		newNode->next = temp->next;
		temp->next = newNode;
		newNode->word = (char*) malloc(sizeof(char*));
	        strcpy(newNode->word,word);
        	newNode->count = 1;

        	return newNode;

	}




}








//iterates through linkedlist and prints word and count
void printWordList(struct WordNode *wordListHead)
{

//	printf("-----------printWordList function------------- \n");

	struct WordNode *temp = wordListHead;

	while(temp != NULL){


		printf("%s %ld \n",low(temp->word),temp->count);
		temp = temp->next;


	}


		

}


//free nodes
void freeNodes(struct WordNode *wordListHead){


	struct WordNode *temp = wordListHead;
	struct WordNode *prev= wordListHead;

	while(temp != NULL){
		
		prev =temp;
		temp = temp->next;
		free(prev);

        }
	free(temp);
}

//string to lowercase
char* low(char* string){


	char* temp = string;
	
	for(int i = 0; i < strlen(temp); i++){
		
		//strcpy(temp[i],tolower(temp[i]));
		temp[i]= tolower(temp[i]);

	}


return temp;
}









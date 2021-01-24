struct WordNode
{
	char* word;
	unsigned long count;
	struct WordNode *next;
};

struct WordNode *addWord(char* word, struct WordNode *wordListHead, int* outofmemory);

void printWordList(struct WordNode *wordListHead);

void freeNodes(struct WordNode *wordListHead);

char* low(char* string);

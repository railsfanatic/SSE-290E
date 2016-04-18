#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int val;
	struct NODE *next;
};

void printList(struct NODE *theNode)
{
	while (theNode->next != NULL)
	{
		printf("%d -> ", theNode->val);
		theNode = theNode->next;
	}
	printf("END\n");
}

int main(int argc, char *argv[])
{
	typedef struct NODE node_t;
	
	node_t *head = NULL;
	
	head = malloc(sizeof(node_t));
	node_t *tail = NULL;
	tail = head;
	
	for (int i = 0; i < 100; i++)
	{
		head->val = rand();
		head->next = malloc(sizeof(node_t));
		head = head->next;
	}
	head->next = NULL;
	
	printList(tail);
	
	return 0;
}

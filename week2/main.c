#include<stdio.h>
#include<stdlib.h>
#include"sll.h"

int main() {
	int choice;
	List* list = list_initialize();
	do {
		printf("\n1.Insert at rear\n2.Display\n3.Delete at front\n4.Insert at specific position\n5.Reverse list\n");
		printf("\nEnter choice : ");
		scanf("%d", &choice);
		switch(choice) {
			int element, index;
			case 1:
				/*Insert element at the End of the list*/
				printf("Enter element to be inserted : ");
				scanf("%d", &element);
				insert_at_end(list, element);
				break;
			case 2:
				/* Print list contents */ 
				printf("Current list is : ");
				list_print(list);
				break;
			case 3:
				/* Remove front element */ 
				list_delete_front(list);
				break;
			case 4:
				/* Insert elements at specified positions */
				printf("Enter element and position to be inserted at  : ");
				scanf("%d%d", &element, &index);
				list_insert_at(list, element, index);
				break;
			case 5:
				/*Reverses the elements of the list*/
				list_reverse(list);
				break;
		}
	} while(choice != 0);
	list_destroy(list);
	return 0;
}

List* list_initialize() {
	List* list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->number_of_nodes = 0;
	return list;
}

void list_print(List* list) 
	{
	Node *p;
	p=list->head;
	if(p == NULL)
	{
		printf("EMPTY\n");
		return;
	}
	while (p!=NULL){
		printf("%d ",p->data);
		p=p->link;
	}
	printf("\n");
}


void list_destroy (List *list)
{
	Node *t, *u=NULL;
	t=list->head;
	while (t->link!=NULL){
		u=t;
		t=t->link;
		free(u);
	}
	free(list);
}

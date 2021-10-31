#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
int main()
{
    List* dll = initialize_list();
    int ele,choice,pos,x;
    do
    {
        printf("\n1.Insert at beginning\n2.Delete at beginning\n3.Count number of nodes\n4.Delete at position\n5.Search for an element\n6.Reverse list\n7.Display\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            // Insert at beginning
            case 1:
            printf("Enter element : ");
                scanf("%d",&ele);
                insert_front(dll,ele);
                break;

	   // Delete element at the beginning of the list  	   
	   case 2:
                dllist_delete_beginning(dll);
		break;

	   // Count number of nodes 
	  case 3:
               x = count_nodes(dll);
		printf("%d\n",x);
            	break;

            // Delete at position
            case 4:
            printf("Enter position : ");
                scanf("%d",&pos);
                position_delete(dll, pos);
                break;

            // Search for element
            case 5:printf("Enter element : ");
                scanf("%d",&ele);
                pos = search_list(dll,ele);
                printf("%d\n",pos);
                break;
	
	    // reverse for element
            case 6:
                reverse_list(dll);
                break;

            // Print entire list
            case 7:
                display(dll);
                break;        
        }
    }
    while (choice != 0);

    destroy_list(dll);
    return 0;
}

List* initialize_list()
{
    List* dll = (List*)malloc(sizeof(List));
    dll->head = NULL;
    dll->number_of_nodes = 0;

    return dll;
}

Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void display(List* dll)
{
    if(dll->number_of_nodes == 0)
        printf("EMPTY");
    else
    {
        Node* temp = dll->head;

        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    
    printf("\n");
}

void destroy_list(List* dll)
{
    Node *p = dll->head;
	Node *q = NULL;

    while (p != NULL)
    {
		q = p;
		p = p->next;
		free(q);
	}
	
    free(dll);
}


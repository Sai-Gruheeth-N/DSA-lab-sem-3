#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	//TODO
	Node *temp=(struct Node*)malloc(sizeof(struct Node));
	if(temp==NULL)
    {
        printf("Insufficient memory.");
    }
	temp->data=data;
	temp->link=NULL;
	if(list->head==NULL)
	{
		list->head=temp;
	}
	Node *cur;
	cur=list->head;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
	temp->link=NULL;
}

void list_delete_front(List* list) 
{
	//TODO
	if(list->head==NULL)
	{
		printf("Empty list\n");
		return;
	}
	else
	{
		Node *cur;
		cur=list->head;
		list->head=cur->link;
		printf("%d is deleted.\n",cur->data);
		free(cur);
	}
}

void list_insert_at (List *list, int data, int position)
{
	//TODO
	Node *temp=(struct Node*)malloc(sizeof(struct Node));
	if(temp==NULL)
    {
        printf("Insufficient memory.");
    }
	temp->data=data;
	temp->link=NULL;
	if(position==1)
	{
		temp->link=list->head;
		list->head=temp;
	}
	else
	{
		Node *cur=list->head;
		Node *prev=NULL;
		for(int i=1;i<position;i++)
		{
			prev=cur;
			cur=cur->link;
		}
		prev->link=temp;
		temp->link=cur;
	}
}

void list_reverse(List* list)
{
 	//TODO
	Node *cur,*prev,*temp=list->head;
	if(temp!=NULL)
	{
		prev=temp;
		temp=temp->link;
		cur=temp;
		prev->link=NULL;
		while(temp!=NULL)
		{
			temp=temp->link;
			cur->link=prev;
			prev=cur;
			cur=temp;
		}
		temp=prev;
		list->head=temp;
	}
}




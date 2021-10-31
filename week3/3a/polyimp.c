#include "poly.h"
void insert_at_end(List *list, int data) 
{
	//TODO
    list->number_of_nodes=0;
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
        list->number_of_nodes++;
        return;
	}
	Node *cur;
	cur=list->head;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
	temp->link=NULL;
    list->number_of_nodes++;
}

long long int evaluate(List *list, int x)
{
    //TODO
    //printf("value of x : %d\n",x);
    long long int value=0;
    Node *coeff=list->head;
    int i=1;
    while(coeff!=NULL)
    {  
        value=value+coeff->data*i;
        coeff=coeff->link;
        i=x*i;
    }
    return(value);
}

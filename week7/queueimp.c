#include "queue.h"
static node *create_node(int id, int time, node *link)
{
//TODO
	node* temp =  (node*)malloc(sizeof(node));
	temp -> id = id;
	temp->time = time;
	temp -> link = link;
	return temp;
}
void list_initialize(List *ptr_list)
{
//TODO
	ptr_list->head=ptr_list->tail=NULL;
	ptr_list->number_of_nodes=0;
}
const int node_get_id(node *node_ptr)
{
//TODO	
	return(node_ptr->id);
}

const int node_get_time(node *node_ptr)
{
//TODO		
	return(node_ptr->time);
}

void list_insert_rear(List *ptr_list, int id, int time)
{
//TODO	
	node* temp=create_node(id,time,NULL);
	if(time>=0)
	{
		if(ptr_list->head==NULL)
		{
			ptr_list->head=ptr_list->tail=temp;
			ptr_list->head->link=ptr_list->tail->link=NULL;
		}
		else
		{
			ptr_list->tail->link=temp;
			ptr_list->tail=temp;
			ptr_list->tail->link=NULL;
		}
		ptr_list->number_of_nodes++;
	}
}

void list_delete_front(List *ptr_list)
{
//TODO
	node *temp=ptr_list->head;
	ptr_list->head=ptr_list->head->link;
	free(temp);
	ptr_list->number_of_nodes--;
}

void list_destroy(List *ptr_list)
{
//TODO	
	node *temp=ptr_list->head;
    node *next;
    while(temp!=NULL)
    {
        next=temp->link;
        free(temp);
        temp=next;
    }
    ptr_list->head=NULL;
}

void queue_initialize(Queue *queue_list)
{
//TODO	
	list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time)
{
//TODO	
	list_insert_rear(ptr->ptr_list,id,time);
}

void queue_dequeue(Queue *ptr)
{
//TODO		
	list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{
//TODO		
	if(ptr->ptr_list->head==NULL)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void queue_peek(Queue *ptr)
{
//TODO	
	if(queue_is_empty(ptr))
	{
		printf("Empty queue.\n");
	}
	else
	{
		int ele=ptr->ptr_list->head->id;
		int time=ptr->ptr_list->head->time;
		printf("Front in the queue : %d %d\n",ele,time);
	}	
}

void queue_destroy(Queue *ptr)
{
//TODO
	list_destroy(ptr->ptr_list);	
}

const int queue_find_person(Queue *ptr_queue, int t)
{
//TODO	
	
	int temptime=t;
	node *temp=ptr_queue->ptr_list->head;
	while(temp!=NULL && temp->time<=t)
	{
		t=t-temp->time;
		temp=temp->link;
		if(t<0 || temp==NULL)
		{
			printf("Empty queue\n");
			return(0);
		}
	}
	printf("%d is getting serviced at %d time.\n",temp->id,temptime);
}
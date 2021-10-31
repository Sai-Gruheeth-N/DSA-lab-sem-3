#include"dll.h"

int count_nodes(List* dll)
{
    if(dll->head==NULL)
    {
        return(0);
    }
    dll->number_of_nodes=1;
    Node *cur=dll->head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
        dll->number_of_nodes++;
    }
	//dll->number_of_nodes++;
    return(dll->number_of_nodes);
}

void insert_front(List* dll, int data)
{
    //TODO
    Node *temp=create_node(data);
    if(dll->head==NULL)
    {
        dll->head=temp;
    }
    else
    {
        temp->next=dll->head;
        dll->head->prev=temp;
        dll->head=temp;
    }
    dll->number_of_nodes++;
}

void dllist_delete_beginning(List* list)
{
    //TODO

    if(list->head==NULL)
    {
        printf("Empty list.\n");
        return;
    }
    else if(list->head->next==NULL)
    {
        printf("%d is deleted.\n",list->head->data);
        free(list->head);
        list->head=NULL;
        list->number_of_nodes--;
        return;
    }
    else
    {
        Node *cur=NULL;
        cur=list->head;
        list->head=cur->next;
        list->head->prev=NULL;
        printf("%d is deleted.\n",cur->data);
        free(cur);
        list->number_of_nodes--;
    }
}

void position_delete(List* dll, int pos)
{
    //TODO
    Node *cur=dll->head,*prev=NULL;
    if(dll->head==NULL)
    {
        printf("Empty list.\n");
    }
    if(pos==0)
    {
        //cur=dll->head;
        dllist_delete_beginning(dll);
        return;
    }
    if(pos==dll->number_of_nodes-1)
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        dll->tail=cur->prev;
        dll->tail->next=NULL;
        printf("%d is deleted.\n",cur->data);
        free(cur);
        dll->number_of_nodes--;
    }
    else
    {
        for(int i=0;cur->next!=NULL&&i<pos;i++)
        {
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        cur->next->prev=prev;
        printf("%d is deleted.\n",cur->data);
        free(cur);
        dll->number_of_nodes--;
    }
}

int search_list(List* dll,int key)
{
    Node *head=dll->head;
    int pos=0;
    Node *cur=head;
    while(cur)
    {
        if(cur->data==key)
        {
            //printf("%d is found at %d position.\n",cur->data,pos);
            return(pos);
        }
        cur=cur->next;
        pos++;
    }
    return(-1);
    //printf("%d is not found.\n",key);
}


void reverse_list(List* dll)
{
    //TODO
    Node *cur=dll->head;
    int temp;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    dll->tail=cur;
    Node *first=dll->head,*last=dll->tail;
    for(int i=0;i<(dll->number_of_nodes/2);i++)
    {
        temp=first->data;
        first->data=last->data;
        last->data=temp;
        first=first->next;
        last=last->prev;
    }
}



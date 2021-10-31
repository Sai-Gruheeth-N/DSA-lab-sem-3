#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
//TODO
    Node *temp=create_node(data);
    if(pos==0)
    {
        if(cll->tail==NULL)
        {
            cll->tail=temp;
            cll->tail->next=cll->tail;
            cll->head=cll->tail;
        }
        else
        {
            temp->next=cll->tail->next;
            cll->tail->next=temp;
            cll->head=cll->tail->next;
        }
        printf("%d is inserted at beginning.\n",cll->tail->next->data);
    }
    else if(pos==cll->length)
    {
        if(cll->tail==NULL)
        {
            cll->tail=temp;
            cll->tail->next=cll->tail;
            cll->head=cll->tail;
        }
        else
        {
            temp->next=cll->tail->next;
            cll->tail->next=temp;
            cll->tail=temp;
            cll->head=cll->tail->next;
        }
        printf("%d is inserted at end.\n",cll->tail->data);
    }
    else if(pos>0 && pos<cll->length)
    {
        Node *cur=cll->tail->next;
        for(int i=1;i<pos;i++)
        {
            cur=cur->next;
        }
        temp->next=cur->next;
        cur->next=temp;
        cll->head=cll->tail->next;
        printf("%d is inserted at %d offset position.\n",cur->next->data,pos);
    }
    cll->length++;
}

void position_delete(List* cll, int pos)
{
//TODO
    if(pos==0)
    {
        if(cll->tail==NULL)
        {
            printf("Empty list.\n");
            return;
        }
        else if(cll->tail->next==cll->tail)
        {
            printf("%d is deleted.\n",cll->tail->next->data);
            cll->head=cll->tail=NULL;
        }
        else
        {
            cll->head=cll->tail->next;
            cll->tail->next=cll->head->next;
            printf("%d is deleted at beginning.\n",cll->head->data);
            free(cll->head);
            cll->head=cll->tail->next;
        }
    }
    else if(pos==cll->length-1)
    {
        Node *cur=cll->tail->next,*prev=NULL;
        if(cll->tail==NULL)
        {
            printf("Empty list.\n");
            return;
        }
        else if(cll->tail->next==cll->tail)
        {
            printf("%d is deleted.\n",cll->tail->next->data);
            cll->head=cll->tail=NULL;
        }
        else
        {
            while(cur->next!=cll->tail->next)
            {
                prev=cur;
                cur=cur->next;
            }
            prev->next=cll->tail->next;
            cll->tail=prev;
            printf("%d is deleted at end.\n",cur->data);
            free(cur);
            cll->head=cll->tail->next;
        }
    }
    else if(pos>0 && pos<cll->length-1)
    {
        Node *cur=cll->tail->next,*nextnode;
        for(int i=1;i<pos;i++)
        {
            cur=cur->next;
        }
        nextnode=cur->next;
        printf("%d is deleted at an offset position %d.\n",nextnode->data,pos);
        cur->next=nextnode->next;
        free(nextnode);
    }
    cll->length--;
}

int josephus(List* cll, int k)
{
    cll->length=0;
    int n;
    printf("Enter the value of 'N' (Length of circle) : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        Node *temp=create_node(i);
        if(cll->tail==NULL)
        {
            cll->tail=temp;
            cll->tail->next=cll->tail;
            cll->head=cll->tail;
        }
        else
        {
            temp->next=cll->tail->next;
            cll->tail->next=temp;
            cll->tail=temp;
            cll->head=cll->tail->next;
        }
        cll->length++;
    }

    Node *cur=cll->tail->next,*prev=NULL;
    while(cur->next!=cur)
    {
        for(int i=0;i<1;i++)
        {
            prev=cur;
            cur=cur->next;
        }

        prev->next=cur->next;
        free(cur);
        cur=prev->next;
    }

    int safe_pos_value=cur->data+k;

    cll->tail=NULL;

    return(safe_pos_value);
}    
#include "5a.h"

static Node* create_Node(int data, Node* link)
{
// TODO - create and allocate dynamic space
    link->data=data;
    link->link=NULL;
    return link;
}

void list_initialize(List* ptr_list) 
{
//TODO - initialize structure members to default values
    ptr_list->head=NULL;
    ptr_list->number_of_Nodes=0;
}

void list_insert_front(List* ptr_list, int data) 
{
//TODO - perform linked list implementation of push operation.
    Node *temp=(Node*)malloc(sizeof(Node));
    temp=create_Node(data,temp);
    temp->link=ptr_list->head;
    ptr_list->head=temp;
    ptr_list->number_of_Nodes++;
}

const int Node_get_data(Node *Node_ptr) 
{
//TODO - return the top most element
    return(Node_ptr->data);
}

void list_delete_front(List* ptr_list) 
{
//TODO - perform linked list implementation of pop operation.
    if(ptr_list->head==NULL)
    {
        printf("Empty list.\n");
        return;
    }
    Node *temp=ptr_list->head;
    ptr_list->head=temp->link;
    free(temp);
    ptr_list->number_of_Nodes--;
}

void list_destroy(List* ptr_list) 
{
//TODO - free the allocated space
    Node *temp=ptr_list->head;
    Node *next;
    while(temp!=NULL)
    {
        next=temp->link;
        free(temp);
        temp=next;
    }
    ptr_list->head=NULL;
}

void Stack_initialize(Stack *ptr_Stack) 
{
//TODO - get the memory allocation for stack, and intern call list initialize
    ptr_Stack->ptr_list=(List*)malloc(sizeof(List));
    list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
//TODO	 - call the function list_insert_front
    list_insert_front(ptr_Stack->ptr_list,key);
}

void Stack_pop(Stack *ptr_Stack) 
{
//TODO- call the function list_delete_front
    list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
//TODO	- return 0 if stack is not empty
    if(ptr_Stack->ptr_list->number_of_Nodes!=0)
    {
        return 0;
    }
    else
    {
        return(1);
    }
}

const int Stack_peek(Stack *ptr_Stack) 
{
//TODO	- return the top most element of the stack
    int temp=Node_get_data(ptr_Stack->ptr_list->head);
    return(temp);
}

void Stack_destroy(Stack *ptr_Stack)
{
//TODO	- deallocate
    list_destroy(ptr_Stack->ptr_list);
}

int match_parenthesis(const char* string)
{
//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
    Stack *ptr_Stack=(Stack*)malloc(sizeof(Stack));
    Stack_initialize(ptr_Stack);
    char temp;
    int i=0;
    while(string[i]!='\0')
    {
        switch(string[i])
        {
            case'(':
            case'[':
            case'{':Stack_push(ptr_Stack,string[i]);
                    break;
            case')':temp=Stack_peek(ptr_Stack);
                    if(temp=='(')
                    {
                        Stack_pop(ptr_Stack);
                    }
                    else
                    {
                        return(0);
                    }
                    break;
            case']':temp=Stack_peek(ptr_Stack);
                    if(temp=='[')
                    {
                        Stack_pop(ptr_Stack);
                    }
                    else
                    {
                        return(0);
                    }
                    break;
            case'}':temp=Stack_peek(ptr_Stack);
                    if(temp=='{')
                    {
                        Stack_pop(ptr_Stack);
                    }
                    else
                    {
                        return(0);
                    }
                    break;
        }
        i++;
    }
    int result;
    if(Stack_is_empty(ptr_Stack))
    {
        result=1;
    }
    else
    {
        result=0;
    }
    Stack_destroy(ptr_Stack);
    return(result);
}
#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
//TODO
	ptr_List->head=NULL;
    ptr_List->number_of_Nodes=0;
}

void List_insert_front(List* ptr_List, int data) 
{
//TODO	
	Node *temp=(Node*)malloc(sizeof(Node));
    temp=create_Node(data,temp);
    temp->link=ptr_List->head;
    ptr_List->head=temp;
    ptr_List->number_of_Nodes++;
}

const int Node_get_data(Node *Node_ptr) 
{
	//TODO
	return(Node_ptr->data);
}

void List_delete_front(List* ptr_List)
{
	//TODO
	if(ptr_List->head==NULL)
    {
        printf("Empty list.\n");
        return;
    }
    Node *temp=ptr_List->head;
    ptr_List->head=temp->link;
    free(temp);
    ptr_List->number_of_Nodes--;
}

void List_destroy(List* ptr_List) 
{
	//TODO
	Node *temp=ptr_List->head;
    Node *next;
    while(temp!=NULL)
    {
        next=temp->link;
        free(temp);
        temp=next;
    }
    ptr_List->head=NULL;
}


void stack_initialize(Stack *ptr_stack) 
{
	// TODO
	ptr_stack->ptr_List=(List*)malloc(sizeof(List));
    List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	// TODO
	List_insert_front(ptr_stack->ptr_List,key);
}

void stack_pop(Stack *ptr_stack) 
{
	// TODO
	List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(Stack *ptr_stack) 
{
	// TODO
	if(ptr_stack->ptr_List->number_of_Nodes!=0)
    {
        return 0;
    }
    else
    {
        return(1);
    }
}

const int stack_peek(Stack *ptr_stack)
{
	// TODO
	int temp=Node_get_data(ptr_stack->ptr_List->head);
    return(temp);
}

void stack_destroy(Stack *ptr_stack) 
{
	// TODO
	List_destroy(ptr_stack->ptr_List);
}

int postfix_eval(const char* expression) 
{
    // TODO
	Stack *ptr_stack=(Stack*)malloc(sizeof(Stack));
    stack_initialize(ptr_stack);
	int i=0;
	int op1,op2,res;
	int eval,temp;
	char sym;
	while(expression[i]!='\0')
	{
		sym=expression[i];
		if(sym>='0'&&sym<='9')
		{
			stack_push(ptr_stack,sym-'0');
		}
		else
		{
			op2=stack_peek(ptr_stack);
			stack_pop(ptr_stack);
			op1=stack_peek(ptr_stack);
			stack_pop(ptr_stack);
			switch(sym)
			{
				case '+':res=op1+op2;
						break;
        		case '-':res=op1-op2;
						break;
        		case '*':res=op1*op2;
						break;
        		case '/':res=op1/op2;
						break;
        		case '$':
        		case '^':temp=1;
						while(op2>0)
						{
							temp=op1*temp;
							op2--;
						}
						res=temp;
						break;
			}
			stack_push(ptr_stack,res);
		}
		i++;
	}
	eval=stack_peek(ptr_stack);
	stack_destroy(ptr_stack);
	return(eval);
}

#include "6b.h"
stack* stack_initialize(int size)
{
//TODO
    stack * ptr_stack = (stack*)malloc(sizeof(stack));
    if(ptr_stack==NULL)
    {
        printf("Stack not created.\n");
        return(NULL);
    }
    else
    {
        ptr_stack->arr=(int*)malloc(size*sizeof(int));
        ptr_stack->top=-1;
        return(ptr_stack);
    }
}

void stack_push(stack *ptr_stack, int key) 
{
//TODO
    ptr_stack->arr[++ptr_stack->top] = key;
}

void stack_pop(stack *ptr_stack)
{
//TODO
    ptr_stack->top=ptr_stack->top-1;
}

int stack_is_empty(stack *ptr_stack)
{
//TODO
    if(ptr_stack->top == -1) 
    {
        return(1);
    }
    else
    {
        return(0);
    }
}

int stack_peek(stack *ptr_stack) 
{
//TODO
    int temp;
    if(ptr_stack->top!=-1)
        temp=ptr_stack->arr[ptr_stack->top];
    return(temp);
}

void stack_destroy(stack *ptr_stack) 
{
//TODO
    ptr_stack->top=-1;
    free(ptr_stack);
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
//TODO
    stack *ptr_stack;
    ptr_stack=stack_initialize(strlen(source_infix));
    
    int i=0,j=0;
    int value_ch,value_top;
    
    for(i=0;source_infix[i]!='\0';i++)
    { 
        if((source_infix[i]>='a' && source_infix[i]<='z') || (source_infix[i] >='A' && source_infix[i]<='Z'))
        {
            target_postfix[j++] = source_infix[i];
        }

        else if(source_infix[i]=='('||source_infix[i]=='['||source_infix[i]=='{')
        {
            stack_push(ptr_stack,source_infix[i]);
        }

        else if(source_infix[i]==')')
        {
            while(stack_peek(ptr_stack)!='(' && !stack_is_empty(ptr_stack))
            {
                target_postfix[j++]=stack_peek(ptr_stack);
                stack_pop(ptr_stack);
            }
            stack_pop(ptr_stack);
        }
        
        else if(source_infix[i]==']')
        {
            while(stack_peek(ptr_stack)!='[' && !stack_is_empty(ptr_stack))
            {
                target_postfix[j++]=stack_peek(ptr_stack);
                stack_pop(ptr_stack);
            }
            stack_pop(ptr_stack);
        }
        
        else if(source_infix[i]=='}')
        {
            while(stack_peek(ptr_stack)!='{' && !stack_is_empty(ptr_stack))
            {
                target_postfix[j++]=stack_peek(ptr_stack);
                stack_pop(ptr_stack);
            }
            stack_pop(ptr_stack);
        }

        else
        {
            switch(source_infix[i])
            {
                case '+':
                case '-':value_ch=1;
                        break;
                case '*':
                case '/':value_ch=3;
                        break;
                case '^':value_ch=5;
                        break;
                case '{':
                case '[':
                case '(':value_ch=7;
                        break;
                case '}':
                case ']':
                case ')':value_ch=0;
                        break;
            }

            switch(stack_peek(ptr_stack))
            {
                case '+':
                case '-':value_top=2;
                        break;
                case '*':
                case '/':value_top=4;
                        break;
                case '^':value_top=6;
                        break;
                case '[':
                case '{':
                case '(':value_top=0;
                        break;
            }
            while(value_top>value_ch && !stack_is_empty(ptr_stack))
            {  
                target_postfix[j++]=stack_peek(ptr_stack);
                stack_pop(ptr_stack);

                switch(stack_peek(ptr_stack))
                {
                    case '+':
                    case '-':value_top=2;
                            break;
                    case '*':
                    case '/':value_top=4;
                            break;
                    case '^':value_top=6;
                            break;
                    case '[':
                    case '{':
                    case '(':value_top = 0;
                            break;
                }
            }
            
            if(value_ch!=value_top)
            {
                stack_push(ptr_stack,source_infix[i]);
            }

            else
            {
                stack_pop(ptr_stack);
            }
        }
    }
    
    while(!stack_is_empty(ptr_stack))
    {
        target_postfix[j++] = stack_peek(ptr_stack);
        stack_pop(ptr_stack);
    }

    target_postfix[j] = '\0';
    stack_destroy(ptr_stack);
}
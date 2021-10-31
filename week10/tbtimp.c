#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    //TODO
    tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
    //TODO
    Node *temp;
    temp=tree->root;
    Node *parent=NULL;
    while(temp!=NULL)
    {
        if(data==temp->data)
        {
            return;
        }
        parent=temp;
        if(data<temp->data)
        {
            if(temp->leftThread==0)
            {
                temp=temp->left;
            }
            else
            {
                break;
            }
            
        }
        else
        {
            if(temp->rightThread==0)
            {
                temp=temp->right;
            }
            else
            {
                break;
            }
        }
    }
    Node *cur=(Node*)malloc(sizeof(Node));
    cur->data=data;
    cur->leftThread=1;
    cur->rightThread=1;

    if(parent==NULL)
    {
        tree->root=cur;
        cur->left=NULL;
        cur->right=NULL;
    }
    else if(data<(parent->data))
    {
        cur->left=parent->left;
        cur->right=parent;
        parent->leftThread=0;
        parent->left=cur;
    }
    else
    {
        cur->left=parent;
        cur->right=parent->right;
        parent->rightThread=0;
        parent->right=cur;
    }
    return;
}


Node *inorder_predecessor(Node *ptr)
{
   //TODO
    if(ptr->leftThread==1)
    {
        return(ptr->left);
    }
    ptr=ptr->left;
    while(ptr->rightThread==0)
    {
        ptr=ptr->right;
    }
    return(ptr);
}

Node *inorder_successor(Node *ptr)
{
   //TODO
   if(ptr->rightThread==1)
    {
        return(ptr->right);
    }
    ptr=ptr->right;
    while(ptr->leftThread==0)
    {
        ptr=ptr->left;
    }
    return(ptr);
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }

    Node *temp=tree->root;
    while(temp->leftThread==0)
    {
        temp=temp->left;
    }
    while(temp!=NULL)
    {
        printfun(temp->data);
        temp=inorder_successor(temp);
    }
    nextline();
    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *temp=tree->root;
    while(temp->rightThread==0)
    {
        temp=temp->right;
    }
    while(temp!=NULL)
    {
        printfun(temp->data);
        temp=inorder_predecessor(temp);
    }
    nextline();
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement  
}

void destroy(Node *r)
{
    //TODO
    free(r);
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}

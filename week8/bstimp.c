#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
//TODO 
  tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
// TODO : Insert element to create a BST
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->left=temp->right=NULL;
    if(tree->root==NULL)
    {
      tree->root=temp;
      return;
    }
    Node *prev=NULL,*cur=tree->root;
    while(cur!=NULL)
    {
      prev=cur;
      if(data==cur->data)
      {
        printf("Duplicate element.\n");
        free(temp);
      }
      if(data<cur->data)
      {
        cur=cur->left;
      }
      else
      {
        cur=cur->right;
      }
    }
    if(data<prev->data)
    {
      prev->left=temp;
    }
    else
    {
      prev->right=temp;
    }
}
void tree_delete(Tree *tree, int element)
{
  // TODO : Delete elements from BST 
  Node *cur=tree->root,*parent=NULL,*succ,*q;
  if(cur==NULL)
  {
    printf("Empty tree.\n");
    return;
  }
  while(cur!=NULL)
  {
    if(element==cur->data)
    {
      break;
    }
    parent=cur;
    if(element<cur->data)
    {
      cur=cur->left;
    }
    else
    {
      cur=cur->right;
    }
  }
  if(cur==NULL)
  {
    printf("No element found.\n");
    return;
  }
  if(cur->left==NULL)
  {
    q=cur->right;
  }
  else if(cur->right==NULL)
  {
    q=cur->left;
  }
  else
  {
    succ=cur->right;
    while(succ->left!=NULL)
    {
      succ=succ->left;
    }
    succ->left=cur->left;
    q=cur->right;
  }
  if(parent==NULL)
  {
    tree->root=q;
    return;
  }
  if(cur==parent->left)
  {
    parent->left=q;
  }
  else
  {
    parent->right=q;
  }
  free(cur);
}

void tree_inorder(Node *r)
{
  //TODO :  use printf to print inorder 
  if(r!=NULL)
  {
    tree_inorder(r->left);
    printf("%d ",r->data);
    tree_inorder(r->right);
  }
}

void tree_preorder(Node *r)
{
  //TODO :  use printf to print preorder
  if(r!=NULL)
  {
    printf("%d ",r->data);
    tree_preorder(r->left);
    tree_preorder(r->right);
  }
}

void tree_postorder(Node *r)
{
  //TODO :  use printf to print postorder
  if(r!=NULL)
  {
    tree_postorder(r->left);
    tree_postorder(r->right);
    printf("%d ",r->data);
  }
}

void postorder(Tree *t)
{
  //TODO
  tree_postorder(t->root);
  printf("\n");
}

void preorder(Tree *t)
{
  //TODO
  tree_preorder(t->root);
  printf("\n");
}

void inorder(Tree *t)
{
  //TODO   
  tree_inorder(t->root);
  printf("\n");
}

void destroy(Node *r)
{
  //TODO  
  Node *temp=r;
    Node *next;
    while(temp!=NULL)
    {
        next=temp->right;
        free(temp);
        temp=next;
    }
    r=NULL;
}

void tree_destroy(Tree *t)
{ 
  destroy(t->root);   
}

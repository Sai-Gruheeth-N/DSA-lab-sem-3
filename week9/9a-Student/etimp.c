#include "et.h"

Node *createExpressionTree(char* a,int len)
{
  //TODO
  Node *stack[len];
  int top=-1;
  Node *temp;
  int i=0;

  for(int i=0;a[i]!='0' && i<len;i++)
  {
    temp=(Node*)malloc(sizeof(Node));
    temp->left=temp->right=NULL;

    if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z') || (a[i]>='0' && a[i]<='9'))
    {    
      
      temp->data=a[i];
      
      if(top!=len-1)
      {
        top+=1;
        stack[top]=temp;
      }

    }
    else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/' || a[i]=='^')
    {
      
      temp->data=a[i];
      
      if(top!=-1)
      {
        temp->right=stack[top];
        top-=1;
      }

      if(top!=-1)
      {
        temp->left=stack[top];
        top-=1;
      }
      
      if(top!=len)
      {
        top+=1;
        stack[top]=temp;
      }

    }
    
  }

  temp=stack[top];
  top-=1;
  return(temp);
}


void inorder(Node *root)
{
  //TODO 
  // Note : Do not change the printf

  if(root!=NULL)
  {
    inorder(root->left);
    printf("%c",root->data);
    inorder(root->right);
  }
}

void preorder(Node *root)
{
  //TODO 
  // Note : Do not change the printf

  if(root!=NULL)
  {
    printf("%c",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(Node *root)
{
  //TODO 
  // Note : Do not change the printf

  if(root!=NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%c",root->data);
  }
}

void freeTree(Node *root)
{
  free(root);
}


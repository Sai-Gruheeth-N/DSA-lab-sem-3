#include<stdio.h>
#include "trie.h"
struct trienode *getnode()
{
  //TODO
  struct trienode *temp=NULL;
  temp=(struct trienode*)malloc(sizeof(struct trienode));
  if(temp)
  {
    temp->endofword=0;
    for(int i=0;i<26;i++)
    {
      temp->child[i]=NULL;
    }
    return(temp);
  }
  else
  {
    printf("Insufficient memory.\n");
    return(NULL);
  }
}

void insert(struct trienode *root, char *key)
{
  //TODO
  struct trienode *cur=root;
  while(*key)
  {
    if(cur->child[*key-'a']==NULL)
    {
      cur->child[*key-'a']=getnode();
    }
    cur=cur->child[*key-'a'];
    key++;
  }
  cur->endofword=1;
}

void display(struct trienode *curr)
{
  //TODO: 
  //Note : DO NOT USE printf() statement, use printfun() and   newline function for printing output 
  for(int i=0;i<26;i++)
  {
    if(curr->child[i]!=NULL)
    {
      word[length++]=i+'a';
      if(curr->child[i]->endofword==1)
      {
        printnewline();
        for(int j=0;j<length;j++)
        {
          printfun(word[j]);
        }
      }
      display(curr->child[i]);
    }
  }
  length--;
  return;
}

int search(struct trienode * root,char *key)
{
//TODO
  if(root==NULL)
  {
    return(0);
  }
  struct trienode *cur=root;
  while(*key)
  {
    cur=cur->child[*key-'a'];
    if(cur==NULL)
    {
      return(0);
    }
    key++;
  }
  return(cur->endofword);
}

void delete_trie(struct trienode *root,char *key)
{
  struct trienode *cur=root;
  while(*key)
  {
    if(cur->child[*key-'a']==NULL)
    {
      return;
    }
    cur=cur->child[*key-'a'];
    key++;
  }
  cur->endofword=0;
  return;
}

int check(struct trienode *x)
{
  //TODO
  int flag=0;
  for(int i=0;i<26;i++)
  {
    if(x->child[i]!=NULL)
    {
      flag+=1;
    }
  }
}

void push(struct trienode *x,int k)
{
  //TODO
  top+=1;
  s[top].m=x;
  s[top].index=k;
} 

struct stack pop()
{
  //TODO
  struct stack cur;
  cur=s[top--];
  return(cur);
}






















 /*void display(struct trienode *curr)
 {
   int i,j;
   for(i=0;i<26;i++)
   {
     if(curr->child[i]!=NULL)
     {
       word[length++]=i+97;
       if(curr->child[i]->endofword==1)//if word found
       {
          printf("\n");//print the word
          for(j=0;j<length;j++)
             printf("%c",word[j]);
        }
       display(curr->child[i]);
     }
    }
    length--;
    return;
 }*/



 /*struct trienode *getnode()
 {
   int i;
   struct trienode *temp;
   temp=(struct trienode*)malloc(sizeof(struct trienode));
   for(i=0;i<26;i++)
    temp->child[i]=NULL;
  temp->endofword=0;
   return temp;
 }*/


 /*void insert(struct trienode * root, char *key)
 {
   int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        curr->child[index]=getnode();
      curr=curr->child[index];
    }
    curr->endofword=1;
  }*/


 /*int search(struct trienode * root,char *key)
  {

  int i,index;
   struct trienode *curr;
   curr=root;

   for(i=0;key[i]!='\0';i++)
   {
     index=key[i]-'a';
     if(curr->child[index]==NULL)
        return 0;
      curr=curr->child[index];
    }
    if(curr->endofword==1)
       return 1;
   return 0;
  }*/

 /*void delete_trie(struct trienode *root,char *key)
  {
    int i,j,index,flag;
    struct trienode* curr;
    curr=root;
    flag=1;

    for(i=0;key[i]!='\0';i++)
    {
      index=key[i]-'a';
      if(curr->child[index]==NULL)
      {
         printf("Key not found\n");
         return;
      }
      curr=curr->child[index];
    }
      curr->endofword=0;
      return;
  }*/













 


 
 




















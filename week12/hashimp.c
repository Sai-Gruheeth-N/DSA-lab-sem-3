#include "hash.h"
HashTable *create_table(int size)
{
    //TODO
    HashTable *table=(HashTable*)malloc(sizeof(HashTable));
    table->size=size;
    table->table = (int*)malloc(table->size * sizeof(int));
    for(int i=0;i<table->size;i++)
    {
        table->table[i]=-1;
    }
    return(table);
}

void insert(HashTable *htable, int element)
{
    //TODO
    int key=element%(htable->size);
    while(htable->table[key]!=0 && htable->table[key]!=-1)
    {
        key+=1;
    }
    htable->table[key]=element;    
}

int search(HashTable *htable, int element)
{
    //TODO
    int key=element%(htable->size);
    while(htable->table[key]!=0)
    {
        if(htable->table[key]==element)
        {
            return(htable->table[key]);
        }
        key+=1;
    }
}

void delete (HashTable *htable, int element)
{
    //TODO
    int key=element%(htable->size);
    int pos=search(htable,element);
    if(pos==-1)
    {
        return;
    }
    else
    {
        htable->table[pos]=-1;
    }
    
}


void destroy_table(HashTable *htable)
{
    //TODO
    free(htable);
}

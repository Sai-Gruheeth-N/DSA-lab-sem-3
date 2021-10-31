#include "heap.h"
heap* heap_construct(int n)
{
    heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    tmp->capacity=n;
    tmp->size=0;
    return(tmp);
}

void heap_destruct(heap* tmp)
{
    //TODO
    tmp->capacity=0;
    tmp->size=0;
    free(tmp);
}

int heap_get_capacity(heap* tmp)
{
    //TODO
    return(tmp->capacity);
}

int heap_get_size(heap* tmp)
{
    //TODO
    return(tmp->size);
}

int heap_insert(heap* tmp,int data)
{
    //TODO
    if(tmp->size>=tmp->capacity)
    {
        return(0);
    }

    tmp->elements[tmp->size]=data;
    int child=tmp->size;
    int parent=(child-1)/2;

    while(child>0 && tmp->elements[parent]>data)
    {
        tmp->elements[child]=tmp->elements[parent];
        child=parent;
        parent=(child-1)/2;
    }

    tmp->elements[child]=data;
    tmp->size+=1;

    return(1);
}

int heap_get_min(heap* tmp)
{
    //TODO
    return(tmp->elements[0]);
}

void heap_remove(heap* tmp)
{
    //TODO

    int parent=0,child;
	int last=tmp->elements[tmp->size-1];

	if(tmp->size==1)
    {
        child=-1;
    }	
	else 
    {
        child=1;
    }

	if(tmp->size>2 && tmp->elements[2]<tmp->elements[1])
    {
		child+=1;
    }

	while(child>=0 && tmp->elements[child]<last)
	{
		tmp->elements[parent]=tmp->elements[child];
		parent=child;
		child=2*parent+1;

		if(child+1<tmp->size-1 && tmp->elements[child+1]<tmp->elements[child])
		{
            child+=1;
        }

		if(child>=tmp->size-1)
        {
  			child=-1;
        }
	}
    
	tmp->elements[parent]=last;
	tmp->size=tmp->size-1;
}


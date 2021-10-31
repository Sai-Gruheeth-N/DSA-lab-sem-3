#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
	//TODO
	int a=v,b=u,temp;
	if(a>=b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	int num=n;
	while(num--)
	{
		for(int i=0;i<n;i++)
		{
			if(graph[a][i]==1)
			{
				if(i>b)
				{
					temp=a;
					a=i;
					i=temp;
				}
				else
				{
					a=i;
				}
			}
			if(a==b)
			{
				return(1);
			}
		}
		return(0);
	}	
}
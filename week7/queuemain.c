#include <stdio.h>
#include "queue.h"
int main()
{
	Queue queue;
	queue_initialize(&queue);
	int choice, id, time, t;
	int loop = 1;
	while (loop)
	{
		printf("\n0.Enqueue\n1.Dequeue\n2.Queue peek\n3.Find person\n");
		printf("Enter choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			printf("Enter id and time : ");
			scanf("%d%d", &id, &time);
			queue_enqueue(&queue, id, time);
			break;

		case 1:
			queue_dequeue(&queue);
			break;

		case 2:
			queue_peek(&queue);
			break;

		case 3:
			printf("Enter time : ");
			scanf("%d", &t);
			queue_find_person(&queue, t);
			break;

		default:
			queue_destroy(&queue);
			loop = 0;
		}
	}
	return 0;
}



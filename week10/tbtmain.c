#include <stdio.h>
#include <stdlib.h>
#include "tbt.h"


int main()
{
    int choice, loop = 1;
    //Tree my_tree;
    tree_initialize(&my_tree);
    while (loop)
    {
        printf("\n1.Insert\n2.Print ascending\n3.Print descending\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            int element;
            int data;
        case 1:
            /* Insert elements */
            printf("Enter element to be inserted : ");
            scanf("%d", &element);
            tree_insert(&my_tree, element);
            break;
        case 2:
            /* Print elements in the ascending order */
            print_ascending(&my_tree);
            break;
        case 3:
            /* Print elements in the descending order */
            print_descending(&my_tree);
            break;
        default:
            tree_destroy(&my_tree);
            loop = 0;
            break;
        }
    }
    return 0;
}

void nextline()
{
	printf("\n");
}
void printfun(int n)
{
	//Node *ptr = tree->root;
	printf("%d ", n);
}

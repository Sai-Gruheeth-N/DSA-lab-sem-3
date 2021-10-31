#include<stdio.h>
#include "et.h"

int main()
{
    char postfix[100];
    int len;
    Node *root;
    int loop = 1,code;
    while(loop)
    {
        printf("\n1.Create expression tree\n2.Inorder traversal\n3.Preorder traversal\n4.Postorder traversal\n");
        printf("Enter choice : ");
        scanf("%d",&code);
        switch(code)
        {
            case 1:
                printf("Enter the postfix expression : ");
                scanf("%s",postfix);
                len=strlen(postfix);
                root = createExpressionTree(postfix,len);
                break;

            case 2:
                inorder(root);
                printf("\n");
                break;

            case 3:
                preorder(root);
                printf("\n");
                break;

            case 4:
                postorder(root);
                printf("\n");    
                break;

            default:
                loop = 0;
                break;

        }
    
    }
    freeTree(root);
    return 0;
}


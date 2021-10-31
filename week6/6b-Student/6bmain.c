#include "6b.h"
#include<stdio.h>

int main() 
{
	char source_infix[2000];
	char target_postfix[2000];
	int number_of_inputs = 0;
	printf("Enter number of inputs : ");
	scanf("%d", &number_of_inputs);
	for(int counter = 0; counter < number_of_inputs; ++ counter) 
	{
		printf("Enter expression %d : ",counter+1);
		scanf("%s", source_infix);
		convert_infix_to_postfix(source_infix, target_postfix);
		printf("Evaluated infix expression : %s\n", target_postfix);
	}
	return 0;
}


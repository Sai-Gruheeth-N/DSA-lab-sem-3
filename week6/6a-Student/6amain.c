#include <stdio.h>
#include "6a.h"
int main() {
	char expression[350];
	int number_of_inputs = 0;
	printf("Enter number of inputs : ");
	scanf("%d", &number_of_inputs);
	for(int counter = 0; counter < number_of_inputs; ++ counter) 
	{
		printf("Enter expression %d : ",counter+1);
		scanf("%s", expression);
		printf("Evaluated postfix expression value : %d\n", postfix_eval(expression));
	}
	return 0;
}



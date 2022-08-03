#include "push_swap.h"

void	print_cmd()
{
	return ;
}

void	print_stack(t_stack* stack1, t_stack* stack2)
{
	// 番兵をスキップ
	if (stack1->next->n != -1)
		stack1 = stack1->next;
	if (stack2->next->n != -1)
		stack2 = stack2->next;
	//printf(" ========== stack %c =========\n", c);
	while(stack1->n != -1 || stack2->n != -1)
	{
		if (stack1->n != -1)
		{
			printf("        %d   ", stack1->n);
			stack1 = stack1->next;
		}
		else
			printf("            ");
		if (stack2->n != -1)
		{
			printf("        %d\n", stack2->n);
			stack2 = stack2->next;
		}
		else
			printf("            \n");
	}
	printf("--------a   ");
	printf("--------b\n");
	printf("\n");
}


void	print_stack_reverse(t_stack*stack)
{
	// 番兵をスキップ
	stack = stack->prev;
	//printf(" ========== stack (reverse) =========\n");
	while(stack->n != -1)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
	printf("\n");
}

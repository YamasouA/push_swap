#include "push_swap.h"

void	swap(t_stack *a, char *cmd)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*top;

	if (a->next->next->n == -1)
		return ;
	top = a->next;
	tmp1 = top->next;
	tmp2 = top->next->next;
	top->next = tmp1->next;
	tmp2->prev = top;
	tmp1->next = top;
	top->prev = tmp1;
	tmp1->prev = a;
	a->next = tmp1;
	ft_putendl_fd(cmd, 1);
}

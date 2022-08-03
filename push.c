#include "push_swap.h"

t_stack	*ft_pop(t_stack *a)
{
	t_stack	*top;

	top = a->next;
	a->next->next->prev = a;
	a->next = a->next->next;
	return (top);
}

void	push(t_stack *a, t_stack *b, char *cmd)
{
	t_stack	*tmp1;

	if (b->next->n == -1)
		return ;
	tmp1 = ft_pop(b);
	tmp1->next = a->next;
	a->next->prev = tmp1;
	a->next = tmp1;
	tmp1->prev = a;
	ft_putendl_fd(cmd, 1);
}

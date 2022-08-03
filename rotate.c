#include "push_swap.h"

void	rotate(t_stack *a, char *cmd)
{
	t_stack	*head;
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*tail;

	if (a->next->next->n == -1)
		return ;
	head = a;
	tail = a->prev;
	tmp1 = a->next;
	tmp2 = a->next->next;
	head->next = tmp2;
	head->prev = tmp1;
	tmp1->next = head;
	tmp1->prev = tail;
	tmp2->prev = head;
	tail->next = tmp1;
	ft_putendl_fd(cmd, 1);
}

void	reverse_rotate(t_stack *a, char *cmd)
{
	t_stack	*head;
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*tail;

	if (a->next->next->n == -1)
		return ;
	head = a;
	tail = a->prev;
	tmp1 = a->next;
	tmp2 = tail->prev;
	head->next = tail;
	tail->prev = head;
	tail->next = tmp1;
	tmp1->prev = tail;
	head->prev = tmp2;
	tmp2->next = head;
	ft_putendl_fd(cmd, 1);
}

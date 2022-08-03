#include "push_swap.h"

t_stack	*init_data(int n, t_stack *prev)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (prev != NULL)
		new->prev = prev;
	else
		new->prev = new;
	new->next = new;
	return (new);
}

bool	push_stack(t_stack *a, int *idx, int a_size)
{
	int		i;
	t_stack	*new;
	t_stack	*prev;

	i = 0;
	prev = a;
	while (i < a_size)
	{
		new = (t_stack *)init_data(idx[i++], prev);
		if (new == NULL)
			return (false);
		prev->next = new;
		prev = new;
	}
	new->next = a;
	a->prev = new;
	return (true);
}

void	lst_free(t_stack *a)
{
	t_stack	*tmp;

	a = a->next;
	while (a->n != -1)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	free(a);
}

bool	is_empty(t_stack *a)
{
	if (a->next->n != -1)
		return (false);
	return (true);
}

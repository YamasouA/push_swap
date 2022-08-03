#include "push_swap.h"

void	push_swap_over_six(t_stack *a, t_stack *b, int a_size)
{
	int	max_n;
	int	nod;
	int	i;
	int	len;

	max_n = a_size - 1;
	nod = 0;
	i = 0;
	while ((max_n >> nod) != 0)
		nod++;
	while (i < nod)
	{
		len = 0;
		while (len < a_size)
		{
			if ((a->next->n >> i) & 1)
				rotate(a, "ra");
			else
				push(b, a, "pb");
			len++;
		}
		while (!is_empty(b))
			push(a, b, "pa");
		i++;
	}
}

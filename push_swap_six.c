#include "push_swap.h"

void	swap_two(t_stack *a)
{
	if (a->next->n > a->next->next->n)
		swap(a, "sa");
}

void	swap_three(t_stack *a)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;

	tmp3 = a->next->n;
	tmp2 = a->next->next->n;
	tmp1 = a->next->next->next->n;
	if (tmp1 > tmp2 && tmp2 > tmp3)
		return ;
	else if (tmp1 > tmp3 && tmp3 > tmp2)
		swap(a, "sa");
	else if (tmp1 < tmp2 && tmp2 < tmp3)
	{
		swap(a, "sa");
		reverse_rotate(a, "rra");
	}
	else if (tmp1 > tmp2 && tmp1 < tmp3)
		rotate(a, "ra");
	else if (tmp1 > tmp3 && tmp2 > tmp1)
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
	else if (tmp1 < tmp3 && tmp3 < tmp2)
		reverse_rotate(a, "rra");
}

void	set_top(t_stack *a, int min, int a_size)
{
	if (min > a_size / 2)
	{
		min = a_size - min;
		while (min-- != 0)
			reverse_rotate(a, "rra");
	}
	else
	{
		while (min-- != 0)
			rotate(a, "ra");
	}
}

void	ft_pop_min(t_stack *a, t_stack *b, int a_size)
{
	t_stack	*tmp;
	int		min;
	long	min_val;
	int		cnt;

	tmp = a->next;
	min_val = LONG_MAX;
	cnt = 0;
	while (tmp->n != -1)
	{
		if (tmp->n < min_val)
		{
			min_val = tmp->n;
			min = cnt;
		}
		cnt++;
		tmp = tmp->next;
	}
	set_top(a, min, a_size);
	push(b, a, "pb");
}

void	push_swap_six(t_stack *a, t_stack *b, int a_size)
{
	if (a_size == 1)
		return ;
	else if (a_size == 2)
		swap_two(a);
	else if (a_size == 3)
		swap_three(a);
	else
	{
		while (a_size > 3)
		{
			ft_pop_min(a, b, a_size);
			a_size--;
		}
		swap_three(a);
		while (b->next->n != -1)
			push(a, b, "pa");
	}
}

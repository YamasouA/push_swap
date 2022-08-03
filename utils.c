#include "push_swap.h"

void	ft_exit(t_stack *a, t_stack *b, int *nbr, int status)
{
	if (a != NULL)
		lst_free(a);
	if (b != NULL)
		lst_free(b);
	free(nbr);
	if (status == EXIT_FAILURE)
		ft_putendl_fd("Error", 1);
	exit(status);
}

bool	is_sorted(int *idx, int a_size)
{
	int	i;

	i = 1;
	while (i < a_size)
	{
		if (idx[i - 1] > idx[i])
			return (false);
		i++;
	}
	return (true);
}

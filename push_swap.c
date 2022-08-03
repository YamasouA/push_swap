#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*idx;
	int		a_size;

	if (check_arg(argc, argv))
		ft_exit(NULL, NULL, NULL, EXIT_FAILURE);
	if (argc < 2)
		ft_exit(NULL, NULL, NULL, EXIT_SUCCESS);
	a_size = argc - 1;
	a = init_data(-1, NULL);
	b = init_data(-1, NULL);
	idx = (int *)malloc(sizeof(int) * a_size);
	if (a == NULL || b == NULL || idx == NULL
		|| !get_index(a_size, argv, idx))
		ft_exit(a, b, idx, EXIT_FAILURE);
	if (is_sorted(idx, a_size))
		ft_exit(a, b, idx, EXIT_SUCCESS);
	if (!push_stack(a, idx, a_size))
		ft_exit(a, b, idx, EXIT_FAILURE);
	if (argc <= 7)
		push_swap_six(a, b, a_size);
	else
		push_swap_over_six(a, b, a_size);
	ft_exit(a, b, idx, EXIT_SUCCESS);
}

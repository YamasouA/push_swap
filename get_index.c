#include "push_swap.h"

void	sort(int *nbs, int a_size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < a_size - 1)
	{
		j = i + 1;
		while (j < a_size)
		{
			if (nbs[i] > nbs[j])
			{
				tmp = nbs[i];
				nbs[i] = nbs[j];
				nbs[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	search_idx(int *nbs, int a_size, int target)
{
	int	idx;

	idx = 0;
	while (idx < a_size)
	{
		if (nbs[idx] == target)
			return (idx);
		idx++;
	}
	return (idx);
}

bool	is_dup(int *nbs, int a_size)
{
	int	i;

	i = 1;
	while (i < a_size)
	{
		if (nbs[i] == nbs[i - 1])
			return (true);
		i++;
	}
	return (false);
}

bool	get_index(int a_size, char **argv, int *idx)
{
	int	*nbs;
	int	i;

	i = -1;
	nbs = (int *)malloc(sizeof(int) * a_size);
	if (nbs == NULL)
		return (false);
	while (++i < a_size)
		nbs[i] = ft_atoi(argv[i + 1]);
	i = -1;
	sort(nbs, a_size);
	if (is_dup(nbs, a_size))
	{
		free(nbs);
		return (false);
	}
	while (++i < a_size)
		idx[i] = search_idx(nbs, a_size, ft_atoi(argv[i + 1]));
	free(nbs);
	return (true);
}

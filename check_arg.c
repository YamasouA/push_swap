#include "push_swap.h"

bool	is_overflow(char c, int nbr)
{
	if ((INT_MIN + (c - '0')) / 10 <= nbr
		&& nbr <= (INT_MAX - (c - '0')) / 10)
		return (false);
	return (true);
}

bool	is_int_number(char *nbr)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	if (*nbr == '-' || *nbr == '+')
	{
		sign = 44 - *nbr++;
		if (*nbr < '0' || *nbr > '9')
		{
			return (false);
		}
	}
	while (*nbr != '\0')
	{
		if (*nbr < '0' || *nbr > '9')
			return (false);
		if (!is_overflow(*nbr, i))
			i = sign * (*nbr - '0') + i * 10;
		else
			return (false);
		nbr++;
	}
	return (true);
}

bool	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if(!is_int_number(argv[i]))
			return (true);
		i++;
	}
	return (false);
}

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "./libft/includes/libft.h"

typedef struct s_stack	t_stack;

struct s_stack {
	t_stack	*prev;
	t_stack	*next;
	int		n;
};

void	swap(t_stack *a, char *cmd);
void	push(t_stack *a, t_stack *b, char *cmd);
void	rotate(t_stack *a, char *cmd);
void	reverse_rotate(t_stack *a, char *cmd);

void	print_stack(t_stack *stack1, t_stack *stack2);
void	print_stack_reverse(t_stack*stack);

void	push_swap(int argc, char **argv);
void	push_swap_six(t_stack *a, t_stack *b, int a_size);
void	push_swap_over_six(t_stack *a, t_stack *b, int a_size);

bool	get_index(int a_size, char **argv, int *idx);

bool	is_empty(t_stack *a);
void	lst_free(t_stack *a);
bool	push_stack(t_stack *a, int *idx, int a_size);
t_stack	*init_data(int n, t_stack *prev);

bool	check_arg(int argc, char **argv);

void	ft_exit(t_stack *a, t_stack *b, int *nbr, int status);
bool	is_sorted(int *idx, int a_size);
#endif

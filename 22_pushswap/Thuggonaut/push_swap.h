#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack_node
{
    int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//handle errors

//stack initiation

//nodes initiation

//stack utils

//commands

//algorithms

#endif
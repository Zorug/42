/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:22:46 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/06 12:31:42 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_front(t_dnode **stack, t_dnode *new)
{
	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

t_dnode	*ft_stack_new(long content)
{
	t_dnode	*new;

	new = (t_dnode *)malloc(sizeof(t_dnode));
	if (!new)
		return (NULL);
	new->value = content;
	new->push_cost = 0;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	new->above_median = false;
	new->target_node = NULL;
	new->cheapest = false;
	return (new);
}

t_dnode	*ft_stack_last(t_dnode *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_dnode **stack, t_dnode *new)
{
	t_dnode	*last;

	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stack_last(*stack);
	last->next = new;
}

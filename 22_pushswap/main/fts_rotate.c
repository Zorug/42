/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:01:26 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/06 12:01:30 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_dnode **stack)
{
	t_dnode	*last_node;
	int		len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_dnode **head_a)
{
	rotate(head_a);
	ft_printf("ra\n");
}

void	rb(t_dnode **head_b)
{
	rotate(head_b);
	ft_printf("rb\n");
}

void	rr(t_dnode **head_a, t_dnode **head_b)
{
	rotate(head_a);
	rotate(head_b);
	ft_printf("rr\n");
}

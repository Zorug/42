/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:24:03 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/06 12:45:46 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dnode	*find_last_node(t_dnode *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	stack_len(t_dnode *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	do_stuff(t_dnode **a, t_dnode **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3)
		pb(a, b);
	if (len_a-- > 3)
		pb(a, b);
	while (len_a-- > 3)
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

/*void	do_stuff(t_dnode **a, t_dnode **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3)
		pb(a, b);
	if (len_a-- > 3)
		pb(a, b);
	while (len_a-- > 3)
 	{
		init_nodes_a(*a, *b);
		ft_printf("\n");	
		move_a_to_b(a, b);
		print_both(*a, *b, print_list_foward);
	}
	sort_three(a);
	print_both(*a, *b, print_list_foward);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	print_both(*a, *b, print_list_foward);
	current_index(*a);
	print_both(*a, *b, print_list_foward);
	min_on_top(a);
	print_both(*a, *b, print_list_foward);
}*/
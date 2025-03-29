/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-turk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:18:23 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/30 14:08:58 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void	push_twice_to_b(t_ps *ps);
static int	the_last_of(t_ps *ps, char chr);
//static int	the_first_of(t_ps *ps, char chr);

	// Part 1 - Push 2 numbers to B
int	algo_turk(t_ps *ps)
{
	push_twice_to_b(ps);
	// Part 2 - Find the most eficient steps
	while (ft_lstsize(ps->a) > 3)
	{
		if (ps->verbose)
			ft_printf("TODO!\n");
		break ;
	}
	// Part 3 - Order the last three elements of A
	algo_small(ps);
	// Part 4 - Return to A -  to the correct position
	// calculate the distance to desired position.
	while ((ft_atoi(ps->a->content) > ft_atoi(ps->b->content))
		&& (the_last_of(ps, 'a') > ft_atoi(ps->b->content))
		&& ft_lstsize(ps->b) >= 1)
	{
		push_a(ps);
		if (ft_lstsize(ps->b) == 0)
			break ;
	}
	// Part 5 - Rotate the minimum to the top
	return (check_order(ps, 'a'), 0);
}

//static int	the_first_of(t_ps *ps, char chr)
//{
//	t_list	*first;
//
//	first = (ps->a);
//	if (chr == 'b')
//		first = (ps->b);
//	return (*(int *) (first->content));
//}

static int	the_last_of(t_ps *ps, char chr)
{
	t_list	*last;

	last = ft_lstlast(ps->a);
	if (chr == 'b')
		last = ft_lstlast(ps->b);
	return (*(int *) (last->content));
}

static void	push_twice_to_b(t_ps *ps)
{
	push_b(ps);
	push_b(ps);
}

//get_maximum_element
//get_median_element
//get_minimim_element
*/

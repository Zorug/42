/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b-op-swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:30:22 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/05 07:24:32 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
sa (swap a):	Swap the first 2 elements at the top of stack a.
				Do nothing if there is only one or no elements.
sb (swap b):	Swap the first 2 elements at the top of stack b.
				Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/

static void	swap_element(t_list **lst);
static int	swap_top(t_ps *ps, char chr);

static int	swap_top(t_ps *ps, char chr)
{
	t_list	**lst;

	lst = &(ps->a);
	if (chr == 'b')
		lst = &(ps->b);
	else if (chr != 'a')
		return (2);
	if (*lst && ((*lst)->next))
		swap_element(lst);
	else
		return (1);
	return (0);
}

static void	swap_element(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void	b_swap_a(t_ps *ps)
{
	swap_top(ps, 'a');
}

void	b_swap_b(t_ps *ps)
{
	swap_top(ps, 'b');
}

void	b_swap_ss(t_ps *ps)
{
	swap_top(ps, 'a');
	swap_top(ps, 'b');
}

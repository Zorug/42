/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b-op-rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:59:35 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/05 07:24:29 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
ra (rotate a):	Shift up all elements of stack a by 1.
				The first element becomes the last one.
rb (rotate b):	Shift up all elements of stack b by 1.
				The first element becomes the last one.
rr : ra and rb at the same time.
*/

static void	rotate_element(t_list **lst);
static int	rotate(t_ps *ps, char chr);

static int	rotate(t_ps *ps, char chr)
{
	t_list	**lst;

	lst = &(ps->a);
	if (chr == 'b')
		lst = &(ps->b);
	else if (chr != 'a')
		return (1);
	if (*lst && ((*lst)->next))
		rotate_element(lst);
	else
		return (1);
	return (0);
}

static void	rotate_element(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	first = *lst;
	*lst = first->next;
	first->next = NULL;
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	b_rotate_a(t_ps *ps)
{
	rotate(ps, 'a');
}

void	b_rotate_b(t_ps *ps)
{
	rotate(ps, 'b');
}

void	b_rotate_rr(t_ps *ps)
{
	rotate(ps, 'a');
	rotate(ps, 'b');
}

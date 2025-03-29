/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b-op-push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:48:39 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/05 07:24:22 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
pa (push a):
			Take the first element at the top of b and put it at the top of a.
			Do nothing if b is empty.
pb (push b):
			Take the first element at the top of a and put it at the top of b.
			Do nothing if a is empty.
*/

//void	ft_lstadd_front(t_list **lst, t_list *new)
//t_list	*ft_lstnew(void *content)

static void	take_element(t_list **lsta, t_list **lstb);
static int	push(t_ps *ps, char chr);

static int	push(t_ps *ps, char chr)
{
	t_list	**lsta;
	t_list	**lstb;

	lsta = &(ps->a);
	lstb = &(ps->b);
	if (chr == 'b')
	{
		lsta = &(ps->b);
		lstb = &(ps->a);
	}
	else if (chr != 'a')
		return (2);
	if (!*lstb)
		return (1);
	take_element(lsta, lstb);
	return (0);
}

static void	take_element(t_list **lsta, t_list **lstb)
{
	t_list	*new;

	new = (*lstb);
	*lstb = (*lstb)->next;
	ft_lstadd_front(lsta, new);
}

void	b_push_a(t_ps *ps)
{
	push(ps, 'a');
}

void	b_push_b(t_ps *ps)
{
	push(ps, 'b');
}

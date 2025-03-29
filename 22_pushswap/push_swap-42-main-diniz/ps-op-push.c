/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-op-push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:48:39 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/29 11:51:49 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		if (ps->verbose)
			ft_printf("		no element on top to push to %c\n", chr);
		return (1);
	}
	if (ps->verbose)
		ft_printf("	Pushing the top element into %c\n", chr);
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

void	push_a(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("PA");
	result = push(ps, 'a');
	if (!(ps->verbose) && (result == 0))
		ft_printf("pa\n");
	print_stacks(ps);
}

void	push_b(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("PB");
	result = push(ps, 'b');
	if (!(ps->verbose) && (result == 0))
		ft_printf("pb\n");
	print_stacks(ps);
}

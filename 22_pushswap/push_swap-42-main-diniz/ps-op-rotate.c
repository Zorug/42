/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-op-rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:59:35 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/03 10:24:41 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ps->verbose)
		ft_printf("	"
			"Shifting UP the elments of stack %c\n", chr);
	if (*lst && ((*lst)->next))
		rotate_element(lst);
	else
	{
		if (ps->verbose)
			ft_printf("		no elements to rotate in stack %c!\n", chr);
		return (1);
	}
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

void	rotate_a(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("RA");
	result = rotate(ps, 'a');
	if (!(ps->verbose) && (result == 0))
		ft_printf("ra\n");
	print_stacks(ps);
}

void	rotate_b(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("RB");
	result = rotate(ps, 'b');
	if (!(ps->verbose) && (result == 0))
		ft_printf("rb\n");
	print_stacks(ps);
}

void	rotate_rr(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("RR");
	result = rotate(ps, 'a');
	result *= rotate(ps, 'b');
	if (!(ps->verbose) && (result == 0))
		ft_printf("rr\n");
	print_stacks(ps);
}

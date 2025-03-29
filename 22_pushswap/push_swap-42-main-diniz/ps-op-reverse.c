/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-op-reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:35:34 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/03 10:24:27 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
rra (reverse rotate a):	Shift down all elements of stack a by 1.
				The last element becomes the first one.
rrb (reverse rotate b):	Shift down all elements of stack b by 1.
				The last element becomes the first one.
rrr : rra and rrb at the same time.
*/

static void	reverse_element(t_list **lst);
static int	reverse(t_ps *ps, char chr);

static int	reverse(t_ps *ps, char chr)
{
	t_list	**lst;

	lst = &(ps->a);
	if (chr == 'b')
		lst = &(ps->b);
	else if (chr != 'a')
		return (1);
	if (ps->verbose)
		ft_printf("	"
			"Shifting DOWN the elments of stack %c\n", chr);
	if (*lst && ((*lst)->next))
		reverse_element(lst);
	else
	{
		if (ps->verbose)
			ft_printf("		no elements to reverse rotate in stack %c!\n", chr);
		return (1);
	}
	return (0);
}

static void	reverse_element(t_list **lst)
{
	t_list	*first;
	t_list	*last;
	t_list	*penultimate;

	first = *lst;
	last = *lst;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
	last->next = first;
	*lst = last;
}

void	reverse_a(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("RRA");
	result = reverse(ps, 'a');
	if (!(ps->verbose) && (result == 0))
		ft_printf("rra\n");
	print_stacks(ps);
}

void	reverse_b(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("RRB");
	result = reverse(ps, 'b');
	if (!(ps->verbose) && (result == 0))
		ft_printf("rrb\n");
	print_stacks(ps);
}

void	reverse_rr(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("RRR");
	result = reverse(ps, 'a');
	result *= reverse(ps, 'b');
	if (!(ps->verbose) && (result == 0))
		ft_printf("rrr\n");
	print_stacks(ps);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-op-swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:30:22 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/29 11:13:16 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ps->verbose)
		ft_printf("	"
			"swaping the first 2 elements at the top of stack %c\n", chr);
	if (*lst && ((*lst)->next))
		swap_element(lst);
	else
	{
		if (ps->verbose)
			ft_printf("		no elements to swap in stack %c!\n", chr);
		return (1);
	}
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

void	swap_a(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("SA");
	result = swap_top(ps, 'a');
	if (!(ps->verbose) && (result == 0))
		ft_printf("sa\n");
	print_stacks(ps);
}

void	swap_b(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("SB");
	result = swap_top(ps, 'b');
	if (!(ps->verbose) && (result == 0))
		ft_printf("sb\n");
	print_stacks(ps);
}

void	swap_ss(t_ps *ps)
{
	int	result;

	if (ps->verbose)
		ft_printf("SS");
	result = swap_top(ps, 'a');
	result *= swap_top(ps, 'b');
	if (!(ps->verbose) && (result == 0))
		ft_printf("ss\n");
	print_stacks(ps);
}

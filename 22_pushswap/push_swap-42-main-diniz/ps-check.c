/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:13 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/30 09:42:09 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_final_static(t_ps *ps, char chr);

int	check_order(t_ps *ps, char chr)
{
	t_list	*current;
	t_list	*previous;

	previous = (ps->a);
	if (chr == 'b')
		previous = (ps->b);
	else if ((chr != 'a') || (!(previous->next)))
		return (2);
	current = previous->next;
	while (previous->next)
	{
		if ((*(int *)(current->content)) <= *(int *)(previous->content))
		{
			if (ps->verbose)
				ft_printf("\033[33mStack %c is not in order\033[0m\n", chr);
			return (1);
		}
		previous = current;
		current = current->next;
	}
	if (ps->verbose)
		check_final_static(ps, chr);
	return (0);
}
// Returns 1 if it's nor ordered
// Returns 0 if it is correclt ordered

static void	check_final_static(t_ps *ps, char chr)
{
	if (ft_lstsize(ps->b) == 0)
		ft_printf("\033[42m"
			"Stack %c looks to be in the correct order!\033[0m\n", chr);
	else
		ft_printf("\033[32m"
			"Stack %c looks to be in the correct order!\033[0m\n", chr);
}

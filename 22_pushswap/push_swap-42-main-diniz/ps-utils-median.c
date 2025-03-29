/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-utils-median.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:44:00 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/04 16:06:57 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median(t_ps *ps, char chr)
{
	int	len;
	int	steps;
	int	mediam;
	int	i;

	len = stack_len(ps, chr);
	if (len % 2 == 0)
		steps = (len / 2) - 1;
	else
		steps = (len - 1) / 2;
	i = 0;
	mediam = max(ps, chr);
	while (i < steps)
	{
		mediam = max_under(ps, chr, mediam);
		i++;
	}
	if (len % 2 == 0)
		mediam = (mediam + (max_under(ps, chr, mediam))) / 2;
	return (mediam);
}

int	max_under(t_ps *ps, char chr, int border)
{
	t_list	*lst;
	int		max_bellow;

	if (chr == 'a')
		lst = (ps->a);
	if (chr == 'b')
		lst = (ps->b);
	max_bellow = min(ps, chr);
	while (lst != NULL)
	{
		if ((max_bellow < *(int *) lst->content)
			&& (*(int *) lst->content < border))
			max_bellow = *(int *) lst->content;
		lst = lst->next;
	}
	return (max_bellow);
}

int	min_above(t_ps *ps, char chr, int border)
{
	t_list	*lst;
	int		min_above;

	if (chr == 'a')
		lst = (ps->a);
	if (chr == 'b')
		lst = (ps->b);
	min_above = max(ps, chr);
	while (lst != NULL)
	{
		if ((min_above > *(int *) lst->content)
			&& (*(int *) lst->content > border))
			min_above = *(int *) lst->content;
		lst = lst->next;
	}
	return (min_above);
}

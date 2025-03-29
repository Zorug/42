/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-utils-order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:24:38 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/04 16:05:55 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_ps *ps, char chr)
{
	t_list	*lst;
	int		min;

	if (chr == 'a')
		lst = (ps->a);
	if (chr == 'b')
		lst = (ps->b);
	min = *(int *) lst->content;
	while (lst != NULL)
	{
		if (min > *(int *) lst->content)
			min = *(int *) lst->content;
		lst = lst->next;
	}
	return (min);
}

int	max(t_ps *ps, char chr)
{
	t_list	*lst;
	int		max;

	if (chr == 'a')
		lst = (ps->a);
	if (chr == 'b')
		lst = (ps->b);
	max = *(int *) lst->content;
	while (lst != NULL)
	{
		if (max < *(int *) lst->content)
			max = *(int *) lst->content;
		lst = lst->next;
	}
	return (max);
}

int	get_value(t_ps *ps, char chr, int n)
{
	t_list	*lst;
	int		pos;

	if (chr == 'a')
		lst = (ps->a);
	if (chr == 'b')
		lst = (ps->b);
	pos = 1;
	while (lst != NULL)
	{
		if (pos == n)
			break ;
		lst = lst->next;
		pos++;
	}
	return (*(int *) lst->content);
}

int	get_pos_from_value(t_ps *ps, char chr, int value)
{
	t_list	*lst;
	int		pos;

	if (chr == 'a')
		lst = (ps->a);
	if (chr == 'b')
		lst = (ps->b);
	pos = 1;
	while (lst != NULL)
	{
		if (*(int *) lst->content == value)
			break ;
		lst = lst->next;
		pos++;
	}
	return (pos);
}

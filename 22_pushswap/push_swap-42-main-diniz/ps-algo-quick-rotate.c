/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-quick-rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:15:13 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/04 16:24:47 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	step_reverse(t_ps *ps, char chr, int steps);
static void	step_rotate(t_ps *ps, char chr, int steps);

void	rotate_into_minimum(t_ps *ps, char chr)
{
	int	steps;

	if (min(ps, chr) != get_value(ps, chr, 1))
	{
		steps = get_pos_from_value(ps, chr, min(ps, chr));
		if (steps > (stack_len(ps, chr) / 2))
		{
			steps = stack_len(ps, chr) - steps + 1;
			step_reverse(ps, chr, steps);
		}
		else
			step_rotate(ps, chr, steps);
	}
	if (ps->verbose)
		check_order(ps, chr);
}

static void	step_reverse(t_ps *ps, char chr, int steps)
{
	while (steps > 0)
	{
		if (chr == 'a')
			reverse_a(ps);
		if (chr == 'b')
			reverse_b(ps);
		steps--;
		print_stacks(ps);
	}
}

static void	step_rotate(t_ps *ps, char chr, int steps)
{
	steps--;
	while (steps > 0)
	{
		if (chr == 'a')
			rotate_a(ps);
		if (chr == 'b')
			rotate_b(ps);
		steps--;
		print_stacks(ps);
	}
}

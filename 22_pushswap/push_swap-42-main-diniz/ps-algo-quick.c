/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:57:08 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/04 16:24:38 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	align_stacks(t_ps *ps, t_eco eco);
static void	align_stacks_direction(t_ps *ps, t_eco eco);
static void	align_reverse_rotate(t_ps *ps, int steps_a, int steps_b);

int	algo_quick(t_ps *ps)
{
	t_eco	eco;

	if (check_order(ps, 'a') == 0)
		return (0);
	quick_move(ps);
	algo_small(ps);
	while (stack_len(ps, 'b') > 0)
	{
		eco = economic_operation(ps);
		align_stacks(ps, eco);
	}
	rotate_into_minimum(ps, 'a');
	return (0);
}

static void	align_stacks(t_ps *ps, t_eco eco)
{
	int	steps_a;
	int	steps_b;

	if (eco.reverse_direction)
	{
		if (eco.next_a == 1)
			steps_a = 0;
		else
			steps_a = (stack_len(ps, 'a') - eco.next_a) + 1;
		steps_b = 1 + stack_len(ps, 'b') - get_pos_from_value(ps, 'b',
				max_under(ps, 'b', get_value(ps, 'a',
						eco.next_a)));
		align_reverse_rotate(ps, steps_a, steps_b);
	}
	else
		align_stacks_direction(ps, eco);
	push_a(ps);
}

static void	align_reverse_rotate(t_ps *ps, int steps_a, int steps_b)
{
	while ((steps_a > 0) || (steps_b > 0))
	{
		if ((steps_a > 0) && (steps_b > 0))
			reverse_rr(ps);
		else if (steps_a > 0)
			reverse_a(ps);
		else if (steps_b > 0)
			reverse_b(ps);
		steps_a--;
		steps_b--;
	}
}

static void	align_stacks_direction(t_ps *ps, t_eco eco)
{
	int	steps_a;
	int	steps_b;

	steps_a = 0 - 1 + eco.next_a;
	if (eco.next_b == 1)
		steps_b = 0;
	else
		steps_b = 0 - 1 + eco.next_b;
	while ((steps_a > 0) || (steps_b > 0))
	{
		if (ps->verbose)
		{
			ft_printf("stack a needs to rotate %i times\n", steps_a);
			ft_printf("stack b needs to rotate %i times\n", steps_b);
		}
		if ((steps_a > 0) && (steps_b > 0))
			rotate_rr(ps);
		else if (steps_a > 0)
			rotate_a(ps);
		else if (steps_b > 0)
			rotate_b(ps);
		steps_a--;
		steps_b--;
	}
}

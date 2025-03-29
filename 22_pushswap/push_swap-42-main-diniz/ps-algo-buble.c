/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-algo-buble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:47:14 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/04 16:05:55 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack_len:	ft_lstsize(ps->a)

int	algo_buble(t_ps *ps, char chr)
{
	if (ps->verbose)
		ft_printf("Iniciating BUBLE SORT at %c\n", chr);
	while (1)
	{
		if (ps->verbose)
		{
			ft_printf("Buble sort: comparing postions 1 (%i) and 2 (%i)\n",
				get_value(ps, chr, 1), get_value(ps, chr, 2));
		}
		if ((get_value(ps, chr, 1) > get_value(ps, chr, 2))
			&& (get_value(ps, chr, 1) != max(ps, chr)))
			swap_stack(ps, chr);
		else
			rotate_stack(ps, chr);
		if (check_order(ps, chr) == 0)
			break ;
	}
	if (ps->verbose)
		ft_printf("Ending buble sort at %c\n", chr);
	return (0);
}

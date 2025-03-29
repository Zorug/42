/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:21:29 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/30 15:23:43 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_ps *ps, char chr);
void	swap_stack(t_ps *ps, char chr);
void	rotate_stack(t_ps *ps, char chr);
void	reverse_stack(t_ps *ps, char chr);

void	push_stack(t_ps *ps, char chr)
{
	if (chr == 'a')
		push_a(ps);
	if (chr == 'b')
		push_b(ps);
}

void	swap_stack(t_ps *ps, char chr)
{
	if (chr == 'a')
		swap_a(ps);
	if (chr == 'b')
		swap_b(ps);
}

void	rotate_stack(t_ps *ps, char chr)
{
	if (chr == 'a')
		rotate_a(ps);
	if (chr == 'b')
		rotate_b(ps);
}

void	reverse_stack(t_ps *ps, char chr)
{
	if (chr == 'a')
		reverse_a(ps);
	if (chr == 'b')
		reverse_b(ps);
}

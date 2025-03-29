/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:36:02 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/04 18:12:37 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//typedef struct s_list
//{
//	int				content;
//	struct s_list	*next;
//}					t_list;

typedef struct s_ps
{
	int		verbose;
	t_list	*a;
	t_list	*b;
}			t_ps;

typedef struct s_eco
{
	int		cost;
	int		next_a;
	int		next_b;
	int		reverse_direction;
}			t_eco;

//ps-initialize
int		initialize(t_ps *ps, int argc, char **argv, int verbose);
//ps-utils
void	compose_indexes(t_ps *ps);
void	print_stacks(t_ps *ps);
int		is_int(const char *nptr);
void	del(void *content);
//ps-op-swap
void	swap_a(t_ps *ps);
void	swap_b(t_ps *ps);
void	swap_ss(t_ps *ps);
//ps-op-push
void	push_a(t_ps *ps);
void	push_b(t_ps *ps);
//ps-op-rotate
void	rotate_a(t_ps *ps);
void	rotate_b(t_ps *ps);
void	rotate_rr(t_ps *ps);
//ps-op-reverse
void	reverse_a(t_ps *ps);
void	reverse_b(t_ps *ps);
void	reverse_rr(t_ps *ps);
//ps-check
int		check_order(t_ps *ps, char chr);
//ps-algo-small
int		algo_small(t_ps *ps);
//ps-algo-buble
int		algo_buble(t_ps *ps, char chr);
//ps-algo-quick
int		algo_quick(t_ps *ps);
//ps-algo-quick-eco
t_eco	economic_operation(t_ps *ps);
//ps-algo-quick-move
void	move_to_b(t_ps *ps);
void	quick_move(t_ps *ps);
int		find_nth_smallest(t_ps *ps, char chr, int len);
//ps-algo-quick-rotate
void	rotate_into_minimum(t_ps *ps, char chr);
//ps-op
void	push_stack(t_ps *ps, char chr);
void	swap_stack(t_ps *ps, char chr);
void	rotate_stack(t_ps *ps, char chr);
void	reverse_stack(t_ps *ps, char chr);
//ps-utils-order
int		get_pos_from_value(t_ps *ps, char chr, int value);
int		get_value(t_ps *ps, char chr, int n);
int		max(t_ps *ps, char chr);
int		min(t_ps *ps, char chr);
int		stack_len(t_ps *ps, char chr);
//ps-utils-median
int		median(t_ps *ps, char chr);
int		max_under(t_ps *ps, char chr, int border);
int		min_above(t_ps *ps, char chr, int border);

//bonus-checker
//bonus-checker-initializer
int		initialize_bonus(t_ps *ps, int argc, char **argv, int verbose);
//bonus-utils-stack
void	print_stacks_bonus(t_ps *ps);
int		is_int_bonus(const char *nptr);
void	del_bonus(void *content);
int		stack_len_bonus(t_ps *ps, char chr);
//bonus-op-swap
void	b_swap_a(t_ps *ps);
void	b_swap_b(t_ps *ps);
void	b_swap_ss(t_ps *ps);
//bonus-op-push
void	b_push_a(t_ps *ps);
void	b_push_b(t_ps *ps);
//bonus-op-rotate
void	b_rotate_a(t_ps *ps);
void	b_rotate_b(t_ps *ps);
void	b_rotate_rr(t_ps *ps);
//bonus-op-reverse
void	b_reverse_a(t_ps *ps);
void	b_reverse_b(t_ps *ps);
void	b_reverse_rr(t_ps *ps);

#endif

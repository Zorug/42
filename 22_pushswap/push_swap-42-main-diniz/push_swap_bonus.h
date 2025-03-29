/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:36:02 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/05 07:34:17 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

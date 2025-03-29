/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b-checker_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:35:33 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/05 07:24:13 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_order_bonus(t_ps *ps);
static void	interpret_order(t_ps *ps, char *line);

int	main(int argc, char **argv)
{
	int		verbose;
	t_ps	ps;
	char	*line;

	verbose = 0;
	if (argc == 1)
		return (1);
	if (initialize_bonus(&ps, argc, argv, verbose) != 0)
		return (ft_putstr_fd("Error\n", 2), 1);
	line = get_next_line(0);
	while (line != NULL)
	{
		interpret_order(&ps, line);
		line = get_next_line(0);
	}
	check_order_bonus(&ps);
	ft_lstclear(&ps.a, (void (*)(void *))del_bonus);
	ft_lstclear(&ps.b, (void (*)(void *))del_bonus);
}

static void	interpret_order(t_ps *ps, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		b_swap_a(ps);
	if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		b_swap_b(ps);
	if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		b_swap_ss(ps);
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		b_push_a(ps);
	if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		b_push_b(ps);
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		b_rotate_a(ps);
	if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		b_rotate_b(ps);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		b_rotate_rr(ps);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		b_reverse_a(ps);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		b_reverse_b(ps);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
		b_reverse_rr(ps);
}

static int	check_order_bonus(t_ps *ps)
{
	t_list	*current;
	t_list	*previous;

	previous = (ps->a);
	if (!(previous->next))
		return (2);
	current = previous->next;
	while (previous->next)
	{
		if ((*(int *)(current->content)) <= *(int *)(previous->content))
		{
			ft_printf("KO\n");
			return (1);
		}
		previous = current;
		current = current->next;
	}
	ft_printf("OK\n");
	return (0);
}

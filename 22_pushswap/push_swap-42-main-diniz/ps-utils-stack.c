/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps-utils-stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:39:53 by abessa-m          #+#    #+#             */
/*   Updated: 2025/02/01 11:25:24 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_ps *ps)
{
	t_list	*lst;

	if (ps->verbose)
	{
		ft_printf("\033[1;90m");
		ft_printf("a(%i): ", ft_lstsize(ps->a));
		lst = (ps->a);
		while (lst)
		{
			ft_printf("%i ", *(int *)lst->content);
			lst = lst->next;
		}
		ft_printf("\nb(%i): ", ft_lstsize(ps->b));
		lst = (ps->b);
		while (lst)
		{
			ft_printf("%i ", *(int *)lst->content);
			lst = lst->next;
		}
		ft_printf("\033[0m\n");
	}
}

//Does not accep invalid int
int	is_int(const char *nptr)
{
	long	nbr;
	long	sign;
	size_t	j;

	j = 0;
	sign = 1;
	if (nptr[j] == '+' || nptr[j] == '-')
	{
		if (nptr[j] == '-')
			sign = -1;
		j++;
	}
	nbr = 0;
	while (ft_isdigit(nptr[j]))
	{
		nbr = (10 * nbr) + (nptr[j] - '0');
		j++;
	}
	nbr *= sign;
	if ((nbr > 2147483647) || (nbr < -2147483648) || (nptr[j]) != '\0')
		return (2);
	return (0);
}

void	del(void *content)
{
	if (content)
		free(content);
}

int	stack_len(t_ps *ps, char chr)
{
	t_list	**lst;
	int		len;

	if (chr == 'a')
		lst = &(ps->a);
	if (chr == 'b')
		lst = &(ps->b);
	len = ft_lstsize(*lst);
	return (len);
}

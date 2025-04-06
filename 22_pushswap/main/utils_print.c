/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:31:52 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/06 12:31:54 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_both(t_dnode *a, t_dnode *b, void (*func)(t_dnode *))
{
	ft_printf("A: ");
	func(a);
	ft_printf("B: ");
	func(b);
	ft_printf("\n");
}

void	print_list_foward(t_dnode *head)
{
	ft_printf("Lista (crescente): ");
	while (head)
	{
		ft_printf("%d -> ", head->value);
		if (!head->next)
			break ;
		head = head->next;
	}
	ft_printf("NULL\n");
}

void	print_cost(t_dnode *head)
{
	ft_printf("Lista: CUSTO: ");
	while (head)
	{
		ft_printf("%d -> ", head->push_cost);
		if (!head->next)
			break ;
		head = head->next;
	}
	ft_printf("NULL\n");
}

void	print_target(t_dnode *head)
{
	ft_printf("Lista: ALVO: ");
	while (head)
	{
		ft_printf("%d -> ", head->target_node->value);
		if (!head->next)
			break ;
		head = head->next;
	}
	ft_printf("NULL\n");
}

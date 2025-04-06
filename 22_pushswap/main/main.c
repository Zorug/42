/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross-s <cgross-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:01:58 by cgross-s          #+#    #+#             */
/*   Updated: 2025/04/06 12:03:52 by cgross-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dnode	*head_a;
	t_dnode	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	head_a = get_stack(argc, argv);
	if (!stack_sorted(head_a))
	{
		if (stack_len(head_a) == 2)
			sa(&head_a);
		else if (stack_len(head_a) == 3)
			sort_three(&head_a);
		else
			ft_sort(&head_a, &head_b);
	}
	ft_stackclear(&head_a, ft_free);
	return (0);
}

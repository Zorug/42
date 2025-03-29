/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:24:15 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_lstiter
//	Prototype
//		void ft_lstiter(t_list *lst, void (*f)(void *));
//	Turn in files
//		-
//	Parameters
//		lst: The address of a pointer to a node.
//		f: The address of the function used to iterate on the list.
//	Return value
//		None
//	External functs.
//		None
//	Description
//		Iterates the list ’lst’ and
//	applies the function ’f’ on the content of each node.

#include "../libft.h"
//	t_list

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

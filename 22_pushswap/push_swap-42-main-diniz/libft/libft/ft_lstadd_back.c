/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:04:08 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_lstadd_back
//	Prototype
//		void ft_lstadd_back(t_list **lst, t_list *new);
//	Turn in files
//		-
//	Parameters
//		lst: The address of a pointer to the first link of a list.
//		new: The address of a pointer to the node to be added to the list.
//	Return value
//		None
//	External functs.
//		None
//	Description
//		Adds the node ’new’ at the end of the list.

#include "../libft.h"
//	NULL, t_list

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:50:05 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_lstadd_front
//	Prototype
//		void ft_lstadd_front(t_list **lst, t_list *new);
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
//		Adds the node ’new’ at the beginning of the list.

#include "../libft.h"
//	t_list

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

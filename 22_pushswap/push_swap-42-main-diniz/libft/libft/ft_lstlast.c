/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:20:10 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_lstlast
//	Prototype
//		t_list *ft_lstlast(t_list *lst);
//	Turn in files
//		-
//	Parameters
//		lst: The beginning of the list.
//	Return value
//		Last node of the list
//	External functs.
//		None
//	Description
//		Returns the last node of the list.

#include "../libft.h"
//	t_list

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

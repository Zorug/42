/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:31:40 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_lstdelone
//	Prototyoe
//		void ft_lstdelone(t_list *lst, void (*del)(void *));
//	Turn in files
//		-
//	Parameters
//		lst: The node to free.
//		del: The address of the function used to delete
//		the content.
//	Return value
//		None
//	External functs.
//		free
//	Description
//		Takes as a parameter a node and (a) frees the memory of the node’s
//	content using the function ’del’ given as a parameter and (b) free the
//	node. The memory of’next’ must not be freed.

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst->content)
		del(lst->content);
	free(lst);
}

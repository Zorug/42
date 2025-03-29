/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:56:27 by abessa-m          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:02 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Function name
//		ft_lstclear
//	Prototype
//		void ft_lstclear(t_list **lst, void (*del)(void *));
//	Turn in files
//		-
//	Parameters
//		lst: The address of a pointer to a node.
//		del: The address of the function used to delete the content of the
//	node.
//	Return value
//		None
//	External functs.
//		free
//	Description
//		Deletes and frees the given node and every successor of that node,
//	using the function ’del’ and free(3). Finally, the pointer to the list
//	must be set to NULL.

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		current = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = current;
	}
	*lst = NULL;
}

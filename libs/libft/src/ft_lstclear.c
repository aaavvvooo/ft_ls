/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:28:45 by apiloian          #+#    #+#             */
/*   Updated: 2023/02/02 14:28:52 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*x;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		x = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = x;
	}
	(*lst) = NULL;
}

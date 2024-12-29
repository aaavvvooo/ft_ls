/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:29:34 by amidoyan          #+#    #+#             */
/*   Updated: 2023/02/02 15:34:29 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*new;

	if (!lst || !f || !del)
		return (0);
	list = NULL;
	while (lst)
	{
		new = (ft_lstnew(f(lst -> content)));
		if (!new)
		{
			ft_lstclear(&list, del);
			return (list);
		}
		ft_lstadd_back(&list, new);
		lst = lst -> next;
	}
	return (list);
}

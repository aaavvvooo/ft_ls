/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:34:07 by amidoyan          #+#    #+#             */
/*   Updated: 2023/02/02 12:34:27 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!new)
		return ;
	if (lst)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		list = ft_lstlast(*lst);
		list -> next = new;
	}
}

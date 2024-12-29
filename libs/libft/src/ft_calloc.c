/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:53:22 by amidoyan          #+#    #+#             */
/*   Updated: 2023/01/24 18:26:49 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	max_size;

	max_size = (size_t) - 1;
	if (count == max_size || size == max_size)
	{
		ptr = 0;
		return (ptr);
	}
	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	ft_bzero (ptr, count * size);
	return (ptr);
}

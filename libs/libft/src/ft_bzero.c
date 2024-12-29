/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:47:49 by amidoyan          #+#    #+#             */
/*   Updated: 2023/01/31 13:48:58 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *b, size_t len)
{
	size_t	counter;
	int 	i;
	char	*ptr;

	counter = 0;
	i = 0;
	ptr = (char *)b;
	while (counter < len)
	{
		ptr[counter] = 0;
		counter++;
		++i;
	
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehayes <ehayes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:53:27 by ehayes            #+#    #+#             */
/*   Updated: 2019/11/14 23:53:33 by ehayes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	char	*tmp_dst;
	char	*tmp_src;
	size_t	counter;

	if (!(tmp_dst = (char *)dst) ||
		!(tmp_src = (char *)src) ||
		!(tmp = (char *)malloc(sizeof(tmp) * (int)len)))
		return (NULL);
	counter = 0;
	while (counter < len)
	{
		tmp[counter] = tmp_src[counter];
		counter++;
	}
	counter = 0;
	while (counter < len)
	{
		tmp_dst[counter] = tmp[counter];
		counter++;
	}
	free(tmp);
	return ((void *)dst);
}

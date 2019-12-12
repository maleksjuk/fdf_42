/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehayes <ehayes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:52:19 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/15 00:02:05 by ehayes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	result;

	if (!dst || !src)
		return (0);
	i = 0;
	j = 0;
	result = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (size > 0)
	{
		while (src[j] && i < size - 1)
		{
			dst[i++] = src[j++];
		}
	}
	if (j > 0)
	{
		dst[i] = '\0';
		return (result + i - j);
	}
	return (result + i);
}

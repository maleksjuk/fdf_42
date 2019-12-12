/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehayes <ehayes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:51:01 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/15 00:04:41 by ehayes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		if (!*s2)
			return ((char*)s1);
		while (s1[i] && i < n)
		{
			while (s1[i] != s2[j] && s1[i])
				i++;
			str = (char*)&(s1[i]);
			while (s1[i] == s2[j] && s1[i] && s2[j] && i++ < n)
				j++;
			if (!s2[j])
				return (str);
			else
				j = 0;
		}
	}
	return (NULL);
}

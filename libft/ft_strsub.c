/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:50:31 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 23:50:33 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*str_new;
	unsigned int	counter;

	if (!(str_new = ft_strnew(len)) || !s)
		return (NULL);
	str = (char *)s;
	counter = 0;
	while (counter < len)
	{
		str_new[counter] = str[start];
		start++;
		counter++;
	}
	return (str_new);
}

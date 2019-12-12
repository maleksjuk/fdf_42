/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehayes <ehayes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:52:34 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/15 00:05:01 by ehayes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*str;
	unsigned int	counter;

	str = (char *)s;
	if (str && f)
	{
		counter = 0;
		while (str[counter])
		{
			(*f)(counter, &str[counter]);
			counter++;
		}
	}
}

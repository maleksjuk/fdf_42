/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:19:59 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 19:32:31 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	prev_char(char c, char prev, int color)
{
	if (prev)
	{
		if ((prev == ' ' || prev == '\t') && (!(c == ' ' || c == '\t' ||
			(c >= '0' && c <= '9') || c == '-' || c == '+')))
			return (1);
		if ((prev == '-' || prev == '+') && (!(c >= '0' && c <= '9')))
			return (1);
		if ((!color && (prev >= '0' && prev <= '9')) &&
			(!((c >= '0' && c <= '9') || c == ' ' || c == ',')))
			return (1);
	}
	return (0);
}

int	extra_char(char *line)
{
	char	c;
	char	prev;
	int		flag;
	int		color;

	color = 0;
	prev = 0;
	while (*line)
	{
		flag = 1;
		c = *line;
		if (c == '-' || c == '+' || (c >= '0' && c <= '9') || c == ' ' ||
			(c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || c == ',' ||
			c == '\t' || c == '\n' || c == 'x')
			flag = 0;
		if (c == ',')
			color = 1;
		if (c == ' ' || c == '\t')
			color = 0;
		if (flag || prev_char(c, prev, color))
			return (1);
		line++;
		prev = c;
	}
	return (0);
}

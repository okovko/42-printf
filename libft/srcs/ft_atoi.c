/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:06:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/08 17:12:12 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	char	c;
	int		neg_num;
	int		neg;

	while ((c = *str) && ISSPACE(c))
		str++;
	neg = c == '-';
	str += c == '-' || c == '+';
	neg_num = 0;
	while ((c = *str++) && ISDIGIT(c))
		neg_num = neg_num * 10 - c + '0';
	return (neg ? neg_num : -neg_num);
}

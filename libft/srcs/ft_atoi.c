/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:06:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 12:53:54 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *ss)
{
	char	cc;
	int		neg_num;
	t_bool	neg;

	while ((cc = *ss) && ISSPACE(cc))
		ss++;
	neg = cc == '-';
	ss += cc == '-' || cc == '+';
	neg_num = 0;
	while ((cc = *ss++) && ISDIGIT(cc))
		neg_num = neg_num * 10 - cc + '0';
	return (neg ? neg_num : -neg_num);
}

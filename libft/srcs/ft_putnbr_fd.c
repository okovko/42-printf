/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:30 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:32:55 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putnbr_fd(int val, int fd)
{
	char	ss[22];
	int		sz;
	int		tmp;

	sz = ft_diglen(val);
	val < 0 ? ss[0] = '-' : (void)0;
	val == 0 ? ss[0] = '0' : (void)0;
	ss[sz] = '\0';
	sz--;
	tmp = val;
	while (tmp)
	{
		ss[sz] = '0' + ABS(tmp % 10);
		tmp /= 10;
		sz--;
	}
	ft_putstr_fd(ss, fd);
}

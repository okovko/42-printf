/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 03:43:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 14:29:52 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_printf.h"

static int			count_exps(const char *fmt)
{
	int		ii;
	char	*hit;
	char	*chk;

	ii = 0;
	chk = ft_strchrnul(fmt, '%');
	while ('\0' != *chk)
	{
		if ('%' == *(chk + 1))
		{
			chk = ft_strchrnul(chk + 2, '%');
			continue ;
		}
		ii++;
		hit = chk;
		chk = ft_strchrnul(chk + 1, '%');
	}
	return (ii);
}

int					ft_printf(const char *fmt, ...)
{
	int		ii;
	va_list	ap;
	int		ap_sz;
	int		sz;

	sz = print_text_until_exp((char **)&fmt);
	ap_sz = count_exps(fmt);
	va_start(ap, fmt);
	ii = 0;
	while (ii < ap_sz)
	{
		sz += print_arg((char **)&fmt, ap);
		sz += print_text_until_exp((char **)&fmt);
		ii++;
	}
	va_end(ap);
	return (sz);
}

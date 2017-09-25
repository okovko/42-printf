/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 03:43:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/24 20:02:56 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	specifiers left to implement: S, C, p
	still need to do the va_list stuff in ft_printf.c itself
	rip the wide char stuff from online and also have mike help me understand
	wtf is going on with that
*/

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

	sz = print_text_until_exp((char *)fmt, (char **)&fmt);
	ap_sz = count_exps(fmt);
	va_start(ap, fmt);
	ii = 0;
	while (ii < ap_sz)
	{
		sz += print_arg(fmt, ap);
		sz += print_text_until_exp((char *)fmt, (char **)&fmt);
		ii++;
	}
	va_end(ap);
	return (sz);
}

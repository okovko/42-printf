/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:23:52 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 15:29:49 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

static int	print_str_indirect(t_fmt_exp *exp, ...)
{
	va_list		ap;

	va_start(ap, exp);
	return (print_str(exp, ap));
}

static int	count_wchar(wchar_t wc)
{
	if (wc <= 0x7F)
		return (1);
	else if (wc <= 0x7FF)
		return (2);
	else if (wc <= 0xFFFF)
		return (3);
	else if (wc <= 0x10FFFF)
		return (4);
	return (0);
}

static int	convert_wchar(char *u8, wchar_t wc)
{
	if (wc <= 0x7F)
		u8[0] = wc;
	else if (wc <= 0x7FF)
	{
		u8[0] = 0xC0 | (wc >> 6);
		u8[1] = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0xFFFF)
	{
		u8[0] = 0xE0 | (wc >> 12);
		u8[1] = 0x80 | ((wc >> 6) & 0x3F) + 0x80;
		u8[2] = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0x10FFFF)
	{
		u8[0] = 0xF0 | (wc >> 18);
		u8[1] = 0x80 | ((wc >> 12) & 0x3F);
		u8[2] = 0x80 | ((wc >> 6) & 0x3F);
		u8[3] = 0x80 | (wc & 0x3F);
	}
	return (count_wchar(wc));
}

int		print_wstr(t_fmt_exp *exp, va_list ap)
{
	char		*u8;
	wchar_t		*beg;
	wchar_t		*ws;
	int			sz;
	int			ii;

	ws = va_arg(ap, wchar_t *);
	if (NULL == ws)
		return (print_str_indirect(exp, NULL));
	beg = ws;
	sz = 0;
	while ('\0' != *ws)
		sz += count_wchar(*ws++);
	u8 = ft_walloc(sz + 1);
	u8[sz] = '\0';
	ws = beg;
	ii = 0;
	while ('\0' != *ws)
		ii = convert_wchar(u8 + ii, *ws++);
	return (print_str_indirect(exp, u8));
}

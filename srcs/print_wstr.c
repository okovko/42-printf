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
		sz += wchar_sz(*ws++);
	u8 = ft_walloc(sz + 1);
	u8[sz] = '\0';
	ws = beg;
	ii = 0;
	while ('\0' != *ws)
		ii = convert_wchar(u8 + ii, *ws++);
	return (print_str_indirect(exp, u8));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:30:34 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 14:30:34 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

int			print_wchar(t_fmt_exp *exp, va_list ap)
{
	char		u8[4];
	wchar_t		wc;
	int			sz;

	wc = va_arg(ap, wint_t);
	sz = convert_wchar(u8, wc);
	print_str_indirect(exp, u8);
	return (sz);
}

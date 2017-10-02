/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 06:28:39 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 10:44:50 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

int		print_wchar(t_fmt_exp *exp, va_list ap)
{
	/*
	wchar_t		wc;
	int			sz;

	wc = va_arg(ap, wchar_t);
	sz = wc <= 0x7F;
	sz += wc <= 0x7FF;
	sz += wc <= 0xFFFF;
	sz += wc <= 0x10FFFF;
	*/
	(void)ap;
	(void)exp;
	return (0);
}

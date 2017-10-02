/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ulong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:51:39 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 07:35:18 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_ulong(t_fmt_exp *exp, va_list ap)
{
	unsigned long	ulong;

	ulong = va_arg(ap, unsigned long);
	return (print_unsigned(exp, ulong));
}

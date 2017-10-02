/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_slong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:08:59 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 04:44:12 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_slong(t_fmt_exp *exp, va_list ap)
{
	long	slong;

	slong = va_arg(ap, long);
	return (print_signed(exp, slong));
}

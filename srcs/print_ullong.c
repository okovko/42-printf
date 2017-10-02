/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ullong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 07:32:44 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 07:32:44 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ullong(t_fmt_exp *exp, va_list ap)
{
	unsigned long long	ullong;

	ullong = va_arg(ap, unsigned long long);
	return (print_unsigned(exp, ullong));
}

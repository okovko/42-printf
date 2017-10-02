/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sllong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 07:29:13 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 07:29:13 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_sllong(t_fmt_exp *exp, va_list ap)
{
	long long	sllong;

	sllong = va_arg(ap, long long);
	return (print_signed(exp, sllong));
}

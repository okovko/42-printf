/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:17:44 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/28 21:58:17 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_uint(t_fmt_exp *exp, va_list ap)
{
	unsigned	uint;

	uint = va_arg(ap, unsigned);
	return (print_unsigned(exp, uint));
}

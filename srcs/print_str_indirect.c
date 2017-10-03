/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_indirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:07:16 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 17:07:16 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str_indirect(t_fmt_exp *exp, ...)
{
	va_list		ap;

	va_start(ap, exp);
	return (print_str(exp, ap));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 17:38:04 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/29 02:02:49 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_sint(t_fmt_exp *exp, va_list ap)
{
	int		sint;

	sint = va_arg(ap, int);
	return (print_signed(exp, sint));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 19:46:46 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 01:42:58 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"

static int	print_str_indirect(t_fmt_exp *exp, ...)
{
	va_list		ap;

	va_start(ap, exp);
	return (print_str(exp, ap));
}

int			print_char(t_fmt_exp *exp, va_list ap)
{
	int		cc;
	char	ss[2];

	cc = va_arg(ap, int);
	ss[0] = cc;
	ss[1] = '\0';
	return (print_str_indirect(exp, ss));
}

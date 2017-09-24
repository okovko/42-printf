/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ullong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:52:30 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 22:05:08 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

int			print_ullong(void *arg, t_fmt_exp *exp)
{
	int		base;

	base = 10;
	if (exp->spec == E_FMT_SPEC_OCTAL)
		base = 8;
	else if (exp->spec == E_FMT_SPEC_HEX)
		base = 16;
	return (print_ullong_base(arg, exp, base));
}

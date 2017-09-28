/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:59:45 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/27 18:38:00 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"

static int		convert_str_pad(t_fmt_exp *exp, t_pz ss, char **prnt)
{
	int		sz;
	t_pz	pad;
	t_pz	cpy;
	t_bool	left;

	sz = MAX(ss.sz, (int)exp->width);
	*prnt = ft_walloc(sz);
	if (exp->set & E_FMT_EXP_SET_PREC)
		cpy.sz = MIN(ss.sz, (int)exp->prec);
	else
		cpy.sz = ss.sz;
	pad.sz = sz - cpy.sz;
	left = exp->flags & E_FMT_FLAG_BIT_LEFT_JUSTIFY;
	cpy.p = left ? *prnt : *prnt + pad.sz;
	pad.p = left ? *prnt + cpy.sz : *prnt;
	ft_memcpy(cpy.p, ss.p, cpy.sz);
	ft_memset(pad.p, ' ', pad.sz);
	return (sz);
}

int		print_str(t_fmt_exp *exp, va_list ap)
{
	t_pz	arg;
	int		sz;
	char	*prnt;

	arg.p = va_arg(ap, char *);
	arg.sz = ft_strlen(arg.p);
	sz = convert_str_pad(exp, arg, &prnt);
	write(1, prnt, sz);
	free(prnt);
	return (sz);
}

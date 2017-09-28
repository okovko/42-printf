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

/*
	consider cleanup by using t_pz for ss and prnt
*/
static int		convert_str_pad(t_fmt_exp *exp, char *ss, char **prnt)
{
	int		sz;
	int		ss_sz;
	t_bool	left;
	t_pz	pad;
	t_pz	cpy;

	ss_sz = ft_strlen(ss);
	sz = MAX(ss_sz, (int)exp->width);
	*prnt = ft_walloc(sz);
	if (exp->set & E_FMT_EXP_SET_PREC)
		cpy.sz = MIN(ss_sz, (int)exp->prec);
	else
		cpy.sz = ss_sz;
	pad.sz = sz - cpy.sz;
	left = exp->flags & E_FMT_FLAG_BIT_LEFT_JUSTIFY;
	cpy.p = left ? *prnt : *prnt + pad.sz;
	pad.p = left ? *prnt + cpy.sz : *prnt;
	ft_memcpy(cpy.p, ss, cpy.sz);
	ft_memset(pad.p, ' ', pad.sz);
	return (sz);
}

int		print_str(t_fmt_exp *exp, va_list ap)
{
	char	*prnt;
	int		sz;

	sz = convert_str_pad(exp, va_arg(ap, char *), &prnt);
	write(1, prnt, sz);
	free(prnt);
	return (sz);
}

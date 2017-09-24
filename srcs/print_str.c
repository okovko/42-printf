/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:59:45 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 22:01:20 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"

static int		fmt(t_fmt_exp *exp, char *ss, char **prnt)
{
	int		sz;
	char	*fmt;
	t_bool	left;
	t_pz	pad;
	t_pz	cpy;

	sz = ft_strlen(ss);
	sz = MAX(sz, (int)exp->width);
	fmt = ft_walloc(sz);
	cpy.sz = MIN(sz, (int)exp->prec);
	pad.sz = sz - cpy.sz;
	left = exp->flags & E_FMT_FLAG_BIT_LEFT_JUSTIFY;
	cpy.p = left ? fmt : fmt + pad.sz;
	pad.p = left ? fmt + cpy.sz : fmt;
	ft_memcpy(cpy.p, ss, cpy.sz);
	ft_memset(pad.p, ' ', pad.sz);
	*prnt = fmt;
	return (sz);
}

int		print_str(void *arg, t_fmt_exp *exp)
{
	char	*prnt;
	int		sz;

	sz = fmt(exp, (char *)arg, &prnt);
	write(1, prnt, sz);
	free(prnt);
	return (sz);
}

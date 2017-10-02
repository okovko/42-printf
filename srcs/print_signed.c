/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:09:45 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 02:47:08 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"

static char		signed_sign(t_fmt_exp *exp, long long val)
{
	char	cc;

	cc = '\0';
	if (val < 0)
		cc = '-';
	else if (exp->flags & E_FMT_FLAG_BIT_SPACE_SIGN)
		cc = ' ';
	else if (exp->flags & E_FMT_FLAG_BIT_FORCE_SIGN)
		cc = '+';
	return (cc);
}

static char		*convert_signed_helper(char *ss, int sz, long long val)
{
	sz--;
	while (val)
	{
		ss[sz] = '0' + PMOD(val, 10);
		val /= 10;
		sz--;
	}
	while (sz >= 0)
	{
		ss[sz] = '0';
		sz--;
	}
	return (ss);
}

static int		convert_signed(t_fmt_exp *exp, long long val, char **conv)
{
	char			*ss;
	char			cc;
	int				sz;

	sz = val == 0 && exp->prec == 0 ? 0 : ft_diglen(val);
	sz = MAX(sz, (int)exp->prec);
	if ((cc = signed_sign(exp, val)))
		sz++;
	ss = ft_walloc(sz);
	ss = convert_signed_helper(ss, sz, val);
	if ('\0' != cc)
		ss[0] = cc;
	*conv = ss;
	return (sz);
}

int				print_signed(t_fmt_exp *exp, long long arg)
{
	t_pz		pad;
	t_pz		nbr;
	t_bool		left;

	nbr.sz = convert_signed(exp, arg, (char **)&nbr.p);
	pad.sz = convert_nbr_pad(exp, nbr.sz, (char **)&pad.p);
	left = exp->flags & E_FMT_FLAG_BIT_LEFT_JUSTIFY;
	if (left)
	{
		write(1, nbr.p, nbr.sz);
		write(1, pad.p, pad.sz);
	}
	else
	{
		write(1, pad.p, pad.sz);
		write(1, nbr.p, nbr.sz);
	}
	free(pad.p);
	free(nbr.p);
	return (pad.sz + nbr.sz);
}

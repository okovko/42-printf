/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:09:45 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 10:18:06 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"

static void		set_sign(t_fmt_exp *exp, long long val, char *pad, char *nbr)
{
	char	cc;

	cc = '\0';
	if (val < 0)
		cc = '-';
	else if (exp->flags & E_FMT_FLAG_BIT_SPACE_SIGN)
		cc = ' ';
	else if (exp->flags & E_FMT_FLAG_BIT_FORCE_SIGN)
		cc = '+';
	if (cc)
	{
		if (exp->flags & E_FMT_FLAG_BIT_LEFT_PAD_ZEROES)
			pad[0] = cc;
		else
			nbr[0] = cc;
	}
}

static int		prefix_sz(t_fmt_exp *exp, long long val)
{
	if (val < 0)
		return (1);
	if (exp->flags & E_FMT_FLAG_BIT_SPACE_SIGN)
		return (1);
	if (exp->flags & E_FMT_FLAG_BIT_FORCE_SIGN)
		return (1);
	return (0);
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
	char		*ss;
	int			sz;
	t_bool		no_print_zero;

	no_print_zero = exp->set & E_FMT_SET_PREC
		&& 0 == exp->prec && 0 == val;
	sz = no_print_zero ? 0 : ft_lldiglen(val);
	sz = MAX(sz, (int)exp->prec) + prefix_sz(exp, val);
	ss = ft_walloc(sz);
	ss = convert_signed_helper(ss, sz, val);
	*conv = ss;
	return (sz);
}

int				print_signed(t_fmt_exp *exp, long long val)
{
	t_pz		pad;
	t_pz		nbr;
	t_bool		left;

	nbr.sz = convert_signed(exp, val, (char **)&nbr.p);
	pad.sz = convert_nbr_pad(exp, nbr.sz, (char **)&pad.p);
	set_sign(exp, val, pad.p, nbr.p);
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

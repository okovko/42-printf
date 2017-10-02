/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:17:33 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 06:49:43 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"

static int		unsigned_prefix_sz(t_fmt_exp *exp, unsigned long long val)
{
	t_bool		prefix;
	t_bool		force;
	int			base;

	prefix = exp->flags & E_FMT_FLAG_BIT_HASH_OVERLOADED;
	force = exp->flags & E_FMT_FLAG_BIT_FORCE_NULL_PTR_PREFIX;
	if (!force && (val == 0 || !prefix))
		return (0);
	base = exp->base;
	if (base == 8)
		return (1);
	else if (base == 16)
		return (2);
	return (0);
}

static char		*unsigned_prefix(char *ss, t_fmt_exp *exp,
							   unsigned long long val)
{
	t_bool		prefix;
	t_bool		upper;
	t_bool		force;
	int			base;
	
	prefix = exp->flags & E_FMT_FLAG_BIT_HASH_OVERLOADED;
	force = exp->flags & E_FMT_FLAG_BIT_FORCE_NULL_PTR_PREFIX;
	if (!force && (val == 0 || !prefix))
		return (ss);
	base = exp->base;
	upper = exp->flags & E_FMT_FLAG_BIT_UPPER;
	if (base == 8)
		ss[0] = '0';
	if (base == 16 && upper)
	{
		ss[0] = '0';
		ss[1] = 'X';
	}
	else if (base == 16 && !upper)
	{
		ss[0] = '0';
		ss[1] = 'x';
	}
	return (ss);
}

static char		*convert_unsigned_helper(t_fmt_exp *exp, char *ss, int sz,
										unsigned long long val)
{
	const char	*digs_lower = "0123456789abcdef";
	const char	*digs_upper = "0123456789ABCDEF";
	t_bool		upper;
	int			base;

	base = exp->base;
	upper = exp->flags & E_FMT_FLAG_BIT_UPPER;
	sz--;
	while (val)
	{
		if (upper)
			ss[sz] = digs_upper[val % base];
		else
			ss[sz] = digs_lower[val % base];
		val /= base;
		sz--;
	}
	while (sz >= 0)
	{
		ss[sz] = '0';
		sz--;
	}
	return (ss);
}

static int		convert_unsigned(t_fmt_exp *exp, unsigned long long val,
									char **conv)
{
	char		*ss;
	int			sz;
	t_bool		no_print_zero;

	no_print_zero = exp->set & E_FMT_SET_PREC
		&& 0 == exp->prec && 0 == val;
	sz = no_print_zero ? 0 : ft_lludiglen(val, exp->base);
	sz = MAX(sz, (int)exp->prec) + unsigned_prefix_sz(exp, val);
	ss = ft_walloc(sz);
	ss = convert_unsigned_helper(exp, ss, sz, val);
	ss = unsigned_prefix(ss, exp, val);
	*conv = ss;
	return (sz);
}

int			print_unsigned(t_fmt_exp *exp, unsigned long long arg)
{
	t_pz		pad;
	t_pz		nbr;
	t_bool		left;

	nbr.sz = convert_unsigned(exp, arg, (char **)&nbr.p);
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

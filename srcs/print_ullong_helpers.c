/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ullong_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:17:33 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/25 05:51:29 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"

static int		ullong_prefix_sz(t_fmt_exp *exp, unsigned long long val)
{
	if (val > 0 && exp->flags & E_FMT_FLAG_BIT_HASH_OVERLOADED)
	{
		if (exp->spec == E_FMT_SPEC_OCTAL)
			return (1);
		else if (exp->spec == E_FMT_SPEC_HEX || exp->spec == E_FMT_SPEC_HEX_UPPER)
			return (2);
	}
	return (0);
}

static char		*ullong_prefix(char *ss, t_fmt_exp *exp,
							   unsigned long long val)
{
	if (val == 0)
		return (ss);
	if (exp->flags & E_FMT_FLAG_BIT_HASH_OVERLOADED)
	{
		if (exp->spec == E_FMT_SPEC_OCTAL)
		{
			ss[0] = '0';
		}
		else if (exp->spec == E_FMT_SPEC_HEX)
		{
			ss[0] = '0';
			ss[1] = 'x';
		}
		else if (exp->spec == E_FMT_SPEC_HEX_UPPER)
		{
			ss[0] = '0';
			ss[1] = 'X';
		}
	}
	return (ss);
}

static char		*convert_ullong_base_helper(t_pz in, unsigned long long val,
											int base, t_bool upper)
{
	const char	*digs_lower = "0123456789abcdef";
	const char	*digs_upper = "0123456789ABCDEF";
	char		*ss;
	int			sz;

	ss = in.p;
	sz = in.sz;
	while (val)
	{
		if (upper)
			ss[sz] = digs_upper[val % base];
		else
			ss[sz] = digs_lower[val % base];
		val /= base;
		sz--;
	}
	while (sz-- && '\0' == ss[sz])
		ss[sz] = '0';
	return (ss);
}

static int		convert_ullong_base(t_fmt_exp *exp, unsigned long long val,
									int base, char **conv)
{
	char			*ss;
	int				sz;
	t_bool			upper;
	t_pz			ss_and_sz;

	if (val == 0 && exp->prec == 0)
	{
		*conv = ft_strdup("");
		return (0);
	}
	upper = exp->spec == E_FMT_SPEC_HEX_UPPER;
	sz = ft_udiglen(val);
	sz = MAX(sz, (int)exp->prec) + ullong_prefix_sz(exp, val);
	ss = ft_walloc(sz);
	ss_and_sz = (t_pz){.p = ss, .sz = sz};
	ss = convert_ullong_base_helper(ss_and_sz, val, base, upper);
	ss = ullong_prefix(ss, exp, val);
	*conv = ss;
	return (sz);
}

int			print_ullong_base(t_fmt_exp *exp, int base, va_list ap)
{
	t_pz				pad;
	t_pz				nbr;
	unsigned long long	arg;

	arg = va_arg(ap, unsigned long long);
	nbr.sz = convert_ullong_base(exp, arg, base, (char **)&nbr.p);
	pad.sz = convert_nbr_pad(exp, nbr.sz, (char **)&pad.p);
	if (exp->flags & E_FMT_FLAG_BIT_LEFT_JUSTIFY)
	{
		write(1, nbr.p, nbr.sz);
		write(1, pad.p, pad.sz);
	}
	else
	{
		write(1, pad.p, pad.sz);
		write(1, nbr.p, nbr.sz);
	}
	return (pad.sz + nbr.sz);
}

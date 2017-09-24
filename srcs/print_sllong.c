/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sllong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:09:45 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 22:03:55 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"

static char		sllong_sign(t_fmt_exp *exp, long long val)
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

static char		*convert_sllong_helper(char *ss, int sz, long long val)
{
	unsigned	uval;

	if (val >= 0)
	{
		uval = (unsigned)val;
		while (uval)
		{
			ss[sz] = '0' + uval % 10;
			uval /= 10;
			sz--;
		}
	}
	else
	{
		while (val)
		{
			ss[sz] = '0' + ABS(val % 10);
			val /= 10;
			sz--;
		}
	}
	while (sz--)
		ss[sz] = '0';
	return (ss);
}

static int		convert_sllong(t_fmt_exp *exp, long long val, char **conv)
{
	char			*ss;
	char			cc;
	int				sz;

	if (val == 0 && exp->prec == 0)
	{
		*conv = ft_strdup("");
		return (0);
	}
	sz = ft_diglen(val);
	sz = MAX(sz, (int)exp->prec);
	if ((cc = sllong_sign(exp, val)))
		sz++;
	ss = ft_walloc(sz);
	ss = convert_sllong_helper(ss, sz, val);
	ss[0] = cc;
	*conv = ss;
	return (sz);
}

int			convert_nbr_pad(t_fmt_exp *exp, int sz, char **conv)
{
	char	cc;
	t_pz	pad;
	t_bool	left;

	if (!((int)exp->width > sz))
	{
		*conv = ft_strdup("");
		return (0);
	}
	left = exp->flags & E_FMT_FLAG_BIT_LEFT_JUSTIFY;
	cc = ' ';
	if (!left && exp->flags & E_FMT_FLAG_BIT_LEFT_PAD_ZEROES)
		cc = '0';
	pad.sz = exp->width - sz;
	pad.p = ft_walloc(sz);
	ft_memset(pad.p, cc, pad.sz);
	*conv = pad.p;
	return (sz);
}

int				print_sllong(void *arg, t_fmt_exp *exp)
{
	t_pz	pad;
	t_pz	nbr;

	nbr.sz = convert_sllong(exp, *(long long *)arg, (char **)&nbr.p);
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

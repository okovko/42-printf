/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_nbr_pad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 07:25:37 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 07:25:37 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

int			convert_nbr_pad(t_fmt_exp *exp, int sz, char **conv)
{
	char	cc;
	t_pz	pad;
	t_bool	left;
	t_bool	prec;
	t_bool	zeroes;

	left = exp->flags & E_FMT_FLAG_BIT_LEFT_JUSTIFY;
	prec = exp->set & E_FMT_SET_PREC;
	zeroes = exp->flags & E_FMT_FLAG_BIT_LEFT_PAD_ZEROES;
	cc = ' ';
	if (!left && !prec && zeroes)
		cc = '0';
	pad.sz = (int)exp->width > sz ? exp->width - sz : 0;
	pad.p = ft_walloc(pad.sz);
	ft_memset(pad.p, cc, pad.sz);
	*conv = pad.p;
	return (pad.sz);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_sym.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:22:10 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 21:22:10 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_parse_fp	g_parse_subspec_fp[] =
{
	parse_fmt_pass,
	parse_fmt_flags,
	parse_fmt_width,
	parse_fmt_prec,
	parse_fmt_len,
	parse_fmt_spec,
};

t_fmt_sym			parse_fmt_sym(t_fmt_exp *exp, t_fmt_sym sym,
									char *loc, char **edg)
{
	int			ii;

	ii = sym + 1;
	while (ii < sizeof(g_parse_subspec_fp))
	{
		if (E_FMT_SYM_NONE != g_parse_subspec_fp[ii](exp, loc, edg))
			return (ii);
		ii++;
	}
	return (E_FMT_SYM_NONE);
}

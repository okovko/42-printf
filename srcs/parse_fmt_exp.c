/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:22:56 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/24 15:52:15 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_exp			*parse_fmt_exp(char *loc)
{
	t_fmt_sym		sym;
	t_fmt_exp		*exp;

	exp = ft_walloc(sizeof(exp));
	*exp = (const t_fmt_exp){.flags = 0};
	sym = E_FMT_SYM_NONE;
	while ('\0' != *loc && E_FMT_SYM_SPEC != sym)
		sym = parse_fmt_sym(exp, sym, loc, &loc);
	return (exp);
}

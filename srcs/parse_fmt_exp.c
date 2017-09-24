/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:22:56 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 21:22:56 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_exp			*parse_fmt_exp(void *arg, char *loc, char **edg)
{
	t_fmt_sym		sym;
	t_fmt_exp		*exp;

	exp = ft_walloc(sizeof(exp));
	*exp = (const t_fmt_exp){0};
	sym = E_FMT_SYM_NONE;
	while ('\0' != *loc && E_FMT_SYM_SPEC != sym)
		sym = parse_fmt_sym(sym, loc, edg);
	return (exp);
}

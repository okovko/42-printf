/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:22:56 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/29 01:32:59 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_exp			*parse_fmt_exp(char **fmt)
{
	t_fmt_sym		sym;
	t_fmt_exp		*exp;

	(*fmt)++;
	exp = ft_walloc(sizeof(*exp));
	*exp = (const t_fmt_exp){.flags = 0};
	sym = E_FMT_SYM_NONE;
	while ('\0' != **fmt)
	{
		sym = parse_fmt_sym(exp, fmt, sym);
		if (E_FMT_SYM_SPEC == sym || E_FMT_SYM_END == sym)
			break ;
	}
	return (exp);
}

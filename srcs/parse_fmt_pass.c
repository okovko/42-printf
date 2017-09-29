/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_pass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:19:22 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/29 01:31:48 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_sym		parse_fmt_pass(t_fmt_exp *exp, char **fmt, va_list ap)
{
	(void)ap;
	(void)exp;
	(*fmt)++;
	return (E_FMT_SYM_NONE);
}

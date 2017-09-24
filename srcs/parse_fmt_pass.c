/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_pass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:19:22 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 21:54:25 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_sym		parse_fmt_pass(t_fmt_exp *exp,
								char *loc, char **edg)
{
	(void)exp;
	loc++;
	*edg = loc;
	return (E_FMT_SYM_NONE);
}

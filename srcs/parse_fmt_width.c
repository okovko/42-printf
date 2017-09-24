/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:20:48 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 21:20:48 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_map_kv		g_width_kvs[] = (t_map_kv[])
{
	{(void *)"*", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_BEFORE}},
};
static t_map		g_width_map =
{
	.sz = sizeof(g_width_kvs),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_width),
	.kvs = g_width_kvs,
};

t_fmt_sym			parse_fmt_width(t_fmt_exp *exp,
									char *loc, char **edg)
{
	t_map_kv		*kv;

	exp->width = ft_strtoi_nol(loc, edg);
	if (loc != *edg)
	{
		exp->set |= E_FMT_SET_WIDTH;
		return (E_FMT_SYM_WIDTH);
	}
	if (NULL != (kv = parse_fmt_tok(g_width_map, loc, edg)))
	{
		exp->set |= E_FMT_SET_WIDTH_SET;
		exp->width = *(t_fmt_width *)kv->val;
		return (E_FMT_SYM_WIDTH);
	}
	return (E_FMT_SYM_NONE);
}
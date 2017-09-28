/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:20:48 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/27 18:43:52 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_map_kv		g_width_kvs[] = (t_map_kv[])
{
	{(void *)"*", (void *)(t_fmt_width[]){E_FMT_WIDTH_BEFORE}},
};
static t_map		g_width_map =
{
	.sz = sizeof(g_width_kvs) / sizeof(g_width_kvs[0]),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_width),
	.kvs = g_width_kvs,
};

t_fmt_sym			parse_fmt_width(t_fmt_exp *exp, char **fmt)
{
	t_map_kv		*kv;
	char			*edg;

	edg = *fmt;
	if (NULL != (kv = parse_fmt_tok(&g_width_map, *fmt, &edg)))
	{
		*fmt = edg;
		exp->set |= E_FMT_EXP_SET_WIDTH;
		exp->width = *(t_fmt_width *)kv->val;
		return (E_FMT_SYM_WIDTH);
	}
	exp->width = ft_strtoi_nol(*fmt, &edg);
	if (*fmt != edg)
	{
		*fmt = edg;
		exp->set |= E_FMT_EXP_SET_WIDTH;
		return (E_FMT_SYM_WIDTH);
	}
	return (E_FMT_SYM_NONE);
}

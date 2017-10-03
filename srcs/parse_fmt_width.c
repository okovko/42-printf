/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:20:48 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 17:27:39 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_map_kv		g_width_kvs[] = (t_map_kv[])
{
	{(void *)"*", (void *)(int[]){E_FMT_WIDTH_BEFORE}},
};
static t_map		g_width_map =
{
	.sz = sizeof(g_width_kvs) / sizeof(g_width_kvs[0]),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(int),
	.kvs = g_width_kvs,
};

t_fmt_sym			parse_fmt_width(t_fmt_exp *exp, char **fmt, va_list ap)
{
	t_map_kv		*kv;
	char			*edg;

	edg = *fmt;
	if (NULL != (kv = parse_fmt_tok(&g_width_map, *fmt, &edg)))
	{
		*fmt = edg;
		exp->set |= E_FMT_SET_WIDTH;
		exp->width = *(int *)kv->val;
		if (E_FMT_WIDTH_BEFORE == exp->width)
			exp->width = va_arg(ap, long long);
		return (E_FMT_SYM_WIDTH);
	}
	exp->width = ft_strtoi_nol(*fmt, &edg);
	if (*fmt != edg)
	{
		*fmt = edg;
		exp->set |= E_FMT_SET_WIDTH;
		return (E_FMT_SYM_WIDTH);
	}
	return (E_FMT_SYM_NONE);
}

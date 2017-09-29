/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:21:05 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/29 02:37:44 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_map_kv		g_prec_kvs[] = (t_map_kv[])
{
	{(void *)".*", (void *)(t_fmt_prec[]){E_FMT_PREC_BEFORE}},
	{(void *)".", (void *)(t_fmt_prec[]){E_FMT_PREC_NONE}},
};
static t_map		g_prec_map =
{
	.sz = sizeof(g_prec_kvs) / sizeof(g_prec_kvs[0]),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_prec),
	.kvs = g_prec_kvs,
};

t_fmt_sym			parse_fmt_prec(t_fmt_exp *exp, char **fmt, va_list ap)
{
	t_map_kv		*kv;
	char			*edg;

	edg = *fmt;
	if (NULL != (kv = parse_fmt_tok(&g_prec_map, *fmt, &edg)))
	{
		*fmt = edg;
		exp->set |= E_FMT_SET_PREC;
		exp->prec = *(t_fmt_prec *)kv->val;
		if (E_FMT_PREC_BEFORE == exp->prec)
			exp->prec = va_arg(ap, long long);
		if (E_FMT_PREC_NONE != exp->prec)
			return (E_FMT_SYM_PREC);
	}
	exp->prec = ft_strtoi_nol(*fmt, &edg);
	if (*fmt != edg)
	{
		*fmt = edg;
		exp->set |= E_FMT_SET_PREC;
		return (E_FMT_SYM_PREC);
	}
	return (E_FMT_SYM_NONE);
}

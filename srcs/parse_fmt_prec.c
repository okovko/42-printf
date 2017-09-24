/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:21:05 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 21:21:05 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_map_kv		g_prec_kvs[] = (t_map_kv[])
{
	{(void *)".*", (void *)(t_fmt_prec[]){E_FMT_TOK_PREC_BEFORE}},
	{(void *)".", (void *)(t_fmt_prec[]){E_FMT_TOK_PREC_NUM}},
};
static t_map		g_prec_map =
{
	.sz = sizeof(g_prec_kvs),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_prec),
	.kvs = g_prec_kvs,
};

t_fmt_sym			parse_fmt_prec(t_fmt_exp *exp,
									char *loc, char **edg)
{
	t_map_kv		*kv;

	exp->prec = ft_strtoi_nol(loc, edg);
	if (loc != *edg)
	{
		exp->set |= E_FMT_SET_PREC;
		return (E_FMT_SYM_PREC);
	}
	if (NULL != (kv = parse_fmt_tok(g_prec_map, loc, edg)))
	{
		exp->set |= E_FMT_SET_PREC_SET;
		exp->prec = *(t_fmt_width *)kv->val;
		return (E_FMT_SYM_WIDTH);
	}
	return (E_FMT_SYM_NONE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:20:11 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/27 21:12:56 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_map_kv		g_flag_kvs[] = (t_map_kv[])
{
	{(void *)"-", (void *)(t_fmt_flag_bit[]){E_FMT_FLAG_BIT_LEFT_JUSTIFY}},
	{(void *)"+", (void *)(t_fmt_flag_bit[]){E_FMT_FLAG_BIT_FORCE_SIGN}},
	{(void *)" ", (void *)(t_fmt_flag_bit[]){E_FMT_FLAG_BIT_SPACE_SIGN}},
	{(void *)"#", (void *)(t_fmt_flag_bit[]){E_FMT_FLAG_BIT_HASH_OVERLOADED}},
	{(void *)"0", (void *)(t_fmt_flag_bit[]){E_FMT_FLAG_BIT_LEFT_PAD_ZEROES}},
};
static t_map		g_flag_map =
{
	.sz = sizeof(g_flag_kvs) / sizeof(g_flag_kvs[0]),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_flag_bit),
	.kvs = g_flag_kvs,
};

t_fmt_sym			parse_fmt_flags(t_fmt_exp *exp, char **fmt)
{
	t_map_kv		*kv;
	char			**edg;

	edg = fmt;
	if (NULL != (kv = parse_fmt_tok(&g_flag_map, *fmt, edg)))
		exp->set |= E_FMT_EXP_SET_FLAGS;
	while (NULL != kv)
	{
		*fmt = *edg;
		exp->flags |= *(t_fmt_flag_bit *)kv->val;
		kv = parse_fmt_tok(&g_flag_map, *fmt, edg);
	}
	return (exp->flags == 0 ? E_FMT_SYM_NONE : E_FMT_SYM_FLAG);
}

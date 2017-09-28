/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:21:50 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/27 21:19:01 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_map_kv		g_spec_kvs[] = (t_map_kv[])
{
	{(void *)"d", (void *)(t_fmt_spec[]){E_FMT_SPEC_INT}},
	{(void *)"D", (void *)(t_fmt_spec[]){E_FMT_SPEC_INT}},
	{(void *)"i", (void *)(t_fmt_spec[]){E_FMT_SPEC_INT}},
	{(void *)"I", (void *)(t_fmt_spec[]){E_FMT_SPEC_INT}},
	{(void *)"u", (void *)(t_fmt_spec[]){E_FMT_SPEC_UINT}},
	{(void *)"U", (void *)(t_fmt_spec[]){E_FMT_SPEC_UINT}},
	{(void *)"o", (void *)(t_fmt_spec[]){E_FMT_SPEC_OCTAL}},
	{(void *)"O", (void *)(t_fmt_spec[]){E_FMT_SPEC_OCTAL}},
	{(void *)"x", (void *)(t_fmt_spec[]){E_FMT_SPEC_HEX}},
	{(void *)"X", (void *)(t_fmt_spec[]){E_FMT_SPEC_HEX_UPPER}},
	{(void *)"f", (void *)(t_fmt_spec[]){E_FMT_SPEC_FLOAT}},
	{(void *)"F", (void *)(t_fmt_spec[]){E_FMT_SPEC_FLOAT_UPPER}},
	{(void *)"e", (void *)(t_fmt_spec[]){E_FMT_SPEC_EXP}},
	{(void *)"E", (void *)(t_fmt_spec[]){E_FMT_SPEC_EXP_UPPER}},
	{(void *)"g", (void *)(t_fmt_spec[]){E_FMT_SPEC_FLOAT_OR_EXP}},
	{(void *)"G", (void *)(t_fmt_spec[]){E_FMT_SPEC_FLOAT_OR_EXP_UPPER}},
	{(void *)"a", (void *)(t_fmt_spec[]){E_FMT_SPEC_HEX_FLOAT}},
	{(void *)"A", (void *)(t_fmt_spec[]){E_FMT_SPEC_HEX_FLOAT_UPPER}},
	{(void *)"c", (void *)(t_fmt_spec[]){E_FMT_SPEC_CHAR}},
	{(void *)"C", (void *)(t_fmt_spec[]){E_FMT_SPEC_CHAR}},
	{(void *)"s", (void *)(t_fmt_spec[]){E_FMT_SPEC_STR}},
	{(void *)"S", (void *)(t_fmt_spec[]){E_FMT_SPEC_STR}},
	{(void *)"p", (void *)(t_fmt_spec[]){E_FMT_SPEC_PTR}},
	{(void *)"n", (void *)(t_fmt_spec[]){E_FMT_SPEC_N_PTR}},
	{(void *)"%", (void *)(t_fmt_spec[]){E_FMT_SPEC_PERCENT}},
};
static t_map		g_spec_map =
{
	.sz = sizeof(g_spec_kvs) / sizeof(g_spec_kvs[0]),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_spec),
	.kvs = g_spec_kvs,
};

t_fmt_sym			parse_fmt_spec(t_fmt_exp *exp, char **fmt)
{
	t_map_kv	*kv;
	char		**edg;

	edg = fmt;
	if (NULL != (kv = parse_fmt_tok(&g_spec_map, *fmt, edg)))
	{
		*fmt = *edg;
		exp->set |= E_FMT_EXP_SET_SPEC;
		exp->spec = *(t_fmt_spec *)kv->val;
	}
	return (NULL == kv ? E_FMT_SYM_NONE : E_FMT_SYM_SPEC);
}

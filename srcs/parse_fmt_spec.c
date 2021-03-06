/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:21:50 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 17:19:47 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_map_kv		g_spec_kvs[] = (t_map_kv[])
{
	{(void *)"d", (void *)(int[]){E_FMT_SPEC_INT}},
	{(void *)"D", (void *)(int[]){E_FMT_SPEC_INT}},
	{(void *)"i", (void *)(int[]){E_FMT_SPEC_INT}},
	{(void *)"u", (void *)(int[]){E_FMT_SPEC_UINT}},
	{(void *)"U", (void *)(int[]){E_FMT_SPEC_UINT}},
	{(void *)"o", (void *)(int[]){E_FMT_SPEC_UINT}},
	{(void *)"O", (void *)(int[]){E_FMT_SPEC_UINT}},
	{(void *)"x", (void *)(int[]){E_FMT_SPEC_UINT}},
	{(void *)"X", (void *)(int[]){E_FMT_SPEC_UINT}},
	{(void *)"p", (void *)(int[]){E_FMT_SPEC_UINT}},
	{(void *)"f", (void *)(int[]){E_FMT_SPEC_FLOAT}},
	{(void *)"F", (void *)(int[]){E_FMT_SPEC_FLOAT_UPPER}},
	{(void *)"e", (void *)(int[]){E_FMT_SPEC_EXP}},
	{(void *)"E", (void *)(int[]){E_FMT_SPEC_EXP_UPPER}},
	{(void *)"g", (void *)(int[]){E_FMT_SPEC_FLOAT_OR_EXP}},
	{(void *)"G", (void *)(int[]){E_FMT_SPEC_FLOAT_OR_EXP_UPPER}},
	{(void *)"a", (void *)(int[]){E_FMT_SPEC_HEX_FLOAT}},
	{(void *)"A", (void *)(int[]){E_FMT_SPEC_HEX_FLOAT_UPPER}},
	{(void *)"c", (void *)(int[]){E_FMT_SPEC_CHAR}},
	{(void *)"C", (void *)(int[]){E_FMT_SPEC_CHAR}},
	{(void *)"s", (void *)(int[]){E_FMT_SPEC_STR}},
	{(void *)"S", (void *)(int[]){E_FMT_SPEC_STR}},
	{(void *)"n", (void *)(int[]){E_FMT_SPEC_N_PTR}},
	{(void *)"%", (void *)(int[]){E_FMT_SPEC_PERCENT}},
};
static t_map		g_spec_map =
{
	.sz = sizeof(g_spec_kvs) / sizeof(g_spec_kvs[0]),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_spec),
	.kvs = g_spec_kvs,
};
static t_map_kv		g_base_kvs[] = (t_map_kv[])
{
	{(void *)"u", (void *)(int[]){10}},
	{(void *)"U", (void *)(int[]){10}},
	{(void *)"o", (void *)(int[]){8}},
	{(void *)"O", (void *)(int[]){8}},
	{(void *)"x", (void *)(int[]){16}},
	{(void *)"X", (void *)(int[]){16}},
	{(void *)"p", (void *)(int[]){16}},
};
static t_map		g_base_map =
{
	.sz = sizeof(g_base_kvs) / sizeof(g_base_kvs[0]),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(int),
	.kvs = g_base_kvs,
};

static int			parse_base(t_map_kv *kv)
{
	t_map_kv	*base_kv;

	if (NULL != (base_kv = ft_mapget(&g_base_map, (void *)kv->key, ft_strcmp)))
		return (*(int *)base_kv->val);
	return (0);
}

static void			parse_overrides(t_fmt_exp *exp, t_map_kv *kv, va_list ap)
{
	char		cc;
	void		*ptr;
	va_list		local_ap;

	cc = *(char *)kv->key;
	if (ft_isupper(cc))
		exp->flags |= E_FMT_FLAG_BIT_UPPER;
	if ('p' == cc)
	{
		exp->len = E_FMT_LEN_LLONG;
		exp->flags |= E_FMT_FLAG_BIT_HASH_OVERLOADED;
		va_copy(local_ap, ap);
		ptr = va_arg(local_ap, void *);
		if (NULL == ptr)
			exp->flags |= E_FMT_FLAG_BIT_FORCE_NULL_PTR_PREFIX;
		va_end(local_ap);
	}
	if ('D' == cc)
		exp->len = E_FMT_LEN_LONG;
}

t_fmt_sym			parse_fmt_spec(t_fmt_exp *exp, char **fmt, va_list ap)
{
	t_map_kv	*kv;
	char		*edg;

	(void)ap;
	edg = *fmt;
	if (NULL != (kv = parse_fmt_tok(&g_spec_map, *fmt, &edg)))
	{
		*fmt = edg;
		exp->set |= E_FMT_SET_SPEC;
		exp->spec = *(t_fmt_spec *)kv->val;
		exp->base = parse_base(kv);
		if (exp->base > 0)
			exp->set |= E_FMT_SET_BASE;
		parse_overrides(exp, kv, ap);
	}
	return (NULL == kv ? E_FMT_SYM_END : E_FMT_SYM_SPEC);
}

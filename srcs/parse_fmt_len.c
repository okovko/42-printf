/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:21:22 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 21:21:22 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_map_kv		g_len_kvs[] = (t_map_kv[])
{
	{(void *)"hh", (void *)(t_fmt_len[]){E_FMT_TOK_LEN_CHAR}},
	{(void *)"h", (void *)(t_fmt_len[]){E_FMT_TOK_LEN_SHRT}},
	{(void *)"ll", (void *)(t_fmt_len[]){E_FMT_TOK_LEN_LLONG}},
	{(void *)"l", (void *)(t_fmt_len[]){E_FMT_TOK_LEN_LONG}},
	{(void *)"j", (void *)(t_fmt_len[]){E_FMT_TOK_LEN_INT_MAX}},
	{(void *)"z", (void *)(t_fmt_len[]){E_FMT_TOK_LEN_SIZE}},
	{(void *)"t", (void *)(t_fmt_len[]){E_FMT_TOK_LEN_PTRDIFF}},
	{(void *)"L", (void *)(t_fmt_len[]){E_FMT_TOK_LEN_LONG_DOUBLE}},
};
static t_map		g_len_map =
{
	.sz = sizeof(g_len_kvs),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_len),
	.kvs = g_len_kvs,
};

t_fmt_exp			*parse_fmt_len(t_fmt_exp *exp,
									char *loc, char **edg)
{
	t_map_kv		*kv;

	if (NULL != (kv = parse_fmt_tok(g_len_map, loc, edg)))
	{
		exp->set |= E_FMT_SET_LEN;
		exp->len = *(t_fmt_len *)kv->val;
	}
	return (NULL == kv ? E_FMT_SYM_NONE : E_FMT_SYM_LEN);
}

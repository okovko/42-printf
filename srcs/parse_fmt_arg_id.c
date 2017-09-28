/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_arg_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:22:40 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/28 02:12:07 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static t_fmt_exp		g_exp_sint =
{
	.spec = E_FMT_SPEC_INT,
	.len = E_FMT_LEN_NONE,
};
static t_fmt_exp		g_exp_schar =
{
	.spec = E_FMT_SPEC_INT,
	.len = E_FMT_LEN_CHAR,
};
static t_fmt_exp		g_exp_sshrt =
{
	.spec = E_FMT_SPEC_INT,
	.len = E_FMT_LEN_SHRT,
};
static t_fmt_exp		g_exp_slong =
{
	.spec = E_FMT_SPEC_INT,
	.len = E_FMT_LEN_LONG,
};
static t_fmt_exp		g_exp_sllong =
{
	.spec = E_FMT_SPEC_INT,
	.len = E_FMT_LEN_LLONG
};
static t_fmt_exp		g_exp_intmax =
{
	.spec = E_FMT_SPEC_INT,
	.len = E_FMT_LEN_INTMAX
};
static t_fmt_exp		g_exp_size =
{
	.spec = E_FMT_SPEC_INT,
	.len = E_FMT_LEN_SIZE
};
static t_fmt_exp		g_exp_usize =
{
	.spec = E_FMT_SPEC_UINT,
	.len = E_FMT_LEN_SIZE
};
static t_fmt_exp		g_exp_ptrdiff =
{
	.spec = E_FMT_SPEC_INT,
	.len = E_FMT_LEN_PTRDIFF
};
static t_fmt_exp		g_exp_uint =
{
	.spec = E_FMT_SPEC_UINT,
	.len = E_FMT_LEN_NONE
};
static t_fmt_exp		g_exp_uchar =
{
	.spec = E_FMT_SPEC_UINT,
	.len = E_FMT_LEN_CHAR
};
static t_fmt_exp		g_exp_ushrt =
{
	.spec = E_FMT_SPEC_UINT,
	.len = E_FMT_LEN_SHRT
};
static t_fmt_exp		g_exp_ulong =
{
	.spec = E_FMT_SPEC_UINT,
	.len = E_FMT_LEN_LONG
};
static t_fmt_exp		g_exp_ullong =
{
	.spec = E_FMT_SPEC_UINT,
	.len = E_FMT_LEN_LLONG
};
static t_fmt_exp		g_exp_uintmax =
{
	.spec = E_FMT_SPEC_UINT,
	.len = E_FMT_LEN_INTMAX
};
static t_fmt_exp		g_exp_uptrdiff =
{
	.spec = E_FMT_SPEC_UINT,
	.len = E_FMT_LEN_PTRDIFF
};
static t_fmt_exp		g_exp_char =
{
	.spec = E_FMT_SPEC_CHAR,
	.len = E_FMT_LEN_NONE
};
static t_fmt_exp		g_exp_wint =
{
	.spec = E_FMT_SPEC_CHAR,
	.len = E_FMT_LEN_LONG
};
static t_fmt_exp		g_exp_str =
{
	.spec = E_FMT_SPEC_STR,
	.len = E_FMT_LEN_NONE
};
static t_fmt_exp		g_exp_wstr =
{
	.spec = E_FMT_SPEC_STR,
	.len = E_FMT_LEN_LONG
};
static t_fmt_exp		g_exp_ptr =
{
	.spec = E_FMT_SPEC_PTR,
	.len = E_FMT_LEN_NONE
};
static t_map_kv			g_arg_kvs[] = 
{
	{(void *)&g_exp_sint, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_SINT}},
	{(void *)&g_exp_schar, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_SCHAR}},
	{(void *)&g_exp_sshrt, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_SSHRT}},
	{(void *)&g_exp_slong, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_SLONG}},
	{(void *)&g_exp_sllong, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_SLLONG}},
	{(void *)&g_exp_intmax, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_INTMAX}},
	{(void *)&g_exp_size, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_SIZE}},
	{(void *)&g_exp_ptrdiff, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_PTRDIFF}},
	{(void *)&g_exp_uint, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_UINT}},
	{(void *)&g_exp_uchar, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_UCHAR}},
	{(void *)&g_exp_ushrt, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_USHRT}},
	{(void *)&g_exp_ulong, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_ULONG}},
	{(void *)&g_exp_ullong, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_ULLONG}},
	{(void *)&g_exp_uintmax, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_UINTMAX}},
	{(void *)&g_exp_usize, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_SIZE}},
	{(void *)&g_exp_uptrdiff, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_PTRDIFF}},
	{(void *)&g_exp_char, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_CHAR}},
	{(void *)&g_exp_wint, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_WINT}},
	{(void *)&g_exp_str, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_STR}},
	{(void *)&g_exp_wstr, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_WSTR}},
	{(void *)&g_exp_ptr, (void *)(t_fmt_arg_id[]){E_FMT_ARG_ID_PTR}},
};
static t_map			g_arg_map =
{
	.sz = sizeof(g_arg_kvs) / sizeof(g_arg_kvs[0]),
	.key_sz = sizeof(t_fmt_exp),
	.val_sz = sizeof(t_fmt_arg_id),
	.kvs = g_arg_kvs,
};

static int			map_keycmp_exp_spec_len(void *key, void *itr, int sz)
{
	t_fmt_exp		*key_exp;
	t_fmt_exp		*key_itr;
	
	(void)sz;
	key_exp = key;
	key_itr = itr;
	if (key_exp->spec == key_itr->spec && key_exp->len == key_itr->len)
		return (0);
	return (-1);
}

t_fmt_arg_id		parse_fmt_arg_id(t_fmt_exp *exp)
{
	t_map_kv		*kv;
	t_fmt_arg_id	id;

	kv = ft_mapget(&g_arg_map, (void *)exp, map_keycmp_exp_spec_len);
	id = *(t_fmt_arg_id *)kv->val;
	return (id);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 03:43:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/21 00:22:38 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	okay i'm happy with how everything is interfaced finally
	now i just need to write the functions that print these types
	also need to figure out how to use va_list properly
	and also store exp function
*/

#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"

static char			g_buf[4096] = 0;
static int			g_iter = 0;
static t_map_kv		g_flag_kvs[] = (t_map_kv[])
{
	{(void *)"-", (void *)(t_fmt_flag[]){E_FMT_TOK_FLAG_LEFT_JUSTIFY}},
	{(void *)"+", (void *)(t_fmt_flag[]){E_FMT_TOK_FLAG_FORCE_SIGN}},
	{(void *)" ", (void *)(t_fmt_flag[]){E_FMT_TOK_FLAG_SPACE_SIGN}},
	{(void *)"#", (void *)(t_fmt_flag[]){E_FMT_TOK_FLAG_HASH_OVERLOADED}},
	{(void *)"0", (void *)(t_fmt_flag[]){E_FMT_TOK_FLAG_LEFT_PAD_ZEROES}},
};
static t_map		g_flag_map =
{
	.sz = sizeof(g_flag_kvs),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_flag),
	.kvs = g_flag_kvs,
};
static t_map_kv		g_width_kvs[] = (t_map_kv[])
{
	{(void *)"*", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_BEFORE}},
	/*
	{(void *)"1", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_NUM}},
	{(void *)"2", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_NUM}},
	{(void *)"3", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_NUM}},
	{(void *)"4", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_NUM}},
	{(void *)"5", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_NUM}},
	{(void *)"6", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_NUM}},
	{(void *)"7", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_NUM}},
	{(void *)"8", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_NUM}},
	{(void *)"9", (void *)(t_fmt_width[]){E_FMT_TOK_WIDTH_NUM}},
	*/
};
static t_map		g_width_map =
{
	.sz = sizeof(g_width_kvs),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_width),
	.kvs = g_width_kvs,
};
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
static t_map_kv		g_spec_kvs[] = (t_map_kv[])
{
	{(void *)"d", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_INT}},
	{(void *)"D", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_INT}},
	{(void *)"i", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_INT}},
	{(void *)"u", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_UINT}},
	{(void *)"U", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_UINT}},
	{(void *)"o", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_OCTAL}},
	{(void *)"O", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_OCTAL}},
	{(void *)"x", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_HEX}},
	{(void *)"X", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_HEX_UPPER}},
	{(void *)"f", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_FLOAT}},
	{(void *)"F", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_FLOAT_UPPER}},
	{(void *)"e", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_EXP}},
	{(void *)"E", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_EXP_UPPER}},
	{(void *)"g", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_FLOAT_OR_EXP}},
	{(void *)"G", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_FLOAT_OR_EXP_UPPER}},
	{(void *)"a", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_HEX_FLOAT}},
	{(void *)"A", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_HEX_FLOAT_UPPER}},
	{(void *)"c", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_CHAR}},
	{(void *)"C", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_CHAR}},
	{(void *)"s", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_STR}},
	{(void *)"S", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_STR}},
	{(void *)"p", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_PTR}},
	{(void *)"n", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_N_PTR}},
	{(void *)"%", (void *)(t_fmt_spec[]){E_FMT_TOK_SPEC_PERCENT}},
};
static t_map		g_spec_map =
{
	.sz = sizeof(g_spec_kvs),
	.key_sz = sizeof(char *),
	.val_sz = sizeof(t_fmt_spec),
	.kvs = g_spec_kvs,
};
/*
static t_map		g_tok_map_arr[] =
{
	g_flag_map,
	g_len_map,
	g_prec_map,
	g_len_map,
	g_spec_map,
};
static t_fmt_sym	g_sym_arr[] =
{
	[E_FMT_TOK_NONE] = E_FMT_SYM_NONE,
	[E_FMT_TOK_FLAG_LEFT_JUSTIFY] = E_FMT_SYM_FLAG,
	[E_FMT_TOK_FLAG_FORCE_SIGN] = E_FMT_SYM_FLAG,
	[E_FMT_TOK_FLAG_SPACE_SIGN] = E_FMT_SYM_FLAG,
	[E_FMT_TOK_FLAG_HASH_OVERLOADED] = E_FMT_SYM_FLAG,
	[E_FMT_TOK_FLAG_LEFT_PAD_ZEROES] = E_FMT_SYM_FLAG,
	[E_FMT_TOK_WIDTH_BEFORE] = E_FMT_SYM_WIDTH,
	[E_FMT_TOK_WIDTH_NUM] = E_FMT_SYM_WIDTH,
	[E_FMT_TOK_PREC_BEFORE] = E_FMT_SYM_PREC,
	[E_FMT_TOK_PREC_NUM] = E_FMT_SYM_PREC,
	[E_FMT_TOK_LEN_CHAR] = E_FMT_SYM_LEN,
	[E_FMT_TOK_LEN_SHRT] = E_FMT_SYM_LEN,
	[E_FMT_TOK_LEN_LONG] = E_FMT_SYM_LEN,
	[E_FMT_TOK_LEN_LLONG] = E_FMT_SYM_LEN,
	[E_FMT_TOK_LEN_INTMAX] = E_FMT_SYM_LEN,
	[E_FMT_TOK_LEN_SIZE] = E_FMT_SYM_LEN,
	[E_FMT_TOK_LEN_PTRDIFF] = E_FMT_SYM_LEN,
	[E_FMT_TOK_LEN_LONG_DOUBLE] = E_FMT_SYM_LEN,
	[E_FMT_TOK_SPEC_INT] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_UINT] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_OCTAL] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_HEX] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_HEX_UPPER] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_FLOAT] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_FLOAT_UPPER] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_EXP] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_EXP_UPPER] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_FLOAT_OR_EXP] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_FLOAT_OR_EXP_UPPER] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_HEX_FLOAT] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_HEX_FLOAT_UPPER] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_CHAR] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_STR] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_PTR] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_N_PTR] = E_FMT_SYM_SPEC,
	[E_FMT_TOK_SPEC_PERCENT] = E_FMT_SYM_SPEC,
};
*/
static t_map_kv		g_arg_kvs[] = (t_map_kv[])
{
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_INT, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_INT}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_INT, .len = E_FMT_LEN_CHAR}, (void *)(t_fmt_arg[]){E_FMT_ARG_SCHAR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_INT, .len = E_FMT_LEN_SHRT}, (void *)(t_fmt_arg[]){E_FMT_ARG_SSHRT}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_INT, .len = E_FMT_LEN_LONG}, (void *)(t_fmt_arg[]){E_FMT_ARG_SLONG}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_INT, .len = E_FMT_LEN_LLONG}, (void *)(t_fmt_arg[]){E_FMT_ARG_SLLONG}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_INT, .len = E_FMT_LEN_INTMAX}, (void *)(t_fmt_arg[]){E_FMT_ARG_INTMAX}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_INT, .len = E_FMT_LEN_SIZE}, (void *)(t_fmt_arg[]){E_FMT_ARG_SIZE}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_INT, .len = E_FMT_LEN_PTRDIFF}, (void *)(t_fmt_arg[]){E_FMT_ARG_PTRDIFF}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_UINT, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_UINT}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_UINT, .len = E_FMT_LEN_CHAR}, (void *)(t_fmt_arg[]){E_FMT_ARG_UCHAR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_UINT, .len = E_FMT_LEN_SHRT}, (void *)(t_fmt_arg[]){E_FMT_ARG_USHRT}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_UINT, .len = E_FMT_LEN_LONG}, (void *)(t_fmt_arg[]){E_FMT_ARG_ULONG}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_UINT, .len = E_FMT_LEN_LLONG}, (void *)(t_fmt_arg[]){E_FMT_ARG_ULLONG}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_UINT, .len = E_FMT_LEN_INTMAX}, (void *)(t_fmt_arg[]){E_FMT_ARG_UINTMAX}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_UINT, .len = E_FMT_LEN_SIZE}, (void *)(t_fmt_arg[]){E_FMT_ARG_SIZE}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_UINT, .len = E_FMT_LEN_PTRDIFF}, (void *)(t_fmt_arg[]){E_FMT_ARG_PTRDIFF}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_FLOAT, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_DBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_FLOAT, .len = E_FMT_LEN_LONG_DOUBLE}, (void *)(t_fmt_arg[]){E_FMT_ARG_LDBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_FLOAT_UPPER, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_DBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_FLOAT_UPPER, .len = E_FMT_LEN_LONG_DOUBLE}, (void *)(t_fmt_arg[]){E_FMT_ARG_LDBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_EXP, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_DBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_EXP, .len = E_FMT_LEN_LONG_DOUBLE}, (void *)(t_fmt_arg[]){E_FMT_ARG_LDBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_EXP_UPPER, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_DBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_EXP_UPPER, .len = E_FMT_LEN_LONG_DOUBLE}, (void *)(t_fmt_arg[]){E_FMT_ARG_LDBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_FLOAT_OR_EXP, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_DBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_FLOAT_OR_EXP, .len = E_FMT_LEN_LONG_DOUBLE}, (void *)(t_fmt_arg[]){E_FMT_ARG_LDBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_FLOAT_OR_EXP_UPPER, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_DBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_FLOAT_OR_EXP_UPPER, .len = E_FMT_LEN_LONG_DOUBLE}, (void *)(t_fmt_arg[]){E_FMT_ARG_LDBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_HEX_FLOAT, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_DBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_HEX_FLOAT, .len = E_FMT_LEN_LONG_DOUBLE}, (void *)(t_fmt_arg[]){E_FMT_ARG_LDBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_HEX_FLOAT_UPPER, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_DBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_HEX_FLOAT_UPPER, .len = E_FMT_LEN_LONG_DOUBLE}, (void *)(t_fmt_arg[]){E_FMT_ARG_LDBL}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_CHAR, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_INT}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_CHAR, .len = E_FMT_LEN_LONG}, (void *)(t_fmt_arg[]){E_FMT_ARG_WINT}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_STR, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_STR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_STR, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_WSTR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_PTR, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_PTR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_N_PTR, .len = E_FMT_LEN_NONE}, (void *)(t_fmt_arg[]){E_FMT_ARG_INT_PTR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_N_PTR, .len = E_FMT_LEN_CHAR}, (void *)(t_fmt_arg[]){E_FMT_ARG_SCHAR_PTR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_N_PTR, .len = E_FMT_LEN_SHRT}, (void *)(t_fmt_arg[]){E_FMT_ARG_SHRT_PTR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_N_PTR, .len = E_FMT_LEN_LONG}, (void *)(t_fmt_arg[]){E_FMT_ARG_LONG_PTR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_N_PTR, .len = E_FMT_LEN_LLONG}, (void *)(t_fmt_arg[]){E_FMT_ARG_LLONG_PTR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_N_PTR, .len = E_FMT_LEN_INTMAX}, (void *)(t_fmt_arg[]){E_FMT_ARG_INTMAX_PTR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_N_PTR, .len = E_FMT_LEN_SIZE}, (void *)(t_fmt_arg[]){E_FMT_ARG_SIZE_PTR}},
	{(void *)(t_fmt_exp){.spec = E_FMT_SPEC_N_PTR, .len = E_FMT_LEN_PTRDIFF}, (void *)(t_fmt_arg[]){E_FMT_ARG_PTRDIFF_PTR}},
};
static t_map		g_arg_map =
{
	.sz = sizeof(g_arg_kvs),
	.key_sz = sizeof(t_fmt_exp),
	.val_sz = sizeof(t_fmt_arg),
	.kvs = g_arg_kvs,
};
static t_convert_fp	g_convert_map[] = (t_convert_fp[])
{
	[E_FMT_ARG_NONE] = NULL,
	[E_FMT_ARG_SCHAR] = convert_schar,
	[E_FMT_ARG_UCHAR] = convert_uchar,
	[E_FMT_ARG_WINT] = convert_wint,
	[E_FMT_ARG_SSHRT] = convert_sshrt,
	[E_FMT_ARG_USHRT] = convert_ushrt,
	[E_FMT_ARG_SINT] = convert_sint,
	[E_FMT_ARG_UINT] = convert_uint,
	[E_FMT_ARG_SLONG] = convert_slong,
	[E_FMT_ARG_ULONG] = convert_ulong,
	[E_FMT_ARG_SLLONG] = convert_sllong,
	[E_FMT_ARG_ULLONG] = convert_ullong,
	[E_FMT_ARG_INTMAX] = convert_intmax
	[E_FMT_ARG_UINTMAX] = convert_uintmax,
	[E_FMT_ARG_SIZE] = convert_size,
	[E_FMT_ARG_PTRDIFF] = convert_ptrdiff,
	[E_FMT_ARG_DBL] = convert_dbl,
	[E_FMT_ARG_LDBL] = convert_ldbl,
	[E_FMT_ARG_STR] = convert_str,
	[E_FMT_ARG_WSTR] = convert_wstr,
	[E_FMT_ARG_PTR] = convert_ptr,
	[E_FMT_ARG_SCHAR_PTR] = convert_count_schar,
	[E_FMT_ARG_SHRT_PTR] = convert_count_shrt,
	[E_FMT_ARG_INT_PTR] = convert_count_int,
	[E_FMT_ARG_LONG_PTR] = convert_count_long,
	[E_FMT_ARG_LLONG_PTR] = convert_count_llong,
	[E_FMT_ARG_INTMAX_PTR] = convert_count_intmax,
	[E_FMT_ARG_SIZE_PTR] = convert_count_size,
	[E_FMT_ARG_PTRDIFF_PTR] = convert_count_ptrdiff,
};
static t_parse_fp	g_parse[] =
{
	parse_fmt_nothing,
	parse_fmt_flags,
	parse_fmt_width,
	parse_fmt_prec,
	parse_fmt_len,
	parse_fmt_spec,
};

int					ft_printf(const char *format, ...)
{
	(void)format;
	return (0);
}

char				*store_fmt_text(char *loc, char **edg)
{
	char	c;

	while ((c = *loc) && '%' != c)
	{
		if (g_iter < sizeof(g_buf))
		{
			g_buf[g_iter] = c;
			g_iter++;
			loc++;
		}
		else
		{
			write(1, g_buf, sizeof(g_buf));
			g_iter = 0;
			// don't need to reset g_buf, in theory
			//g_buf = (const char[sizeof(g_buf)]){0};
		}
	}
	*edg = loc;
	return (loc);
}

void				store_fmt_exp(t_fmt_exp *exp, void *arg)
{
	
}

t_map_kv			*parse_fmt_tok(t_map *mp, char *loc, char **edg)
{
	t_map_kv	*kv;

	kv = ft_mapget(mp, (void *)loc, ft_map_keycmp_str);
	if (NULL != kv)
		*edg = loc + ft_strlen((char *)kv->key);
	return (kv);
}

t_map_kv			*parse_fmt_arg(void *arg, t_fmt_exp *exp)
{

}

t_fmt_sym			parse_fmt_pass(t_fmt_exp *exp,
									char *loc, char **edg)
{
	(void)exp;
	loc++;
	*edg = loc;
	return (E_FMT_SYM_NONE);
}

t_fmt_sym			parse_fmt_flags(t_fmt_exp *exp,
									char *loc, char **edg)
{
	t_map_kv		*kv;

	if (NULL != (kv = parse_fmt_tok(g_flag_map, loc, edg)))
		exp->set |= E_FMT_EXP_SET_FLAGS;
	while (NULL != kv)
	{
		exp->flags |= *(t_fmt_flag_bit *)kv->val;
		kv = parse_fmt_tok(g_flag_map, loc, edg);
	}
	return (exp->set & E_FMT_EXP_SET_FLAGS_SET ?
			E_FMT_SYM_FLAG : E_FMT_SYM_NONE);
}

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

t_fmt_exp			*parse_fmt_len(t_fmt_exp *exp,
									char *loc, char **edg)
{
	t_map_kv		*kv;

	if (NULL != (kv = parse_fmt_tok(g_len_map, loc, edg)))
		exp->len = *(t_fmt_len *)kv->val;
	return (NULL == kv ? E_FMT_SYM_NONE : E_FMT_SYM_LEN);
}

t_fmt_exp			*parse_fmt_spec(t_fmt_exp *exp, t_map_kv *kv,
									char *loc, char **edg)
{
	t_map_kv		*kv;

	if (NULL != (kv = parse_fmt_tok(g_spec_map, loc, edg)))
		exp->spec = *(t_fmt_spec *)kv->val;
	return (NULL == kv ? E_FMT_SYM_NONE : E_FMT_SYM_SPEC);
}

t_fmt_sym			parse_fmt_sym(t_fmt_exp *exp, t_fmt_sym sym,
								  char *loc, char **edg)
{
	int			ii;

	ii = sym + 1;
	while (ii < sizeof(g_parse))
	{
		if (E_FMT_SYM_NONE != g_parse[ii](exp, loc, edg))
			return (ii);
		ii++;
	}
	return (E_FMT_SYM_NONE);
}

t_fmt_exp			*parse_fmt_exp(void *arg, char *loc, char **edg)
{
	t_fmt_sym			sym;
	t_map_kv			*kv;
	t_fmt_exp			*exp;

	if (NULL == (exp = malloc(sizeof(exp))))
		return (NULL);
	exp->set = E_FMT_EXP_SET_UNSET;
	sym = E_FMT_SYM_NONE;
	while ('\0' != *loc && E_FMT_SYM_SPEC != sym)
		sym = parse_fmt_sym(sym, loc, edg);
	kv = ft_mapget(g_
	return (exp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 03:44:40 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/27 18:37:07 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <wchar.h>

#include "libft.h"

typedef enum		e_fmt_sym
{
	E_FMT_SYM_NONE,
	E_FMT_SYM_FLAG,
	E_FMT_SYM_WIDTH,
	E_FMT_SYM_PREC,
	E_FMT_SYM_LEN,
	E_FMT_SYM_SPEC,
}					t_fmt_sym;

typedef enum		e_fmt_tok
{
	E_FMT_TOK_NONE,
	E_FMT_TOK_FLAG_LEFT_JUSTIFY,
	E_FMT_TOK_FLAG_FORCE_SIGN,
	E_FMT_TOK_FLAG_SPACE_SIGN,
	E_FMT_TOK_FLAG_HASH_OVERLOADED,
	E_FMT_TOK_FLAG_LEFT_PAD_ZEROES,
	E_FMT_TOK_WIDTH_NUM,
	E_FMT_TOK_WIDTH_BEFORE,
	E_FMT_TOK_PREC_NUM,
	E_FMT_TOK_PREC_BEFORE,
	E_FMT_TOK_LEN_CHAR,
	E_FMT_TOK_LEN_SHRT,
	E_FMT_TOK_LEN_LONG,
	E_FMT_TOK_LEN_LLONG,
	E_FMT_TOK_LEN_INTMAX,
	E_FMT_TOK_LEN_SIZE,
	E_FMT_TOK_LEN_PTRDIFF,
	E_FMT_TOK_LEN_LONG_DOUBLE,
	E_FMT_TOK_SPEC_INT,
	E_FMT_TOK_SPEC_UINT,
	E_FMT_TOK_SPEC_OCTAL,
	E_FMT_TOK_SPEC_HEX,
	E_FMT_TOK_SPEC_HEX_UPPER,
	E_FMT_TOK_SPEC_FLOAT,
	E_FMT_TOK_SPEC_FLOAT_UPPER,
	E_FMT_TOK_SPEC_EXP,
	E_FMT_TOK_SPEC_EXP_UPPER,
	E_FMT_TOK_SPEC_FLOAT_OR_EXP,
	E_FMT_TOK_SPEC_FLOAT_OR_EXP_UPPER,
	E_FMT_TOK_SPEC_HEX_FLOAT,
	E_FMT_TOK_SPEC_HEX_FLOAT_UPPER,
	E_FMT_TOK_SPEC_CHAR,
	E_FMT_TOK_SPEC_STR,
	E_FMT_TOK_SPEC_PTR,
	E_FMT_TOK_SPEC_N_PTR,
	E_FMT_TOK_SPEC_PERCENT,
}					t_fmt_tok;

typedef enum		e_fmt_flag_bit
{
	E_FMT_FLAG_BIT_NONE,
	E_FMT_FLAG_BIT_LEFT_JUSTIFY = BIT_FLAG(1),
	E_FMT_FLAG_BIT_FORCE_SIGN = BIT_FLAG(2),
	E_FMT_FLAG_BIT_SPACE_SIGN = BIT_FLAG(3),
	E_FMT_FLAG_BIT_HASH_OVERLOADED = BIT_FLAG(4),
	E_FMT_FLAG_BIT_LEFT_PAD_ZEROES = BIT_FLAG(5),
}					t_fmt_flag_bit;

typedef enum		e_fmt_width
{
	E_FMT_WIDTH_BEFORE = ~(~0u >> 1),
	E_FMT_WIDTH_NONE = 0,
}					t_fmt_width;

typedef enum		e_fmt_prec
{
	E_FMT_PREC_BEFORE = ~(~0u >> 1),
	E_FMT_PREC_NONE = 0,
	E_FMT_PREC_ZERO,
}					t_fmt_prec;

typedef enum		e_fmt_len
{
	E_FMT_LEN_NONE,
	E_FMT_LEN_CHAR,
	E_FMT_LEN_SHRT,
	E_FMT_LEN_LONG,
	E_FMT_LEN_LLONG,
	E_FMT_LEN_INTMAX,
	E_FMT_LEN_SIZE,
	E_FMT_LEN_PTRDIFF,
	E_FMT_LEN_LONG_DOUBLE,
}					t_fmt_len;

typedef enum		e_fmt_spec
{
	E_FMT_SPEC_NONE,
	E_FMT_SPEC_INT,
	E_FMT_SPEC_UINT,
	E_FMT_SPEC_OCTAL,
	E_FMT_SPEC_HEX,
	E_FMT_SPEC_HEX_UPPER,
	E_FMT_SPEC_FLOAT,
	E_FMT_SPEC_FLOAT_UPPER,
	E_FMT_SPEC_EXP,
	E_FMT_SPEC_EXP_UPPER,
	E_FMT_SPEC_FLOAT_OR_EXP,
	E_FMT_SPEC_FLOAT_OR_EXP_UPPER,
	E_FMT_SPEC_HEX_FLOAT,
	E_FMT_SPEC_HEX_FLOAT_UPPER,
	E_FMT_SPEC_CHAR,
	E_FMT_SPEC_STR,
	E_FMT_SPEC_PTR,
	E_FMT_SPEC_N_PTR,
	E_FMT_SPEC_PERCENT,
}					t_fmt_spec;

typedef enum		e_fmt_arg_id
{
	E_FMT_ARG_ID_NONE,
	E_FMT_ARG_ID_SCHAR,
	E_FMT_ARG_ID_UCHAR,
	E_FMT_ARG_ID_CHAR,
	E_FMT_ARG_ID_WINT,
	E_FMT_ARG_ID_SSHRT,
	E_FMT_ARG_ID_USHRT,
	E_FMT_ARG_ID_SINT,
	E_FMT_ARG_ID_UINT,
	E_FMT_ARG_ID_SLONG,
	E_FMT_ARG_ID_ULONG,
	E_FMT_ARG_ID_SLLONG,
	E_FMT_ARG_ID_ULLONG,
	E_FMT_ARG_ID_INTMAX,
	E_FMT_ARG_ID_UINTMAX,
	E_FMT_ARG_ID_SIZE,
	E_FMT_ARG_ID_PTRDIFF,
	E_FMT_ARG_ID_DBL,
	E_FMT_ARG_ID_LDBL,
	E_FMT_ARG_ID_STR,
	E_FMT_ARG_ID_WSTR,
	E_FMT_ARG_ID_PTR,
	E_FMT_ARG_ID_SCHAR_PTR,
	E_FMT_ARG_ID_SHRT_PTR,
	E_FMT_ARG_ID_INT_PTR,
	E_FMT_ARG_ID_LONG_PTR,
	E_FMT_ARG_ID_LLONG_PTR,
	E_FMT_ARG_ID_INTMAX_PTR,
	E_FMT_ARG_ID_SIZE_PTR,
	E_FMT_ARG_ID_PTRDIFF_PTR,
}					t_fmt_arg_id;

typedef enum		e_fmt_exp_set
{
	E_FMT_EXP_SET_NONE = 0,
	E_FMT_EXP_SET_FLAGS = BIT_FLAG(1),
	E_FMT_EXP_SET_WIDTH = BIT_FLAG(2),
	E_FMT_EXP_SET_PREC = BIT_FLAG(3),
	E_FMT_EXP_SET_LEN = BIT_FLAG(4),
	E_FMT_EXP_SET_SPEC = BIT_FLAG(5),
}					t_fmt_exp_set;

typedef struct		s_fmt_exp
{
	int				set;
	int				flags;
	t_fmt_width		width;
	t_fmt_prec		prec;
	t_fmt_len		len;
	t_fmt_spec		spec;
}					t_fmt_exp;

typedef t_fmt_sym	(*t_parse_subspec_fp)(t_fmt_exp *, char **);
typedef int			(*t_print_arg_fp)(t_fmt_exp *, va_list);

int					print_ptr(t_fmt_exp *exp, va_list ap);
int					print_str(t_fmt_exp *exp, va_list ap);
int					print_char(t_fmt_exp *exp, va_list ap);
int					print_sint(t_fmt_exp *exp, va_list ap);
int					print_size(t_fmt_exp *exp, va_list ap);
int					print_uint(t_fmt_exp *exp, va_list ap);
int					print_wint(t_fmt_exp *exp, va_list ap);
int					print_wstr(t_fmt_exp *exp, va_list ap);
int					print_schar(t_fmt_exp *exp, va_list ap);
int					print_slong(t_fmt_exp *exp, va_list ap);
int					print_sshrt(t_fmt_exp *exp, va_list ap);
int					print_uchar(t_fmt_exp *exp, va_list ap);
int					print_ulong(t_fmt_exp *exp, va_list ap);
int					print_ushrt(t_fmt_exp *exp, va_list ap);
int					print_intmax(t_fmt_exp *exp, va_list ap);
int					print_sllong(t_fmt_exp *exp, va_list ap);
int					print_ullong(t_fmt_exp *exp, va_list ap);
int					print_ptrdiff(t_fmt_exp *exp, va_list ap);
int					print_uintmax(t_fmt_exp *exp, va_list ap);
int					print_ullong_base(t_fmt_exp *exp, int base, va_list ap);
int					print_text_until_exp(char **fmt);
int					print_arg(char **fmt, va_list ap);
t_fmt_sym			parse_fmt_sym(t_fmt_exp *exp, char **fmt, t_fmt_sym sym);
t_fmt_sym			parse_fmt_spec(t_fmt_exp *exp, char **fmt);
t_fmt_sym			parse_fmt_pass(t_fmt_exp *exp, char **fmt);
t_fmt_sym			parse_fmt_prec(t_fmt_exp *exp, char **fmt);
t_fmt_sym			parse_fmt_flags(t_fmt_exp *exp, char **fmt);
t_fmt_sym			parse_fmt_width(t_fmt_exp *exp, char **fmt);
t_fmt_sym			parse_fmt_len(t_fmt_exp *exp, char **fmt);
t_fmt_arg_id		parse_fmt_arg_id(t_fmt_exp *exp);
t_map_kv			*parse_fmt_tok(t_map *mp, char *loc, char **edg);
t_fmt_exp			*parse_fmt_exp(char **fmt);
int					convert_nbr_pad(t_fmt_exp *exp, int sz, char **conv);
int					ft_printf(const char *fmt, ...);

#endif

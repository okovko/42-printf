/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 03:44:40 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/21 00:22:47 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stddef.h>
#include <stdint.h>
#include <wchar.h>

#include "libft.h"

typedef void (*t_parse_fp)(t_fmt_exp *, char *, char **);
typedef void (*t_convert_fp)(t_fmt_exp *, void *);

typedef enum	e_fmt_sym
{
	E_FMT_SYM_NONE,
	E_FMT_SYM_FLAG,
	E_FMT_SYM_WIDTH,
	E_FMT_SYM_PREC,
	E_FMT_SYM_LEN,
	E_FMT_SYM_SPEC,
}				t_fmt_sym;

typedef enum	e_fmt_tok
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
}				t_fmt_tok;

/*
typedef enum	e_fmt_flag
{
	E_FMT_FLAG_NONE,
	E_FMT_FLAG_LEFT_JUSTIFY,
	E_FMT_FLAG_FORCE_SIGN,
	E_FMT_FLAG_SPACE_SIGN,
	E_FMT_FLAG_HASH_OVERLOADED,
	E_FMT_FLAG_LEFT_PAD_ZEROES,
}				t_fmt_flag;
*/

typedef enum	e_fmt_flag_bit
{
	E_FMT_FLAG_BIT_NONE,
	E_FMT_FLAG_BIT_LEFT_JUSTIFY = BIT_FLAG(1),
	E_FMT_FLAG_BIT_FORCE_SIGN = BIT_FLAG(2),
	E_FMT_FLAG_BIT_SPACE_SIGN = BIT_FLAG(3),
	E_FMT_FLAG_BIT_HASH_OVERLOADED = BIT_FLAG(4),
	E_FMT_FLAG_BIT_LEFT_PAD_ZEROES = BIT_FLAG(5),
}				t_fmt_flag_bit;

typedef enum		e_fmt_width
{
	E_FMT_WIDTH_BEFORE = ~(~0u >> 1),
	E_FMT_WIDTH_NONE = 0,
}					t_fmt_width;

typedef enum		e_fmt_prec
{
	E_FMT_PREC_BEFORE = ~(~0u >> 1),
	E_FMT_PREC_NONE = 0,
}					t_fmt_prec;

typedef enum	e_fmt_len
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
}				t_fmt_len;

typedef enum	e_fmt_spec
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
}				t_fmt_spec;

typedef union			u_fmt_arg_value
{
	signed char			schar;
	unsigned char		uchar;
	wint_t				wint;
	short				sshrt;
	unsigned short		ushrt;
	int					sint;
	unsigned			uint;
	long				slong;
	unsigned long		ulong;
	long long			sllong;
	unsigned long long	ullong;
	intmax_t			intmax;
	uintmax_t			uintmax;
	size_t				size;
	ptr_diff_t			ptr_diff;
	double				dbl;
	long double			ldbl;
	char				*str;
	wchar_t				*wstr;
	void				*ptr;
	signed char			*schar_ptr;
	short				*shrt_ptr;
	int					*int_ptr;
	long				*long_ptr;
	long long			*llong_ptr;
	intmax_t			*intmax_ptr;
	size_t				*size_ptr;
	ptrdiff_t			*ptrdiff_ptr;
}						t_fmt_arg_value;

typedef enum		e_fmt_arg_id
{
	E_FMT_ARG_NONE,
	E_FMT_ARG_SCHAR,
	E_FMT_ARG_UCHAR,
	E_FMT_ARG_WINT,
	E_FMT_ARG_SSHRT,
	E_FMT_ARG_USHRT,
	E_FMT_ARG_SINT,
	E_FMT_ARG_UINT,
	E_FMT_ARG_SLONG,
	E_FMT_ARG_ULONG,
	E_FMT_ARG_SLLONG,
	E_FMT_ARG_ULLONG,
	E_FMT_ARG_INTMAX,
	E_FMT_ARG_UINTMAX,
	E_FMT_ARG_SIZE,
	E_FMT_ARG_PTRDIFF,
	E_FMT_ARG_DBL,
	E_FMT_ARG_LDBL,
	E_FMT_ARG_STR,
	E_FMT_ARG_WSTR,
	E_FMT_ARG_PTR,
	E_FMT_ARG_SCHAR_PTR,
	E_FMT_ARG_SHRT_PTR,
	E_FMT_ARG_INT_PTR,
	E_FMT_ARG_LONG_PTR,
	E_FMT_ARG_LLONG_PTR,
	E_FMT_ARG_INTMAX_PTR,
	E_FMT_ARG_SIZE_PTR,
	E_FMT_ARG_PTRDIFF_PTR,
}					t_fmt_arg_id;

typedef enum		e_fmt_exp_set
{
	E_FMT_EXP_SET_UNSET = 0,
	E_FMT_EXP_SET_FLAGS = BIT_FLAG(1),
	E_FMT_EXP_SET_WIDTH = BIT_FLAG(2),
	E_FMT_EXP_SET_PREC = BIT_FLAG(3),
	E_FMT_EXP_SET_LEN = BIT_FLAG(4),
	E_FMT_EXP_SET_SPEC = BIT_FLAG(5),
}					t_fmt_exp_set;

typedef struct			s_fmt_arg
{
	t_fmt_arg_id		id;
	t_fmt_arg_value		val;
	int					sz;
}						t_fmt_arg;

typedef struct			s_fmt_exp
{
	int					set;
	int					flags;
	t_fmt_width			width;
	t_fmt_prec			prec;
	t_fmt_len			len;
	t_fmt_spec			spec;
	t_fmt_arg			arg;
}						t_fmt_exp;

int			ft_printf(const char *fmt, ...);
t_list		*parse_fmt(const char *fmt);
t_fmt_exp	*parse_fmt_exp(t_fmt_exp *fmt_exp, char **fmt_loc);

#endif

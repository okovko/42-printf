/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 03:44:40 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/14 19:18:44 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"

typedef enum	e_fmt_spec
{
	E_FMT_SPEC_BAD = -1,
	E_FMT_SPEC_NONE = 0,
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
	E_FMT_SPEC_N,
	E_FMT_SPEC_PERCENT,
}				t_fmt_spec;

typedef enum	e_fmt_len
{
	E_FMT_LEN_BAD = -1,
	E_FMT_LEN_NONE = 0,
	E_FMT_LEN_CHAR,
	E_FMT_LEN_SHRT,
	E_FMT_LEN_LONG,
	E_FMT_LEN_LLONG,
	E_FMT_LEN_INT_MAX,
	E_FMT_LEN_SIZE,
	E_FMT_LEN_PTR_DIFF,
	E_FMT_LEN_LONG_DOUBLE,
}				t_fmt_len;

typedef enum	e_fmt_flag_bit
{
	E_FMT_FLAG_NONE = 0,
	E_FMT_FLAG_LEFT_JUSTIFY = BIT_FLAG(1),
	E_FMT_FLAG_FORCE_SIGN = BIT_FLAG(2),
	E_FMT_FLAG_SPACE_SIGN = BIT_FLAG(3),
	E_FMT_FLAG_HASH_OVERLOADED = BIT_FLAG(4),
	E_FMT_FLAG_LEFT_PAD_ZEROES = BIT_FLAG(5),
}				t_fmt_flag_bit;

typedef enum	e_fmt_flags
{
	E_FMT_FLAGS_BAD = -1,
	E_FMT_FLAGS_NONE = 0,
	E_FMT_FLAGS_ALL_SET = BIT_FLAGS_MAX(5)
}				t_fmt_flags;

typedef enum		e_fmt_width
{
	E_FMT_WIDTH_NONE = -1,
}					t_fmt_width;

typedef enum		e_fmt_prec
{
	E_FMT_PREC_NONE = -1,
}					t_fmt_prec;

typedef struct		s_fmt_exp
{
	t_fmt_spec		spec;
	t_fmt_len		len;
	t_fmt_flags		flags;
	t_fmt_width		width;
	t_fmt_prec		prec;
}					t_fmt_exp;

int			ft_printf(const char *fmt, ...);
t_list		*parse_fmt(const char *fmt);
t_fmt_exp	*parse_fmt_exp(t_fmt_exp *fmt_exp, char **fmt_loc);

#endif

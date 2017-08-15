/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 03:43:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/14 19:19:36 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"

int					ft_printf (const char *format, ...)
{
	(void)format;
	return (0);
}

t_list				*parse_fmt(const char *fmt)
{
	char		*loc;
	t_list		*lst;
	t_fmt_exp	*exp;

	loc = ft_strchr(fmt, '%');
	lst = NULL;
	while (NULL != loc)
	{
		exp = parse_fmt_exp(&loc);
		lst = ft_lstadd(ft_lstnode((void *), sizeof(*exp)));
		loc = ft_strchr(fmt, '%');
	}
	return (ft_lstsrev(&lst));
}

t_fmt_exp			*parse_fmt_exp(char **loc)
{
	t_fmt_exp	*exp;

	CHKALLOC(exp = malloc(sizeof(*exp)));
	*exp = (const t_fmt_exp){0};
	(*loc)++;
	exp->flags = parse_fmt_flags(loc);
	exp->width = parse_fmt_width(loc);
	exp->prec = parse_fmt_prec(loc);
	exp->len = parse_fmt_len(loc);
	exp->spec = parse_fmt_spec(loc);
	return (exp);
}

t_fmt_spec			parse_fmt_spec(char **loc)
{
	char	c;

	c = **loc;
	RETIF(E_FMT_SPEC_INT, 'd' == c || 'i' == c);
	RETIF(E_FMT_SPEC_UINT, 'u' == c);
	RETIF(E_FMT_SPEC_OCTAL, 'o' == c);
	RETIF(E_FMT_SPEC_HEX, 'x' == c);
	RETIF(E_FMT_SPEC_HEX_UPPER, 'X' == c);
	RETIF(E_FMT_SPEC_FLOAT, 'f' == c);
	RETIF(E_FMT_SPEC_FLOAT_UPPER, 'F' == c);
	RETIF(E_FMT_SPEC_EXP, 'e' == c);
	RETIF(E_FMT_SPEC_EXP_UPPER, 'E' == c);
	RETIF(E_FMT_SPEC_FLOAT_OR_EXP, 'g' == c);
	RETIF(E_FMT_SPEC_FLOAT_OR_EXP_UPPER, 'G' == c);
	RETIF(E_FMT_SPEC_HEX_FLOAT, 'a' == c);
	RETIF(E_FMT_SPEC_HEX_FLOAT_UPPER, 'A' == c);
	RETIF(E_FMT_SPEC_CHAR, 'c' == c);
	RETIF(E_FMT_SPEC_STR, 's' == c);
	RETIF(E_FMT_SPEC_PTR, 'p' == c);
	RETIF(E_FMT_SPEC_N, 'n' == c);
	RETIF(E_FMT_SPEC_PERCENT, '%' == c);
	return (E_FMT_SPEC_BAD);
}

t_fmt_len			parse_fmt_len(char **loc)
{
	char		a;
	char		b;

	a = **loc;
	b = a == '\0' ? '\0' : *(*loc + 1);
	if (is_fmt_len_char(a))
		(*loc)++;
	if ('h' == b || 'l' == b)
		(*loc)++;
	RETIF(E_FMT_LEN_CHAR, 'h' == a && 'h' == b);
	RETIF(E_FMT_LEN_LLONG, 'l' == a && 'l' == b);
	RETIF(E_FMT_LEN_SHRT, 'h' == a);
	RETIF(E_FMT_LEN_LONG, 'l' == a);
	RETIF(E_FMT_LEN_INT_MAX, 'j' == a);
	RETIF(E_FMT_LEN_SIZE, 'z' == a);
	RETIF(E_FMT_PTR_DIFF, 't' == a);
	RETIF(E_FMT_LONG_DOUBLE, 'L' == a);
	if (is_fmt_flags_char(a) || ISDIGIT(a) || a == '.')
		return (E_FMT_LEN_BAD);
	return (E_FMT_LEN_NONE);
}

t_fmt_width			parse_fmt_width(char **loc)
{
	char			*str;
	char			c;
	e_fmt_width		width;

	if (!ISDIGIT(**loc))
		return (E_FMT_WIDTH_NONE);
	str = *loc;
	width = 0;
	while ((c = *str++) && ISDIGIT(c))
		width = width * 10 + c - '0';
	if (is_fmt_flags_char(**loc))
		return (E_FMT_WIDTH_BAD);
	*loc = str;
	return (width);
}

t_fmt_prec			parse_fmt_prec(char **loc)
{
	char			*str;
	char			c;
	e_fmt_prec		prec;

	if (**loc != '.')
		return (E_FMT_PREC_NONE);
	(*loc)++;
	if (!ISDIGIT(**loc))
		return (E_FMT_PREC_NONE);
	str = *loc;
	prec = 0;
	while ((c = *str++) && ISDIGIT(c))
		prec = prec * 10 + c - '0';
	if (is_fmt_char_flag(c) || c == '.')
		return (E_FMT_PREC_BAD);
	*loc = str;
	return (prec);
}

t_fmt_flag_bit		fmt_scan_flag(char **fmt)
{
	char	c;

	c = *fmt;
	if (is_fmt_flags_char(c))
		(*fmt)++;
	if ('-' == c)
		return (E_FMT_FLAG_LEFT_JUSTIFY);
	if ('+' == c)
		return (E_FMT_FLAG_FORCE_SIGN);
	if (' ' == c)
		return (E_FMT_FLAG_SPACE_SIGN);
	if ('#' == c)
		return (E_FMT_FLAG_HASH_OVERLOADED);
	if ('0' == c)
		return (E_FMT_FLAG_PAD_ZEROES);
	return (E_FMT_FLAG_NONE);
}

t_fmt_flags			*parse_fmt_flags(char **loc)
{
	t_fmt_flags			f;
	t_fmt_flag_bit		b;

	f = E_FMT_FLAGS_NONE;
	b = fmt_scan_flag(loc);
	while (b != E_FMT_FLAG_NONE)
	{
		if (f & b)
			return (E_FMT_FLAGS_BAD);
		f |= b;
		b = fmt_scan_flag(loc);
	}
	return (f);
}

t_bool				is_fmt_flags_char(char c)
{
	return ('-' == c || '+' == c || ' ' == c || '#' == c || '0' == c)
}

t_bool				is_fmt_len_char(char c)
{
	return ('h' == a || 'l' == a || 'j' == a || 'z' == a || 't' == a
			|| 'L' == a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 15:52:37 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/29 01:31:57 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

static t_print_arg_fp	g_print_arg_fp[] = (t_print_arg_fp[])
{
	[E_FMT_ARG_ID_NONE] = print_nothing,
	[E_FMT_ARG_ID_SCHAR] = print_schar,
	[E_FMT_ARG_ID_UCHAR] = print_uchar,
	[E_FMT_ARG_ID_SSHRT] = print_sshrt,
	[E_FMT_ARG_ID_USHRT] = print_ushrt,
	[E_FMT_ARG_ID_SINT] = print_sint,
	[E_FMT_ARG_ID_UINT] = print_uint,
	[E_FMT_ARG_ID_SLONG] = print_slong,
	[E_FMT_ARG_ID_ULONG] = print_ulong,
	[E_FMT_ARG_ID_SLLONG] = print_sllong,
	[E_FMT_ARG_ID_ULLONG] = print_ullong,
	[E_FMT_ARG_ID_INTMAX] = print_intmax,
	[E_FMT_ARG_ID_UINTMAX] = print_uintmax,
	[E_FMT_ARG_ID_SIZE] = print_size,
	[E_FMT_ARG_ID_PTRDIFF] = print_ptrdiff,
	[E_FMT_ARG_ID_CHAR] = print_char,
	[E_FMT_ARG_ID_WINT] = print_wint,
	[E_FMT_ARG_ID_STR] = print_str,
	[E_FMT_ARG_ID_WSTR] = print_wstr,
	[E_FMT_ARG_ID_PTR] = print_ptr,
};

int				print_arg(char **fmt, va_list ap)
{
	t_fmt_exp		*exp;
	t_fmt_arg_id	id;
	int				sz;

	exp = parse_fmt_exp(fmt, ap);
	id = parse_fmt_arg_id(exp);
	sz = g_print_arg_fp[id](exp, ap);
	free(exp);
	return (sz);
}

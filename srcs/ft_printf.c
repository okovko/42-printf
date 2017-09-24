/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 03:43:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/24 02:37:32 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	specifiers left to implement: S, C, p
	still need to do the va_list stuff in ft_printf.c itself
	rip the wide char stuff from online and also have mike help me understand
	wtf is going on with that
*/

#include <stdarg.h>

#include "ft_printf.h"

static t_print_arg_fp	g_print_arg_fp[] = (t_print_arg_fp[])
{
	[E_FMT_ARG_ID_NONE] = NULL,
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

int					ft_printf(const char *format, ...)
{
	char	*fmt;

	fmt = (char *)format;
	(void)g_print_arg_fp;
	return (print_text_until_arg(fmt, &fmt));
}

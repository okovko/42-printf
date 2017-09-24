/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 03:43:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 21:07:32 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	still need to actually read about va_list syntax, but, just cast
	to void * and pass into deref'd array of fn ptrs so it should be 1 liner
	bigger issue is that i didn't account for lowercase and capitalcase
	specifiers (that i need to do for the first version, anyways)
	which are: xX, sS, cC
	still need to implement p specifier
	still need to handle X properly
	the next order of business is to strip static off everything because
	of the 5 function per file limit, and break up the functions into 3 files
	should maybe move all this junk into the .h file if that's legal
	actually static should be okay. split each function into file and
	the maps are not shared between them. i hope.
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
	[E_FMT_ARG_ID_INTMAX] = print_intmax
	[E_FMT_ARG_ID_UINTMAX] = print_uintmax,
	[E_FMT_ARG_ID_SIZE] = print_size,
	[E_FMT_ARG_ID_PTRDIFF] = print_ptrdiff,
	[E_FMT_ARG_ID_DBL] = print_dbl,
	[E_FMT_ARG_ID_LDBL] = print_ldbl,
	[E_FMT_ARG_ID_CHAR] = print_char,
	[E_FMT_ARG_ID_WINT] = print_wint,
	[E_FMT_ARG_ID_STR] = print_str,
	[E_FMT_ARG_ID_WSTR] = print_wstr,
	[E_FMT_ARG_ID_PTR] = print_ptr,
};

int					ft_printf(const char *format, ...)
{
	return (print_text_until_arg(format, &format));
}

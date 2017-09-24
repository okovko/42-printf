/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 03:43:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/24 13:53:15 by olkovale         ###   ########.fr       */
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

static char			*next_exp(const char *fmt)
{
	char	*next;

	if (NULL == (next = ft_strchr(fmt, '%')))
		return (NULL);
	if ('%' == *(next + 1))
		return (next_exp(fmt + 2));
	return (next);
}

static int			count_exps(const char *fmt)
{
	int		ii;
	char	*hit;
	char	*chk;

	ii = 0;
	chk = (char *)fmt;
	while ('\0' != *(chk = ft_strchr(chk, '%')))
	{
		if ('%' == *(chk + 1))
		{
			chk += 2;
			continue ;
		}
		ii++;
		hit = chk;
	}
	return (ii);
}

int					ft_printf(const char *fmt, ...)
{
	int		ii;
	void	*arg;
	va_list	args;
	int		arg_sz;
	int		sz;

	sz = print_text_until_exp((char *)fmt, (char **)&fmt);
	arg_sz = count_exps(fmt);
	va_start(args, fmt);
	ii = 0;
	while (ii < arg_sz)
	{
		arg = va_arg(args, void *);
		sz += print_arg(fmt, arg);
		fmt = next_exp(fmt);
		ii++;
	}
	va_end(args);
	sz += print_text_until_exp((char *)fmt, (char **)&fmt);
	return (sz);
}

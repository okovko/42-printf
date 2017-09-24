/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 19:46:46 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 12:54:48 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

static char		*schar_right(char *ss, char cc, int sz)
{
	int		ii;

	ii = sz;
	ss[ii] = cc;
	while (--ii)
		ss[ii] = ' ';
	return (ss);
}

static char		*schar_left(char *ss, char cc, int sz)
{
	int		ii;

	ii = 0;
	ss[ii] = cc;
	while (++ii < sz)
		ss[ii] = ' ';
	return (ss);
}

int		print_schar(void *arg, t_fmt_exp *exp)
{
	char	cc;
	int		sz;
	char	*ss;

	cc = *(char *)arg;
	sz = 1 < exp->width ? exp->width : 1;
	ss = malloc(sz);
	if (exp->flags & E_FMT_FLAG_BIT_LEFT_JUSTIFY)
		write(1, schar_left(ss, cc, sz), sz);
	else
		write(1, schar_right(ss, cc, sz), sz);
	free(ss);
	return (sz);
}

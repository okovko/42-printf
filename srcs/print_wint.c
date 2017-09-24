/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 06:28:39 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 05:58:19 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

static char		*wint_right(wint_t *ws, wint_t wc, int sz)
{
	int		ii;

	ii = sz;
	ws[ii] = wc;
	while (--ii)
		ws[ii] = ' ';
	return (ws);
}

static char		*wint_left(wint_t *ws, wint_t wc, int sz)
{
	int		ii;

	ii = 0;
	ws[ii] = wc;
	while (++ii < sz)
		ws[ii] = ' ';
	return (ws);
}

int		print_wint(void *arg, t_fmt_exp *exp)
{
	wint_t	wc;
	int		sz;
	wint_t	*ws;

	wc = *(wint_t *)arg;
	sz = 1 < exp->width > exp->width : 1;
	ws = malloc(sz * sizeof(wint_t));
	if (exp->flags & E_FMT_FLAG_BIT_LEFT_JUSTIFY)
		write(1, wint_left(ws, wc, sz), sz);
	else
		write(1, wint_right(ws, wc, sz), sz);
	free(ws);
	return (sz);
}

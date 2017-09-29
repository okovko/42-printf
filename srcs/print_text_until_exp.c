/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text_until_exp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:14:55 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/27 21:05:18 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

static char	g_buf[4096] = {0};
static int	g_itr = 0;

static int	print_buf(void)
{
	int		sz;

	sz = g_itr;
	write(1, g_buf, g_itr);
	g_itr = 0;
	return (sz);
}

int			print_text_until_exp(char **edg)
{
	int		sz;
	char	cc;
	char	*loc;

	loc = *edg;
	sz = 0;
	while (((cc = *loc) && '%' != cc) || ('%' == cc && '%' == *(loc + 1)))
	{
		if ((unsigned)g_itr < sizeof(g_buf))
		{
			g_buf[g_itr] = cc;
			g_itr++;
			loc++;
			if ('%' == cc)
				loc++;
		}
		else
			sz += print_buf();
	}
	sz += print_buf();
	*edg = loc;
	return (sz);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text_until_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:14:55 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 21:14:55 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	g_buf[4096] = 0;
static int	g_itr = 0;

int			print_text_until_arg(char *loc, char **edg)
{
	int		sz;
	char	cc;

	while ((cc = *loc) && '%' != cc)
	{
		if (g_itr < sizeof(g_buf))
		{
			g_buf[g_itr] = cc;
			g_itr++;
			loc++;
		}
		else
		{
			write(1, g_buf, sizeof(g_buf));
			g_itr = 0;
			return (sizeof(g_buf));
		}
	}
	sz = g_itr;
	write(1, g_buf, g_itr);
	g_itr = 0;
	*edg = loc;
	return (sz);
}

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

int			print_text_until_exp(char **edg)
{
	int		sz;
	char	cc;
	char	*loc;

	loc = *edg;
	sz = 0;
	while (((cc = *loc) && '%' != cc) || ('%' == cc && '%' == *(loc + 1)))
	{
		write(1, &cc, 1);
		sz++;
		loc++;
	}
	*edg = loc;
	return (sz);
}

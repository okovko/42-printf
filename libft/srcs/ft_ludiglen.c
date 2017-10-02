/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ludiglen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:07:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 08:19:30 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long		ft_ludiglen(unsigned long val, int base)
{
	unsigned long		sz;

	sz = val == 0;
	while (val)
	{
		sz++;
		val /= base;
	}
	return (sz);
}

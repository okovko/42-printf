/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lludiglen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:07:40 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 08:19:03 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

unsigned long long		ft_lludiglen(unsigned long long val, int base)
{
	int		sz;

	sz = val == 0;
	while (val)
	{
		sz++;
		val /= base;
	}
	return (sz);
}

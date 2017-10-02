/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udiglen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:06:43 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 08:19:44 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

unsigned		ft_udiglen(unsigned val, int base)
{
	unsigned		sz;

	sz = val == 0;
	while (val)
	{
		sz++;
		val /= base;
	}
	return (sz);
}

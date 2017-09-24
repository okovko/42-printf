/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:06:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/21 02:33:02 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, int sz)
{
	unsigned char	c1;
	unsigned char	c2;

	if (sz <= 0)
		return (0);
	sz--;
	c1 = *(unsigned char *)s1++;
	c2 = *(unsigned char *)s2++;
	while (c1 == c2 && sz--)
	{
		c1 = *(unsigned char *)s1++;
		c2 = *(unsigned char *)s2++;
	}
	return (c1 - c2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:06:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/23 16:39:34 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		*tmp;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if ((tmp = (unsigned char *)malloc(sizeof(unsigned char) * n)))
	{
		i = 0;
		while (i < n)
		{
			tmp[i] = s[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			d[i] = tmp[i];
			i++;
		}
		free(tmp);
	}
	return (dest);
}

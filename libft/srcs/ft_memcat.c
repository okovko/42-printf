/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 05:11:24 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:52:21 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memcat(void *dst, const void *src, int dst_sz, int src_sz)
{
	void	*beg;

	beg = dst;
	dst += dst_sz;
	while (src_sz--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (beg);
}

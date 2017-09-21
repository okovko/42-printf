/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 06:53:54 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:21:46 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

int		ft_strlcat(char *dst, const char *src, int sz)
{
	int		ii;
	int		dst_sz;
	int		src_sz;
	int		left_to_copy;

	ii = 0;
	while (dst[ii] && ii < sz)
		ii++;
	dst_sz = ii;
	src_sz = ft_strlen(src);
	left_to_copy = sz - dst_sz;
	if (left_to_copy == 0)
		return (dst_sz + src_sz);
	ii = 0;
	while (src[ii] && left_to_copy-- > 1)
	{
		dst[dst_sz + ii] = src[ii];
		ii++;
	}
	dst[dst_sz + ii] = '\0';
	return (dst_sz + src_sz);
}

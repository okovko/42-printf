/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:06:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:41:40 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int sz)
{
	char				cc;
	void				*dst_beg;
	unsigned char		*tmp;
	unsigned char		*tmp_beg;

	if (NULL == (tmp = malloc(sz)))
		return (NULL);
	tmp_beg = tmp;
	dst_beg = dst;
	while ((cc = *(unsigned char *)src++))
		*tmp++ = cc;
	tmp = tmp_beg;
	while ((cc = *tmp++))
		*(unsigned char *)dst++ = cc;
	free(tmp);
	return (dst_beg);
}

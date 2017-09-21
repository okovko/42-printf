/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:06:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:50:36 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int cc, int sz)
{
	unsigned char uc;

	uc = (unsigned char)cc;
	if (sz < 0)
		return (NULL);
	while (sz--)
		if ((*(unsigned char *)dst++ = *(unsigned char *)src++) == uc)
			return (dst);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 01:03:51 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 01:03:51 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memcchr(const void *s, int c, size_t n)
{
	const unsigned char *ss;

	ss = (const unsigned char *)s;
	while (n--)
		if (*ss++ != (unsigned char)c)
			return ((void *)(ss - 1));
	return (NULL);
}

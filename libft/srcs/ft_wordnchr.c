/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 16:16:39 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/24 06:30:57 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_wordnchr(const char *str, char q, char d, size_t n)
{
	char	c;

	if (n == 0)
		return (NULL);
	while (((c = *str)) && c != d && n != 0)
	{
		if (c == q)
			return ((char *)str);
		str++;
		n--;
	}
	if (c == q && (q == d || q == '\0'))
		return ((char *)str);
	return (NULL);
}

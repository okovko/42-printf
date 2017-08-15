/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 16:06:37 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/01 16:06:37 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strnchr(const char *str, char q, size_t n)
{
	char	c;

	while ((c = *str) && n != 0)
	{
		if (c == q)
			return ((char *)str);
		str++;
		n--;
	}
	if (c == q)
		return ((char *)str);
	return (NULL);
}

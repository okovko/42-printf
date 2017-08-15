/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:29:19 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/01 16:07:02 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strchr(const char *str, char q)
{
	char	c;

	while ((c = *str))
	{
		if (c == q)
			return ((char *)str);
		str++;
	}
	if (q == '\0')
		return ((char *)str);
	return (NULL);
}

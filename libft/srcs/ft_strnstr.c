/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:32:07 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/29 14:31:33 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strnstr(const char *str, const char *query, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	nlen;

	nlen = ft_strlen(query);
	if (ft_strlen(str) < nlen)
		return (NULL);
	if (*query == '\0')
		return ((char *)str);
	i = 0;
	while (i + nlen <= n && str[i])
	{
		j = 0;
		while (query[j] && str[i + j] == query[j])
			j++;
		if (query[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

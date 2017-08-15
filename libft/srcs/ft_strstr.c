/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 01:51:04 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/29 14:30:46 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strstr(const char *str, const char *query)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(str) < ft_strlen(query))
		return (NULL);
	if (*query == '\0')
		return ((char *)str);
	i = 0;
	while (str[i])
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

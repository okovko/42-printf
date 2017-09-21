/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 06:53:54 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:13:51 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strmapi(char const *ss, char (*ff)(int, char))
{
	char	cc;
	char	*beg;
	char	*map;

	if (NULL == ss || NULL == ff)
		return (NULL);
	if (NULL == (map = malloc(ft_strlen(ss) + 1)))
		return (NULL);
	beg = map;
	while ((cc = *ss++))
	{
		*map = ff(map - beg, cc);
		map++;
	}
	*map = '\0';
	return (map);
}

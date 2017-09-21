/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:32:32 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:18:29 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strmap(char const *ss, char (*ff)(char))
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
		*map++ = ff(cc);
	*map = '\0';
	return (beg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:47 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/23 17:00:01 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	c;
	char	*start;

	if (!s)
		return (NULL);
	while (ISSPACE((c = *s)))
		s++;
	if (!*((start = (char *)s)))
		return (ft_strnew(0));
	while ((c = *s))
		s++;
	s--;
	while (ISSPACE((c = *s)))
		s--;
	return (ft_strsub(start, 0, s - start + 1));
}

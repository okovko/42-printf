/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:47 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 08:10:32 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strtrim(char const *ss)
{
	char	cc;
	char	*beg;

	if (NULL == ss)
		return (NULL);
	while (ISSPACE((cc = *ss)))
		ss++;
	if (!*((beg = (char *)ss)))
		return (ft_strnew(0));
	while ((cc = *ss))
		ss++;
	ss--;
	while (ISSPACE((cc = *ss)))
		ss--;
	return (ft_strsub(beg, 0, ss - beg + 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:29:19 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 13:04:50 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strrchr(const char *ss, char qry)
{
	char	cc;
	char	*fin;

	fin = NULL;
	while ((cc = *ss))
	{
		if (cc == qry)
			fin = (char *)ss;
		ss++;
	}
	if ('\0' == qry)
		return ((char *)ss);
	return ((char *)fin);
}

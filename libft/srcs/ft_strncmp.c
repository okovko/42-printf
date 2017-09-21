/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 02:25:54 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:12:24 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, int sz)
{
	unsigned char	c1;
	unsigned char	c2;

	if (sz == 0)
		return (0);
	c1 = *s1;
	c2 = *s2;
	while (c1 == c2 && c1 && sz--)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
	}
	return (c1 - c2);
}

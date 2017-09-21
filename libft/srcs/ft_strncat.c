/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 06:37:18 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/11 16:39:54 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, int sz)
{
	char	cc;
	char	*beg;

	beg = dst;
	while (*dst)
		dst++;
	while ((cc = *src++) && sz--)
		*dst++ = cc;
	*dst = '\0';
	return (beg);
}

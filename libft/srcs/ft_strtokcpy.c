/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtokcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 20:24:56 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 14:30:22 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char		*ft_strtokcpy(char *dst, const char *src, const char *dlm)
{
	char	*beg;
	char	cc;

	beg = dst;
	while ((cc = *src++) && NULL == ft_strchr(dlm, cc))
		*dst++ = cc;
	*dst = '\0';
	return (beg);
}

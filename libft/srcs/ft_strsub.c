/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 06:53:54 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 14:54:37 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strsub(char const *ss, int beg, int sz)
{
	char	*sub;

	if (NULL == ss || beg < 0 || sz < 0)
		return (NULL);
	if (NULL == (sub = ft_strnew(sz)))
		return (NULL);
	return (ft_strncpy(sub, ss + beg, sz));
}

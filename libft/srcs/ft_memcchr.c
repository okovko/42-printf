/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 01:03:51 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:05:25 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memcchr(const void *mm, int cc, int sz)
{
	if (NULL == mm || sz < 0)
		return (NULL);
	while (sz--)
		if (*(unsigned char *)mm++ != (unsigned char)cc)
			return ((void *)(mm - 1));
	return (NULL);
}

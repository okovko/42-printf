/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:06:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/28 02:40:32 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memset(void *mm, int bb, int sz)
{
	unsigned char	*byts;

	byts = mm;
	while (sz--)
		*byts++ = (unsigned char)bb;
	return (mm);
}

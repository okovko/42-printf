/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drnglen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 22:45:42 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/20 03:31:06 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "libft.h"

size_t	ft_drnglen(int a, int b, int (*f)(int))
{
	size_t			len;
	const size_t	max = ABS(b - a);

	RNULLCHECK(0, f);
	RETIF(0, ABS(b - a) <= ABS(b - f(a)));
	len = 0;
	while (a < b && len < max)
	{
		a = f(a);
		len++;
	}
	return (len == max ? len : 0);
}

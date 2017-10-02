/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldiglen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:06:24 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 07:55:38 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

long long		ft_lldiglen(long long val)
{
	long long		sz;

	sz = val == 0;
	while (val)
	{
		sz++;
		val /= 10;
	}
	return (sz);
}

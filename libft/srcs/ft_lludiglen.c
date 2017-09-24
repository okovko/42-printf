/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lludiglen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 06:07:40 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 21:40:10 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

unsigned long long		ft_lludiglen(unsigned long long val)
{
	int		sz;

	sz = val == 0;
	while (val)
	{
		sz++;
		val /= 10;
	}
	return (sz);
}

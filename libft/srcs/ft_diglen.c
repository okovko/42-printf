/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diglen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 22:15:35 by olkovale          #+#    #+#             */
/*   Updated: 2017/10/02 08:19:53 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

int		ft_diglen(int val)
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

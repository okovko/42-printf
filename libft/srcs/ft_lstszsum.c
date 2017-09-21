/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstszsum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 21:09:05 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:52:58 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

int		ft_lstszsum(t_lst *ll)
{
	int		sum;

	sum = 0;
	while (NULL != ll)
	{
		sum += ll->sz;
		ll = ll->nxt;
	}
	return (sum);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmemfind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 04:55:15 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/08 04:55:15 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst		*ft_lstmemfind(t_lst *ll, void *qry, int ofst, int sz)
{
	t_lst	*itr;

	itr = ll;
	while (NULL != itr)
	{
		if (0 == ft_memcmp((void *)qry, (void *)(itr->dat + ofst), sz))
			return (itr);
		itr = itr->nxt;
	}
	return (NULL);
}

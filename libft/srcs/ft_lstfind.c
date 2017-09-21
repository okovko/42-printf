/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 00:46:15 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:53:58 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst		*ft_lstfind(t_lst *ll, void *qry,
						int (*cmp)(void *, void *, int))
{
	t_lst	*itr;

	itr = ll;
	while (NULL != itr)
	{
		if (0 == cmp(qry, itr->dat, itr->sz))
			return (itr);
		itr = itr->nxt;
	}
	return (NULL);
}

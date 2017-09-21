/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:07:11 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:54:13 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static t_lst	*ft_lstdelcmp_beg(t_lst **ll, void *qry,
									int (*cmp)(const void *, const void *, int))
{
	t_lst	*beg;
	t_lst	*tmp;

	beg = *ll;
	while (NULL != beg && 0 == cmp(qry, beg->dat, beg->sz))
	{
		tmp = beg;
		free(tmp->dat);
		free(tmp);
		beg = beg->nxt;
	}
	*ll = beg;
	return (beg);
}

t_lst			*ft_lstdelcmp(t_lst **ll, void *qry,
								int (*cmp)(const void *, const void *, int))
{
	t_lst	*prv;
	t_lst	*cur;

	if (!ll || !*ll || !qry || !cmp)
		return (NULL);
	if (NULL == (prv = ft_lstdelcmp_beg(ll, qry, cmp)))
		return (NULL);
	cur = prv->nxt;
	while (NULL != cur)
	{
		if (0 != cmp(qry, cur->dat, cur->sz))
		{
			prv = cur;
			cur = cur->nxt;
			continue ;
		}
		prv->nxt = cur->nxt;
		free(cur->dat);
		free(cur);
		cur = prv->nxt;
	}
	return (*ll);
}

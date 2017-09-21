/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:08 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 12:54:13 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_lst	*ft_lstdel(t_lst **ll, void (*del)(void *, int))
{
	t_lst	*itr;

	if (NULL == ll || NULL == *ll || NULL == del)
		return (NULL);
	itr = *ll;
	while (itr)
	{
		del(itr->dat, itr->sz);
		itr = (**ll).nxt;
		free(*ll);
		*ll = itr;
	}
	return (NULL);
}

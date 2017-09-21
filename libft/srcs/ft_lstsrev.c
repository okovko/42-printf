/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 23:29:10 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:53:20 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

t_lst	*ft_lstsrev(t_lst **ll)
{
	t_lst	*prv;
	t_lst	*cur;
	t_lst	*nxt;

	if (NULL == ll)
		return (NULL);
	prv = NULL;
	cur = *ll;
	while (cur)
	{
		nxt = cur->nxt;
		cur->nxt = prv;
		prv = cur;
		cur = nxt;
	}
	*ll = prv;
	return (*ll);
}

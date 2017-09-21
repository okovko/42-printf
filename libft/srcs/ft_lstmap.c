/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:12 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:53:28 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

t_lst	*ft_lstmap(t_lst *ll, t_lst *(*ff)(t_lst *elm))
{
	t_lst	*beg;
	t_lst	*map;

	if (!ll || !ff)
		return (NULL);
	map = ff(ll);
	beg = map;
	ll = ll->nxt;
	while (ll)
	{
		map->nxt = ff(ll);
		map = map->nxt;
		ll = ll->nxt;
	}
	return (beg);
}

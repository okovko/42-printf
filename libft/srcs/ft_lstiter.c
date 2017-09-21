/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 05:48:56 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:53:35 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstiter(t_lst *ll, void (*ff)(t_lst *elm))
{
	t_lst	*beg;

	if (!ll || !ff)
		return (NULL);
	beg = ll;
	while (ll)
	{
		ff(ll);
		ll = ll->nxt;
	}
	return (beg);
}

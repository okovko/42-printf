/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:14:03 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:53:25 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_lst	*ft_lstnew(void const *dat, int sz)
{
	t_lst	*ll;

	if (NULL == (ll = (t_lst *)malloc(sizeof(*ll))))
		return (NULL);
	if (NULL == (ll->dat = malloc(sizeof(sz))))
	{
		free(ll);
		return (NULL);
	}
	if (dat)
	{
		ft_memcpy(ll->dat, dat, sz);
		ll->sz = sz;
	}
	else
	{
		ll->dat = NULL;
		ll->sz = 0;
	}
	ll->nxt = NULL;
	return (ll);
}

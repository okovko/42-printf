/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 02:53:50 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/28 21:23:23 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_map_kv	*ft_mapget(t_map *mp, void *key,
						int (*keycmp)(void *, void *, int))
{
	t_map_kv	*iter;
	t_map_kv	*end;

	if (NULL == mp || NULL == key)
		return (NULL);
	iter = mp->kvs;
	end = iter + mp->sz;
	while (iter < end)
	{
		if (0 == keycmp(key, iter->key, (int)mp->key_sz))
			return (iter);
		iter++;
	}
	return (NULL);
}

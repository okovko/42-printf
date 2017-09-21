/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 02:53:50 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 18:15:07 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_map_kv	*ft_mapget(t_map *map, void *key,
						int (*keycmp)(void *, void *, size_t))
{
	t_map_kv	*iter;
	t_map_kv	*end;

	NULLCHECK(map, key);
	iter = map->kvs;
	end = iter + map->sz;
	while (iter < end)
	{
		if (0 == keycmp(key, iter->key, (size_t)map->key_sz))
			return (iter);
		iter++;
	}
	return (NULL);
}

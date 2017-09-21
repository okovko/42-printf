/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsgen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 19:53:18 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/18 03:10:49 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_map	*ft_mapsgen(t_map *map, void *keys, void *vals)
{
	t_map_kv	*iter;
	t_map_kv	*end;

	NULLCHECK(map, keys, vals);
	map->kvs = malloc(sizeof(*iter) * map->sz);
	CHKALLOC(map->kvs);
	iter = map->kvs;
	end = iter + map->sz;
	while (iter < end)
	{
		iter->key = keys;
		iter->val = vals;
		keys += map->key_sz;
		vals += map->val_sz;
		iter++;
	}
	return (map);
}

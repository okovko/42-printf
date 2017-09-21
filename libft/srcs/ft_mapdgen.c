/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdgen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 19:53:47 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/18 19:12:06 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_map	*ft_mapdgen(t_map *map, void *keys, void *vals)
{
	t_map_kv	*iter;
	t_map_kv	*end;

	NULLCHECK(map, keys, vals);
	map->kvs = malloc(sizeof(*iter) * map->sz);
	iter = map->kvs;
	CHKALLOC(iter);
	end = iter + map->sz;
	while (iter < end)
	{
		iter->key = malloc(map->key_sz);
		iter->key = malloc(map->key_sz);
		iter->val = malloc(map->val_sz);
		CHKALLOC(iter, iter->key, iter->val);
		ft_memcpy(iter->key, keys, map->key_sz);
		ft_memcpy(iter->val, vals, map->val_sz);
		keys += map->key_sz;
		vals += map->val_sz;
		iter++;
	}
	return (map);
}

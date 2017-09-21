/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:10:12 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/24 22:48:07 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_map_kv	*ft_mapnget(t_map *map, void *key,
						int (*keycmp)(void *, void *, size_t), int sz)
{
	t_map_kv	*iter;
	t_map_kv	*end;

	NULLCHECK(map, key);
	iter = map->kvs;
	end = iter + map->sz;
	while (iter < end)
	{
		if (0 == keycmp(key, iter->key, (size_t)sz))
			return (iter);
		iter++;
	}
	return (NULL);
}

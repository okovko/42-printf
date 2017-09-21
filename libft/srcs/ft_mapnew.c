/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 16:53:07 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/18 19:11:58 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_map	*ft_mapnew(int sz, int key_sz, int val_sz)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	CHKALLOC(map);
	map->sz = sz;
	map->key_sz = key_sz;
	map->val_sz = val_sz;
	return (map);
}

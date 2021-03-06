/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt_tok.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 21:18:36 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/28 21:34:57 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_map_kv		*parse_fmt_tok(t_map *mp, char *loc, char **edg)
{
	t_map_kv	*kv;

	kv = ft_mapget(mp, (void *)loc, ft_map_keycmp_str);
	if (NULL != kv)
		*edg = loc + ft_strlen((char *)kv->key);
	return (kv);
}

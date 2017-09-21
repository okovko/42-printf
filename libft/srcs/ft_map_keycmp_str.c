/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_keycmp_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 22:27:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/24 22:57:14 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_map_keycmp_str(void *key, void *iter, size_t sz)
{
	(void)sz;
	return (ft_strcmp((char *)key, (char *)iter));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_keycmp_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 22:27:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/25 03:47:09 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_map_keycmp_str(void *key, void *iter, int sz)
{
	(void)sz;
	return (ft_strcmp((char *)key, (char *)iter));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_keycmp_strnstr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:31:08 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/21 02:21:46 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_map_keycmp_strnstr(void *str, void *query, int sz)
{
	return (NULL != ft_strnstr((char *)str, (char *)query, sz));
}

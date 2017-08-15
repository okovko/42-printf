/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 19:05:59 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/21 12:24:34 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "libft.h"

void	ft_cpyswap(void *a, void *b, size_t sz)
{
	void	*tmp;

	tmp = malloc(sz);
	ft_memcpy(tmp, a, sz);
	ft_memcpy(a, b, sz);
	ft_memcpy(b, tmp, sz);
	free(tmp);
}

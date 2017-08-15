/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:29:50 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 13:29:50 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "libft.h"

void	*ft_memjoin(void const *m1, void const *m2, size_t s1, size_t s2)
{
	void	*cat;

	NULLCHECK(m1, m2);
	CHKALLOC(cat = malloc(s1 + s2));
	ft_memcpy(cat, m1, s1);
	ft_memcpy(cat + s1, m2, s2);
	return (cat);
}

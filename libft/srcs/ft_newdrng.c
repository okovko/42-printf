/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newdrng.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 07:46:34 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/26 23:49:44 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "libft.h"

t_drange	*ft_newdrng(int a, int b, int (*f)(int))
{
	t_drange	*rng;
	int			*r;
	size_t		len;

	NULLCHECK(f);
	NULLIF((len = ft_drnglen(a, b, f)) == 0);
	rng = malloc(sizeof(t_drange));
	r = malloc(sizeof(int) * (len));
	CHKALLOC(rng, r);
	rng->start = r;
	while (a < b)
	{
		*r++ = a;
		a = f(a);
	}
	rng->end = r;
	return (rng);
}

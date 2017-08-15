/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 07:16:43 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/21 12:50:23 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "libft.h"

void	*ft_cpyrev(void *start, void *end, size_t sz)
{
	void			*s;
	void			*e;
	void			*tmp;

	NULLCHECK(start, end);
	NULLIF(sz == 0);
	tmp = malloc(sz);
	CHKALLOC(tmp);
	s = start;
	e = end;
	while (s < e)
	{
		ft_memcpy(tmp, s, sz);
		ft_memcpy(s, e, sz);
		ft_memcpy(e, tmp, sz);
		s += sz;
		e -= sz;
	}
	free(tmp);
	return (start);
}

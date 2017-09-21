/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:12:42 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:53:16 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char		*ft_lststr(t_lst *ll)
{
	char	*ln;
	int		sz;
	int		uz;

	if (NULL == ll)
		return (NULL);
	sz = ft_lstszsum(ll);
	if (NULL == (ln = malloc(sz + 1)))
		return (NULL);
	ln[sz] = '\0';
	uz = 0;
	while (NULL != ll)
	{
		ln = ft_memcpy(ln + uz, (char *)ll->dat,
						ll->sz);
		uz += ll->sz;
		ll = ll->nxt;
	}
	return (ln);
}

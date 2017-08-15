/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpermute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 00:03:20 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 16:11:18 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_dpermute(int *start, int *end)
{
	int	*i;
	int	*j;
	int	*k;

	RETIF(false, start == end || start == end - 1);
	end--;
	i = end;
	while (true)
	{
		j = i;
		--i;
		if (*i < *j)
		{
			k = end;
			while (NOT(*i < *k))
				k--;
			ft_cpyswap((void *)i, (void *)k, sizeof(int));
			ft_cpyrev((void *)j, (void *)end, sizeof(int));
			return (true);
		}
		IF((i == start),
			ft_cpyrev(start, end, sizeof(int)),
			RET(false));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xy_from_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 08:18:38 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 22:26:16 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_point		*ft_xy_from_str(t_text *tx, t_rect *rx, char *pos)
{
	char	*f;
	t_point	*pt;

	NULLCHECK(tx, rx, pos);
	pt = malloc(sizeof(t_point));
	CHKALLOC(pt);
	f = ft_strvchrhed(tx->start, pos, tx->delim);
	pt->x = (pos - f) - (f != tx->start);
	pt->y = 0;
	while (f != tx->start)
	{
		f = ft_strvchrhed(tx->start, f - 1, tx->delim);
		pt->y++;
	}
	return (pt);
}

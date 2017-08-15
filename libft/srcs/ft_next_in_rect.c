/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_in_rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 22:46:16 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/27 00:04:32 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_next_in_rect(t_text *tx, t_rect *rx, char *pos)
{
	t_point	*offset;
	char	*f;

	NULLCHECK(tx, rx);
	RETIF(tx->start, NULL == pos);
	offset = ft_xy_from_str(tx, rx, pos);
	RETIF(NULL, NULL == offset);
	RETIF(NULL, (size_t)offset->x > rx->x1 || (size_t)offset->y > rx->y1);
	RETIF(NULL, (size_t)offset->x < rx->x0 || (size_t)offset->y < rx->y0);
	if ((size_t)offset->x + 1 <= rx->x1 && *(pos + 1) != tx->delim)
		return (pos + 1);
	else if ((f = ft_strchrnul(pos, tx->delim)) != tx->end
			&& (size_t)(tx->end - (f + 1)) > rx->x0
			&& (size_t)offset->y + 1 <= rx->y1)
		return (f + 1 + rx->x0);
	else
		return (NULL);
}

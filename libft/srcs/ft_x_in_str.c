/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_in_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 17:00:46 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 22:32:22 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

#include "libft.h"

char	*ft_x_in_str(t_text *tx, char *pos, int x)
{
	char	*line_start;
	char	*line_end;
	char	*f;
	int		len;

	if (!tx || !pos)
		return (NULL);
	if (x == 0)
		return (pos);
	line_start = ft_strvchrhed(tx->start, pos, tx->delim);
	line_start += line_start != tx->start;
	line_end = ft_strchrnul(pos, tx->delim);
	len = line_end - line_start;
	if (x < 0 && ABS(x) > (pos - line_start))
		return (NULL);
	else if (x > 0 && x > (line_end - pos))
		return (NULL);
	f = pos + x;
	return (f >= line_start && f <= line_end ? f : NULL);
}

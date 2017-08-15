/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xy_in_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 17:00:46 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 22:32:25 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

#include "libft.h"

static ptrdiff_t	offset_helper(t_text *tx, char *pos, char **line_start)
{
	char		*f;

	f = ft_strvchr(tx->start, pos, tx->delim);
	*line_start = f ? f + 1 : tx->start;
	return (pos - *line_start);
}

char				*ft_xy_in_str(t_text *tx, char *pos, int x, int y)
{
	char			*line_start;
	char			*line_end;
	char			*f;
	const ptrdiff_t	initial_offset = offset_helper(tx, pos, &line_start);

	NULLCHECK(tx, pos);
	NULLIF((f = ft_strchrnul(pos, tx->delim)) && *f == '\0');
	(y > 0) ? (line_end = f)
			: (f = line_start - 1);
	while (y != 0)
	{
		(y > 0) ? (line_start = line_end + 1)
				: (line_end = line_start - 1);
		IF(y > 0,
			line_start = line_end + 1,
			NULLIF((f = ft_strchrnul(f + 1, tx->delim)) == tx->end && y != 1),
			line_end = f);
		IF(y <= 0,
			line_end = line_start - 1,
			NULLIF((f = ft_strvchrhed(tx->start, f + 1, tx->delim))
					== tx->start && y != 1),
			line_start = f);
		(y > 0) ? (y--) : (y++);
	}
	return (ft_x_in_str(tx, line_start, x + initial_offset));
}

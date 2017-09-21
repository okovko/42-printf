/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 04:27:49 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/08 04:27:49 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

int			get_next_buf(int fd, int sz, char **buf)
{
	int		ret;

	if (NULL == buf)
		return (-1);
	if (NULL == (*buf = malloc(sz)))
		return (-1);
	ret = read(fd, *buf, sz);
	if (0 >= ret)
	{
		free(*buf);
		*buf = NULL;
	}
	return (ret);
}

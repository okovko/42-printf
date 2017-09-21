/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_scan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 04:23:16 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/08 04:23:16 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

int		get_next_scan(const char *buf, const char *dlm, char **out)
{
	int		sz;

	if (NULL == buf || NULL == out || NULL == dlm)
		return (-1);
	sz = ft_strcspn(buf, dlm);
	if (NULL == (*out = malloc(sz)))
		return (-1);
	*out = ft_memcpy((void *)*out, (void *)buf, sz);
	return (sz);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:40:41 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:31:26 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strbuf(const char *buf, int sz)
{
	char	*ss;

	if (NULL == buf)
		return (NULL);
	if (NULL == (ss = malloc(sz + 1)))
		return (NULL);
	return (ft_strncpy(ss, buf, sz));
}

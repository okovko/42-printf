/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:40:41 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 13:40:41 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strbuf(const char *buf, size_t sz)
{
	char	*str;

	NULLCHECK(buf);
	CHKALLOC(str = ft_strnew(sz));
	return (ft_strncpy(str, buf, sz));
}

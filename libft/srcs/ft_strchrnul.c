/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:06:47 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 16:06:47 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrnul(const char *ss, char qry)
{
	char	cc;

	while ((cc = *ss))
	{
		if (cc == qry)
			return ((char *)ss);
		ss++;
	}
	return ((char *)ss);
}

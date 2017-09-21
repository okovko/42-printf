/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 01:51:04 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 13:40:53 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strstr(const char *ss, const char *qry)
{
	const char	*ss_itr;
	const char	*qry_itr;

	while (*ss)
	{
		ss_itr = ss;
		qry_itr = qry;
		while (*ss_itr && *qry_itr)
			if (*ss_itr++ != *qry_itr++)
				break ;
		if ('\0' == *qry_itr)
			return ((char *)(ss));
		if ('\0' == *ss_itr)
			return (NULL);
		ss++;
	}
	return (NULL);
}

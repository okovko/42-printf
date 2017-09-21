/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:32:07 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 13:36:44 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strnstr(const char *ss, const char *qry, int sz)
{
	const char	*ss_itr;
	const char	*qry_itr;
	int			qsz;

	qsz = ft_strlen(qry);
	while (*ss && sz-- >= qsz)
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

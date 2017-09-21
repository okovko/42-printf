/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:14:15 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 13:14:15 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *ss, const char *dlm)
{
	static char		*beg;
	char			*end;

	if (NULL != ss)
		return ((beg = ss));
	if ('\0' == *beg)
		return (NULL);
	beg = beg + ft_strspn(beg, dlm);
	end = beg + ft_strcspn(beg, dlm);
	*end = '\0';
	ss = beg;
	beg = end + 1;
	return (ss);
}

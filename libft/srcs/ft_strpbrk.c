/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:07:00 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/11 16:22:38 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *ss, const char *dlm)
{
	char	cc;
	
	if (NULL == ss || NULL == dlm)
		return (NULL);
	while ((cc = *ss))
		if (NULL != (ft_strchr(dlm, cc)))
			return ((char *)ss);
		else
			ss++;
	return (NULL);
}

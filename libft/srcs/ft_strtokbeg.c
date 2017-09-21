/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtokbeg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:41:45 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 14:41:45 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtokbeg(const char *ss, const char *dlm)
{
	char	cc;

	if (NULL == ss || NULL == dlm)
		return ((char *)ss);
	while ((cc = *ss) && ft_strchr(dlm, cc))
		ss++;
	return ((char *)ss);
}

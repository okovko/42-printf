/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoknxt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:06:49 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 14:39:55 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoknxt(const char *ss, const char *dlm)
{
	char	cc;

	while ((cc = *ss) && NULL == ft_strchr(dlm, cc))
		ss++;
	while ((cc = *ss) && ft_strchr(dlm, cc))
		ss++;
	return ((char *)ss);
}

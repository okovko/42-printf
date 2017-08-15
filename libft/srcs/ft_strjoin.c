/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:17:56 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 00:30:21 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;

	if (!s1 || !s2)
		return (NULL);
	if ((cat = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		ft_strcpy(cat, s1);
		return (ft_strcat(cat, s2));
	}
	return (NULL);
}

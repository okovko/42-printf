/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:14:51 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 00:44:11 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *dup;

	if ((dup = ft_strnew(ft_strlen(src))))
		return (ft_strcpy(dup, src));
	return (NULL);
}

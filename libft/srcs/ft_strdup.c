/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:14:51 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:27:18 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;

	if (NULL == (dup = malloc(ft_strlen(src) + 1)))
		return (NULL);
	return (ft_strcpy(dup, src));
}

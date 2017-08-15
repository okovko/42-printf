/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newdarri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 21:43:29 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/22 23:26:26 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

int	*ft_newdarri(size_t len)
{
	int		*arr;
	size_t	i;

	arr = malloc(sizeof(int) * len);
	CHKALLOC(arr);
	i = 0;
	while (i < len)
	{
		arr[i] = i;
		i++;
	}
	return (arr);
}

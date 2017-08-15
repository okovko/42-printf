/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darrfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:30:16 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 16:06:13 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

int		*ft_darrfind(int *arr, int value, int len)
{
	int	ii;

	ii = 0;
	while (ii < len)
	{
		if (arr[ii] == value)
			return (arr + ii);
		ii++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darrmin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:53:59 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/21 18:53:59 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_darrmin(int *arr, int len)
{
	int	i;
	int	min;
	int	loc;

	loc = 0;
	min = arr[0];
	i = 1;
	while (i < len)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			loc = i;
		}
		i++;
	}
	return (arr + loc);
}

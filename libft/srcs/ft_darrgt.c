/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darrgt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:19:09 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 16:07:57 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_darrmingt(int *arr, int val, int len)
{
	int		i;
	int		*min;
	int		loc;
	t_bool	found;

	loc = 0;
	found = false;
	min = NULL;
	i = 0;
	while (i < len)
	{
		if (NULL == min && arr[i] > val)
		{
			found = true;
			min = arr + i;
			loc = i;
		}
		else if (min && arr[i] < *min && arr[i] > val)
		{
			min = arr + i;
			loc = i;
		}
		i++;
	}
	return (found ? arr + loc : NULL);
}

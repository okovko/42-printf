/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dmin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 07:34:57 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/21 07:42:08 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dmin(int *first, int *last)
{
	int	min;
	int	*head;

	head = first;
	min = *first;
	while (first <= last)
		min = MIN(*first++, min);
	return (head - first);
}

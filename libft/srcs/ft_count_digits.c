/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 20:17:46 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/14 12:11:24 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

size_t		ft_count_digits(long value)
{
	size_t	count;

	count = value == 0;
	while (value)
	{
		count++;
		value /= 10;
	}
	return (count);
}

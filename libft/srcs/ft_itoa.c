/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:15:17 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/21 19:08:37 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*head;
	char	*str;

	if (!(str = malloc((n < 0) + ft_count_digits(n) + 1)))
		return (NULL);
	head = str;
	if (n < 0)
		*str++ = '-';
	*str++ = ABS(n % 10) + '0';
	n /= 10;
	while (n)
	{
		*str++ = ABS(n % 10) + '0';
		n /= 10;
	}
	*str = '\0';
	ft_strrev(*head == '-' ? head + 1 : head);
	return (head);
}

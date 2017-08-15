/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:30 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/21 19:10:30 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*head;
	char	*str;
	char	num[22];

	str = num;
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
	ft_putstr_fd(head, fd);
}

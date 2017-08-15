/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 06:37:18 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 00:23:06 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	c;
	char	*head;

	head = dest;
	while (*dest)
		dest++;
	while ((c = *src++))
		*dest++ = c;
	*dest = '\0';
	return (head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 20:24:56 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/23 09:06:18 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char		*ft_word_copy(char *dest, char const *src, char delim)
{
	char	*head;
	char	c;

	head = NULL;
	while ((c = *src++) && c != delim)
		*dest++ = c;
	*dest = '\0';
	return (head);
}

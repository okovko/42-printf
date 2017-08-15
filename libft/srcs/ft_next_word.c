/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 20:23:28 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/26 04:40:01 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const	*ft_next_word(char const *str, char delim)
{
	char	c;

	while ((c = *str) && c != delim)
		str++;
	while ((c = *str) && c == delim)
		str++;
	return (str);
}

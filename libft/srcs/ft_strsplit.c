/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 23:06:36 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/23 16:58:25 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char		**ft_strsplit(char const *str, char c)
{
	unsigned	i;
	unsigned	count;
	char		**strarr;

	if (!str)
		return (NULL);
	while (*str && *str == c)
		++str;
	i = 0;
	count = ft_count_words(str, c);
	if (((strarr = (char **)malloc((count + 1) * sizeof(char *)))) == NULL)
		return (NULL);
	while (i < count + 1)
	{
		strarr[i] = ft_strnew(ft_word_length(str, c));
		ft_word_copy(strarr[i], str, c);
		str = ft_next_word(str, c);
		i++;
	}
	strarr[count] = 0;
	return (strarr);
}

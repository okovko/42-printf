/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 09:45:09 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/21 21:20:56 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchrnul(const char *str, char q)
{
	char	c;

	while ((c = *str))
	{
		if (c == q)
			return ((char *)str);
		str++;
	}
	return ((char *)str);
}

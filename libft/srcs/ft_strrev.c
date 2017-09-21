/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 20:21:57 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:01:43 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*lft;
	char	*rgt;
	char	tmp;

	lft = str;
	rgt = ft_strchrnul(str, '\0');
	rgt -= rgt > lft;
	while (lft < rgt)
	{
		tmp = *lft;
		*lft = *rgt;
		*rgt = tmp;
		lft++;
		rgt--;
	}
	return (str);
}

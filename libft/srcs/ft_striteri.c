/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:24:37 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:24:37 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stritri(char *ss, void (*ff)(int, char *))
{
	char	*beg;

	beg = ss;
	if (NULL == ss || NULL == ff)
		return ;
	while (*ss)
	{
		ff(ss - beg, ss);
		ss++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtokamt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 20:24:12 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 14:25:49 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strtokamt(const char *ss, const char *dlm)
{
	int		sz;

	sz = 0;
	while (*ss)
	{
		ss = ft_strtoknxt(ss, dlm);
		sz++;
	}
	return (sz);
}

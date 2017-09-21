/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 23:06:36 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/11 16:47:51 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char		**ft_strsplit(const char *ss, const char *dlm)
{
	int			ii;
	int			sz;
	char		**sarr;

	if (NULL == ss || NULL == dlm)
		return (NULL);
	ss = ft_strtokbeg(ss, dlm);
	ii = 0;
	sz = ft_strtokamt(ss, dlm);
	if (NULL == (sarr = malloc((sz + 1) * sizeof(char *))))
		return (NULL);
	while (ii < sz + 1)
	{
		sarr[ii] = malloc(ft_strtoklen(ss, dlm) + 1);
		ft_strtokcpy(sarr[ii], ss, dlm);
		ss = ft_strtoknxt(ss, dlm);
		ii++;
	}
	sarr[sz] = 0;
	return (sarr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:01:55 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 13:01:55 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcspn(const char *ss, const char *dlm)
{
	const char	*beg;

	if (NULL == ss || NULL == dlm)
		return (0);
	beg = ss;
	while (*ss && NULL == ft_strchr(dlm, *ss))
		ss++;
	return (ss - beg);
}

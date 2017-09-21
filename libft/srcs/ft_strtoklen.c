/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoklen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:14:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 16:14:23 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strtoklen(const char *ss, const char *dlm)
{
	char		cc;
	const char	*beg;

	beg = ss;
	while ((cc = *ss) && NULL == ft_strchr(dlm, cc))
		ss++;
	while ((cc = *ss) && ft_strchr(dlm, cc))
		ss++;
	return (ss - beg);
}

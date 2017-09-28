/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi_nol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 19:52:53 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/27 18:44:28 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strtoi_nol(const char *ss, char **edg)
{
	char	cc;
	int		nn;

	nn = 0;
	while ((cc = *ss) && ISDIGIT(cc))
	{
		nn = nn * 10 + cc - '0';
		ss++;
	}
	*edg = (char *)ss;
	return (nn);
}

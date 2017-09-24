/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi_nol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 19:52:53 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/23 21:42:32 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strtoi_nol(const char *ss, char **endptr)
{
	char	cc;
	int		nn;

	nn = 0;
	while ((cc = *ss) && ISDIGIT(cc))
	{
		nn = nn * 10 - cc + '0';
		ss++;
	}
	*endptr = (char *)ss;
	return (nn);
}

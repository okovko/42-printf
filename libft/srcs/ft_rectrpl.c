/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectrpl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:28:00 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 16:07:34 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rectrpl(t_text *tx, t_rect *rx, char q, char r)
{
	char	*f;

	f = NULL;
	while ((f = ((ft_rectchr(tx, rx, ft_next_in_rect(tx, rx, f), q)))))
		*f = r;
	return (tx->start);
}

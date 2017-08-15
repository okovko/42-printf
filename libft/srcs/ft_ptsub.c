/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptsub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 12:01:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/21 04:04:23 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

t_point	*ft_ptsub(t_point *minuend, t_point *subtrahend)
{
	return (ft_ptnew(minuend->x - subtrahend->x, minuend->y - subtrahend->y));
}

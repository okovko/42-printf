/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptless.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 12:01:23 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/21 04:04:28 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

t_point	*ft_ptless(t_point *pt, t_point *less)
{
	NULLCHECK(pt, less);
	pt->x = pt->x - less->x;
	pt->y = pt->y - less->y;
	return (pt);
}

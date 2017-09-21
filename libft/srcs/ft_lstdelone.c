/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 08:15:09 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/06 15:54:08 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_lst	*ft_lstdelone(t_lst **ll, void (*del)(void *, int))
{
	if (!ll || !*ll || !del)
		return (NULL);
	del((*ll)->dat, (*ll)->sz);
	free(*ll);
	*ll = NULL;
	return (NULL);
}

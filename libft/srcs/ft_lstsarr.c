/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 06:42:38 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/21 03:07:33 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "libft.h"

void	**ft_lstsarr(t_list *lst)
{
	void	**arr;
	size_t	i;
	size_t	max;

	NULLCHECK(lst);
	max = ft_lstlen(lst) + 1;
	arr = malloc(max * sizeof(void *));
	CHKALLOC(arr);
	i = 0;
	while (i < max && lst)
	{
		arr[i] = lst->content;
		lst = lst->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

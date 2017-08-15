/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrslst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:16:39 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/19 05:54:09 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_arrslst(void *arr, size_t sz)
{
	t_list			*lst;
	unsigned char	*ptr;

	NULLCHECK(arr);
	NULLIF(sz == 0);
	lst = NULL;
	ptr = (unsigned char *)arr;
	while (ptr)
	{
		ft_lstadd(&lst, ft_lstnew((void *)ptr, sz));
		ptr++;
	}
	return (ft_lstsrev(&lst));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:37:54 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/14 11:32:54 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

t_list	*ft_lstdcpy(t_list *lst)
{
	t_list	*dcpy;
	t_list	*node;

	NULLCHECK(lst);
	dcpy = NULL;
	while (lst)
	{
		NULLIF((node = ft_lstnode(lst->content, lst->content_size)) == NULL);
		ft_lstadd(&dcpy, node);
		lst = lst->next;
	}
	return (ft_lstsrev(&dcpy));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstscpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:04:04 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/14 11:49:29 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

t_list	*ft_lstscpy(t_list *lst)
{
	t_list	*scpy;
	t_list	*node;

	NULLCHECK(lst);
	scpy = NULL;
	while (lst)
	{
		NULLIF((node = ft_lstnode(lst->content, lst->content_size)) == NULL);
		ft_lstadd(&scpy, node);
		lst = lst->next;
	}
	return (ft_lstsrev(&scpy));
}
